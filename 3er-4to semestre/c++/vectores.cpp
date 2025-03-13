/*Ejercicios sobre vectores (Estructura de datos I) con el fin
de practicar la manipulacion y operaciones en ellos, ademas
se debe usar Programacion orientada a objetos*/

#include <iostream>
#include <vector>
#include <tuple>
#include <random>

using namespace std;

class Vector{
private:
    int size;
    int* vector;
public:
    Vector(int _size){
        vector = new int[_size];
        size = _size;
    };
    ~Vector(){
        delete[] vector;
    };

    int getSize() const { return this->size; }

    int elementIn(int pos) const {
        if (pos >= this->size){
            throw out_of_range("Position number out of range");
        }
        return *(this->vector+pos);
    }

    void fill(){
        for (int i = 0; i < this->size; i++){
            cout<<"Type element of position "<<i<<" -> ";
            cin>>*(vector+i);
        }
    }

    void randomFill(int start = -101, int end = 101){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(start, end);
        for (int i = 0; i < this->size; i++){
            *(vector+i) = distr(gen);
        }
    }

    void show() const {
        for (int i = 0; i < this->size; i++){
            cout<<*(this->vector+i)<<" ";
        }
        cout<<endl;
    }

    int average() const {
        int sum = 0;
        for (int i = 0; i < this->size; i++){
            sum += *(vector+i);
        }
        return sum/this->size;
    }

    tuple<int, int, int, int> sumNegativesPositives() const {
        int posit = 0, negat = 0, sumPos = 0, sumNeg = 0;
        for (int i = 0; i < this->size; i++){
            if (*(this->vector+i) >= 0){
                posit++;
                sumPos += *(this->vector+i);
            } else {
                negat++;
                sumNeg += *(this->vector+i);
            }
        }
        return make_tuple(posit, sumPos, negat, sumNeg);   
    }

    tuple<int, int> max() const {
        int max = *(this->vector+0); 
        int maxIndex = 0;

        for (int i = 1; i < this->size; i++){
            if (*(this->vector+i) > max){
                max = *(this->vector+i);
                maxIndex = i;
            }
        }
        return make_tuple(max, maxIndex);
    }

    Vector toSquare() const {
        Vector newVector = Vector(this->size);

        for (int i = 0; i < newVector.size; i++){
            newVector.vector[i] = (*(this->vector+i))*(*(this->vector+i));
        }
        return newVector;
    }

    Vector inverse() const {
        Vector newVector = Vector(this->size);

        for (int i = newVector.size-1, j = 0; i >= 0; i--, j++){
            newVector.vector[j] = *(this->vector+i);
        }
        return newVector;
    }

    static Vector vectorsSum(const Vector& vector1, const Vector& vector2) {
        if (vector1.size != vector2.size){
            throw runtime_error("Vectors must have the same size");
        }
        
        Vector newVector = Vector(vector1.size);
        for (int i = 0; i < newVector.size; i++){
            newVector.vector[i] = vector1.vector[i] + vector2.vector[i];
        }
        return newVector;
    }

    static bool areEqual(const Vector& vector1, const Vector& vector2){
        if (vector1.size != vector2.size) { return false; }
        
        for (int i = 0; i < vector1.size; i++){
            if (vector1.vector[i] != vector2.vector[i]) {
                return false;
            }
        }
        return true;
    }

    static Vector inverseProd(const Vector& vector1, const Vector& vector2){
        if (vector1.size != vector2.size){
            throw runtime_error("Vectors must have the same size");
        }

        Vector newVector = Vector(vector1.size);
        for (int i = 0, j = newVector.size-1; i < newVector.size; i++, j--){
            newVector.vector[i] = (vector1.vector[i]) * (vector2.vector[j]);
        }
        return newVector;
    }
};

void exercise1(){
    /*Calcular el promedio de 10 valores almacenados en un vector. Determinar
    además cuantos son mayores que el promedio, imprimir el promedio, el
    número de datos mayores que el promedio y una lista(otro vector) de
    valores mayores que el promedio.*/
    Vector vector1 = Vector(10);
    
    vector1.fill();
    int avg = vector1.average();
    int greaterAvg = 0;
    vector<int> newVector = {};
    for (int i = 0; i < vector1.getSize(); i++){
        if (vector1.elementIn(i) > avg) {
            greaterAvg++;
            newVector.push_back(vector1.elementIn(i));
        }
    }
    
    cout<<"Average: "<<avg<<endl<<"Greatest than avg: "<<greaterAvg<<endl<<"Elements: ";
    for (int i = 0; i < newVector.size(); i++){
        cout<<newVector[i]<<" ";
    }
    cout<<endl;

}

void exercise2(){
    /*Almacenar 300 números en un vector, imprimir cuantos son negativos y positivos. 
    Imprimir además la suma de los negativos y la suma de los positivos.*/
    Vector vector2 = Vector(300);

    vector2.randomFill();
    vector2.show();

    int posit, negat, sumPos, sumNeg;
    tie(posit, sumPos, negat, sumNeg) = vector2.sumNegativesPositives();
    cout<<"Positivies amount: "<<posit<<"-Positivies sum: "<<sumPos<<endl;
    cout<<"Negativies amount: "<<negat<<"-Negativies sum: "<<sumNeg<<endl;
}

void exercise3(){
    /*Llenar un vector de 10 elementos, imprimir la posición y el valor del
    elemento mayor almacenado en el vector. Todos los elementos del vector 
    deben ser diferentes.*/
    Vector vector3 = Vector(10);

    vector3.fill();
    vector3.show();

    int max, index;
    tie(max, index) = vector3.max();

    cout<<"Maximum value: "<<max<<" - Maximum index: "<<index<<endl;
}

void exercise4(){
    /*Almacenar 10 números en un vector, elevar al cuadrado cada valor
    almacenado en el vector, almacenar el resultado en otro vector. Imprimir el
    vector original y el vector resultante.*/
    Vector vector4 = Vector(10);

    vector4.fill();
    vector4.show();
    vector4.toSquare().show();
}

void exercise5(){
    /*Almacenar 10 números en un vector, almacenarlos en otro vector en
    orden inverso al vector original e imprimir el vector resultante.*/
    Vector vector5 = Vector(10);

    vector5.fill();
    vector5.show();
    vector5.inverse().show();
}

void exercise6(){
    /*Llenar dos vectores A y B de 10 elementos cada uno, sumar el elemento
    uno del vector A con el elemento uno del vector B y así sucesivamente
    hasta 10, almacenar el resultado en un vector C, e imprimir el vector
    resultante.*/
    Vector vectorA = Vector(10);
    Vector vectorB = Vector(10);

    cout<<"Fill up vector A: "<<endl;
    vectorA.fill();
    cout<<"Fill up vector B: "<<endl;
    vectorB.fill();

    cout<<"Vector A: ";
    vectorA.show();
    cout<<"Vector B: ";
    vectorB.show();
    cout<<"Vector A+B: ";
    Vector::vectorsSum(vectorA, vectorB).show();
}

void exercise7(){
    /*A partir de dos vectores M y N de 10 elementos cada uno. Hacer un algoritmo 
    que escriba la palabra Iguales; si ambos vectores son iguales y Diferentes; 
    si no lo son. Serán iguales cuando en la misma posición de ambos vectores 
    se tenga el mismo valor para todos los elementos.*/
    Vector vectorM = Vector(10);
    Vector vectorN = Vector(10);

    cout<<"Fill up the first vector:"<<endl;
    vectorM.fill();
    cout<<"Fill up the second vector:"<<endl;
    vectorN.fill();

    bool equal = Vector::areEqual(vectorM, vectorN);
    if (equal){
        cout<<"Vectors are equal"<<endl;
    } else {
        cout<<"Vectors are NOT equal"<<endl;
    }
    cout<<"Vector M: ";
    vectorM.show();
    cout<<"Vector N: ";
    vectorN.show();
}

void exercise8(){
    /*Leer dos vectores A y B de 10 elementos cada uno y multiplicar 
    el primer elemento de A con el ultimo elemento de B y así
    sucesivamente hasta llegar a los 10 elementos de A por el primer
    elemento de B. El resultado de la multiplicación almacenarlo en un vector C.*/
    Vector vectorA = Vector(10);
    Vector vectorB = Vector(10);

    cout<<"Fill up the A vector:"<<endl;
    vectorA.fill();
    cout<<"Fill up the B vector:"<<endl;
    vectorB.fill();

    cout<<"Vector A: ";
    vectorA.show();
    cout<<"Vector B: ";
    vectorB.show();
    cout<<"Inverse product: "<<endl;
    Vector::inverseProd(vectorA, vectorB).show();
}

void cleanWait(){
    system("pause");
    system("cls");
}

int main(){
    cout<<"Exercise 1: (Averages)"<<endl;
    exercise1();
    cleanWait();

    cout<<"Exercise 2: (Random numbers)"<<endl;
    exercise2();
    cleanWait();

    cout<<"Exercise 3: (Maximum)"<<endl;
    exercise3();
    cleanWait();
    
    cout<<"Exercise 4: (Squares)"<<endl;
    exercise4();
    cleanWait();
    
    cout<<"Exercise 5: (Inverse)"<<endl;
    exercise5();
    cleanWait();
    
    cout<<"Exercise 6: (Vector sum)"<<endl;
    exercise6();
    cleanWait();
    
    cout<<"Exercise 7: (Are they iqual?)"<<endl;
    exercise7();
    cleanWait();
    
    cout<<"Exercise 8: (Inverse product)"<<endl;
    exercise8();
    cleanWait();
    
    return 0;
}