# Práctica 1: Playlist de música

Programación Orientada a Objetos · Ingeniería Mecatrónica · Tercer semestre

Llena cada espacio conforme avances en las fases de [PRACTICA.md](PRACTICA.md).

## Fase 1. Entender el problema

**1.1 El problema con mis propias palabras**
El objetivo es modelar un sistema de biblioteca musical que organice canciones y podcasts en diferentes listas de reproducción (playlists). El sistema debe ser capaz de calcular la duración total de la playlist y requiere aplicar correctamente los conceptos de herencia, composición y agregación en C++ para gestionar la memoria y las relaciones entre los objetos.

[Inserta aquí tu respuesta]

**1.2 Sustantivos (posibles clases) y verbos (posibles métodos)**

Sustantivos: ___cancion,duracion,pista,playlist,podcast__

Verbos: __Organizar, agrupar, agregar, calcular, mostrar, imprimir, validar ___

**1.3 Relaciones** (completa con "es un", "tiene un" o "usa un")

*   Una canción ___es una__ pista.
*   Un podcast __es una___ pista.
*   Una pista ___tiene una__ duración.
*   Una playlist __usa una ___ canción.

## Fase 2. Diseñar la solución

**2.1 Diagrama de clases**

![Diagrama de clases](diseno_solucion.png)

**2.2 Justificación de cada relación**

| Relación | Tipo | ¿Por qué? |
| --- | --- | --- |
| Cancion - Pista | ___herencia__ | ___Una canción es un tipo específico de pista, por lo que hereda sus atributos (como el título) y métodos base.__ |
| Podcast - Pista | __herencia ___ | __Un podcast es un tipo específico de pista y comparte el comportamiento fundamental definido en la clase padre. ___ |
| Pista - Duracion | __composision ___ | ___La pista crea y es dueña de su duración; si el objeto contenedor de la pista desaparece, la duración debe desaparecer también.__ |
| Playlist - Cancion | __agregacion ___ | __La playlist agrupa canciones mediante punteros sin ser su dueña; si la lista se destruye, las canciones siguen existiendo de forma independiente. ___ |
| Playlist - Podcast | __agregacion ___ | __Al igual que con las canciones, la playlist solo hace referencia a podcasts ya existentes en el sistema. ___ |

## Fase 3. Implementar

**3.1 Bitácora de dudas**

| # | Duda | Cómo la resolví | Fuente |
| --- | --- | --- | --- |
| 1 | ¿Cómo inicializar el atributo duracion desde el constructor de Pista? | Utilizando la lista de inicialización (`: duracion(min, seg)`) en la definición del constructor. | Apuntes de clase / Documentación C++. |
| 2 | ¿Por qué conviene validar el tiempo en el constructor de `Duracion` y no en el `main`? | Para garantizar el encapsulamiento. La clase es la única responsable de asegurar que sus datos siempre tengan un estado válido desde que nace el objeto. | Análisis del código. |
| 3 | ¿Qué pasaría si se quita `duracion(min, seg)` de la lista de inicialización en `Pista`? | El compilador arroja un error porque intentaría llamar a un constructor por defecto (sin parámetros) para `Duracion`, el cual no existe. | Prueba en el compilador (error). |

**3.2 Experimentos guiados**

**3.2 Experimentos guiados**

Experimento 1, orden de construcción y destrucción: Primero se inicializa la clase base (`Pista`) junto con sus componentes (`Duracion`), y al final se construye la clase derivada (`Cancion` o `Podcast`). La destrucción de los objetos ocurre en el orden exactamente inverso.

Experimento 2, ¿quién es dueño de quién?: La clase `Pista` es dueña absoluta de `Duracion` (Composición: si la pista se elimina, su duración también). Sin embargo, `Playlist` NO es dueña de las pistas (Agregación: solo almacena punteros, por lo que las canciones siguen existiendo aunque la playlist se destruya).

Experimento 3, un objeto en dos playlists: Al modificar el título de una canción que está en dos listas distintas, el cambio se refleja automáticamente en ambas. Esto se debe a que las playlists no guardan copias de la canción, sino punteros que apuntan a la misma instancia en la memoria.

## Fase 4. Probar y mejorar

**4.1 Tabla de pruebas**

| # | Caso | Resultado esperado | Resultado obtenido | ¿Pasa? |
|---|---|---|---|---|
| 1 | Duración normal | `Duracion(3, 45)` | 3:45 | **3:45 (Éxito)** |
| 2 | Segundos mayores a 59 | `Duracion(0, 75)` | 1:15 | **1:15 (Éxito)** |
| 3 | Valores negativos | `Duracion(-2, 10)` | 0:00 | **0:00 (Éxito)** |
| 4 | Título vacío | Canción con título `""` | "Sin título" | **"Sin título" (Éxito)** |
| 5 | Playlist vacía | `duracionTotal()` y `cantidadPistas()` | 0:00 y 0 pistas | **0:00 y 0 pistas (Éxito)** |
| 6 | Canción duplicada | Agregar dos veces la misma canción | La segunda vez devuelve `false` | **Devuelve `false` (Éxito)** |
| 7 | Puntero nulo | `agregarCancion(nullptr)` | Devuelve `false` | **Devuelve `false` (Éxito)** |
| 8 | Total mixto | 2 canciones y 1 podcast | Suma correcta en m:ss | **141:34 (Éxito)** |
**4.2 Bitácora de mejoras**

| # | Falla o mejora detectada | Qué cambié | Por qué |
| --- | --- | --- | --- |
| 1 | Caída por punteros nulos. | Validé `if (puntero == nullptr)` al agregar. | Evitar que el programa falle. |
| 2 | Pistas duplicadas. | Ciclo `for` para comparar memoria. | Evitar repetir la misma pista. |
| 3 | Tiempos inválidos. | Normalización en constructor `Duracion`. | Garantizar datos válidos siempre. |
Retos opcionales que intenté: _____

## Fase 5. Publicar en GitHub

**5.1 Enlace a mi fork**

[Inserta aquí el enlace a tu fork]

## Cierre y reflexión

**6.1 ¿Qué aprendiste en esta práctica?**

[Inserta aquí tu respuesta]

**6.2 ¿Qué cambiarías de tu proceso la próxima vez?**

[Inserta aquí tu respuesta]