#include "ListaDGrupos.h"
//metodos de la clase

//constructor

ListaDGrupos::ListaDGrupos()
{
    head = NULL;
    length = 0;
}

//destructor

ListaDGrupos::~ListaDGrupos()
{
    NodoDGrupos *aux;

   while(head) {
      aux = head;
      head = head->next;
      delete aux;
   }
}

//metodo para verificar si esta vacia

bool ListaDGrupos::isVoid(){
    return (head == NULL);
}

////metodo para insertar al inicio

void ListaDGrupos::insertAtHead(string pCodCurso, string pCodCarrera, string pCodGrupo, string pCodProfesor, int pCupoTotal, int pCupoMatri, int pCupoCong){
    NodoDGrupos *newNode = new NodoDGrupos(pCodCurso, pCodCarrera, pCodGrupo, pCodProfesor, pCupoTotal, pCupoMatri, pCupoCong);
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
void ListaDGrupos::insertAtPos(int pos, string pCodCurso, string pCodCarrera, string pCodGrupo, string pCodProfesor, int pCupoTotal, int pCupoMatri, int pCupoCong){
    if (isVoid() || pos <= 0){
        insertAtHead(pCodCurso, pCodCarrera, pCodGrupo, pCodProfesor, pCupoTotal, pCupoMatri, pCupoCong);
    }
    else if(pos > length-1){
        insertAtTail(pCodCurso, pCodCarrera, pCodGrupo, pCodProfesor, pCupoTotal, pCupoMatri, pCupoCong);
    }
    else{
        NodoDGrupos *newNode = new NodoDGrupos(pCodCurso, pCodCarrera, pCodGrupo, pCodProfesor, pCupoTotal, pCupoMatri, pCupoCong);
        NodoDGrupos *aux = head;
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
void ListaDGrupos::insertAtTail(string pCodCurso, string pCodCarrera, string pCodGrupo, string pCodProfesor, int pCupoTotal, int pCupoMatri, int pCupoCong){
    NodoDGrupos *newNode = new NodoDGrupos(pCodCurso, pCodCarrera, pCodGrupo, pCodProfesor, pCupoTotal, pCupoMatri, pCupoCong);
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
void ListaDGrupos::deleteAtHead(){
    if(isVoid()){
        cout << "La lista ya está vacía" << endl;
    }
    else if(head->next == head){
        NodoDGrupos *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDGrupos *aux = head;
        NodoDGrupos *temp = head;
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
void ListaDGrupos::deleteAtPos(int pos){
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
        NodoDGrupos *aux = head;
        while(i < pos){
            aux = aux->next;
            i++;
        }
        NodoDGrupos *temp = aux->next;
        aux->next = aux->next->next;
        aux->next->previous = aux;
        delete temp;
        length--;
    }
}

//metodo de eliminacion al final
void ListaDGrupos::deleteAtTail(){
    if(isVoid()){
        cout << "La lista está vacía" << endl;
    }
    else if(head->next == head){
        NodoDGrupos *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDGrupos *aux = head;
        while (aux->next->next != head)
            aux = aux->next;
        NodoDGrupos *temp = aux->next;
        aux->next = head;
        head->previous = aux;
        delete temp;
        length--;
    }

}

//metodo de impresion
void ListaDGrupos::print(){
   if (isVoid()){
    }
    else{
        NodoDGrupos *aux = head;
        do{
            cout << aux->codCarrera << ", " << aux->codCurso << ", " << aux->codGrupo << ", " << aux->codProfesor << ", " << aux->cupoTotal << ", " << aux->cupoMatriculado << ", " << aux->cupoCongelado << endl;
            aux = aux->next;
        }while(aux != head);
    }
}

//metodo de carga de datos
void ListaDGrupos::cargarDatos(string pCodCurso, string pCodCarrera){
    string archivoAbrir = "Grupos.txt";
    fstream archivo(archivoAbrir.c_str());
    string linea;
    if (!archivo.is_open()){
        cout << "abrio el archivo" << endl;
        archivo.open(archivoAbrir.c_str(), ios::in);
    }
    int cont = 1;
    while(getline(archivo, linea)){
        string codCarrera = getCodCarrera(linea);
        string codCurso = getCodCurso(linea);
        if (codCurso == pCodCurso && codCarrera == pCodCarrera){
            string codGrupo = getCodGrupo(linea);
            string codProfe = getCodProf(linea);
            int cupoTotal = getCupoTotal(linea);
            int cupoMatri = getCupoMatri(linea);
            int cupoCong = getCupoConge(linea);
            if(!grupoIsInLista(codCarrera, codGrupo) && isProfesorInCarrera(codCarrera, codProfe) &&
            !isProfesorInOtroGrupo(codProfe, codGrupo, head)){
                insertAtTail(codCurso, codCarrera, codGrupo, codProfe, cupoTotal, cupoMatri, cupoCong);
                if(head != NULL){
                    cargarDatosEstudiantes();
                }
            }
        }
    }
}

void ListaDGrupos::cargarDatosEstudiantes(){
    NodoDGrupos *aux = head;
    do{
        if(aux->next == head){
            aux->estudiantes->cargarDatos(aux->codCarrera, aux->codCurso, aux->codGrupo, head);
        }
        aux = aux->next;
    }while(aux != head);
}
//METODOS DE RETORNO DE LLAVES
//codCarrera
string ListaDGrupos::getCodCarrera(string linea){
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

//codCurso
string ListaDGrupos::getCodCurso(string linea){
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

//codGrupo
string ListaDGrupos::getCodGrupo(string linea){
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

//codProf
string ListaDGrupos::getCodProf(string linea){
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

//cupoTotal
int ListaDGrupos::getCupoTotal(string linea){
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

//cupoMatri
int ListaDGrupos::getCupoMatri(string linea){
    stringstream ss;
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result1 = "";
    int result2 = 0;
    for(int i = 0; i < strlen(linea.c_str()); i++){
        if(cont > 5){
            break;
        }
        else if (frase[i] == ';'){
            cont++;
        }
        else if (cont == 5){
            result1.push_back(frase[i]);
        }
    }
    ss << result1;
    ss >> result2;
    return result2;
}

//cupoCongelado
int ListaDGrupos::getCupoConge(string linea){
    stringstream ss;
    int cont = 0;
    char frase[1024];
    strcpy(frase, linea.c_str());
    string result1 = "";
    int result2 = 0;
    for(int i = 0; i < strlen(linea.c_str()); i++){
        if(cont > 6){
            break;
        }
        else if (frase[i] == ';'){
            cont++;
        }
        else if (cont == 6){
            result1.push_back(frase[i]);
        }
    }
    ss << result1;
    ss >> result2;
    return result2;
}


//METODO QUE VALIDA QUE DOS GRUPOS SEAN IGUALES
bool ListaDGrupos::grupoIsInLista(string pCodCarrera, string pCodGrupo){
    if(isVoid()){
        return false;
    }
    else{
        NodoDGrupos *aux = head;
        do{
            if(aux->codGrupo == pCodGrupo && aux->codCarrera == pCodCarrera){
                return true;
            }
            aux = aux->next;
        }while(aux != head);
        return false;
    }
}

//METODO QUE VALIDA SI EL PROFESOR SE ENCUENTRA EN LA CARRERA
bool ListaDGrupos::isProfesorInCarrera(string pCodCarrera, string pCodProfesor){
    ListaDProfesores *profesores = new ListaDProfesores();
    profesores->cargarDatos();
    NodoDProfesores *aux = profesores->head;
    do{
        if(pCodProfesor == aux->codProfesor && pCodCarrera == aux->codCarrera){
            return true;
        }
        aux = aux->next;
    }while(aux != profesores->head);
    return false;
}

//VALIDA SI EL PROFESOR SE ENCUENTRA EN OTRO GRUPO
bool ListaDGrupos::isProfesorInOtroGrupo(string pCodProfesor, string pCodGrupoActual, NodoDGrupos *head){
    if(head == NULL){
        return false;
    }
    else{
        NodoDGrupos *aux = head;
        do{
            if(aux->codGrupo != pCodGrupoActual && aux->codProfesor == pCodProfesor){
                return true;
            }
            aux = aux->next;
        }while(aux != head);
        return false;
    }
}

//metodo de impresion total
void ListaDGrupos::printAll(){
    if(head == NULL){
        cout << "\t" << "\t" << "---" << endl;
    }
    else{
        NodoDGrupos *aux = head;
        do{
            cout << "\t"  << "\t" << aux->codGrupo << ", " << aux->codProfesor << ", " << aux->cupoTotal << ", " << aux->cupoMatriculado << ", " << aux->cupoCongelado << endl;
            aux->estudiantes->print();
            aux = aux->next;
        }while(aux != head);
    }
}

//METODO QUE RETORNA LA DIRECCION DE MEMORIA DE UN CURSO SEGUN SU POSICION
NodoDGrupos *ListaDGrupos::getPosicion(int pos){
    if(!isVoid()){
        NodoDGrupos *aux = head;
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
