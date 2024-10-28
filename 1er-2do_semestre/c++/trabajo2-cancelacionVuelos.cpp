/*La empresa de aviacion PAJAROS VOLADORES posee 3 aviones con
capacidad de 100 pasajeros cada uno.
La empresa tiene asignadas 3 rutas, las cuales vuelan una vez al dia entre:

TIA 1. Practica: construccion de algoritmos basicos en C++

Codigo: GDO- FR-131
Version: 003
Pagina: 4 de 8

- Medellin - Apartado, ruta 1
- Medellin - Caucasia, ruta 2
- Medellin - Quibdo, ruta 3
La empresa tiene como politica cancelar el vuelo cuando:
a. El numero de pasajeros reservados sea inferior al 20% del cupo del avion.
b. Cuando el numero de reservaciones para este es menor que el excedente del
cupo normal para otra ruta, en este caso se haran los dos vuelos para una
misma ruta.
Elaborar un algoritmo que calcule:
- Numero de pasajeros por vuelo.
- Rutas a las cuales se cumplio el vuelo.
- Numero de vuelos cancelados.
- En caso de cancelar vuelos que rutas fueron.
Por cada reservacion se tiene un registro con el numero de la ruta (1, 2 o 3).*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

const int CAPACIDAD_AVION = 100;
const int MIN_PASAJEROS = CAPACIDAD_AVION * 0.20; 

int pasajerosRuta1, pasajerosRuta2, pasajerosRuta3; 
int ruta1Excedente, ruta2Excedente, ruta3Excedente;
int vuelosCancelados = 0;
bool ruta1Cancelada = false, ruta2Cancelada = false, ruta3Cancelada = false;

int excedente(int pasajeros){
    if (pasajeros > CAPACIDAD_AVION){
        return pasajeros - CAPACIDAD_AVION;
    }
    return 0;
}

bool rutaCancelada(int numRuta, int pasajeros, int pasajerosOtroVuelo, string ruta) {
    int excedenteOtroVuelo, otraRuta;
    excedenteOtroVuelo = excedente(pasajerosOtroVuelo);
    if (pasajeros < MIN_PASAJEROS){
        cout<<"Ruta "<<numRuta<<"("<<ruta<<")"<<" cancelada por falta de pasajeros ("<<pasajeros<<")"<<endl;
        return true;
    }
    else if ((excedenteOtroVuelo > 0) && (pasajeros < excedenteOtroVuelo)) {
        cout<<"Ruta "<<numRuta<<"("<<ruta<<")"<<" cancelada, sera redirigida por ser menor al excedente de otra ruta "<<endl;
        return true;
    }
    if (pasajeros>CAPACIDAD_AVION){
        otraRuta = excedente(pasajeros);
        cout<<"Ruta "<<numRuta<<"("<<ruta<<")"<<" se cumplio con exito en dos rutas, pasajeros ("<<CAPACIDAD_AVION<<")"<<"("<<otraRuta<<")"<<endl;
        return false;    
    }
    cout<<"Ruta "<<numRuta<<"("<<ruta<<")"<<" se cumplio con exito ("<<pasajeros<<" pasajeros)"<<endl;
    return false;
}

int main() {
        
    string continuarStr = "";

    while (true){
 
        cout<<"Ingrese el numero de pasajeros para la ruta 1 (Medellin-Apartado): ";
        cin>>pasajerosRuta1;

        cout<<"Ingrese el numero de pasajeros para la ruta 2 (Medellin-Caucasia): ";
        cin>>pasajerosRuta2;

        cout<<"Ingrese el numero de pasajeros para la ruta 3 (Medellin-Quibdo): ";
        cin>>pasajerosRuta3;

        cout<<"---------------"<<endl<<"Resultados: "<<endl;
        ruta1Cancelada = rutaCancelada(1, pasajerosRuta1, max(pasajerosRuta2, pasajerosRuta3), "Medellin-Apartado");
        ruta2Cancelada = rutaCancelada(2, pasajerosRuta2, max(pasajerosRuta1, pasajerosRuta3), "Medellin-Caucasia");
        ruta3Cancelada = rutaCancelada(3, pasajerosRuta3, max(pasajerosRuta1, pasajerosRuta2), "Medellin-Quibdo");

        if (ruta1Cancelada) vuelosCancelados++;
        if (ruta2Cancelada) vuelosCancelados++;
        if (ruta3Cancelada) vuelosCancelados++;

        cout<<"Numero de vuelos cancelados: "<<vuelosCancelados<<endl;
        cout<<"---------------"<<endl;
        
        cout<<"Desea continuar? (y/n) ";
        cin>>continuarStr;
        transform(continuarStr.begin(), continuarStr.end(), continuarStr.begin(), ::tolower);

        if (continuarStr=="y"){
            vuelosCancelados = 0;
            continue;
        }
        else if (continuarStr=="n"){
            break;
        }

        return 0;
    }
}