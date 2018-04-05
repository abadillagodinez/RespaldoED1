#include "ListaCircularDoble.h"
//metodos de la clase

//constructor

ListaCircularDoble::ListaCircularDoble()
{
    head = NULL;
    length = 0;
}

//destructor

ListaCircularDoble::~ListaCircularDoble()
{
    NodoD *aux;

   while(head) {
      aux = head;
      head = head->next;
      delete aux;
   }
}

//metodo para verificar si esta vacia

bool ListaCircularDoble::isVoid(){
    return (head == NULL);
}

////metodo para insertar al inicio

void ListaCircularDoble::insertAtHead(int pNewElement){
    NodoD *newNode = new NodoD(pNewElement);
    if (isVoid())
    {
        head = newNode;
        head->next = head;
        head->previous = head;
        length++;
    }
   else
    {
         newNode->next = head;
         newNode->previous = head->previous;
         head->previous->next = newNode;
         newNode->next->previous = newNode;
         head = newNode;
         length++;
    }
}
 //metodo para insertar en posicion
void ListaCircularDoble::insertAtPos(int pos, int pNewElement){
    if (isVoid() || pos <= 0){
        insertAtHead(pNewElement);
    }
    else if(pos > length-1){
        insertAtTail(pNewElement);
    }
    else{
        NodoD *newNode = new NodoD(pNewElement);
        NodoD *aux = head;
        int i = 1;
        while((i != pos)&&(aux->next != head)){
            i++;
            aux = aux->next;
        }
        newNode->next = aux->next;
        aux->next = newNode;
        aux->next->previous = aux;
        newNode->next->previous = newNode;
        length++;
    }
}

//metodo para insertar al final de la lista
void ListaCircularDoble::insertAtTail(int pNewElement){
    NodoD *newNode = new NodoD(pNewElement);
    if(isVoid()){
        head = newNode;
        head->next = head;
        head->previous = head;
        length++;
    }
    else{
        newNode->previous = head->previous;
        newNode->next = head->previous->next;
        head->previous->next = newNode;
        head->previous = newNode;
        length++;
    }
}

//metodo que elimina del inicio de la lista
void ListaCircularDoble::deleteAtHead(){
    if(isVoid()){
        cout << "La lista ya está vacía" << endl;
    }
    else if(head->next == head){
        NodoD *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoD *aux = head;
        NodoD *temp = head;
        while (aux->next != head){
            aux = aux->next;
            }
        aux->next = head->next;
        head = head->next;
        head->previous = aux;
        temp->next = NULL;
        temp->previous = NULL;
        delete temp;
        length--;
    }
}

//metodo de eliminacion en posicion
void ListaCircularDoble::deleteAtPos(int pos){
    if(isVoid()){
        cout << "La lista está vacía" << endl;
    }
    else if((pos > length-1) || (pos<0)){
        cout << "ERROR: posición no válida" << endl;
    }
    else if(pos == 0){
        deleteAtHead();
    }
    else{
        int i = 1;
        NodoD *aux = head;
        while(i < pos){
            aux = aux->next;
            i++;
        }
        NodoD *temp = aux->next;
        aux->next = aux->next->next;
        aux->next->previous = aux;
        delete temp;
        length--;
    }
}

//metodo de eliminacion al final
void ListaCircularDoble::deleteAtTail(){
    if(isVoid()){
        cout << "La lista está vacía" << endl;
    }
    else if(head->next == head){
        NodoD *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoD *aux = head;
        while (aux->next->next != head)
            aux = aux->next;
        NodoD *temp = aux->next;
        aux->next = head;
        head->previous = aux;
        delete temp;
        length--;
    }

}

//metodo de impresion
void ListaCircularDoble::print(){
   if (isVoid()){
        cout << "la lista esta vacia";
    }
    else{
        NodoD *aux = head;
        do{
            if (aux->next == head){
                cout << aux->value;
                aux = aux->next;
            }
            else{
                cout << aux->value<< " -> ";
                aux = aux->next;
            }
        }while(aux != head);
    }
    cout << endl;

}
