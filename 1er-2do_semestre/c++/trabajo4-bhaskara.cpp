/*Se requiere que usted permita que se realicen las siguientes operaciones sobre tres números A, B y C:
Primera operación: Determine el porcentaje al que equivale A, B y C en relación a la sumatoria de ellos.
Segunda operación: (Formula bhaskara)*/

#include <iostream>
#include <limits>
#include <tuple>
#include <cmath>

using namespace std;

tuple <double, double, double> pedirNumeros(){
    double numeroA, numeroB, numeroC;

    //Iteramos 3 veces en el for para pedir cada dato
    for (int i=1; i<=3; i++){
        if (i == 1){
            cout<<"Ingresa el numero A => ";
            cin>> numeroA;
        }
        else if (i == 2){
            cout<<"Ingresa el numero B => ";
            cin>> numeroB;
        }
        else if (i == 3){
            cout<<"Ingresa el numero C => ";
            cin>> numeroC;
        }

        //En caso de haber algun error, limpiamos el buffer e ignoramos la cantidad de caracteres ingresados
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Tipo de dato incorrecto, intenta de nuevo\n";        
            //Restamos 1 a la variable i para repetir la iteracion donde hubo el fallo 
            i--;
        }
    }
    return make_tuple(numeroA, numeroB, numeroC);
} 

tuple <double, double, double, double> porcentajes(double num1, double num2, double num3){
    //Calculamos el total y los porcentajes de cada numero
    double total = num1 + num2 + num3;
    double porNum1 = round(num1*100/total); 
    double porNum2 = round(num2*100/total); 
    double porNum3 = round(num3*100/total); 
    
    return make_tuple(porNum1, porNum2, porNum3, total);
}

tuple <double, double> bhaskara(double a, double b, double c){
    //Calculamos la discriminante
    double discriminante = sqrt(pow(b, 2) - 4*a*c);
    double resultado1 = ((-1*b) + (discriminante)) / (2*a);
    double resultado2 = ((-1*b) - (discriminante)) / (2*a);
    
    //En caso de ser negativa quiere decir que la ecuacion no tiene solucion real 
    if (discriminante < 0){
        return make_tuple(NAN, NAN);
    }
    //Si no es negativa retornamos los respectivos resultados
    else{
        return make_tuple(resultado1, resultado2);
    }
}

int main(){
    //Declaramos las variables a usar
    double numeroA, numeroB, numeroC, total;
    double porc_numeroA, porc_numeroB, porc_numeroC;
    double bhaskara1, bhaskara2;

    while (true){
        //Desempaquetamos los valores que devuelven las funciones y mostramos los datos en consola
        tie(numeroA, numeroB, numeroC) = pedirNumeros();
        tie(porc_numeroA, porc_numeroB, porc_numeroC, total) = porcentajes(numeroA, numeroB, numeroC);
        tie(bhaskara1, bhaskara2) = bhaskara(numeroA, numeroB, numeroC);

        cout<<"---------------------------------\n";
        cout<<"Total: "<<total<<endl<<"Numeros-Porcentajes:\n"<<numeroA<<" - "<<porc_numeroA<<"%"<<endl<<numeroB<<" - "<<porc_numeroB<<"%"<<endl<<numeroC<<" - "<<porc_numeroC<<"%"<<endl;
        if (isnan(bhaskara1) || isnan(bhaskara2)){
            cout<<"La ecucion no tiene soluciones reales\n";
        } 
        cout<<"Bhaskara resultado 1: "<<bhaskara1<<endl<<"Bhaskara resultado 2: "<<bhaskara2<<endl;
        cout<<"---------------------------------\n";   

        char continuar;
        cout<<"Deseas continuar (y/n) => ";
        cin>>continuar;

        if (tolower(continuar) == 'y'){
            continue;
        } 
        else{
            break;
        }
    }

    return 0;
}