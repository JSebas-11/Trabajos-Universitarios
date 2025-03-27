/*Ejercicios sobre matrices y vectores (Estructura de datos I) con el fin
de practicar la manipulacion y operaciones en ellas, ademas se debe 
usar Programacion orientada a objetos

En un arreglo bidimensional se guarda la información referente a las ventas que
realizan 4 empresas en 4 ciudades diferentes (Medellín, Bogotá, Cali,
Barranquilla).*/

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

const string STRAIGHT_LINES = "--------------------------------------\n";

class VectorNames {
public:
    VectorNames(initializer_list<string> values) : data(values) {}
    vector<string> data;

    int position(const string& toEvalue) const {
        for (int i = 0; i < data.size(); i++){
            if (this->data.at(i) == toEvalue){
                return i;
            }
        }
        return -1;
    }
    int size() const {
        return this->data.size();
    }
};

class Dataset{
private:
    int rows, cols, elements;
    vector<vector<int>> matrData;
    VectorNames companies;
    VectorNames cities;

public:
    Dataset(const VectorNames& compNames, const VectorNames& citNames, const vector<vector<int>>& data)
        : companies(compNames), cities(citNames), matrData(data){
        rows = compNames.size();
        cols = citNames.size();
        elements = rows*cols;
    };
    
    void show() const {
        cout<<STRAIGHT_LINES;
        for (int i = 0; i < this->rows; i++){
            cout<<this->companies.data[i]<<":\n";
            for (int j = 0; j < this->cols; j++){
                cout<<"\t"<<this->cities.data[j]<<": "<<this->matrData[i][j]<<"\n";
            }
        }
        cout<<STRAIGHT_LINES;
    }

    int sum() const {
        int totalSum = 0;
        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                totalSum += this->matrData[i][j];
            }
        }
        return totalSum;
    }

    tuple<string, string> exists(int value){
        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                if (this->matrData[i][j] == value){
                    return make_tuple(this->companies.data[i], this->cities.data[j]);
                }
            }
        }
        return make_tuple("\0", "\0");
    }

    int existsIndex(const string& by, const string& nameBy) const { 
        if (by != "company" && by != "city"){
            throw invalid_argument("Parameter by must by: company or city");
        }
        return (by == "company") ? companies.position(nameBy) : cities.position(nameBy);
    }

    int sumBy(const string& by, const string& nameBy) const {
        
        int searchIn = this->existsIndex(by, nameBy);
        if (searchIn == -1){ return -1; }

        int totalSum = 0;
        if (by == "company"){
            searchIn = this->companies.position(nameBy);
            for (int i = 0; i < this->cols; i++){
                totalSum += this->matrData[searchIn][i];
            }
        } else {
            searchIn = this->cities.position(nameBy);
            for (int i = 0; i < this->rows; i++){
                totalSum += this->matrData[i][searchIn];
            }
        }

        return totalSum;
    }

    int valueByBoth(const string& company, const string& city) const {
        int comIndex = this->companies.position(company);
        int cityIndex = this->cities.position(city);

        if (comIndex == -1 || cityIndex == -1){ return -1; }
        
        return this->matrData[comIndex][cityIndex];
    }

    int average() const {
        return this->sum()/this->elements;
    } 

    tuple<int, int, int> avgComparation() const {
        int greater = 0; int equal = 0; int less = 0;
        int number; int avg = this->average(); 

        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                number = this->matrData[i][j];
                if (number > avg) { greater++; } 
                else if (number < avg) { less++; } 
                else { equal++; }
            }
        }
        return make_tuple(greater, equal, less);
    }

    int avgBy(const string& by, const string& nameBy) const {
        int searchIn = this->existsIndex(by, nameBy);
        if (searchIn == -1){ return -1; }

        int totalSum = this->sumBy(by, nameBy);
        return totalSum/this->cols;
    }

    void showAverages(string& by) const {
        if (by != "company" && by != "city"){
            throw invalid_argument("Parameter by must by: company or city");
        }

        if (by == "company"){
            cout<<STRAIGHT_LINES;
            for (const string& company : this->companies.data){
                cout<<company<<": "<<this->avgBy(by, company)<<"\n";
            }
            cout<<STRAIGHT_LINES;
        } else {
            cout<<STRAIGHT_LINES;
            for (const string& city : this->cities.data){
                cout<<city<<": "<<this->avgBy(by, city)<<"\n";
            }
            cout<<STRAIGHT_LINES;
        }
    }

    tuple<int, int> greatesLeast(const string& by, const string& nameBy) const {
        int searchIn = this->existsIndex(by, nameBy);
        if (searchIn == -1){ return make_tuple(-1, -1); }

        int max; 
        int min;
        
        if (by == "company"){
            max = this->matrData[searchIn][0];
            min = this->matrData[searchIn][0];
            for (int i = 0; i < this->cols; i++){
                if (this->matrData[searchIn][i] > max){
                    max = this->matrData[searchIn][i];
                }
                if (this->matrData[searchIn][i] < min){
                    min = this->matrData[searchIn][i];
                }
            }
        } else {
            max = this->matrData[0][searchIn];
            min = this->matrData[0][searchIn];
            for (int i = 0; i < this->rows; i++){
                if (this->matrData[i][searchIn] > max){
                    max = this->matrData[i][searchIn];
                }
                if (this->matrData[i][searchIn] < min){
                    min = this->matrData[i][searchIn];
                }
            }
        } 
        return make_tuple(max, min);
    } 

    tuple<int, int, int, string, string> maxData() const {
        int max = this->matrData[0][0];
        int maxRow = 0;
        int maxCol = 0;
        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                if (this->matrData[i][j] > max){
                    max = this->matrData[i][j];
                    maxRow = i;
                    maxCol = j;
                }
            }
        }
        return make_tuple(max, maxRow, maxCol, this->companies.data.at(maxRow), this->cities.data.at(maxCol));
    }
    tuple<int, int, int, string, string> minData() const {
        int min = this->matrData[0][0];
        int minRow = 0;
        int minCol = 0;
        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                if (this->matrData[i][j] < min){
                    min = this->matrData[i][j];
                    minRow = i;
                    minCol = j;
                }
            }
        }
        return make_tuple(min, minRow, minCol, this->companies.data.at(minRow), this->cities.data.at(minCol));
    }

    tuple<int, int> greatestByRowNum() const {
        int maxPair = this->matrData[0][0];
        int maxOdd = this->matrData[1][0];

        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                if (i % 2 == 0){
                    if (this->matrData[i][j] > maxPair){
                        maxPair = this->matrData[i][j];
                    }
                } else {
                    if (this->matrData[i][j] > maxOdd){
                        maxOdd = this->matrData[i][j];
                    }
                }
            }
        }
        return make_tuple(maxPair, maxOdd);
    }

    tuple<int, int> leastByRowNum() const {
        int minPair = this->matrData[0][0];
        int minOdd = this->matrData[1][0];

        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                if (i % 2 == 0){
                    if (this->matrData[i][j] < minPair){
                        minPair = this->matrData[i][j];
                    }
                } else {
                    if (this->matrData[i][j] < minOdd){
                        minOdd = this->matrData[i][j];
                    }
                }
            }
        }
        return make_tuple(minPair, minOdd);
    }

    int soldsByCompIn(const string& company, const string& city1, const string& city2) const {
        string byComp = "company";
        string byCity = "city";

        int comIndex = this->existsIndex(byComp, company);
        int city1Index = this->existsIndex(byCity, city1);
        int city2Index = this->existsIndex(byCity, city2);

        if (comIndex == -1 || city1Index == -1 || city2Index == -1){
            return -1;
        }
        
        return this->matrData[comIndex][city1Index] + this->matrData[comIndex][city2Index];
    }

    int between(int starts, int ends) const {
        int counter = 0, valueIter;

        for (int i = 0; i < this->rows; i++){
            for (int j = 0; j < this->cols; j++){
                valueIter = this->matrData[i][j];
                if (valueIter >= starts && valueIter <= ends){
                    counter++;
                }
            }
        }
        return counter;
    }

    int betweenIn(const string& city, int starts, int ends) const {
        int counter = 0, valueIter;

        int cityIndex = this->cities.position(city);
        if (cityIndex == -1) { return -1; }

        for (int i = 0; i < this->rows; i++){
            valueIter = this->matrData[i][cityIndex];
            if (valueIter >= starts && valueIter <= ends){
                counter++;
            }
        }
        return counter;
    }

    tuple<int, int> greaterLessThan(const string& city, int value) const {
        int greaterC = 0, lessC = 0, 
        valueIter;

        int cityIndex = this->cities.position(city);
        if (cityIndex == -1) { return make_tuple(-1, -1); }

        for (int i = 0; i < this->rows; i++){
            valueIter = this->matrData[i][cityIndex];
            if (valueIter > value){ greaterC++; }
            else if (valueIter < value){ lessC++; }
        }
        return make_tuple(greaterC, lessC);
    }

    int soldsMultpOf(const string& company, int value) const {
        int counter = 0;

        int compIndex = this->companies.position(company);
        if (compIndex == -1){ return -1; }

        for (int i = 0; i < this->cols; i++){
            if (this->matrData[compIndex][i] % value == 0){
                counter++;
            }
        }
        return counter;
    }
};

void exercises1(Dataset& df){
    /*Valor al que ascienden todas las ventas.
    Ventas totales de x ciudad.
    Ventas totales de x empresa.
    Ventas realizadas en ciudad x en y empresa.*/
    cout<<"Suma total ventas: "<<df.sum()<<"\n";

    string byCity = "city"; string byCompany = "company";
    string city1 = "Medellin"; string city2 = "Cali";
    string empr1 = "Burras at Home"; string empr2 = "Luca Hoddies";
    
    cout<<"Ventas totales "<<city1<<": "<<df.sumBy(byCity, city1)<<"\n";
    cout<<"Ventas totales "<<city2<<": "<<df.sumBy(byCity, city2)<<"\n";
    cout<<"Ventas totales "<<empr1<<": "<<df.sumBy(byCompany, empr1)<<"\n";
    cout<<"Ventas totales "<<empr2<<": "<<df.sumBy(byCompany, empr2)<<"\n";

    city1 = "Bogota"; city2 = "Barranquilla";
    empr1 = "Tussi Limited Corp."; empr2 = "Pasion Salvaje S.A";

    cout<<"Ventas en "<<empr1<<", "<<city1<<": "<<df.valueByBoth(empr1, city1)<<"\n";
    cout<<"Ventas en "<<empr2<<", "<<city2<<": "<<df.valueByBoth(empr2, city2)<<"\n";
}

void exercises2(Dataset& df){
    /*Cantidad de ventas superiores al promedio.
    Cantidad de ventas inferiores o iguales al promedio.
    Ventas promedio de cada empresa y ciudad.*/
    cout<<"Promedio general: "<<df.average()<<"\n";

    int greaterAvg, lessAvg, equalAvg;
    tie(greaterAvg, lessAvg, equalAvg) = df.avgComparation();
    cout<<"Mayores promedio: "<<greaterAvg<<"\n";
    cout<<"Menores promedio: "<<lessAvg<<"\n";
    cout<<"Iguales promedio: "<<equalAvg<<"\n";

    string by = "company";
    cout<<"Promedios por Empresa:\n";
    df.showAverages(by);
    by = "city";
    cout<<"Promedios por ciudad:\n";
    df.showAverages(by);
}

void exercises3(Dataset& df){
    /*Venta mayor y menor realizada en x ciudad.
    Venta mayor y menor realizada en x empresa.
    Nombre de empresa, posicion y ciudad donde se produjo la mayor venta.
    Nombre de empresa, posicion y ciudad donde se produjo la menor venta.*/
    string byCity = "city"; string byCompany = "company";
    string city1 = "Medellin"; string city2 = "Bogota";
    string empr1 = "Pasion Salvaje S.A"; string empr2 = "Luca Hoddies";

    int max, min;
    tie(max, min) = df.greatesLeast(byCity, city1);
    cout<<city1<<": mayor: "<<max<<", menor: "<<min<<"\n";
    tie(max, min) = df.greatesLeast(byCity, city2);
    cout<<city2<<": mayor: "<<max<<", menor: "<<min<<"\n";
    tie(max, min) = df.greatesLeast(byCompany, empr1);
    cout<<empr1<<": mayor: "<<max<<", menor: "<<min<<"\n";
    tie(max, min) = df.greatesLeast(byCompany, empr2);
    cout<<empr2<<": mayor: "<<max<<", menor: "<<min<<"\n";

    int maxValue, row, col, minValue;
    string comp, city;
    tie(maxValue, row, col, comp, city) = df.maxData();
    cout<<"Maximo en ["<<row<<"]["<<col<<"]: "<<maxValue<<". "<<comp<<"-"<<city<<"\n";
    tie(minValue, row, col, comp, city) = df.minData();
    cout<<"Minimo en ["<<row<<"]["<<col<<"]: "<<minValue<<". "<<comp<<"-"<<city<<"\n";
}

void exercises4(Dataset& df){
    /*Leer el valor de una venta y verificar si alguna empresa tiene ese valor.
    Venta mayor de las empresas pares e impares.
    Venta menor de las empresas pares e impares.
    Mostrar cantidad de ventas de una empresa en x en y, z ciudades.*/
    int value;
    cout<<"Ingresa un valor a verificar en la tabla -> ";
    cin>>value; cin.clear();

    string comp, city;
    tie(comp, city) = df.exists(value);
    if (comp == "\0"){
        cout<<"No existe venta con ese valor "<<value<<"\n";
    } else {
        cout<<"Venta con valor "<<value<<" fue realizada en "<<comp<<", "<<city<<'\n';
    }

    int maxPair, maxOdd;
    tie(maxPair, maxOdd) = df.greatestByRowNum();
    cout<<"Mayor de empresas con index pares: "<<maxPair<<"\n";
    cout<<"Mayor de empresas con index impares: "<<maxOdd<<"\n";
    int minPair, minOdd;
    tie(minPair, minOdd) = df.leastByRowNum();
    cout<<"Menor de empresas con index pares: "<<minPair<<"\n";
    cout<<"Menor de empresas con index impares: "<<minOdd<<"\n";

    comp = "Pasion Salvaje S.A";
    string city1 = "Medellin";
    string city2 = "Cali";

    cout<<"Ventas "<<comp<<" en "<<city1<<" y "<<city2<<": "<<df.soldsByCompIn(comp, city1, city2)<<"\n";
}

void exercises5(Dataset& df){
    /*Cantidad de ventas entre un rango dado.
    Cantidad de ventas entre un rango dado en x ciudad.
    Cantidad de ventas superiores y menores a un valor en ciudad x.
    Cantidad de ventas múltiplos de n en la Empresa x.*/
    int start, end;
    cout<<"Ingresa el numero desde el que comienza el rango -> ";
    cin>>start; cin.clear();
    cout<<"Ingresa el numero en el que termina el rango -> ";
    cin>>end; cin.clear();

    string city1 = "Barranquilla"; 
    string city2 = "Bogota";

    cout<<"Hay "<<df.between(start, end)<<" valores en el rango ("<<start<<"-"<<end<<")\n";
    cout<<"Hay "<<df.betweenIn(city1, start, end)<<" valores en el rango ("<<start<<"-"<<end<<") en "<<city1<<"\n";
    cout<<"Hay "<<df.betweenIn(city2, start, end)<<" valores en el rango ("<<start<<"-"<<end<<") en "<<city2<<"\n";

    int value, greater, less;
    cout<<"Numero para buscar cuales son mayores y menores -> ";
    cin>>value; cin.clear();

    city1 = "Medellin", city2 = "Cali";

    tie(greater, less) = df.greaterLessThan(city1, value);
    cout<<"Hay "<<greater<<" mayores y "<<less<<" menores a "<<value<<" en "<<city1<<"\n";
    tie(greater, less) = df.greaterLessThan(city2, value);
    cout<<"Hay "<<greater<<" mayores y "<<less<<" menores a "<<value<<" en "<<city2<<"\n";

    int multiple;
    cout<<"Ingresa el numero de los cuales quieres contar las ventas multiplos de el -> ";
    cin>>multiple; cin.clear();

    string comp1 = "Tussi Limited Corp.", comp2 = "Pasion Salvaje S.A";
    cout<<"Hay "<<df.soldsMultpOf(comp1, multiple)<<" ventas multipls de "<<multiple<<" en "<<comp1<<"\n";
    cout<<"Hay "<<df.soldsMultpOf(comp2, multiple)<<" ventas multipls de "<<multiple<<" en "<<comp2<<"\n";
}

void cleanWait(){
    system("pause");
    system("cls");
}

int main(){

    VectorNames companies = {"Tussi Limited Corp.", "Burras at Home", "Pasion Salvaje S.A", "Luca Hoddies"};
    VectorNames cities = {"Medellin", "Bogota", "Cali", "Barranquilla"};
    vector<vector<int>> soldsData = 
    {
        {128, 50, 115, 32},
        {138, 30, 145, 160},
        {187, 129, 210, 48},
        {21, 69, 87, 45},
    };
   
    Dataset df = Dataset(companies, cities, soldsData);

    df.show();
    cleanWait();

    exercises1(df);
    cleanWait();

    exercises2(df);
    cleanWait();

    exercises3(df);
    cleanWait();

    exercises4(df);
    cleanWait();

    exercises5(df);
    cleanWait();

    return 0;
}