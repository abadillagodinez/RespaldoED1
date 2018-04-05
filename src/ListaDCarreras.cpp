#include "ListaDCarreras.h"
//metodos de la clase

//constructor

ListaDCarreras::ListaDCarreras()
{
    head = NULL;
    length = 0;
}

//destructor

ListaDCarreras::~ListaDCarreras()
{
    NodoDCarreras *aux;

   while(head) {
      aux = head;
      head = head->next;
      delete aux;
   }
}

//metodo para verificar si esta vacia

bool ListaDCarreras::isVoid(){
    return (head == NULL);
}

////metodo para insertar al inicio

void ListaDCarreras::insertAtHead(string pNombre, string pCode){
    NodoDCarreras *newNode = new NodoDCarreras(pNombre, pCode);
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
void ListaDCarreras::insertAtPos(int pos, string pNombre, string pCode){
    if (isVoid() || pos <= 0){
        insertAtHead(pNombre, pCode);
    }
    else if(pos > length-1){
        insertAtTail(pNombre, pCode);
    }
    else{
        NodoDCarreras *newNode = new NodoDCarreras(pNombre, pCode);
        NodoDCarreras *aux = head;
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
void ListaDCarreras::insertAtTail(string pNombre, string pCode){
    NodoDCarreras *newNode = new NodoDCarreras(pNombre, pCode);
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
void ListaDCarreras::deleteAtHead(){
    if(isVoid()){
        cout << "La lista ya está vacía" << endl;
    }
    else if(head->next == head){
        NodoDCarreras *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDCarreras *aux = head;
        NodoDCarreras *temp = head;
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
void ListaDCarreras::deleteAtPos(int pos){
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
        NodoDCarreras *aux = head;
        while(i < pos){
            aux = aux->next;
            i++;
        }
        NodoDCarreras *temp = aux->next;
        aux->next = aux->next->next;
        aux->next->previous = aux;
        delete temp;
        length--;
    }
}

//metodo de eliminacion al final
void ListaDCarreras::deleteAtTail(){
    if(isVoid()){
        cout << "La lista está vacía" << endl;
    }
    else if(head->next == head){
        NodoDCarreras *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDCarreras *aux = head;
        while (aux->next->next != head)
            aux = aux->next;
        NodoDCarreras *temp = aux->next;
        aux->next = head;
        head->previous = aux;
        delete temp;
        length--;
    }

}

//metodo de impresion
void ListaDCarreras::print(){
   if (isVoid()){
        cout << "la lista esta vacia";
    }
    else{
        NodoDCarreras *aux = head;
        do{
            cout << aux->codCarrera << ", " << aux->nombre << endl;
            aux = aux->next;
        }while(aux != head);
    }

}

//imprime la direccion de memoria de el head y el siguiente.
void ListaDCarreras::direccionDeMemoria(){
    cout << "Direccion de head es: " << head << " y la del segundo elemento es: " << head->next << endl;
}


//metodo que carga los datos en memmoria
void ListaDCarreras::cargarDatos(){
    string archivoAbrir = "Carreras.txt";
    fstream archivo(archivoAbrir.c_str());
    string linea;
    if (!archivo.is_open()){
        cout << "abrio el archivo" << endl;
        archivo.open(archivoAbrir.c_str(), ios::in);
    }
    while(getline(archivo, linea)){
        string codigo = getCodCarrera(linea);
        string nombre = getNombreCarrera(linea);
        if (!carreraInLista(codigo)){
            insertAtTail(nombre, codigo);
            cargarDatosCursos();
        }
    }

}

void ListaDCarreras::cargarDatosCursos(){
    NodoDCarreras *aux = head;
    do{
        if(aux->next == head){
            aux->cursos->cargarDatos(aux->codCarrera);
        }
        aux = aux->next;
    }while (aux != head);
}

string ListaDCarreras::getCodCarrera(string linea){
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result = "";
    for(int i = 0; i < 2; i++){
        result.push_back(frase[i]);
    }
    return result;
}

string ListaDCarreras::getNombreCarrera(string linea){
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result = "";
    for(int i = 0; i < strlen(linea.c_str()); i++){
        if (cont != 0 ){
            result.push_back(frase[i]);
        }
        else if (frase[i] == ';'){
            cont = 1;
        }
    }
    return result;
}

//metodo que verifica si una carrera esta en la lista
bool ListaDCarreras::carreraInLista(string pCodCarrera){
    if(isVoid()){
        return false;
    }
    else{
        NodoDCarreras *aux = head;
        do{
            if(aux->codCarrera == pCodCarrera){
                return true;
            }
            aux = aux->next;
        }while(aux != head);
        return false;
    }
}

//imprime toda la estructura
void ListaDCarreras::printAll(){
    if(head == NULL){
        cout << "-" << endl;
    }
    else{
        NodoDCarreras *aux = head;
        do{
            cout << aux->codCarrera << ", " << aux->nombre << endl;
            aux->cursos->printAll();
            aux = aux->next;
        }while(aux != head);
    }
}

NodoDCarreras *ListaDCarreras::getPosition(int pos){
    if(!isVoid()){
        int cont = 0;
        NodoDCarreras *aux = head;
        do{
            if(cont == pos){
                return aux;
            }
            cont++;
            aux = aux->next;
        }while(aux != head);
    }
}
