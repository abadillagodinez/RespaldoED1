#include "ListaDEstCurs.h"
#include "NodoDGrupos.h"
//metodos de la clase

//constructor

ListaDEstCurs::ListaDEstCurs()
{
    head = NULL;
    length = 0;
}

//destructor

ListaDEstCurs::~ListaDEstCurs()
{
    NodoDEstCurs *aux;

   while(head) {
      aux = head;
      head = head->next;
      delete aux;
   }
}

//metodo para verificar si esta vacia

bool ListaDEstCurs::isVoid(){
    return (head == NULL);
}

////metodo para insertar al inicio

void ListaDEstCurs::insertAtHead(int id, string pCodCurso, string pCodGrupo){
    NodoDEstCurs *newNode = new NodoDEstCurs(id, pCodCurso, pCodGrupo);
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
void ListaDEstCurs::insertAtPos(int pos, int id, string pCodCurso, string pCodGrupo){
    if (isVoid() || pos <= 0){
        insertAtHead(id, pCodCurso, pCodGrupo);
    }
    else if(pos > length-1){
        insertAtTail(id, pCodCurso, pCodGrupo);
    }
    else{
        NodoDEstCurs *newNode = new NodoDEstCurs(id, pCodCurso, pCodGrupo);
        NodoDEstCurs *aux = head;
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
void ListaDEstCurs::insertAtTail(int id, string pCodCurso, string pCodGrupo){
    NodoDEstCurs *newNode = new NodoDEstCurs(id, pCodCurso, pCodGrupo);
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
void ListaDEstCurs::deleteAtHead(){
    if(isVoid()){
        cout << "La lista ya está vacía" << endl;
    }
    else if(head->next == head){
        NodoDEstCurs *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDEstCurs *aux = head;
        NodoDEstCurs *temp = head;
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
void ListaDEstCurs::deleteAtPos(int pos){
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
        NodoDEstCurs *aux = head;
        while(i < pos){
            aux = aux->next;
            i++;
        }
        NodoDEstCurs *temp = aux->next;
        aux->next = aux->next->next;
        aux->next->previous = aux;
        delete temp;
        length--;
    }
}

//metodo de eliminacion al final
void ListaDEstCurs::deleteAtTail(){
    if(isVoid()){
        cout << "La lista está vacía" << endl;
    }
    else if(head->next == head){
        NodoDEstCurs *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDEstCurs *aux = head;
        while (aux->next->next != head)
            aux = aux->next;
        NodoDEstCurs *temp = aux->next;
        aux->next = head;
        head->previous = aux;
        delete temp;
        length--;
    }

}

//metodo de impresion
void ListaDEstCurs::print(){
   if (isVoid()){
        cout << "\t" << "\t" << "\t" << "----";
    }
    else{
        NodoDEstCurs *aux = head;
        do{
            cout << "\t" << "\t" << "\t" << aux->idEstudiante << ", " << aux->codCurso << ", " << aux->codGrupo << endl;
            aux = aux->next;

        }while(aux != head);
    }
    cout << endl;

}


//metodo de carga de datos
void ListaDEstCurs::cargarDatos(string pCodCarrera, string pCodCurso, string pCodGrupo, NodoDGrupos *headDeLista){
    ListaDEstudiante *estudiantes = new ListaDEstudiante();
    estudiantes->cargarDatos();
    string archivoAbrir = "Estudiante-Curso.txt";
    fstream archivo(archivoAbrir.c_str());
    string linea;
    if (!archivo.is_open()){
        cout << "abrio el archivo" << endl;
        archivo.open(archivoAbrir.c_str(), ios::in);
    }
    while(getline(archivo, linea)){
        int id = getIdentificacion(linea);
        string curso = getCodCurso(linea);
        string grupo = getCodGrupo(linea);
        string carrera = estudiantes->getCarreraPorEstudiante(id, pCodCarrera);
        if(carrera == pCodCarrera && curso == pCodCurso && grupo == pCodGrupo){
            if(!isEstudianteInLista(id, curso, grupo) && !isInOtroGrupo(id, curso, grupo, headDeLista)){
                NodoDGrupos *nodoGrupo = getGrupoActual(grupo, headDeLista);
                if(nodoGrupo != NULL){
                    if(nodoGrupo->isPosibleMatricular()){
                        insertAtTail(id, curso, grupo);
                        nodoGrupo->cupoMatriculado++;
                    }
                }
            }
        }
    }
}


NodoDGrupos* ListaDEstCurs::getGrupoActual(string pCodGrupo, NodoDGrupos *headDeLista){
    if(headDeLista == NULL){
        return NULL;
    }
    else{
        NodoDGrupos *aux = headDeLista;
        do{
            if(aux->codGrupo == pCodGrupo){
                return aux;
            }
            aux = aux->next;
        }while(aux != headDeLista);
    }
}
//metodo que valida que el estudiante no este en otro grupo
bool ListaDEstCurs::isInOtroGrupo(int id, string pCodCurso, string pCodGrupo, NodoDGrupos *head){
    NodoDGrupos *aux = head;
    do{
        if(aux->estudiantes->isEstudianteInLista(id, pCodCurso, pCodGrupo)){
            return true;
        }
        aux = aux->next;
    }while(aux != head);
}


//METODOS DE CARGA DE LA LINEA
//codGrupo
string ListaDEstCurs::getCodGrupo(string linea){
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result = "";
    result.push_back(frase[15]);
    return result;
}

//metodo de obtencion de identificacion
int ListaDEstCurs::getIdentificacion(string linea){
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

//codCurso
string ListaDEstCurs::getCodCurso(string linea){
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

//metodo de verificacion
bool ListaDEstCurs::isEstudianteInLista(int id, string pCodCurso, string pCodGrupo){
    if(isVoid()){
        return false;
    }
    else{
        NodoDEstCurs *aux = head;
        do{
            if(aux->idEstudiante == id && aux->codCurso == pCodCurso){
                return true;
            }
            aux = aux->next;
        }while(aux != head);
        return false;
    }
}
