//Leer un número entero N y calcular el resultado de la siguiente serie: 1 – 1/2+ 1/3 – 1/4 +.... +/- 1/N.
#include <iostream>

using namespace std;

int main(){

    int num;
    
    while (true){
        
        cout<<"Ingresa un numero entero positivo => ";
        cin>>num;

        if (num<=0){
            cout<<"Ingresa un numero mayor a 0\n";
            continue;
        }

        float result = 1.0, div;

        for (int i = 1; i <= num; i++){

            if (i == 1){
                cout<<i<<" - ";
            }
            else if (i == num){
                div =  1.0 / i;
                if (num % 2 == 0){
                    result -= div;
                }
                else{
                    result += div;
                }
                cout<<"1"<<"/"<<i<<" = "<<result;
            }
            else if (i % 2 == 0){
                cout<<"1"<<"/"<<i<<" + ";
                div =  1.0 / i;
                result -= div; 
            }
            else {
                cout<<"1"<<"/"<<i<<" - ";
                div =  1.0 / i;
                result += div;
            }
        } 

        char is_continue;

        cout<<"\nQuieres continuar? (y/n)";
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