// Interfaz de la clase Duracion.
// Guarda un tiempo en minutos y segundos, siempre en un estado válido.

#ifndef DURACION_H
#define DURACION_H

class Duracion {
private:
    int minutos;
    int segundos;

public:
    Duracion(int min, int seg);

    int getMinutos() const;
    int getSegundos() const;

    int totalSegundos() const;

    void imprimir() const;
};

#endif
