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
c:\Users\braya\Downloads\diseno_solucion.drawio.png

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
| 1 | __¿Cómo inicializar el atributo duracion desde el constructor de Pista? ___ | __Utilizando la lista de inicialización (: duracion(min, seg)) en la definición del constructor. ___ | ___Apuntes de clase / Documentación C++.__ |
| 2 | _____ | _____ | _____ |
| 3 | _____ | _____ | _____ |

**3.2 Experimentos guiados**

Experimento 1, orden de construcción y destrucción: _____

Experimento 2, ¿quién es dueño de quién?: _____

Experimento 3, un objeto en dos playlists: _____

## Fase 4. Probar y mejorar

**4.1 Tabla de pruebas**

| # | Caso | Resultado esperado | Resultado obtenido | ¿Pasa? |
| --- | --- | --- | --- | --- |
| 1 | Duración normal `Duracion(3, 45)` | 3:45 | _____ | _____ |
| 2 | Segundos mayores a 59 `Duracion(0, 75)` | 1:15 | _____ | _____ |
| 3 | Valores negativos `Duracion(-2, 10)` | 0:00 | _____ | _____ |
| 4 | Título vacío | "Sin título" | _____ | _____ |
| 5 | Playlist vacía | 0:00 y 0 pistas | _____ | _____ |
| 6 | Canción duplicada | La segunda vez devuelve `false` | _____ | _____ |
| 7 | Puntero nulo | Devuelve `false` | _____ | _____ |
| 8 | Total con 2 canciones y 1 podcast | Suma correcta en m:ss | _____ | _____ |

**4.2 Bitácora de mejoras**

| # | Falla o mejora detectada | Qué cambié | Por qué |
| --- | --- | --- | --- |
| 1 | _____ | _____ | _____ |
| 2 | _____ | _____ | _____ |

Retos opcionales que intenté: _____

## Fase 5. Publicar en GitHub

**5.1 Enlace a mi fork**

[Inserta aquí el enlace a tu fork]

## Cierre y reflexión

**6.1 ¿Qué aprendiste en esta práctica?**

[Inserta aquí tu respuesta]

**6.2 ¿Qué cambiarías de tu proceso la próxima vez?**

[Inserta aquí tu respuesta]