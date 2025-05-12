/*Ejercicios sobre pilas (Estructura de datos I) con el fin de practicar 
la manipulacion y operaciones en ellas, ademas se debe usar Programacion
orientada a objetos y clase base abstracta*/

#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct StackNode {
    int value;
    StackNode* next;
    StackNode(int _value){
        this->value = _value;
        this->next = nullptr;
    }
};

//Clase para abstraer las diferentes posibles implementaciones del stack (array, nodos)
class BaseStack { 
private:
    int length;
public:
    virtual ~BaseStack() = default;
    virtual void show() const = 0;
    virtual void randomFill(int numElements, int start, int end) = 0;
    virtual bool exists(int toFind) const = 0; 
    virtual int sum() const = 0; 
    virtual float average() const = 0;
    virtual BaseStack* copy() const = 0;
};

//Clase de implementacion del stack como array
class ArrStack : public BaseStack {
private:
    int length;
    int top;
    int* array;
public:
    ArrStack(int len){
        this->length = len;
        this->array = new int[len];
    };
    ~ArrStack(){ delete[] this->array; };
    
    void defineTop(){ this->top = *(this->array+0); }

    void show() const override {
        for (int i = this->length-1; i >= 0; i--){
            cout<<*(this->array+i)<<" ";
        }
        cout<<" <-- top\n";
    }

    void randomFill(int numElements = 0, int start = 0, int end = 100) override {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> range(start, end);
        numElements = this->length-1;

        for (int i = numElements; i >= 0; i--){
            *(this->array+i) = range(gen);
        }
        this->defineTop();
    }

    bool exists(int toFind) const override {
        for (int i = 0; i < this->length; i++){
            if (*(this->array+i) == toFind){
                return true;
            }
        }
        return false;
    }

    int sum() const override {
        int total = 0;
        for (int i = 0; i < this->length; i++){
            total += *(this->array+i);
        }
        return total;
    }

    float average() const override {
        return static_cast<float>(this->sum()) / static_cast<float>(this->length);
    }

    BaseStack* copy() const override {
        ArrStack* newStack = new ArrStack(this->length);

        for (int i = this->length-1; i >= 0; i--){
            *(newStack->array+i) = *(this->array+i);
        }
        newStack->defineTop();
        return newStack;
    }
};

//Clase de implementacion del stack como lista enlazada
class Stack : public BaseStack {
private:
    int length;
    StackNode* top;
public:
    Stack(){
        this->length = 0;
        this->top = nullptr;
    };
    ~Stack(){
        while (this->top){
            StackNode* newTop = this->top->next;
            delete this->top;
            this->top = newTop;
        }
    };
    
    void AddNode(StackNode* toAdd){
        if (!this->top){ this->top = toAdd; } 
        else {
            toAdd->next = this->top;
            this->top = toAdd;
        }
        this->length++;
    }

    void RemoveNode(int toDelValue){
        if (!this->top) { return; }
        
        if (this->top->value == toDelValue){
            StackNode* newTop = this->top->next;
            delete this->top;
            this->top = newTop;
            this->length--;
        } else {
            StackNode* temp = this->top;
            while (temp){
                if (temp->next->value == toDelValue){
                    StackNode* toDel = temp->next;
                    temp->next = temp->next->next;
                    delete toDel;
                    this->length--;
                    break;
                }
                temp = temp->next;
            }
        }
    }

    void RemoveNodeAt(int toDelPosition){
        if (!this->top) { return; }
        if (toDelPosition < 0 || toDelPosition > this->length-1) { return; }
        
        if (toDelPosition == 0){
            this->RemoveNode(this->top->value);
        } else {
            StackNode* temp = this->top->next;
            for (int i = 1; temp; i++){
                if (i == toDelPosition){
                    this->RemoveNode(temp->value);
                    break;
                }
                temp = temp->next;
            }
        }
    }

    void unstack(int until){
        StackNode* temp = this->top;
        while (temp){
            StackNode* current = temp;
            temp = temp->next;
            if (current->value != until){ 
                this->RemoveNode(current->value);
                continue;
            }
            break; 
        }
    }

    void show() const override {
        if (!this->top){
            cout<<"There's nothing to show\n";
            return;
        }
        StackNode* temp = this->top;
        while (temp){
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<"\ttop("<<this->top->value<<")\n";
    }

    void randomFill(int numElements, int start = 0, int end = 100) override {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> range(start, end);

        for (int i = 0; i < numElements; i++){
            this->AddNode(new StackNode(range(gen)));
        }
    }

    bool exists(int toFind) const override {
        StackNode* temp = this->top;
        while (temp){
            if (temp->value == toFind){ return true; }
            temp = temp->next;
        }
        return false;
    }

    int sum() const override {
        int total = 0;
        StackNode* temp = this->top;
        while (temp){
            total += temp->value;
            temp = temp->next;
        }
        return total;
    }

    float average() const override {
        return static_cast<float>(this->sum()) / static_cast<float>(this->length);
    }

    StackNode* GetNodeAt(int position) const {
        if (!this->top) { return nullptr; }
        if (position < 0 || position > this->length-1) { return nullptr; }
        
        if (position == 0){ return this->top; }
        else {
            StackNode* temp = this->top->next;
            for (int i = 1; temp; i++){
                if (i == position){ return temp; }
                temp = temp->next;
            }
        }
    }

    BaseStack* copy() const override {
        Stack* newStack = new Stack();
        vector<StackNode*> tempVec = {};
        
        StackNode* temp = this->top;
        while (temp){
            tempVec.push_back(new StackNode(temp->value));
            temp = temp->next;
        }
        for (int i = tempVec.size()-1; i >= 0; i--){
            newStack->AddNode(tempVec.at(i));
        }
        
        return newStack;
    }
    
    Stack* operator+ (const Stack& other) const {
        if (!this->top || !other.top) { throw runtime_error("Stacks must have data"); }
        
        Stack* newStack = new Stack();
        vector<StackNode*> tempVec = {};
        
        for (int i = this->length-1; i >= 0; i--){ tempVec.push_back(this->GetNodeAt(i)); }
        for (int i = other.length-1; i >= 0; i--){ tempVec.push_back(other.GetNodeAt(i)); }

        for (int i = 0; i < tempVec.size(); i++){ newStack->AddNode(tempVec.at(i)); }
        
        return newStack;
    }
};

void exercise1(BaseStack* stack){
    /*Se tiene una pila (como array) y cargada con los precios de ciertos productos.
    Crear un programa que permita indicar si en dicha pila se encuentra o no un valor 
    ingresado por el usuario, así como el precio promedio de los productos.*/
    int toFind;
    cout<<"Type the number to look for -> ";
    cin>>toFind;
    cin.clear();

    cout<<"Is "<<toFind<<" in the stack? "<<boolalpha<<stack->exists(toFind)<<"\n";
    stack->show();
    cout<<"Total Sum: "<<stack->sum()<<" - Average: "<<stack->average()<<"\n";
}

void exercise2(BaseStack* stack){
    /*Se tiene una pila (como array), se pide hacer un programa que
    permita copiar el contenido de una pila en otra. Los elementos de la pila
    resultante deberán quedar en el mismo orden que los de la pila original.*/
    cout<<"Original stack:\n";
    stack->show();
    cout<<"Copy stack:\n";
    stack->copy()->show();
}

void exercise3(BaseStack* stack){ 
    /*Realizar los ejercicios anteriores con una pila representada como lista ligada.*/
    exercise1(stack);
    exercise2(stack);
}

void exercise4(Stack* stack){ 
    /*Se tiene un pila (como lista ligada) y cargada con información numérica. 
    Se pide crear un algoritmo que permita eliminar un nodo indicando el valor y 
    otro indicando la posicion*/
    int element;
    stack->show();
    cout<<"Type the node's value to remove -> ";
    cin>>element;
    cin.clear();
    if (stack->exists(element)){ stack->RemoveNode(element); }
    else { cout<<"Element doesnt exist\n"; }
    cout<<"Type the node's position to remove -> ";
    cin>>element;
    cin.clear();
    stack->RemoveNodeAt(element);
    stack->show();
}

void exercise5(Stack* stack){ 
    /*Se tiene una pila (como lista ligada) cargada con información entera y positiva. 
    Elabore un programa que permita desapilar todos los elementos de la pila a partir
     de un dato indicado por el usuario.*/
    int element;
    stack->show();
    cout<<"Type the node's value limit to unstack -> ";
    cin>>element;
    cin.clear();
    if (stack->exists(element)){ stack->unstack(element); }
    else { cout<<"Element doesnt exist\n"; }
    cout<<"Final Stack:\n";
    stack->show();
}

void exercise6(){ 
    /*Se tienen dos pilas (como listas ligadas) y cargadas con información entera y positiva. 
    Crear un algoritmo que permita unir en una sola pila las dos pilas anteriores, apilando
    la 2da pila en la 1ra.*/
    Stack* stack1 = new Stack();
    Stack* stack2 = new Stack();
    stack1->randomFill(10);
    stack2->randomFill(5);

    cout<<"Stack 1: ";
    stack1->show();
    cout<<"Stack 2: ";
    stack2->show();
    Stack* unionSt = *(stack1)+*(stack2);
    cout<<"Union stack: ";
    unionSt->show();

    delete stack1;
    delete stack2;
    delete unionSt;
}

void cleanWait(){
    system("pause");
    system("cls");
}

int main(){
    int elements;

    cout<<"Type the array's stack lenght -> ";
    cin>>elements;
    cin.clear();

    ArrStack* arrayStack = new ArrStack(elements); 

    arrayStack->randomFill();

    cout<<"Exercise 1 (Find and average in Array Stack): \n";
    exercise1(arrayStack);
    cleanWait();

    cout<<"Exercise 2 (Copies): \n";
    exercise2(arrayStack);
    cleanWait();
    cout<<"Type the node's stack lenght -> ";
    cin>>elements;
    cin.clear();
    
    Stack* nodeStack = new Stack();
    nodeStack->randomFill(elements);
    
    cout<<"Exercise 3 (Same exercises with stack as linked list): \n";
    exercise3(nodeStack);
    cleanWait();
    
    cout<<"Exercise 4 (Remove x node): \n";
    exercise4(nodeStack);
    cleanWait();
    
    cout<<"Exercise 5 (Unstack): \n";
    exercise5(nodeStack);
    cleanWait();
    delete nodeStack;
    delete arrayStack;

    cout<<"Exercise 6 (Stack union): \n";
    exercise6();
    cleanWait();
    
    return 0;
}