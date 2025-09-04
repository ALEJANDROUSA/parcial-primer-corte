# Parcial Final Programacion - Alejandro Poveda Sandoval

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

## Conclusiones
- El ejercicio permitio contrastar los paradigmas de programacion declarativo y imperativo, mostrando como en el primero se describe que se quiere lograr mientras que en el segundo se detallan los pasos para conseguirlo.
- La implementacion en C evidencio la importancia de la gestion manual de memoria y como se pueden optimizar estructuras mediante tecnicas como bitfields, arrays dinamicos y compactacion.
- El uso de notacion de calculo lambda mostro la base teorica de la programacion funcional, reforzando la comprension de la abstraccion y composicion de funciones.
- En general, el parcial integro distintos enfoques de programacion que permiten desarrollar una vision mas amplia de las herramientas disponibles para resolver problemas computacionales de manera eficiente y segura.
