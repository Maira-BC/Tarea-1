#include <locale.h>
#include "tarea1_mairab_anaist.h"

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    vector<Ejercicio*> listaEjercicios;
    Rutina rutina;
    int opcion;

    do {
        cout << "\n======= Menú =======\n";
        cout << "1. Crear ejercicio\n";
        cout << "2. Mostrar ejercicios\n";
        cout << "3. Generar rutina\n";
        cout << "4. Actualizar ejercicio\n";
        cout << "5. Eliminar ejercicio\n";
        cout << "6. Buscar por intensidad\n";
        cout << "7. Salir\n";
        cin >> opcion;

        if(opcion == 1) {
            int codigo, tiempo, semana, tipo;
            string nombre, intensidad, descripcion;

            cout << "Código: "; cin >> codigo;
            cout << "Nombre: "; cin >> nombre;
            cout << "Intensidad: "; cin >> intensidad;
            cout << "Tiempo: "; cin >> tiempo;
            cout << "Descripción: "; cin >> descripcion;
            cout << "Semana: "; cin >> semana;
            cout << "Tipo (1 = Cardio, 2 = Fuerza): "; cin >> tipo;

            if(tipo==1) {
                listaEjercicios.push_back(new Cardio(codigo, nombre, intensidad, tiempo, descripcion, semana));
            }
            else {
                listaEjercicios.push_back(new Fuerza(codigo, nombre, intensidad, tiempo, descripcion, semana));
            }
        }

        else if(opcion == 2) {
            for(int i = 0; i < listaEjercicios.size(); i++) {
                listaEjercicios[i]->mostrar();
            }
        }

        else if(opcion == 3) {

            rutina = Rutina(); // Reiniciar rutina
            int cantidad;
            string intensidadDeseada;

            cout << "Cantidad de ejercicios: "; cin >> cantidad;
            cout << "Intensidad deseada: "; cin >> intensidadDeseada;

            int contador = 0;

            for(int i = 0; i < listaEjercicios.size() && contador < cantidad; i++) {
                if(listaEjercicios[i]->getIntensidad() == intensidadDeseada) {
                    rutina.agregarEjercicio(listaEjercicios[i]);
                    contador++;
                }
            }

            rutina.mostrarRutina();
            cout << "Tiempo total: " << rutina.calcularTiempoTotal() << " minutos.\n";
        }

        else if(opcion == 4) {
            int codigoBuscar;
            cout << "Ingrese código del ejercicio a actualizar: "; cin >> codigoBuscar;

            bool encontrado = false;

            for(int i = 0; i < listaEjercicios.size(); i++) {
                if(listaEjercicios[i]->getCodigo() == codigoBuscar) {
                    string nombre, intensidad, descripcion;
                    int tiempo;

                    cout << "Nuevo nombre: "; cin >> nombre;
                    cout << "Nueva intensidad: "; cin >> intensidad;
                    cout << "Nuevo tiempo: "; cin >> tiempo;
                    cout << "Nueva descripción: "; cin >> descripcion;

                    listaEjercicios[i]->actualizar(nombre, intensidad, tiempo, descripcion);
                    encontrado = true;
                    break;
                }
            }

            if(!encontrado) {
                cout << "No se encontró el ejercicio.\n";
            }
        }

        else if(opcion == 5) {
            int codigoEliminar;
            cout << "Ingrese código a eliminar: "; cin >> codigoEliminar;

            bool eliminado = false;

            for(int i = 0; i < listaEjercicios.size(); i++) {
                if(listaEjercicios[i]->getCodigo() == codigoEliminar) {
                    listaEjercicios.erase(listaEjercicios.begin() + i);
                    cout << "Ejercicio eliminado.\n";
                    break;
                }
            }

            if(!eliminado) {
                cout << "No se encontró el ejercicio.\n";
            }
        }

        else if(opcion == 6) {
            string intensidadBuscar;
            cout << "Ingrese intensidad: "; cin >> intensidadBuscar;

            bool encontrado = false;

            for(int i = 0; i < listaEjercicios.size(); i++) {
                if(listaEjercicios[i]->getIntensidad() == intensidadBuscar) {
                    listaEjercicios[i]->mostrar();
                }
            }

            if(!encontrado) {
                cout << "No se encontraron ejercicios con esa intensidad.\n";
            }
        }
    }

    while(opcion != 7);
    return 0;
}