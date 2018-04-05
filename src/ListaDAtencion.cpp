#include "ListaDAtencion.h"
//metodos de la clase

//constructor

ListaDAtencion::ListaDAtencion()
{
    head = NULL;
    length = 0;
}

//destructor

ListaDAtencion::~ListaDAtencion()
{
    NodoDAtencion *aux;

   while(head) {
      aux = head;
      head = head->next;
      delete aux;
   }
}

//metodo para verificar si esta vacia

bool ListaDAtencion::isVoid(){
    return (head == NULL);
}

////metodo para insertar al inicio

void ListaDAtencion::insertAtHead(int pIdEstudiante, string pCodCurso, string pCodGrupo, int pAccion){
    NodoDAtencion *newNode = new NodoDAtencion(pIdEstudiante, pCodCurso, pCodGrupo, pAccion);
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
void ListaDAtencion::insertAtPos(int pos, int pIdEstudiante, string pCodCurso, string pCodGrupo, int pAccion){
    if (isVoid() || pos <= 0){
        insertAtHead(pIdEstudiante, pCodCurso, pCodGrupo, pAccion);
    }
    else if(pos > length-1){
        insertAtTail(pIdEstudiante, pCodCurso, pCodGrupo, pAccion);
    }
    else{
        NodoDAtencion *newNode = new NodoDAtencion(pIdEstudiante, pCodCurso, pCodGrupo, pAccion);
        NodoDAtencion *aux = head;
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
void ListaDAtencion::insertAtTail(int pIdEstudiante, string pCodCurso, string pCodGrupo, int pAccion){
    NodoDAtencion *newNode = new NodoDAtencion(pIdEstudiante, pCodCurso, pCodGrupo, pAccion);
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
void ListaDAtencion::deleteAtHead(){
    if(isVoid()){
        cout << "La lista ya está vacía" << endl;
    }
    else if(head->next == head){
        NodoDAtencion *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDAtencion *aux = head;
        NodoDAtencion *temp = head;
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
void ListaDAtencion::deleteAtPos(int pos){
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
        NodoDAtencion *aux = head;
        while(i < pos){
            aux = aux->next;
            i++;
        }
        NodoDAtencion *temp = aux->next;
        aux->next = aux->next->next;
        aux->next->previous = aux;
        delete temp;
        length--;
    }
}

//metodo de eliminacion al final
void ListaDAtencion::deleteAtTail(){
    if(isVoid()){
        cout << "La lista está vacía" << endl;
    }
    else if(head->next == head){
        NodoDAtencion *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDAtencion *aux = head;
        while (aux->next->next != head)
            aux = aux->next;
        NodoDAtencion *temp = aux->next;
        aux->next = head;
        head->previous = aux;
        delete temp;
        length--;
    }

}

//metodo de impresion
void ListaDAtencion::print(){
   if (isVoid()){
        cout << "la lista esta vacia";
    }
    else{
        NodoDAtencion *aux = head;
        do{
            cout << aux->idEstudiante << ", " << aux->codCurso << ", " << aux->codGrupo << ", " << aux->accion << endl;
            aux = aux->next;
        }while(aux != head);
    }
    cout << endl;
}

//metodo de carga de datos
void ListaDAtencion::cargarDatos(){
    string archivoAbrir = "Atencion.txt";
    fstream archivo(archivoAbrir.c_str());
    string linea;
    if (!archivo.is_open()){
        cout << "abrio el archivo" << endl;
        archivo.open(archivoAbrir.c_str(), ios::in);
    }
    while(getline(archivo, linea)){
        int id = getIdEstudiante(linea);
        string curso = getCodCurso(linea);
        string grupo = getCodGrupo(linea);
        int accion = getAccion(linea);
        if (!atencionInLista(id, curso, grupo, accion)){
            insertAtTail(id, curso,grupo, accion);
        }
    }

}


//metodo de recuperacion del id
int ListaDAtencion::getIdEstudiante(string linea){
    stringstream ss;
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result1 = "";
    int result2 = 0;
    for(int i = 0; i < strlen(linea.c_str()); i++){
        if(cont > 0){
            break;
        }
        else if (frase[i] == ';'){
            cont++;
        }
        else if (cont == 0){
            result1.push_back(frase[i]);
        }
    }
    ss << result1;
    ss >> result2;
    return result2;
}


//metodo de recuperacion del codCurso
string ListaDAtencion::getCodCurso(string linea){
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result = "";
    for(int i = 0; i < strlen(linea.c_str()); i++){
        if(cont > 1){
            break;
        }
        else if (frase[i] == ';'){
            cont++;
        }
        else if (cont == 1){
            result.push_back(frase[i]);
        }
    }
    return result;
}

//metodo de recuperacion del codGrupo
string ListaDAtencion::getCodGrupo(string linea){
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result = "";
    for(int i = 0; i < strlen(linea.c_str()); i++){
        if(cont > 2){
            break;
        }
        else if (frase[i] == ';'){
            cont++;
        }
        else if (cont == 2){
            result.push_back(frase[i]);
        }
    }
    return result;
}

//metodo de recuperacion de la accion
int ListaDAtencion::getAccion(string linea){
    stringstream ss;
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result1 = "";
    int result2 = 0;
    for(int i = 0; i < strlen(linea.c_str()); i++){
        if(cont > 3){
            break;
        }
        else if (frase[i] == ';'){
            cont++;
        }
        else if (cont == 3){
            result1.push_back(frase[i]);
        }
    }
    ss << result1;
    ss >> result2;
    return result2;
}

bool ListaDAtencion::atencionInLista(int pIdEstudiante, string pCodCurso, string pCodGrupo, int pAccion){
    NodoDAtencion *aux = head;
    if (isVoid()){
        return false;
    }
    else{
        do{
            if(aux->idEstudiante == pIdEstudiante && aux->codCurso == pCodCurso && aux->codGrupo == pCodGrupo && aux->accion == pAccion){
                return true;
            }
            aux = aux->next;
        }while(aux != head);
        return false;
    }
}
