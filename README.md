# Parcial Final Programacion - Universidad

## Objetivo
Este parcial busca aplicar distintos paradigmas de programacion y optimizacion de memoria en el desarrollo de programas que resuelvan problemas de gestion de estudiantes y operaciones basicas sobre listas.

## Tecnologias utilizadas
- Haskell (programacion declarativa/funcional)
- Python (programacion imperativa)
- C (gestiona memoria dinamicamente con malloc y free)

## Procedimiento
1. **Punto 1:** Se implemento un algoritmo de ordenamiento de estudiantes por nota descendente y por nombre ascendente en caso de empate. Se realizo en dos enfoques:
   - Declarativo en Haskell (OrdenEstudiantesDeclarativo.hs)
   - Imperativo en Python (ordenar_estudiantes_imperativo.py)

2. **Punto 2:** Se implemento en C un sistema de gestion de estudiantes con estructuras optimizadas, uso de bitfields, cadenas dinamicas y arrays dinamicos para notas. Incluye un mecanismo de compactacion de memoria para evitar desperdicio. (estudiantes_memoria.c)

3. **Punto 3:** Se expreso en notacion de calculo lambda la forma de calcular el promedio de una lista de n elementos. (PromedioLambda.hs)

## Ejecucion de los programas

### Haskell
Compilar y ejecutar con:
```bash
ghc OrdenEstudiantesDeclarativo.hs -o orden_declarativo
./orden_declarativo
```

Para el calculo lambda no es necesario compilar, el archivo PromedioLambda.hs contiene la expresion en notacion lambda.

### Python
Ejecutar con:
```bash
python ordenar_estudiantes_imperativo.py
```

### C
Compilar y ejecutar con:
```bash
gcc -O2 -std=c11 estudiantes_memoria.c -o estudiantes_memoria
./estudiantes_memoria
```

## Como subir a GitHub

1. Crear un repositorio en GitHub desde la pagina web (ejemplo: `parcial-final`).
2. En tu computador, abrir la terminal y clonar el repositorio:
   ```bash
   git clone https://github.com/tuusuario/parcial-final.git
   cd parcial-final
   ```
3. Copiar dentro de esta carpeta los archivos:
   - OrdenEstudiantesDeclarativo.hs
   - ordenar_estudiantes_imperativo.py
   - estudiantes_memoria.c
   - PromedioLambda.hs
   - README.md
4. Agregar los archivos al control de versiones:
   ```bash
   git add .
   git commit -m "Entrega final del parcial de programacion"
   ```
5. Subir al repositorio remoto en GitHub:
   ```bash
   git push origin main
   ```

Una vez hecho esto, el profesor podra ver el repositorio y ejecutar cada uno de los codigos segun las instrucciones.
