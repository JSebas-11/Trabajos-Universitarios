//Calcular el promedio de los números impares introducidos por el usuario. Terminar cuando introduzca el primer número par.

#include <iostream>

using namespace std;

int main(){

    int num, sum, amount=0;

    while (true){

        cout<<"Ingresa numero impar => ";
        cin>>num;

        if (num%2==0 || num<0){
            break;
        }
        sum += num;
        amount ++;     
    }

    cout<<"El promedio de "<<sum<<" / "<<amount<<" es : "<<(sum/amount);
    
    return 0;
}
