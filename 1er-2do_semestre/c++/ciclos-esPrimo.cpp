//Diseña un algoritmo que decida si un número es primo. 0 para salir

#include <iostream>
#include <vector>

using namespace std;

int main(){

    while (true){

        int num, numMultiplos;
        vector <int> multiplos={};

        cout<<"Ingresa el numero => ";
        cin>>num;

        for (int i=1; i<=num; i++){
            if (num%i==0){
                numMultiplos +=1;
                multiplos.push_back(i); 
            }
        }

        numMultiplos = multiplos.size();

        if (num==0){
            break;
        }

        else if (num<0 || numMultiplos>2){
            cout<<"El numero "<<num<<" NO es primo\n";
        }
        else{
            cout<<"El numero "<<num<<" ES primo\n";
        }

    }


    return 0;
}
