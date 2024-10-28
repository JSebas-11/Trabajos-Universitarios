/*Realiza el control de acceso a una caja fuerte. La combinación será un número de 4 cifras. El programa nos pedirá la combinación para abrirla. 
Si no acertamos en 3 intentos, se nos mostrará el mensaje “Caja bloqueada” y si acertamos nos dirá “La caja fuerte se ha abierto satisfactoriamente”.*/

#include <iostream>

using namespace std;

int main(){

    int password=7819, userPassword, attempts=3;

    while (attempts>0 && attempts<=3){
        
        cout<<"Ingresa la combinacion (4 cifras) => ";
        cin>>userPassword;

        if (userPassword==password){
            cout<<"La caja se ha abierto satisfactoriamente";
            break;
        }
        else{
            attempts -=1;
            if (attempts==0){
                cout<<"Caja bloqueada, intentos agotados"<<endl;
            }
            else {
                cout<<"Clave incorrecta, intentos restantes "<<attempts<<endl;
            }
        }
    }

    return 0;
}
