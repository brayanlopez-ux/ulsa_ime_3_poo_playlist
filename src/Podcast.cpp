// Implementación de la clase Podcast.

#include "Podcast.h"

#include <iostream>

// TODO 3.2: implementa el constructor, los accedentes y mostrar() de Podcast.

// Constructor: llama al constructor de Pista desde la lista de inicialización
Podcast::Podcast(const std::string& titulo, int min, int seg, const std::string& anfitrion, int numeroEpisodio)
    : Pista(titulo, min, seg), anfitrion(anfitrion), numeroEpisodio(numeroEpisodio) {}

// Accedentes
std::string Podcast::getAnfitrion() const {
    return anfitrion;
}

int Podcast::getNumeroEpisodio() const {
    return numeroEpisodio;
}

// Método mostrar: llama a mostrarInfo() de la clase base y agrega anfitrión y episodio
void Podcast::mostrar() const {
    mostrarInfo(); // Imprime el título y la duración
    std::cout << " - " << anfitrion << " (Ep. " << numeroEpisodio << ")\n";
}