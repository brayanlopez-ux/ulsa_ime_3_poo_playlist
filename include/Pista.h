// Interfaz de la clase Pista (clase base).
// Datos comunes a cualquier cosa que se pueda reproducir.
// Relación: una Pista TIENE una Duracion (composición).

#ifndef PISTA_H
#define PISTA_H

#include <string>
#include "Duracion.h"

class Pista {
private:
    std::string titulo;
    Duracion duracion;

public:
    Pista(const std::string& titulo, int min, int seg);

    std::string getTitulo() const;
    Duracion getDuracion() const;

    void setTitulo(const std::string& nuevoTitulo);

    void mostrarInfo() const;
};

#endif
