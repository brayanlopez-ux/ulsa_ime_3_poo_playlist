// Implementación de la clase Duracion.

#include "Duracion.h"

#include <iostream>
#include <iomanip> // Necesario para std::setfill y std::setw

Duracion::Duracion(int min, int seg) : minutos(min), segundos(seg) {
    // TODO 1.1: valida y normaliza.
    if (minutos < 0 || segundos < 0) {
        minutos = 0;
        segundos = 0;
    } else {
        // Si seg es mayor a 59, convierte el excedente en minutos
        minutos += segundos / 60;
        segundos = segundos % 60;
    }
    
    // Pregunta: ¿por qué conviene validar aquí y no en main?
    // Respuesta (para tu bitácora): Validar en el constructor garantiza el principio
    // de encapsulamiento. La clase es la única responsable de asegurar que sus datos 
    // siempre estén en un estado válido desde que el objeto nace. Si lo validas en el main, 
    // cualquier otra parte del programa u otro programador podría olvidar hacer la 
    // validación antes de crear el objeto, generando errores difíciles de rastrear.
}

int Duracion::getMinutos() const { return minutos; }

int Duracion::getSegundos() const { return segundos; }

// TODO 1.2: implementa  int Duracion::totalSegundos() const
//   Devuelve la duración completa expresada en segundos.
int Duracion::totalSegundos() const {
    return (minutos * 60) + segundos;
}

// TODO 1.3: implementa  void Duracion::imprimir() const
//   Imprime con el formato m:ss (por ejemplo 3:05, no 3:5).
void Duracion::imprimir() const {
    std::cout << minutos << ":" << std::setfill('0') << std::setw(2) << segundos;
}