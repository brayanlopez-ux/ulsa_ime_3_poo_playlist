// Práctica 1: Playlist de música
// Programación Orientada a Objetos - Ingeniería Mecatrónica, 3er semestre
//
// Compilar (desde la raíz del repositorio):
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/*.cpp -o playlist
// Ejecutar:
//   ./playlist

#include <iostream>

#include "Playlist.h"
#include "Cancion.h"
#include "Podcast.h"
#include "Duracion.h"

int main() {
    std::cout << "Practica 1: Playlist de musica\n\n";

    // TODO 5.1: crea la biblioteca: al menos tres canciones y un podcast.
    Cancion c1("Bohemian Rhapsody", 5, 55, "Queen", "Rock");
    Cancion c2("Billie Jean", 4, 54, "Michael Jackson", "Pop");
    Cancion c3("Hotel California", 6, 30, "Eagles", "Rock");
    Podcast p1("Lex Fridman Podcast", 130, 45, "Lex Fridman", 300);

    // TODO 5.2: crea dos playlists y agrega pistas a cada una.
    //   Al menos una canción debe estar en las dos playlists.
    Playlist lista1("Mis Favoritas");
    Playlist lista2("Clásicos del Rock");

    lista1.agregarCancion(&c1);
    lista1.agregarCancion(&c2);
    lista1.agregarPodcast(&p1);

    // c1 se agrega a ambas listas
    lista2.agregarCancion(&c1);
    lista2.agregarCancion(&c3);

    // TODO 5.3: muestra ambas playlists.
    std::cout << "=== MOSTRANDO PLAYLISTS ORIGINALES ===\n";
    lista1.mostrar();
    lista2.mostrar();

    // TODO 5.4: experimentos guiados de la Fase 3.
    std::cout << "\n=== EXPERIMENTO 3: Un objeto, dos playlists ===\n";
    std::cout << "Cambiando el titulo de 'Bohemian Rhapsody' a 'Bohemian Rhapsody (Remastered)'...\n";
    c1.setTitulo("Bohemian Rhapsody (Remastered)");
    
    std::cout << "Imprimiendo de nuevo para comprobar que se actualizo en ambas listas (Agregacion):\n";
    lista1.mostrar();
    lista2.mostrar();

    // TODO 5.5: casos de prueba de la Fase 4.
    std::cout << "\n=== CASOS DE PRUEBA FASE 4 ===\n";
    
    // Caso 1: Duración normal
    std::cout << "Caso 1 (Normal 3:45): ";
    Duracion(3, 45).imprimir();
    std::cout << "\n";

    // Caso 2: Segundos mayores a 59
    std::cout << "Caso 2 (Segundos > 59 -> 0:75 debe ser 1:15): ";
    Duracion(0, 75).imprimir();
    std::cout << "\n";

    // Caso 3: Valores negativos
    std::cout << "Caso 3 (Negativos -> -2:10 debe ser 0:00): ";
    Duracion(-2, 10).imprimir();
    std::cout << "\n";

    // Caso 4: Título vacío
    Cancion cVacia("", 3, 15, "Artista Desconocido", "Indie");
    std::cout << "Caso 4 (Titulo vacio): " << cVacia.getTitulo() << "\n";

    // Caso 5: Playlist vacía
    Playlist listaVacia("Lista Vacia");
    std::cout << "Caso 5 (Playlist vacia): Pistas = " << listaVacia.cantidadPistas() << " | Duracion = ";
    listaVacia.duracionTotal().imprimir();
    std::cout << "\n";

    // Caso 6: Canción duplicada
    bool agregadoDuplicado = lista1.agregarCancion(&c2);
    std::cout << "Caso 6 (Cancion duplicada): " << (agregadoDuplicado ? "true" : "false") << " (Esperado: false)\n";

    // Caso 7: Puntero nulo
    bool agregadoNulo = lista1.agregarCancion(nullptr);
    std::cout << "Caso 7 (Puntero nulo): " << (agregadoNulo ? "true" : "false") << " (Esperado: false)\n";

    // Caso 8: Total con 2 canciones y 1 podcast (Comprobable al ver la impresión de 'lista1')
    std::cout << "Caso 8: Comprobable en la impresion de 'Mis Favoritas' arriba.\n";

    return 0;
}
