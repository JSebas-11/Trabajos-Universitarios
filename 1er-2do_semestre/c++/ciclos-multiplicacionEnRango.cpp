//Multiplicar los números introducidos por el usuario que estén en el rango (1,10). Terminar cuando el usuario introduzca un número fuera del rango y mostrar el resultado.

#include <iostream>

using namespace std;

int main(){

    int mult=1, num;

    while (true){

        cout<<"Ingresa un numero entre 1 y 10 => ";
        cin>>num;

        if (!(num>=1 && num<=10)){
            break;
        }

        mult *= num;
        
    }

    cout<<"El resultado es: "<<mult;

    return 0;
}
