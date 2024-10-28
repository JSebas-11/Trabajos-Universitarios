//Escriba un algoritmo que decida si dos números positivos son amigos. Dos números son amigos, si la suma de sus divisores (distintos de ellos mismos) son iguales.

#include <iostream>

using namespace std;

bool friends(int x, int y){
    int sum1=0, sum2=0;

    for (int i=1; i<x; i++){
        if (x%i==0){
            sum1 += i;
        }
    } 

    for (int i=1; i<y; i++){
        if (y%i==0){
            sum2 += i;
        }
    }

    if (sum1==y && sum2==x){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    while (true){
        int num1, num2;
        bool areFriends; 
        char isContinue;

        cout<<"Ingresa el 1er numero => ";
        cin>>num1;

        cout<<"Ingresa el 2do numero => ";
        cin>>num2;

        if (num1<=0 || num2<=0){
            cout<<"Ingresa un numero mayor a 0\n";
            continue;
        }

        areFriends = friends(num1, num2);

        if (areFriends==true){
            cout<<num1<<" y "<<num2<<" son amigos\n";
        }

        else{
            cout<<num1<<" y "<<num2<<" NO son amigos\n";
        }

        cout<<"Continuar? (y/n)";
        cin>>isContinue;

        if (tolower(isContinue)=='y'){
            continue;
        }
        break;

    }
    

    return 0;
}