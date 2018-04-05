#include "ListaDProfesores.h"

//metodos de la clase

//constructor

ListaDProfesores::ListaDProfesores()
{
    head = NULL;
    length = 0;
}

//destructor

ListaDProfesores::~ListaDProfesores()
{
    NodoDProfesores *aux;

   while(head) {
      aux = head;
      head = head->next;
      delete aux;
   }
}

//metodo para verificar si esta vacia

bool ListaDProfesores::isVoid(){
    return (head == NULL);
}

////metodo para insertar al inicio

void ListaDProfesores::insertAtHead(string pCodProfesor, string pCodCarrera, int pCategoria, string pNombre){
    NodoDProfesores *newNode = new NodoDProfesores(pCodProfesor, pCodCarrera, pCategoria, pNombre);
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
void ListaDProfesores::insertAtPos(int pos, string pCodProfesor, string pCodCarrera, int pCategoria, string pNombre){
    if (isVoid() || pos <= 0){
        insertAtHead(pCodProfesor, pCodCarrera, pCategoria, pNombre);
    }
    else if(pos > length-1){
        insertAtTail(pCodProfesor, pCodCarrera, pCategoria, pNombre);
    }
    else{
        NodoDProfesores *newNode = new NodoDProfesores(pCodProfesor, pCodCarrera, pCategoria, pNombre);
        NodoDProfesores *aux = head;
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
void ListaDProfesores::insertAtTail(string pCodProfesor, string pCodCarrera, int pCategoria, string pNombre){
    NodoDProfesores *newNode = new NodoDProfesores(pCodProfesor, pCodCarrera, pCategoria, pNombre);
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
void ListaDProfesores::deleteAtHead(){
    if(isVoid()){
        cout << "La lista ya está vacía" << endl;
    }
    else if(head->next == head){
        NodoDProfesores *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDProfesores *aux = head;
        NodoDProfesores *temp = head;
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
void ListaDProfesores::deleteAtPos(int pos){
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
        NodoDProfesores *aux = head;
        while(i < pos){
            aux = aux->next;
            i++;
        }
        NodoDProfesores *temp = aux->next;
        aux->next = aux->next->next;
        aux->next->previous = aux;
        delete temp;
        length--;
    }
}

//metodo de eliminacion al final
void ListaDProfesores::deleteAtTail(){
    if(isVoid()){
        cout << "La lista está vacía" << endl;
    }
    else if(head->next == head){
        NodoDProfesores *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDProfesores *aux = head;
        while (aux->next->next != head)
            aux = aux->next;
        NodoDProfesores *temp = aux->next;
        aux->next = head;
        head->previous = aux;
        delete temp;
        length--;
    }

}

//metodo de impresion
void ListaDProfesores::print(){
   if (isVoid()){
        cout << "la lista esta vacia";
    }
    else{
        NodoDProfesores *aux = head;
        do{
            cout << aux->codProfesor << ", " << aux->codCarrera << ", " << aux->categoria << ", " << aux->nombre << endl;;
            aux = aux->next;
        }while(aux != head);
    }
    cout << endl;
}

//metodo de carga de datos
void ListaDProfesores::cargarDatos(){
    string archivoAbrir = "Profesores.txt";
    fstream archivo(archivoAbrir.c_str());
    string linea;
    if (!archivo.is_open()){
        cout << "abrio el archivo" << endl;
        archivo.open(archivoAbrir.c_str(), ios::in);
    }
    while(getline(archivo, linea)){
        string codProf = getCodProfe(linea);
        string codCarr = getCodCarrera(linea);
        int catego = getCategoria(linea);
        string nombre = getNombre(linea);
        if(!isProfesorInLista(codProf)){
            insertAtTail(codProf, codCarr, catego, nombre);
        }
    }
}

//codCarrera
string ListaDProfesores::getCodCarrera(string linea){
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

//codProfesor
string ListaDProfesores::getCodProfe(string linea){
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result = "";
    for(int i = 0; i < strlen(linea.c_str()); i++){
        if(cont > 0){
            break;
        }
        else if (frase[i] == ';'){
            cont++;
        }
        else if (cont == 0){
            result.push_back(frase[i]);
        }
    }
    return result;
}

//Categoria
int ListaDProfesores::getCategoria(string linea){
    stringstream ss;
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result1 = "";
    int result2 = 0;
    for(int i = 0; i < strlen(linea.c_str()); i++){
        if(cont > 2){
            break;
        }
        else if (frase[i] == ';'){
            cont++;
        }
        else if (cont == 2){
            result1.push_back(frase[i]);
        }
    }
    ss << result1;
    ss >> result2;
    return result2;
}

//nombre
string ListaDProfesores::getNombre(string linea){
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result = "";
    for(int i = 0; i < strlen(linea.c_str()); i++){
        if(cont > 3){
            break;
        }
        else if (frase[i] == ';'){
            cont++;
        }
        else if (cont == 3){
            result.push_back(frase[i]);
        }
    }
    return result;
}

//metodo de validacion para no repetir profesores
bool ListaDProfesores::isProfesorInLista(string pCodeProf){
    if (isVoid()){
        return false;
    }
    else{
        NodoDProfesores *aux = head;
        do{
            if(aux->codProfesor == pCodeProf){
                return true;
            }
            aux = aux->next;
        }while(aux != head);
    return false;
    }
}
