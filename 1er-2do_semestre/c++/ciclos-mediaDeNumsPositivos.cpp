//Escribe un programa que calcule la media de un conjunto de números positivos introducidos por teclado. El usuario indicará que ha terminado 
//de introducir los datos cuando meta un número negativo.

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main(){

    float mean, num, sum=0, amount=0;
    double floatPiece, intPiece;

    while (true){
        cout<<"Ingresa el numero => ";
        cin>>num;

        if (num<0){
            break;
        }

        sum += num;
        amount ++;
    }

    mean = sum/amount;

    floatPiece = modf(mean, &intPiece);

    if (floatPiece==0){
        cout<<"El promedio de la suma ("<<sum<<")"<<" es: "<<intPiece<<"."<<floatPiece;
    }
    else {
        char value;
        vector <char> newNum;

        string meanStr = to_string(mean);

        for (int i=0; i<meanStr.size(); i++){
            value = meanStr[i];
            newNum.push_back(value);
        }

        cout<<"El promedio de la suma ("<<sum<<")"<<" es: ";

        for (int i=0; i<newNum.size(); i++){
            cout<<newNum[i];
        }
    }

    return 0;
}