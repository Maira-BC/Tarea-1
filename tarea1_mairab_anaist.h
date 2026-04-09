#ifndef ejercicio_h
#define ejercicio_h
#include <iostream>
#include <vector>
using namespace std;

class Ejercicio {
-protected:
    int codigo;
    string nombre;
    string tipo;
    string intensidad;
    int tiempo;
    string descripcion;
    int ultimaSemana;


public:
    Ejercicio(int codigo, string nombre, string tipo, string intensidad, int tiempo, string descripcion, int semana);
    virtual ~Ejercicio();

    virtual void mostrar();
    string getIntensidad();
    int getTiempo();
};

class Cardio : public Ejercicio {
public: 
    Cardio(int codigo, string nombre, string intensidad, int tiempo, string descripcion, int semana);
    void mostrar;
};

class Fuerza : public Ejercicio {
public:
    Fuerza(int codigo, string nombre, string intensidad, int tiempo, string descripcion, int semana);
    void mostrar();
};

class Rutina {
private:
    vector<Ejercicio*> ejercicios;

public:
    void agregarEjercicio(Ejercicio* e);
    void mostrarRutina();
    int calcularTiempoTotal();
};

#endif