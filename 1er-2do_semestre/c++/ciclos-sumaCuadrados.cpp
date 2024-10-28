/*Calcular la suma de los cuadrados de los números: del 1 al 10.
                                                    del 13 al 25.
                                                    y rango ingresado por user*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int sum = 0, square;

    for (int i=1; i<=10; i++){
        
        square = pow(i, 2);
        sum += square;

        if (i==10){
            cout<<"Suma de los cuadrados del 1 al 10: "<<sum<<endl;
        }
    }

    sum = 0;

    for (int i=13; i<=25; i++){
        square = pow(i, 2);
        sum += square;

        if (i==25){
            cout<<"Suma de los cuadrados del 13 al 25: "<<sum<<endl;
        }
    }

    int ini, final;

    while (true){
        
        sum = 0;

        cout<<"Ingresa el 1er num del rango => ";
        cin>>ini;

        cout<<"Ingresa el 2do num del rango => ";
        cin>>final;

        if (!(ini>0 && final>0)){
            cout<<"Ingresa numeros mayores a 0\n";
            continue;
        }
        if (ini>=final){
            cout<<"El 2do numero debe ser mayor al 1ro\n";
            continue;
        }

        for (int i=ini; i<=final; i++){
            square = pow(i, 2);
            sum += square;

            if (i==final){
                cout<<"Suma de los cuadrados del "<<ini<<" al "<<final<<": "<<sum<<endl;
            }
        }

        char is_continue;

        cout<<"Deseas continuar? (y/n) => ";
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