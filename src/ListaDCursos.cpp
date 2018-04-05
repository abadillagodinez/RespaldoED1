#include "ListaDCursos.h"
ListaDCursos::ListaDCursos()
{
    head = NULL;
    length = 0;
}

//destructor

ListaDCursos::~ListaDCursos()
{
    NodoDCursos *aux;

   while(head) {
      aux = head;
      head = head->next;
      delete aux;
   }
}

//metodo para verificar si esta vacia

bool ListaDCursos::isVoid(){
    return (head == NULL);
}

////metodo para insertar al inicio

void ListaDCursos::insertAtHead(string pNombre, string pCodCurso, string pCodCarrera){
    NodoDCursos *newNode = new NodoDCursos(pNombre, pCodCurso, pCodCarrera);
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
void ListaDCursos::insertAtPos(int pos, string pNombre, string pCodCurso, string pCodCarrera){
    if (isVoid() || pos <= 0){
        insertAtHead(pNombre, pCodCurso, pCodCarrera);
    }
    else if(pos > length-1){
        insertAtTail(pNombre, pCodCurso, pCodCarrera);
    }
    else{
        NodoDCursos *newNode = new NodoDCursos(pNombre, pCodCurso, pCodCarrera);
        NodoDCursos *aux = head;
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
void ListaDCursos::insertAtTail(string pNombre, string pCodCurso, string pCodCarrera){
    NodoDCursos *newNode = new NodoDCursos(pNombre, pCodCurso, pCodCarrera);
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
void ListaDCursos::deleteAtHead(){
    if(isVoid()){
        cout << "La lista ya está vacía" << endl;
    }
    else if(head->next == head){
        NodoDCursos *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDCursos *aux = head;
        NodoDCursos *temp = head;
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
void ListaDCursos::deleteAtPos(int pos){
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
        NodoDCursos *aux = head;
        while(i < pos){
            aux = aux->next;
            i++;
        }
        NodoDCursos *temp = aux->next;
        aux->next = aux->next->next;
        aux->next->previous = aux;
        delete temp;
        length--;
    }
}

//metodo de eliminacion al final
void ListaDCursos::deleteAtTail(){
    if(isVoid()){
        cout << "La lista está vacía" << endl;
    }
    else if(head->next == head){
        NodoDCursos *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDCursos *aux = head;
        while (aux->next->next != head)
            aux = aux->next;
        NodoDCursos *temp = aux->next;
        aux->next = head;
        head->previous = aux;
        delete temp;
        length--;
    }

}

//metodo de impresion
void ListaDCursos::print(){
   if (isVoid()){
        cout << "la lista esta vacia";
    }
    else{
        NodoDCursos *aux = head;
        do{
            cout << aux->codCarrera << ", " << aux->codCurso << ", " << aux->nombre << endl;
            aux = aux->next;
        }while(aux != head);
    }
    cout << endl;

}


//metodo para cargar los cursos
void ListaDCursos::cargarDatos(string pCodCarrera){
    string archivoAbrir = "Cursos.txt";
    fstream archivo(archivoAbrir.c_str());
    string linea;
    if (!archivo.is_open()){
        cout << "abrio el archivo" << endl;
        archivo.open(archivoAbrir.c_str(), ios::in);
    }
    while(getline(archivo, linea)){
        string codigo = getCodCarrera(linea);
        if (codigo == pCodCarrera){
            string codigoCurso = getCodCurso(linea);
            string nombre = getNombreCurso(linea);
            if (!cursoInLista(codigoCurso)){
                insertAtTail(nombre, codigoCurso, codigo);
                cargarDatosGrupos();
            }
        }
    }
}

//metodo que carga los datos de los grupo
void ListaDCursos::cargarDatosGrupos(){
    NodoDCursos *aux = head;
    do{
        if(aux->next == head){
            aux->grupos->cargarDatos(aux->codCurso, aux->codCarrera);
        }
        aux = aux->next;
    }while (aux != head);
}


//metodo que retorna el codigo de la carrera
string ListaDCursos::getCodCarrera(string linea){
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result = "";
    for(int i = 0; i < 2; i++){
        result.push_back(frase[i]);
    }
    return result;
}

//metodo que retorna el codigo del curso
string ListaDCursos::getCodCurso(string linea){
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result = "";
    for (int i = 3; i < 6; i++){
        result.push_back(frase[i]);
    }
    return result;
}

//metodo que retorna el nombre del curso
string ListaDCursos::getNombreCurso(string linea){
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result = "";
    for(int i = 0; i < strlen(linea.c_str()); i++){
        if (cont == 2 ){
            result.push_back(frase[i]);
        }
        else if (frase[i] == ';'){
            cont++;
        }
    }
    return result;
}


//metodo que verifica que no haya un curso repetido
bool ListaDCursos::cursoInLista(string pCodCurso){
    if(isVoid()){
        return false;
    }
    else{
        NodoDCursos *aux = head;
        do{
            if(aux->codCurso == pCodCurso){
                return true;
            }
            aux = aux->next;
        }while(aux != head);
        return false;
    }
}

//metodo de impresion total
void ListaDCursos::printAll(){
    if(head == NULL){
        cout << "\t" << "--" << endl;
    }
    else{
        NodoDCursos *aux = head;
        do{
            cout << "\t" << aux->codCurso << ", " << aux->nombre << endl;
            aux->grupos->printAll();
            aux = aux->next;
        }while(aux != head);
    }
}


//METODO QUE RETORNA LA DIRECCION DE MEMORIA DE UN CURSO SEGUN SU POSICION
NodoDCursos *ListaDCursos::getPosicion(int pos){
    if(!isVoid()){
        NodoDCursos *aux = head;
        int cont = 0;
        do{
            if(cont == pos){
                return aux;
            }
            cont++;
            aux = aux->next;
        }while(aux != head);
    }
}
