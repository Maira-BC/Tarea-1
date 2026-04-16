#include "tarea1_mairab_anaist.h"

// Ejercicio base
Ejercicio::Ejercicio(int codigo, string nombre, string tipo, string intensidad, int tiempo, string descripcion, int semana) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->tipo = tipo;
    this->intensidad = intensidad;
    this->tiempo = tiempo;
    this->descripcion = descripcion;
    this->ultimaSemana = semana;
}

Ejercicio::~Ejercicio() {}

void Ejercicio::mostrar() {
    cout << "Código: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Intensidad: " << intensidad << endl;
    cout << "Tiempo: " << tiempo << " minutos." << endl;
    cout << "Descripción: " << descripcion << endl;
}

string Ejercicio::getIntensidad() {
    return intensidad;
}

int Ejercicio::getTiempo() {
    return tiempo;
}

int Ejercicio::getCodigo() {
    return codigo;
}

// Actualizar ejercicio
void Ejercicio::actualizar(string nombre, string intensidad, int tiempo, string descripcion) {
    this->nombre = nombre;
    this->intensidad = intensidad;
    this->tiempo = tiempo;
    this->descripcion = descripcion;
}

// Cardio
Cardio::Cardio(int codigo, string nombre, string intensidad, int tiempo, string descripcion, int semana)
: Ejercicio(codigo, nombre, "Cardio", intensidad, tiempo, descripcion, semana) {}

void Cardio::mostrar() {
    cout << "[Cardio]" << endl;
    Ejercicio::mostrar();
}

// Fuerza
Fuerza::Fuerza(int codigo, string nombre, string intensidad, int tiempo, string descripcion, int semana)
: Ejercicio(codigo, nombre, "Fuerza", intensidad, tiempo, descripcion, semana) {}

void Fuerza::mostrar() {
    cout << "[Fuerza]" << endl;
    Ejercicio::mostrar();
}

// Rutina
void Rutina::agregarEjercicio(Ejercicio* e) {
    ejercicios.push_back(e);
}

void Rutina::mostrarRutina() {
    for(int i = 0; i < ejercicios.size(); i++) {
        ejercicios[i]->mostrar();
    }
}

int Rutina::calcularTiempoTotal() {
    int total = 0;
    for(int i = 0; i < ejercicios.size(); i++) {
        total += ejercicios[i]->getTiempo();
    }

    return total;
}