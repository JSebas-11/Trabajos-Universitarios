//Contar el número de números pares que introduzca el usuario y el número de impares. Terminar cuando el usuario introduzca el número 0.

#include <iostream>

using namespace std;

int main(){

    int num, numPar=0, numImpar=0;

    while (true){
        
        cout<<"Ingresa un numero par o impar =>";
        cin>>num;

        if (num<=0){
            break;
        }

        if (num%2==0){
            numPar ++;
        }
        else {
            numImpar ++;
        }
    }

    cout<<"Hubo "<<numPar<<" numeros pares, y "<<numImpar<<" numeros impares";
    
    return 0;
}