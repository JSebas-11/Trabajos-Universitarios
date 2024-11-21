/*Escribe un programa que simule un juego en el que el usuario tiene que adivinar un número
aleatorio generado por la computadora. Implementa las siguientes características:

1. La computadora genera un número aleatorio entre rango ingresado por el usuario.
2. El usuario tiene 5 intentos para adivinar el número.
3. Después de cada intento, el programa debe indicar si el número introducido es
mayor, menor o correcto.
4. Si el usuario adivina el número o agota los intentos, el programa debe mostrar un
mensaje adecuado y terminar..*/

#include <iostream>
#include <random> 
#include <limits> 
#include <tuple>

using namespace std;

tuple <int, int> askRange(){
    int start, end;

    while (true){    
        cout<<"Ingresa el comienzo del rango => ";
        cin>>start;
        
        if (cin.fail()){
            cin.clear(),
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"*Ingresa un numero*\n";
            continue;
        }
        if (start <= 0){
            cout<<"*El numero debe ser mayor a 0*\n";
            continue;
        }

        cout<<"Ingresa el fin del rango => ";
        cin>>end;

        if (cin.fail()){
            cin.clear(),
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"*Ingresa un numero*\n";
            continue;
        }
        if (end <= start){
            cout<<"*Rango incorrecto el fin debe ser mayor al comienzo*\n";
            continue;
        }
    
        return make_tuple(start, end);
    }
}

int generateNum(int start, int end){
    int randomNum;

    random_device randomDev;
    //Motor de números aleatorios y generador de números aleatorios con una semilla basada en el reloj
    mt19937 gen(randomDev()); 
    //Generamos rango
    uniform_int_distribution<> distribucion(start, end);

    //Generamos numero y lo retornamos
    randomNum = distribucion(gen);
    return randomNum;
}

void adivinateNum(int start, int end, int genNum){
    int userNum = -1, lives = 5;
    
    //El numero generado siempre sera mayor a 0, asi que con eso aseguramos su ejecucion al menos 1 vez 
    while (userNum != genNum && lives >= 1){
        cout<<"----------------------------\n";
        cout<<"Ingresa un numero entre "<<start<<"-"<<end<<endl<<"Lives: "<<lives<<endl;
        cout<<"----------------------------\n";
        cin>>userNum;

        //En caso de entrada invalida se advierte al usuario
        if (cin.fail()){
            cin.clear(),
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"*Dato no valido*\n";
            continue;
        }
        //Comprobamos que el usuario ingrese un numero dentro del rango
        if (!(userNum >= start && userNum <= end)){
            cout<<"*Numero fuera de rango*\n";    
            continue;
        }
        //Damos feedback al usuario y redefinimos las variables para actualizar el rango
        if (userNum > genNum){
            cout<<"El numero es menor al ingresado\n";
            end = userNum;
            lives -= 1;
        }
        else if (userNum < genNum){
            cout<<"El numero es mayor al ingresado\n";
            start = userNum;
            lives -= 1;
        }
        else{
            cout<<"----------------------------\n";
            cout<<"Correcto, has adivinado el numero "<<(userNum)<<" "<<(genNum)<<endl;
            cout<<"----------------------------\n";
        }
        //Mostrar mensaje en caso agotar las vidas
        if (lives == 0){
            cout<<"----------------------------\n";
            cout<<"Perdiste, te quedaste sin vidas\n";
            cout<<"----------------------------\n";
        }
    }
}

int main() {
    int start, end, genNum;
    char isContinue;

    while (true){
        //Llamamos a la funcion con los rangos y los desempaquetamos para pasarlos como parametros a las sgtes dos funciones
        tie(start, end) = askRange();
        genNum = generateNum(start, end);
        adivinateNum(start, end, genNum);

        cout<<"Deseas jugar de nuevo (y/n) => ";
        cin>>isContinue;

        if (tolower(isContinue) == 'y'){
            continue;
        }
        else{
            break;
        }
    }
    
    return 0;
}