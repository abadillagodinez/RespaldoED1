#include "ListaDEstudiante.h"
//metodos de la clase

//constructor

ListaDEstudiante::ListaDEstudiante()
{
    head = NULL;
    length = 0;
}

//destructor

ListaDEstudiante::~ListaDEstudiante()
{
    NodoDEstudiante *aux;

   while(head) {
      aux = head;
      head = head->next;
      delete aux;
   }
}

//metodo para verificar si esta vacia

bool ListaDEstudiante::isVoid(){
    return (head == NULL);
}

////metodo para insertar al inicio

void ListaDEstudiante::insertAtHead(int id, string pCodCarrera, string pNombre, string pDireccion, int pTelefono){
    NodoDEstudiante *newNode = new NodoDEstudiante(id, pCodCarrera, pNombre, pDireccion, pTelefono);
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
void ListaDEstudiante::insertAtPos(int pos, int id, string pCodCarrera, string pNombre, string pDireccion, int pTelefono){
    if (isVoid() || pos <= 0){
        insertAtHead(id, pCodCarrera, pNombre, pDireccion, pTelefono);
    }
    else if(pos > length-1){
        insertAtTail(id, pCodCarrera, pNombre, pDireccion, pTelefono);
    }
    else{
        NodoDEstudiante *newNode = new NodoDEstudiante(id, pCodCarrera, pNombre, pDireccion, pTelefono);
        NodoDEstudiante *aux = head;
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
void ListaDEstudiante::insertAtTail(int id, string pCodCarrera, string pNombre, string pDireccion, int pTelefono){
    NodoDEstudiante *newNode = new NodoDEstudiante(id, pCodCarrera, pNombre, pDireccion, pTelefono);
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
void ListaDEstudiante::deleteAtHead(){
    if(isVoid()){
        cout << "La lista ya está vacía" << endl;
    }
    else if(head->next == head){
        NodoDEstudiante *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDEstudiante *aux = head;
        NodoDEstudiante *temp = head;
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
void ListaDEstudiante::deleteAtPos(int pos){
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
        NodoDEstudiante *aux = head;
        while(i < pos){
            aux = aux->next;
            i++;
        }
        NodoDEstudiante *temp = aux->next;
        aux->next = aux->next->next;
        aux->next->previous = aux;
        delete temp;
        length--;
    }
}

//metodo de eliminacion al final
void ListaDEstudiante::deleteAtTail(){
    if(isVoid()){
        cout << "La lista está vacía" << endl;
    }
    else if(head->next == head){
        NodoDEstudiante *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDEstudiante *aux = head;
        while (aux->next->next != head)
            aux = aux->next;
        NodoDEstudiante *temp = aux->next;
        aux->next = head;
        head->previous = aux;
        delete temp;
        length--;
    }

}

//metodo de impresion
void ListaDEstudiante::print(){
   if (isVoid()){
        cout << "la lista esta vacia";
    }
    else{
        NodoDEstudiante *aux = head;
        do{
            cout << aux->identificacion << ", " << aux->codCarrera << ", " << aux->nombre << ", " << aux->direccion << ", " << aux->telefono << endl;
            aux = aux->next;
        }while(aux != head);
    }
    cout << endl;
}

//cargar dato
void ListaDEstudiante::cargarDatos(){
    string archivoAbrir = "Estudiantes.txt";
    fstream archivo(archivoAbrir.c_str());
    string linea;
    if (!archivo.is_open()){
        cout << "abrio el archivo" << endl;
        archivo.open(archivoAbrir.c_str(), ios::in);
    }
    while(getline(archivo, linea)){
        int id = getIdentificacion(linea);
        string nombre = getNombre(linea);
        string carrera = getCodCarrera(linea);
        string direccion = getDireccion(linea);
        int telefono = getTelefono(linea);
        if (!isEstudianteInLista(id, carrera, nombre)){
            insertAtTail(id, carrera, nombre, direccion, telefono);
        }
    }
    //print();
}


//METODOS DE OBTENCION
//metodo de obtencion de identificacion
int ListaDEstudiante::getIdentificacion(string linea){
    stringstream ss;
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result1 = "";
    int result2 = 0;
    for(int i = 0; i < strlen(linea.c_str()); i++){
        if (frase[i] != ';'){
            result1.push_back(frase[i]);
        }
        else{
            break;
        }
    }
    ss << result1;
    ss >> result2;
    return result2;
}

//telefono
int ListaDEstudiante::getTelefono(string linea){
    stringstream ss;
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result1 = "";
    int result2 = 0;
    for(int i = 0; i < strlen(linea.c_str()); i++){
        if(cont > 4){
            break;
        }
        else if (frase[i] == ';'){
            cont++;
        }
        else if (cont == 4){
            result1.push_back(frase[i]);
        }
    }
    ss << result1;
    ss >> result2;
    return result2;
}

//codCarrera
string ListaDEstudiante::getCodCarrera(string linea){
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

//nombre
string ListaDEstudiante::getNombre(string linea){
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

//direccion
string ListaDEstudiante::getDireccion(string linea){
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


//validacion
bool ListaDEstudiante::isEstudianteInLista(int id, string carrera, string nombre){
    if (isVoid()){
        return false;
    }
    else{
        NodoDEstudiante *aux = head;
        do{
            if(aux->identificacion == id && (aux->codCarrera == carrera || aux->nombre == nombre)){
                return true;
            }
            aux = aux->next;
        }while(aux != head);
        return false;
    }
}

//validacion de un estudiante en una carrera
string ListaDEstudiante::getCarreraPorEstudiante(int id, string carrera){
    string result = "";
    if (isVoid()){
        return result;
    }
    else{
        NodoDEstudiante *aux = head;
        do{
            if(aux->identificacion == id && aux->codCarrera == carrera){
                result = aux->codCarrera;
                break;
            }
            aux = aux->next;
        }while(aux != head);
        return result;
    }
}

string ListaDEstudiante::direccionYTelefono(int id){
    string result ="";
    if(isVoid()){
        cout << "La lista de estudiantes esta vacia" << endl;
    }
    else{
        NodoDEstudiante *aux = head;
        do{
            if(aux->identificacion == id){
                stringstream ss;
                string telefono;
                ss << aux->telefono;
                ss >> telefono;
                result += "Nombre: " + aux->nombre + "\nDireccion: " + aux->direccion + "\nTelefono: " + telefono + "\n\n";
                break;
            }
            aux = aux->next;
        }while(aux != head);
        return result;
    }
}
