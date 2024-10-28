#include <iostream>

using namespace std;

void calc_Pulsaciones () {
    /*Calcular el número de pulsaciones que debe tener una persona por cada 10 segundos de ejercicio aeróbico; 
    la fórmula que se aplica cuando el sexo es femenino es: num_pulsaciones = (220 −edad)/10 y 
    si el sexo es masculino: num_pulsaciones = (210 − edad)/10.*/
    int sexo, edad, num_pulsaciones;

    while (true){    
        cout<<"Ingresa tu sexo:\n\t1.Masculino\n\t2.Femenino";
        cin>>sexo;

        if (! (sexo == 1 || sexo == 2)){
            cout<<"Ingresa un numero valido"<<"\n";
            continue;
        }
        else {
            cout<<"Ingresa tu edad => ";
            cin>>edad;

            if (sexo == 1){
                num_pulsaciones = (210-edad)/10;
            }
            else {
                num_pulsaciones = (220-edad)/10;
            }
        }
        cout<<"Cada 10 segs de ejercicio aerobico debes tener "<<num_pulsaciones<<" pulsaciones";
        break;
    }

}
 
int main(){
    
    calc_Pulsaciones();
    return 0;
    
}

    