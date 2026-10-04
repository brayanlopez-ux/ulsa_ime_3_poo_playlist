// Implementación de la clase Playlist.

#include "Playlist.h"

#include <iostream>

// TODO 4.1: implementa el constructor de Playlist.
Playlist::Playlist(const std::string& nombre) : nombre(nombre) {}

// TODO 4.2: implementa  bool Playlist::agregarCancion(Cancion* cancion)
//   Devuelve false si el puntero es nullptr o si la canción ya está en la
//   playlist; en otro caso la agrega y devuelve true.
bool Playlist::agregarCancion(Cancion* cancion) {
    if (cancion == nullptr) {
        return false;
    }
    
    // Iterar para evitar duplicados comparando las direcciones de memoria
    for (Cancion* c : canciones) {
        if (c == cancion) {
            return false;
        }
    }
    
    canciones.push_back(cancion);
    return true;
}

// TODO 4.3: implementa  bool Playlist::agregarPodcast(Podcast* podcast)
//   Mismas reglas que agregarCancion.
bool Playlist::agregarPodcast(Podcast* podcast) {
    if (podcast == nullptr) {
        return false;
    }
    
    for (Podcast* p : podcasts) {
        if (p == podcast) {
            return false;
        }
    }
    
    podcasts.push_back(podcast);
    return true;
}

// TODO 4.4: implementa  int Playlist::cantidadPistas() const
int Playlist::cantidadPistas() const {
    return canciones.size() + podcasts.size();
}

// TODO 4.5: implementa  Duracion Playlist::duracionTotal() const
//   Suma los segundos de todas las pistas y devuelve una Duracion.
Duracion Playlist::duracionTotal() const {
    int totalSegundos = 0;
    
    for (Cancion* c : canciones) {
        totalSegundos += c->getDuracion().totalSegundos();
    }
    
    for (Podcast* p : podcasts) {
        totalSegundos += p->getDuracion().totalSegundos();
    }
    
    // Al pasar todos los segundos al constructor de Duracion,
    // este automáticamente calculará y normalizará los minutos y segundos.
    return Duracion(0, totalSegundos);
}

// TODO 4.6: implementa  void Playlist::mostrar() const
//   Imprime el nombre, cada pista, la cantidad de pistas y la duración total.
void Playlist::mostrar() const {
    std::cout << "\n=== Playlist: " << nombre << " ===\n";
    std::cout << "Cantidad de pistas: " << cantidadPistas() << " | Duración total: ";
    duracionTotal().imprimir();
    std::cout << "\n-------------------------------------\n";
    
    for (Cancion* c : canciones) {
        c->mostrar();
    }
    
    for (Podcast* p : podcasts) {
        p->mostrar();
    }
}