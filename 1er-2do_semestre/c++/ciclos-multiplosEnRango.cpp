//Introducir un rango especificado por 2 números, el primero es menor al segundo y contar el número de múltiplos de 3 que existe en el rango. 
//Por ejemplo, si se introduce 2 y 21, el número de múltiplos de 3 es 7, dado que 3, 6, 9, 12, 15, 18 y 21 son múltiplos de 3 en el rango [2,21]. 

#include <iostream>
#include <vector>

using namespace std;

int main(){

    while (true){
        
        int num1, num2, numMult=0;
        vector <int> multiplos3={};

        cout<<"Ingresa el 1er numero =>";
        cin>>num1;

        cout<<"Ingresa el 2do numero =>";
        cin>>num2;

        if (num1<=0 || num2<=0 || num1>=num2){
            cout<<"Ingresa el rango correctamente\n";
            continue;
        }

        for (int i=num1; i<=num2; i++){
            if (i%3==0){
                numMult +=1;
                multiplos3.push_back(i);
            }
        }

        cout<<"En el rango ("<<num1<<", "<<num2<<"), hay "<<numMult<<" multiplos de 3:\n\t( ";

        for (int i=0; i<multiplos3.size(); i++){
            cout<<multiplos3[i]<<" ";
        }
        cout<<")\n";

        char is_continue;

        cout<<"Continuar? (y/n)";
        cin>>is_continue;

        if (tolower(is_continue)=='y'){
            continue;
        }
        break;

    }

    return 0;
}
