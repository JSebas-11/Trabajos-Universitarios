/*Una oficina de seguros ha reunido datos concernientes a todos los accidentes de tránsito en el área metropolitana de Medellín en el último año. 
Por cada conductor involucrado en un accidente se toman los siguientes datos: año de nacimiento, sexo (1: Femenino, 2: Masculino), 
registro del carro (1: Medellín, 2: Otras ciudades) y nombre del conductor. 
Hacer un algoritmo que muestre:
    • El porcentaje de conductores menores de 25 años.
    • Porcentaje de conductores del sexo femenino.
    • Porcentaje de conductores masculinos con edades entre 16 y 30 años.
    • Porcentaje de conductores cuyos carros están registrados fuera de Medellín.
    • Nombre del conductor con mayor edad y el de menor edad involucrados en un accidente.
*/

#include <iostream>
#include <string>
#include <limits>
#include <locale>
#include <windows.h>

using namespace std;

int pedirNumAccidentes(){
    
    int numero;

    while (true){
        cout<<"Ingresa el número de accidentes a registrar => ";
        cin>>numero;
        
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"*Dato no valido*\n";
            continue;
        }
        if (numero < 1){
            cout<<"*El número no puede ser menor a 1*\n";
            continue;
        }
        return numero;
    }
};

int pedirAño(){

    int añoNacimiento;

    while (true){
        cout<<"Ingresa tu año de nacimiento => ";
        cin>>añoNacimiento;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"*Dato no valido*\n";
            continue;
        }
        if (!(añoNacimiento >= 1924 && añoNacimiento <= 2008)){
            cout<<"*Edad fuera de rango*\n";
            continue;
        }
        return añoNacimiento;
    }
};

string pedirSexo(){

    int sexo;
    
    while (true){
        cout<<"Selecciona el sexo con el que te identificas\n\t1.Masculino.\n\t2.Femenino.\n";
        cin>>sexo;
        
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"*Dato no valido*\n";
            continue;
        }
        if (!(sexo == 1 or sexo == 2)){
            cout<<"*Ingresa un número correcto*\n";
            continue;
        }
        else {
            if (sexo == 1){
                return "Masculino";
            }
            else{
                return "Femenino";
            }
        }
    }
};

string pedirRegistro(){

    int registro;
    
    while (true){
        cout<<"Selecciona a donde pertenece el registro de tu vehículo\n\t1.Medellín.\n\t2.Otras ciudadades.\n";
        cin>>registro;
        
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"*Dato no valido*\n";
            continue;
        }
        if (!(registro == 1 or registro == 2)){
            cout<<"*Ingresa un número correcto*\n";
            continue;
        }
        else {
            if (registro == 1){
                return "Medellín";
            }
            else{
                return "Otras ciudades";
            }
        }
    }
    
};

string pedirNomConductor(){
    
    string nombre;

    while (true){
        cout<<"Ingresa tu Nombre => ";
        cin.ignore();
        getline(cin, nombre);
        
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"*Dato no valido*\n";
            continue;
        }
        return nombre;
    }
};

void pedirMostrarDatos(int accidentes){

    int año, edad;
    string sexo, registro, nombre;

    int menores25 = 0, femenino=0, masculinos16_30 = 0, otrasCiudades = 0, maxEdad=0, minEdad=1000;
    string maxNombre, minNombre;

    for (int i = 1; i <= accidentes; i++){
        año = pedirAño();
        sexo = pedirSexo();
        registro = pedirRegistro();
        nombre = pedirNomConductor();
        edad = 2024 - año;

        if (edad > maxEdad) {
            maxEdad = edad;
            maxNombre = nombre;
        }
        else if (edad == maxEdad){
            maxEdad = edad;
            maxNombre += " ";
            maxNombre += nombre;
        }

        if (edad < minEdad) {
            minEdad = edad;
            minNombre = nombre;
        }
        else if (edad == minEdad){
            minEdad = edad;
            minNombre += " ";
            minNombre += nombre;
        }

        if (edad < 25){
            menores25 ++;
        }

        if (sexo=="Femenino"){
            femenino ++;
        }
        else{
            if (edad >= 16 && edad <= 30){
                masculinos16_30 ++;
            }
        }

        if (registro == "Otras ciudades"){
            otrasCiudades ++;
        }
    }
    cout<<"-----------------------"<<endl;
    cout<<"El porcentaje de conductores menores de 25 años es: "<<menores25*100/accidentes<<"%"<<endl;
    cout<<"El porcentaje de conductores del sexo femenino es: "<<femenino*100/accidentes<<"%"<<endl;
    cout<<"El porcentaje de conductores masculinos con edades entre 16 y 30 años: "<<masculinos16_30*100/accidentes<<"%"<<endl;
    cout<<"El porcentaje de conductores cuyos carros estan registrados fuera de Medellín: "<<otrasCiudades*100/accidentes<<"%"<<endl;
    cout<<"Mayor/Mayores: ("<<maxEdad<<") "<<maxNombre<<endl;
    cout<<"Menor/Menores: ("<<minEdad<<") "<<minNombre<<endl;
    cout<<"-----------------------"<<endl;
}

int main(){

    system("chcp 65001 > nul");
    SetConsoleOutputCP(CP_UTF8);
    
    int accidentes;

    while (true){
        accidentes = pedirNumAccidentes();

        pedirMostrarDatos(accidentes);

        char continuar;

        while (true){

            cout<<"¿Desea continuar? (y/n)";
            cin>>continuar;

            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"*Opcion inválida*\n";
                continue;
            }

            if (tolower(continuar) == 'y'){
                break;
            }
            else if (towlower(continuar) == 'n'){
                exit(0);
            }
            else{
                cout<<"*Opcion inválida*\n";
                continue;
            }
        }
    }
    return 0;
}