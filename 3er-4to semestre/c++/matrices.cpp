/*Ejercicios sobre matrices (Estructura de datos I) con el fin
de practicar la manipulacion y operaciones en ellas, ademas
se debe usar Programacion orientada a objetos*/

#include <iostream>
#include <tuple>
#include <random>

using namespace std;

class Matrix{
private:
    int rows, cols, **MatrixPtr;
public:
    Matrix(int _rows, int _cols) : rows(_rows), cols(_cols) {
        MatrixPtr = new int*[rows];
        for (int i = 0; i < rows; i++){
            MatrixPtr[i] = new int[cols];
        }
    };
    ~Matrix(){
        for (int i = 0; i < rows; i++){
            delete[] MatrixPtr[i];
        }
        delete[] MatrixPtr;
    };

    void show() const {
        cout<<"-------------------\n";
        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                cout<<*(*(this->MatrixPtr+i)+j)<<" ";
            }
            cout<<"\n";
        }
        cout<<"-------------------\n";
    }

    void fill(){
        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                cout<<"["<<i<<"]"<<"["<<j<<"]  <- ";
                cin>>*(*(this->MatrixPtr+i)+j);
            }
        }
    }

    void fillByCols(){
        for (int i = 0; i < this->cols; i++){
            for (int j = 0; j < this->rows; j++){
                cout<<"["<<j<<"]"<<"["<<i<<"]  <- ";
                cin>>*(*(this->MatrixPtr+j)+i);
            }
        }
    }

    void randomFill(int starts = 1, int ends = 101){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(starts, ends);

        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                *(*(this->MatrixPtr+i)+j) = distr(gen);
            }
        }
    }

    Matrix transpose() const {
        Matrix newMatrix = Matrix(this->cols, this->rows);

        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                newMatrix.MatrixPtr[j][i] = *(*(this->MatrixPtr+i)+j); 
            }
        }
        return newMatrix;
    }
    
    tuple<int, int> evenOdds() const {
        int even = 0, odd = 0;
        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){

                if (*(*(this->MatrixPtr+i)+j) % 2 == 0){ even++; } 
                else { odd++; }
                
            }
        }
        return make_tuple(even, odd);
    }

    tuple<int, int> diagSum() const {
        int main = 0, sec = 0;

        for (int i = 0, j = this->cols-1; i < this->cols; i++, j--){
            main += *(*(this->MatrixPtr+i)+i);
            sec += *(*(this->MatrixPtr+i)+j);
        }
        return make_tuple(main, sec);
    }

    int sum() const {
        int sum = 0;
        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                sum += *(*(this->MatrixPtr+i)+j);
            }
        }
        return sum;
    }

    int avg() const {
        return (this->sum())/(this->rows*this->cols);
    }

    int maxDiag(int which) const { //1 Main diagonal - 2 Secundary diagonal
        if (which != 1 && which != 2){
            throw invalid_argument("Parameter must by 1 (main) or 2 (secundary)");
        }

        int max = *(*(this->MatrixPtr+0)+0);
        
        if (which == 1){
            for (int i = 0; i < this->cols; i++){
                if (*(*(this->MatrixPtr+i)+i) > max){
                    max = *(*(this->MatrixPtr+i)+i);
                }
            }
        } else if (which == 2){
            for (int i = this->cols-1, j = 0; i >= 0; i--, j++){
                if (*(*(this->MatrixPtr+j)+i) > max){
                    max = *(*(this->MatrixPtr+j)+i);
                }
            }
        }
        return max;
    }

    int minDiag(int which) const { //1 Main diagonal - 2 Secundary diagonal
        if (which != 1 && which != 2){
            throw invalid_argument("Parameter must by 1 (main) or 2 (secundary)");
        }

        int min = *(*(this->MatrixPtr+0)+0);
        
        if (which == 1){
            for (int i = 0; i < this->cols; i++){
                if (*(*(this->MatrixPtr+i)+i) < min){
                    min = *(*(this->MatrixPtr+i)+i);
                }
            }
        } else if (which == 2){
            for (int i = this->cols-1, j = 0; i >= 0; i--, j++){
                if (*(*(this->MatrixPtr+j)+i) < min){
                    min = *(*(this->MatrixPtr+j)+i);
                }
            }
        }
        return min;
    }

    tuple<int, int> diagAvg() const {
        int mainSum = 0;
        int secSum = 0;

        for (int i = 0, j = this->cols-1; i < this->cols; i++, j--){
            mainSum += *(*(this->MatrixPtr+i)+i);
            secSum += *(*(this->MatrixPtr+i)+j);
        }
        
        return make_tuple(mainSum/this->cols, secSum/this->cols);
    }
    
    int topTriangularSum() const {
        int sum = 0;
        
        for (int i = 0; i < this->rows; i++){
            for (int j = i; j < this->cols; j++){
                sum += *(*(this->MatrixPtr+i)+j);
            }
        }
        return sum;
    }

    int bottomTriangularSum() const {
        int sum = 0;
        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j <= i; j++){
                sum += *(*(this->MatrixPtr+i)+j);
            }
        }
        return sum;
    }
};

void exercise1(){
    /*Llenar matriz de 3x3 recorriéndola por filas. Imprimir información transpuesta.*/
    Matrix* matrix1 = new Matrix(3, 3);
    matrix1->fillByCols();
    cout<<"Original matrix:\n";
    matrix1->show();
    cout<<"Tranposed matrix:\n";
    matrix1->transpose().show();
}

void exercise2(){
    /*Determinar la cantidad de elementos pares e impares de una matriz de NxN.*/
    int size, evens, odds;
    cout<<"Type the size of matrix -> ";
    cin>>size;

    Matrix* matrix2 = new Matrix(size, size);
    matrix2->fill();
    cout<<"Matrix:\n";
    matrix2->show();
    tie(evens, odds) = matrix2->evenOdds();
    cout<<"Matrix has "<<evens<<" even numbers and "<<odds<<" odd numbers\n";
}

void exercise3(){
    /*Determinar la sumatoria de la diagonal principal y secundaria de una matriz de orden 4*/
    int mainDiag, secDiag;

    Matrix* matrix3 = new Matrix(4, 4);
    matrix3->fill();
    cout<<"Matrix:\n";
    matrix3->show();
    tie(mainDiag, secDiag) = matrix3->diagSum();
    cout<<"Sum main diagonal: "<<mainDiag<<"\nSum secundary diagonal: "<<secDiag<<"\n";
}

void exercise4(){
    //Determinar la suma y el promedio de los elementos de una matriz de NxM.    
    int rows, cols;
    cout<<"Matrix rows -> ";
    cin>>rows; cin.clear();
    cout<<"Matrix cols -> ";
    cin>>cols; cin.clear();

    Matrix* matrix4 = new Matrix(rows, cols);
    matrix4->randomFill(1, 21);
    cout<<"Matrix:\n";
    matrix4->show();
    cout<<"Sum: "<<matrix4->sum()<<"\nAverage: "<<matrix4->avg()<<"\n";
}

void exercise5(){
    /*Calcular elemento mayor de la diagonal principal de una matriz de 5x5, y
    luego calcular el elemento menor de diagonal secundaria.*/
    Matrix* matrix5 = new Matrix(5, 5);

    matrix5->randomFill();
    cout<<"Matrix:\n";
    matrix5->show();
    cout<<"Maximum main diagonal: "<<matrix5->maxDiag(1)<<" - Maximum second diagonal: "<<matrix5->maxDiag(2)<<"\n";
    cout<<"Minimum main diagonal: "<<matrix5->minDiag(1)<<" - Minimum second diagonal: "<<matrix5->minDiag(2)<<"\n";
}

void exercise6(){
    //Determinar el promedio de los datos ubicados en cada diagonal.
    int main, sec;
    Matrix* matrix6 = new Matrix(5, 5);

    matrix6->randomFill(1, 21);
    cout<<"Matrix:\n";
    matrix6->show();
    tie(main, sec) = matrix6->diagAvg(); 

    cout<<"Main diagonal average: "<<main<<"\nSecundary diagonal average: "<<sec<<"\n";

}

void exercise7(){
    //Calcular suma de los elementos de la triangular superior (Incluir elementos de diagonal) 
    Matrix* matrix7 = new Matrix(4, 4);

    matrix7->randomFill(1, 21);
    cout<<"Matrix:\n";
    matrix7->show();

    cout<<"Sum top triangular: "<<matrix7->topTriangularSum()<<"\n";
}

void exercise8(){
    //Calcular la suma de los elementos de la triangular superior 
    Matrix* matrix8 = new Matrix(4, 4);

    matrix8->randomFill(1, 21);
    cout<<"Matrix:\n";
    matrix8->show();

    cout<<"Sum bottom triangular: "<<matrix8->bottomTriangularSum()<<"\n";
}

void cleanWait(){
    system("pause");
    system("cls");
}

int main(){
    cout<<"Exercise 1 (transpose): \n";
    exercise1();
    cleanWait();

    cout<<"Exercise 2 (even and odd numbers): \n";
    exercise2();
    cleanWait();

    cout<<"Exercise 3 (Order 4 matrix main and secundary diagonal): \n";
    exercise3();
    cleanWait();

    cout<<"Exercise 4 (Sum and average): \n";
    exercise4();
    cleanWait();

    cout<<"Exercise 5 (Max and min diagonals): \n";
    exercise5();
    cleanWait();

    cout<<"Exercise 6 (Averages diagonals): \n";
    exercise6();
    cleanWait();

    cout<<"Exercise 7 (top triangular): \n";
    exercise7();
    cleanWait();

    cout<<"Exercise 8 (bottom triangular): \n";
    exercise8();
    cleanWait();

    return 0;
}