//Mostrar la tabla de multiplicar del número que seleccione el usuario. Revisar que esté en el rango (1,10)

#include <iostream>

using namespace std;

int main(){

    int num;

    while (true){
        cout<<"Ingresa un numero del 1 al 10 => ";
        cin>>num;

        if (!(num>=1 && num<=10)){
            cout<<"Ingresa un numero que este dentro del rango\n";
            continue;
        }

        for (int i=1; i<=10; i++){
            int result = num*i; 
            cout<<num<<"*"<<i<<":"<<result<<endl;
        }

        char is_continue;

        cout<<"Deseas continuar? (y/n)";
        cin>>is_continue;

        if (tolower(is_continue)=='y'){
            continue;
        }
        else{
            break;
        }
    }
    
    return 0;
}
