/*Calcular las sumas siguientes: 100 + 90 + 80 + 70 + … 0
                                100 - 90 + 80 - 70 + … 0*/

#include <iostream>
#include <string>

using namespace std;

int main(){

    int result = 0;
    cout<<"Suma 1:\n\t";

    for (int i=100; i>=0; i-=10){
        result +=i;
        if(i==0){
            cout<<i<<" = "<<result;
            break;
        }
        cout<<i<<" + ";
    }

    cout<<"\nSuma 2:\n\t";
    int result2 = 0;
    string istr;

    for (int i = 100; i>=0; i-=10){
        istr = to_string(i);
        int toInt = stoi(istr.substr(0, 1)); 

        if (i==100){
            cout<<i<<" - ";
        }
        else if (i==0) {
            cout<<i<<" = "<<result2;
        }
        else if (toInt%2==0) {
            cout<<i<<" - ";
            result2 -= i;
        }
        else {
            cout<<i<<" + ";
            result2 += i;
        }

    }

    return 0;
}