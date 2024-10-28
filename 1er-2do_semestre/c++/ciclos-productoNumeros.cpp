//Calcular el producto de los primeros 5 números impares y N num impares.

#include <iostream>

using namespace std;

int main(){

    int sum=0;

    for (int i=1; i<=5; i+=2){
        sum += i;

        if (i==5){
            cout<<"La suma de los numeros impares hasta el 5 es: "<<sum<<endl;
        }
    }

    while (true){
        int lim;
        cout<<"Ingresa el numero impar hasta el cual se sumara => ";
        cin>>lim;

        if (lim%2==0 || lim<1){
            cout<<"Ingresa un numero adecuado\n";
            continue;
        }

        int sum = 0;

        for (int i=1; i<=lim; i+=2){
            sum += i;

            if (i==lim){
                cout<<"La suma de los numeros impares hasta el "<<lim<<" es: "<<sum<<endl;
            }
        }

        char is_continue;

        cout<<"Deseas continuar? (y/n)";
        cin>>is_continue;

        if (tolower(is_continue)=='y'){
            continue;
        }
        break;
    }
    
    return 0;
}