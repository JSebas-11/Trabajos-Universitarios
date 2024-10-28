//Calcular el factorial de n recursivamente.
//La función factorial se representa con “!” detrás de un número. Hay que multiplicar todos los números enteros positivos que hay entre ese número y el 1. 

#include <iostream>

using namespace std;

int factorialFunc(int n) {
    if (n==0 || n==1){  
        return 1;
    }
    else {
        return n * factorialFunc(n-1);  
    }
}

int main(){

    while (true){
        
        int num, factorial=1, mult=0, factorialRec;
        char isContinue;
    
        cout<<"Ingresa el numero del que queres el factorial => ";
        cin>>num;

        if (num<=0){
            cout<<"El numero debe ser un entero positivo\n";
            continue;
        }

        for (int i=1; i<=num; i++){
            mult = 1 * i;
            factorial *= mult; 
        }

        factorialRec = factorialFunc(num);

        cout<<num<<"! en ciclo es: "<<factorial<<endl;
        cout<<num<<"! recursivamente es: "<<factorial<<endl;

        cout<<"Continuar(y/n) ";
        cin>>isContinue;

        if (tolower(isContinue)=='y'){
            continue;
        }
        break;

    }

    return 0;
}