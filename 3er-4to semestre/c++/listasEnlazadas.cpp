/*Ejercicios sobre listas enlazadas (Estructura de datos I) con el fin
de practicar la manipulacion y operaciones en las mismas, usar Programacion orientada a objetos*/

#include <iostream>
#include <string>
#include <tuple>
#include <random>

using namespace std;

struct node {
    int value;
    node* next;
    node(int _value){
        this->value = _value;
        this->next = nullptr;
    }
};

class linkList{
private:
    node* head;
    int numElem;
public:
    linkList(){
        this->head = nullptr;
        this->numElem = 0;
    };
    ~linkList(){
        node* temp = head;
        while (temp){
            node* toDel = temp;
            temp = temp->next;
            delete toDel;
        }
    };

    int getSize() const { return this->numElem; }

    void show() const {
        if (!head) { cout<<"Empty list\n"; }
        else {
            node* temp = head;
            while (temp){
                cout<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<"\n";
        }
    }

    void add(node* toAdd){
        if (!this->head){ this->head = toAdd; }
        else {
            node* temp = head;
            while (temp){
                if (!temp->next){
                    temp->next = toAdd;
                    break;
                }
                temp = temp->next;
            }
        }
        this->numElem++;
    }

    void randomFill(int numElements, int start = 0, int end = 101){
        if (numElements <= 0){
            throw out_of_range("numElements must be greater than 0");
        }

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> range(start, end);

        for (int i = 0; i < numElements; i++){
            this->add(new node(range(gen)));
        }
    }

    void remove(int x){
        if (!head){ throw runtime_error("List is empty"); }

        if (head->value == x){
            node* newHead = head->next;
            delete head;
            head = newHead;
            this->numElem--;
            cout<<"Element deleted succesfully\n";
            return;
        } else {
            node* temp = head;
            node* prev = nullptr;
            while (temp->next){
                prev = temp;
                temp = temp->next;

                if (temp->value == x){
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                    this->numElem--;
                    cout<<"Element deleted succesfully\n";
                    return;
                }
            }
        }
        cout<<"Element doesnt exist\n";
    }

    int maximum() const {
        if (!head){ throw runtime_error("List is empty"); }
        
        int max = head->value;
        node* temp = head->next;
        while (temp){
            if (temp->value > max){
                max = temp->value;
            }
            temp = temp->next;
        }
        return max;
    }

    int minimum() const {
        if (!head){ throw runtime_error("List is empty"); }
        
        int min = head->value;
        node* temp = head->next;
        while (temp){
            if (temp->value < min){
                min = temp->value;
            }
            temp = temp->next;
        }
        return min;
    }

    tuple<int, int> pairOdd() const {
        if (!head){ throw runtime_error("List is empty"); }

        int pairs = 0, odds = 0; 
        node* temp = head;
        while (temp){
            if (temp->value % 2 == 0){ pairs++; }
            else { odds++; }
            temp = temp->next;
        }
        return make_tuple(pairs, odds);
    }

    void lookForBreak(int number) const {
        if (!head){ throw runtime_error("List is empty"); }

        node* temp = head;
        while (temp){
            if (temp->value == number){
                cout<<"Number found, I will break loop\n";
                return;
            }
            temp = temp->next;
        }
        cout<<"Loop ends, Number has not been found\n";
    }

    int count(int number) const {
        if (!head){ throw runtime_error("List is empty"); }

        int count = 0;
        node* temp = head;
        while (temp){
            if (temp->value == number){
                count++;
            }
            temp = temp->next;
        }
        return count;
    }

    int sum() const {
        if (!head){ throw runtime_error("List is empty"); }

        int sum = 0;
        node* temp = head;
        while (temp){
            sum += temp->value;
            temp = temp->next;
        }
        return sum;
    }

    float average() const {
        return this->sum()/this->numElem;
    }

    linkList* operator^ (const linkList& other) const {
        if (!this->head || !other.head){ 
            throw runtime_error("Lists can not be empty"); 
        }

        linkList* newList = new linkList();
        node* temp = this->head;
        while (temp){
            newList->add(new node(other.count(temp->value)));
            temp = temp->next;
        }
        return newList;
    }

    void operator+ (linkList& other){
        if (!this->head || !other.head){ 
            throw runtime_error("Lists can not be empty"); 
        }

        node* temp = this->head;
        while (temp->next){ temp = temp->next; }

        temp->next = other.head;
        this->numElem += other.numElem;
    }
};

void exercise1(linkList* list){
    /*Crear un metodo que muestre cual es el dato mayor y el dato menor
    almacenado en una lista con enlace simple.*/
    cout<<"List: ";
    list->show();
    cout<<"Max: "<<list->maximum()<<" - Min: "<<list->minimum()<<"\n";
}

void exercise2(linkList* list){
    /*A partir de una lista de enteros. Crear un metodo para determinar 
    cuántos de esos valores son pares y cuántos son impares.*/
    cout<<"List: ";
    list->show();
    int pair, odd;
    tie(pair, odd) = list->pairOdd();
    cout<<"Pair numbers: "<<pair<<" - Odd numbers: "<<odd<<"\n";
}

void exercise3(linkList* list){
    /*A partir de una lista de enteros. Crear un metodo para 
    determinar si existe o no un valor x (en caso de encontrarlo
    deberá hacer rompimiento de ciclo).*/
    int number;
    cout<<"Number to look for -> ";
    cin>>number;
    cin.clear();
    list->lookForBreak(number);
}

void exercise4(linkList* list){
    /*Crear un metodo que permita realizar la búsqueda de un dato ingresado
    por el usuario en una lista ligada. Deberá indicar si existe o no dicho valor
    en la lista en caso de existir mostrar cuántas veces se encuentra ese valor.*/
    int number;
    cout<<"Number to look for and count -> ";
    cin>>number;
    cin.clear();

    int count = list->count(number);
    if (count == 0){ cout<<"Number is not in list\n"; }
    else { cout<<number<<" is in list "<<count<<" times\n"; }
}

void exercise5(linkList* list, int size){
    /*Elabore un metodo para que apartir de dos listas ligadas con enteros, imprima
    los promedios de cada lista y determine el mayor.*/
    linkList* list2 = new linkList();
    list2->randomFill(size);

    cout<<"List1: ";
    list->show();
    cout<<"List2: ";
    list2->show();
    float avg1 = list->average(); 
    float avg2 = list2->average();
    
    if (avg1 > avg2){
        cout<<"List1 has the greatest average ("<<avg1<<") avgList2 ("<<avg2<<")\n";
    } else if (avg1 < avg2){
        cout<<"List2 has the greatest average ("<<avg2<<") avgList1 ("<<avg1<<")\n";
    } else {
        cout<<"List1 has the same average ("<<avg1<<")("<<avg2<<")\n";
    }
}

void exercise6(linkList* list, int size){
    /*A partir de dos listas con enteros. Crear metodo para contar cuantas veces aparecen
    valores de la primera lista en la segunda lista.*/
    linkList* list3 = new linkList();
    list3->randomFill(size);

    linkList* newList = (*list)^(*list3);
    cout<<"List2: ";
    list3->show();

    cout<<"List1 and appearances in List2: \n\t";
    list->show();
    cout<<"\t";
    newList->show();
}

void exercise7(linkList* list){
    /*Crear metodo que permita unir dos listas con enlaces simples.*/
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> range(1, 11);

    linkList* list4 = new linkList();
    list4->randomFill(range(gen));

    cout<<"List1 original size: "<<list->getSize()<<"\n";
    cout<<"List1: ";
    list->show();
    cout<<"List2: ";
    list4->show();

    (*list)+(*list4);
    cout<<"New size: "<<list->getSize()<<"\n";
    list->show();
}

void exercise8(linkList* list){
    /*Crear metodo que permita eliminar un dato ingresado por el usuario en
    la lista. En caso de no encontrar el dato, se deberá informar.*/
    list->show();
    int number;
    cout<<"Number to remove -> ";
    cin>>number;
    cin.clear();
    list->remove(number);
    list->show();
}

void cleanWait(){
    system("pause");
    system("cls");
}

int main(){
    int elements;

    linkList* generalList = new linkList();
    
    while (true){
        cout<<"How many number do you want to include in your List -> ";
        cin>>elements;
        cin.clear();
        
        try{
            generalList->randomFill(elements);
        }
        catch(const out_of_range& e){
            cerr<<e.what()<<'\n';
            continue;
        }
        break;
    }
    cout<<"Random elements list:\n";
    generalList->show();
    cleanWait();

    cout<<"Exercise 1: (Greatest and least)"<<endl;
    exercise1(generalList);
    cleanWait();

    cout<<"Exercise 2: (Pair and odd numbers)"<<endl;
    exercise2(generalList);
    cleanWait();

    cout<<"Exercise 3: (x in List (break))"<<endl;
    exercise3(generalList);
    cleanWait();
    
    cout<<"Exercise 4: (x in List (count))"<<endl;
    exercise4(generalList);
    cleanWait();
    
    cout<<"Exercise 5: (Averages)"<<endl;
    exercise5(generalList, elements);
    cleanWait();
    
    cout<<"Exercise 6: (Numbers listX in listY)"<<endl;
    exercise6(generalList, elements);
    cleanWait();
    
    cout<<"Exercise 7: (Union)"<<endl;
    exercise7(generalList);
    cleanWait();
    
    cout<<"Exercise 8: (Remove x)"<<endl;
    exercise8(generalList);
    cleanWait();
    
    delete generalList;
    return 0;
}