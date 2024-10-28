//Escriba un algoritmo que muestre en binario un número entre 0 y 255.
#include <iostream>
#include <bitset>

using namespace std;

int main(){

    int num, binNum;
    char isContinue;

    while (true){
        cout<<"Ingresa el numero a convertir a binario => ";
        cin>>num;

        if (num<=0 || num>255){
            cout<<"El numero debe estar entre 0 y 255\n";
            continue;
        }

        bitset<8> binNum(num);

        cout<<num<<" en binario es: "<<binNum<<endl;

        cout<<"Continuar? (y/n)";
        cin>>isContinue;

        if (tolower(isContinue)=='y'){
            continue;
        }
        break;
    }
    
    return 0;
}