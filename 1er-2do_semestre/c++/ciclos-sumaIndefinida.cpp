//Calcular la suma de los números introducidas por el usuario. Terminar cuando introduzca cero.

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int num, sum=0;

    do {
        cout<<"Ingresa el numero a sumar => ";
        cin>>num;

        sum += num;

    } while (num!=0);

    cout<<"El resultado de la suma es: "<<sum<<endl;

//Escriba un programa que sume los n primeros números impares.

    while (true){
        
        char is_continue;
        int sum=0, impAmount;
        vector<int> impares={};

        cout<<"Ingresa el numero de impares a sumar => ";
        cin>> impAmount;

        if (impAmount <= 0){
            cout<<"Ingresa un numero mayor a 0";
            continue;
        }

        for (int i=1, count=0; count<impAmount; i++){
            if (i%2!=0){
                impares.push_back(i);
                sum += i;
                count++;
            }
            
        }

        cout<<"Suma: "<<sum<<endl<<"Numeros: \n";

        for (int i=0; i<=(impares.size())-1; i++){
            cout<<impares[i]<<" ";
        }

        cout<<"\nContinuar? (y/n) ";
        cin>>is_continue;

        if (tolower(is_continue)=='y'){
            continue;
        }
        break;
    
    }
    
    return 0;
}