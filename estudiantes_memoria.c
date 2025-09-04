#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    unsigned edad : 7;
    unsigned borrado : 1;
    uint32_t identificacion;
} MetaCompacta;

typedef struct {
    char   *nombre;
    char   *apellido;
    float  *notas;
    size_t  n_notas;
    MetaCompacta meta;
} Estudiante;

typedef struct {
    Estudiante **items;
    size_t size;
    size_t cap;
} DB;

static char *dup_ajustada(const char *s) {
    size_t n = strlen(s) + 1;
    char *p = (char*)malloc(n);
    if (!p) { perror("malloc"); exit(1); }
    memcpy(p, s, n);
    return p;
}

static Estudiante *crear_estudiante(const char *nombre, const char *apellido,
                                    uint32_t id, unsigned edad,
                                    const float *notas, size_t n_notas)
{
    Estudiante *e = (Estudiante*)malloc(sizeof *e);
    if (!e) { perror("malloc"); exit(1); }

    e->nombre   = dup_ajustada(nombre);
    e->apellido = dup_ajustada(apellido);

    e->notas = NULL;
    e->n_notas = 0;
    if (n_notas > 0) {
        e->notas = (float*)malloc(n_notas * sizeof(float));
        if (!e->notas) { perror("malloc"); exit(1); }
        memcpy(e->notas, notas, n_notas * sizeof(float));
        e->n_notas = n_notas;
    }

    e->meta.edad = (edad > 127) ? 127 : edad;
    e->meta.borrado = 0;
    e->meta.identificacion = id;

    return e;
}

static void liberar_estudiante(Estudiante *e) {
    if (!e) return;
    free(e->nombre);
    free(e->apellido);
    free(e->notas);
    free(e);
}

static void db_init(DB *db) {
    db->items = NULL;
    db->size = 0;
    db->cap = 0;
}

static void db_reservar(DB *db, size_t nueva_cap) {
    if (nueva_cap <= db->cap) return;
    Estudiante **nuevo = (Estudiante**)realloc(db->items, nueva_cap * sizeof(Estudiante*));
    if (!nuevo) { perror("realloc"); exit(1); }
    for (size_t i = db->cap; i < nueva_cap; ++i) nuevo[i] = NULL;
    db->items = nuevo;
    db->cap = nueva_cap;
}

static void db_agregar(DB *db, Estudiante *e) {
    if (db->size == db->cap) {
        size_t nueva = db->cap ? db->cap * 2 : 4;
        db_reservar(db, nueva);
    }
    db->items[db->size++] = e;
}

static void db_eliminar(DB *db, size_t idx) {
    if (idx >= db->size || !db->items[idx]) return;
    db->items[idx]->meta.borrado = 1;
    free(db->items[idx]->nombre);   db->items[idx]->nombre = NULL;
    free(db->items[idx]->apellido); db->items[idx]->apellido = NULL;
    free(db->items[idx]->notas);    db->items[idx]->notas = NULL;
}

static void db_compactar(DB *db) {
    size_t w = 0;
    for (size_t r = 0; r < db->size; ++r) {
        Estudiante *e = db->items[r];
        if (e && e->meta.borrado == 0) {
            db->items[w++] = e;
        } else if (e && e->meta.borrado == 1) {
            liberar_estudiante(e);
        }
    }
    db->size = w;
    if (db->cap > 0 && db->size * 2 < db->cap) {
        size_t nueva_cap = db->cap / 2;
        Estudiante **nuevo = (Estudiante**)realloc(db->items, nueva_cap * sizeof(Estudiante*));
        if (nuevo) {
            db->items = nuevo;
            db->cap = nueva_cap;
        }
    }
}

static void db_destruir(DB *db) {
    for (size_t i = 0; i < db->size; ++i) liberar_estudiante(db->items[i]);
    free(db->items);
    db->items = NULL;
    db->size = db->cap = 0;
}

static void imprimir(const DB *db) {
    puts("=== Registros ===");
    for (size_t i = 0; i < db->size; ++i) {
        const Estudiante *e = db->items[i];
        if (!e) continue;
        printf("[%zu] %s %s | id=%u | edad=%u | notas=",
            i,
            e->nombre ? e->nombre : "(liberada)",
            e->apellido ? e->apellido : "(liberada)",
            e->meta.identificacion,
            e->meta.edad
        );
        for (size_t k = 0; k < e->n_notas; ++k) {
            printf("%s%.2f", (k?", ":""), e->notas[k]);
        }
        puts("");
    }
}

int main(void) {
    DB db; db_init(&db);

    float notas1[] = {4.5f, 4.0f};
    float notas2[] = {3.7f, 4.8f, 4.9f};
    float notas3[] = {5.0f};

    db_agregar(&db, crear_estudiante("Ana",   "Rojas", 1001, 20, notas1, 2));
    db_agregar(&db, crear_estudiante("Luis",  "Gomez", 1002, 22, notas2, 3));
    db_agregar(&db, crear_estudiante("Lucia", "Diaz",  1003, 19, notas3, 1));

    imprimir(&db);

    puts("\n-- Eliminando indice 1 (Luis) y compactando --");
    db_eliminar(&db, 1);
    db_compactar(&db);
    imprimir(&db);

    db_destruir(&db);
    return 0;
}
