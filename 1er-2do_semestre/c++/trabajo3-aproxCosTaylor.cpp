/*Este archivo en C++ implementa una aproximacion de la funcion coseno utilizando la serie de Taylor.
cos(x) en radianes, con un numero configurable de terminos en la serie para mejorar la precision del resultado. 
La serie de Taylor utilizada es una expansion en torno a 𝑥 = 0, y toma la forma: cos(𝑥) = ∑(N) 𝑛=0 ((−1)^𝑛*ang^2𝑛) / (2𝑛)!

Algunas caracteristicas del Codigo:
Opcion de ingresar angulo en grados y conversio automatica a radianes. 
Configuracion del numero de terminos para obtener una mayor precision en la aproximacion. 
Manejo basico de errores, por ejemplo, evitar valores de entrada fuera de rango o ingreso de caracteres invalidos.*/

//Librerias necesarias para el correcto funcionamiento del programa
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Funcion para pedir numero mayor a 0
int pedirNum(){
    int num;
    while (true){
    
        cout<<"Ingresa la cantidad de terminos de la serie => ";
        cin>>num;

        //Actuar en caso de algun posible input inesperado (Por ejemplo, caracter)
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Dato no valido, intenta de nuevo\n";
            continue;
        }
        else if (num<=0){
            cout<<"El numero debe ser mayor a 0, intenta de nuevo\n";
            continue;
        }
        return num;
    }
}

//Funcion con formula correspondiente para convertir grados a radianes
long double gradARad(float angGrados){
    return angGrados*3.141592/180;
}

//Funcion para pedir angulo
float pedirAngulo(){
    float angulo;
    while (true){
        int medida;
        cout<<"Ingresar angulo en grados o radianes?\n1.Grados\n2.Radianes\n";
        cin>>medida;
        //Actuar y volver a pedir dato en caso de que el input no sea las opciones que esperamos
        if (!(medida==1 or medida==2)){
            cout<<"Ingresa un numero correcto\n";
            continue;
        }
        else{
            //En caso de querer ingresar el angulo en grados, nos aseguramos que este en el rango correspondiente
            if (medida==1){
                while (true){
                    cout<<"Ingresa el angulo en grados => ";
                    cin>>angulo;
                    if (!(angulo>=-360 && angulo<=360)){
                        cout<<"Valor fuera de rango\n";
                        continue;
                    }
                    //Retornamos angulo ingresado convertido a radianes (Necesaria conversion para la aproximacion coseno serie Taylor)
                    return gradARad(angulo);
                }
            }
            else{
                //En caso de querer ingresar el angulo en radianes, nos aseguramos que este en el rango correspondiente antes de ser retornado
                while (true){
                    cout<<"Ingresa el angulo en radianes => ";
                    cin>>angulo;
                    if (!(angulo>=-6.2832 && angulo<=6.2832)){
                        cout<<"Valor fuera de rango\n";
                        continue;
                    }
                    return angulo;
                }
            }
        }
    }  
}

//Funcion para calcular factorial de un numero  
long double calcFactorial(int num){
    //Factorial se define como la multiplicacion de todos los numeros previos (desde 1 hasta n) incluyendo n
    long double resultado=1.0, multiplicacion;
    for (int i = 1; i <= num; i++){
        resultado *= i;
    }
    return resultado;
}

//Funcion para calcular el coseno de un angulo
long double cosenoTaylor(int numTerminos, float angulo){
    long double resultado = 0;
    /*Suma que se ira acumulando hasta llegar a la cantidad de terminos establecidos, 
    acumulara la division entre Numerador:  -1 elevado a valor de i (en esa iteracion) multplicado por el angulo elevado al resultado de 2 por valor de i (en esa iteracion) 
                                Denominador: factorial de 2 multiplicado por valor de i (en esa iteracion)*/
    for (int i = 0; i <= numTerminos; i++){
        resultado += (pow((-1), i)*pow(angulo,(2*i))) / calcFactorial(2*i);
    }
    return resultado;
}

//Funcion principal
int main(){
    int cantidadTerminos;
    float angulo;
    long double resultado;
    char continuar;

    while (true){

        cantidadTerminos = pedirNum();
        angulo = pedirAngulo();
        resultado = cosenoTaylor(cantidadTerminos, angulo);

        cout<<"----------\nAproximacion funcion coseno del angulo (rad)"<<angulo<<" es: "<<fixed<<setprecision(10)<<resultado<<"\n----------\n";

        while (true){
            cout<<"Deseas continuar? (y/n)";
            cin>>continuar;

            if (tolower(continuar)=='y'){
                break;
            }
            else if (tolower(continuar)=='n'){
                exit(0);
            }
            else{
                cin.clear();
                cin.ignore();
                cout<<"Opcion incorrecta\n";
                continue;
            }
        }
    }
    return 0;
}
