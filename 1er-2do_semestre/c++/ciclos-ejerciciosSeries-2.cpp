//Leer un número entero N y calcular el resultado de la siguiente serie: 2/1 + 4/3+ 6/5 +8/7 +10/9 +12/11 + N/N...

#include <iostream>

using namespace std;

int main(){

    int num;

    while (true){
        cout<<"Ingresa un numero entero positivo => ";
        cin>>num;

        if (num<=0){
            cout<<"Ingresa un numero mayor a 0";
            continue;
        }

        float result=0, div;

        if (num%2==0){

            for (float i=2.0, j=1.0; i<=num; i+=2, j+=2){
                if (i==num){
                    div = i / j;
                    result += div;
                    cout<<i<<"/"<<j<<" = "<<result;
                }
                else {
                    div = i / j;
                    result += div;
                    cout<<i<<"/"<<j<<" + ";
                } 
            }
        }
        else {

            for (float i=2.0, j=1.0; j<=num; i+=2, j+=2){
                if (j==num){
                    div = i / j;
                    result += div;
                    cout<<i<<"/"<<j<<" = "<<result;
                }
                else {
                    div = i / j;
                    result += div;
                    cout<<i<<"/"<<j<<" + ";
                } 
            }

        }

        char is_continue;

        cout<<"\nDeseas continuar? (y/n) => ";
        cin>>is_continue;

        if (tolower(is_continue)=='y'){
            continue;
        }
        else {
            break;
        }
    }
    

    return 0;
}
