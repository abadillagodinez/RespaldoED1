#include "ListaDMesas.h"
//metodos de la clase

//constructor

ListaDMesas::ListaDMesas()
{
    head = NULL;
    length = 0;
}

//destructor

ListaDMesas::~ListaDMesas()
{
    NodoDMesas *aux;

   while(head) {
      aux = head;
      head = head->next;
      delete aux;
   }
}

//metodo para verificar si esta vacia

bool ListaDMesas::isVoid(){
    return (head == NULL);
}

////metodo para insertar al inicio

void ListaDMesas::insertAtHead(int pNewElement){
    NodoDMesas *newNode = new NodoDMesas(pNewElement);
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
void ListaDMesas::insertAtPos(int pos, int pNewElement){
    if (isVoid() || pos <= 0){
        insertAtHead(pNewElement);
    }
    else if(pos > length-1){
        insertAtTail(pNewElement);
    }
    else{
        NodoDMesas *newNode = new NodoDMesas(pNewElement);
        NodoDMesas *aux = head;
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
void ListaDMesas::insertAtTail(int pNewElement){
    NodoDMesas *newNode = new NodoDMesas(pNewElement);
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
void ListaDMesas::deleteAtHead(){
    if(isVoid()){
        cout << "La lista ya está vacía" << endl;
    }
    else if(head->next == head){
        NodoDMesas *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDMesas *aux = head;
        NodoDMesas *temp = head;
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
void ListaDMesas::deleteAtPos(int pos){
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
        NodoDMesas *aux = head;
        while(i < pos){
            aux = aux->next;
            i++;
        }
        NodoDMesas *temp = aux->next;
        aux->next = aux->next->next;
        aux->next->previous = aux;
        delete temp;
        length--;
    }
}

//metodo de eliminacion al final
void ListaDMesas::deleteAtTail(){
    if(isVoid()){
        cout << "La lista está vacía" << endl;
    }
    else if(head->next == head){
        NodoDMesas *temp = head;
        head = NULL;
        delete temp;
        length--;
    }
    else{
        NodoDMesas *aux = head;
        while (aux->next->next != head)
            aux = aux->next;
        NodoDMesas *temp = aux->next;
        aux->next = head;
        head->previous = aux;
        delete temp;
        length--;
    }

}

//metodo de impresion
void ListaDMesas::print(){
   if (isVoid()){
        cout << "la lista esta vacia" << endl;
    }
    else{
        NodoDMesas *aux = head;
        do{
            cout << aux->id<< endl;
            aux = aux->next;
        }while(aux != head);
    }
    cout << endl;
}

void ListaDMesas::cargaEstructura(){
    profesores->cargarDatos();
    cout << "Cargo la lista de profesores..." << endl;
    estudiantes->cargarDatos();
    cout << "Cargo la lista de estudiantes..." << endl;
    carreras->cargarDatos();
    cout << "Cargo la estructura..." << endl;
    atencion->cargarDatos();
    cout << "Cargo los primeros 10 en la cola de atencion..." << endl;
}

//METODO PARA IMPRESION DEL MENU DE REPORTES
void ListaDMesas::MenuReportes(){
    cout << "BIENVENIDO AL MENU DE REPORTES " << endl << endl;
    cout << "A. Carreras" << endl << "B. Cursos de una carrera" << endl << "C. Profesores" << endl << "D. Profesores de un curso" << endl
    << "E. Estudiantes de un grupo" << endl << "F. Estudiantes de una carrera" << endl << "G. Profesores de servicio" << endl
    << "H. Profesores de una carrera" << endl << "I. Cantidad de personas atendidas por mostrador" << endl << "J. Mostrar estructura" << endl<< "K. Salir" << endl;
    char op;
    cout << "Elija una opcion: ";
    cin >> op;
    cout << endl;
    switch(op){
        case 'A':
            reporteCarreras();
            MenuReportes();
        case 'B':
            reporteCursosDeUnaCarrera();
            MenuReportes();
        case 'C':
            reporteProfesores();
            MenuReportes();
        case 'D':
            if(profesores->isVoid()){
                cout << "La lista de profesores es vacia, no se puede generar el reporte" << endl;
            }
            else{
                reporteProfesoresDeUnCurso();
                MenuReportes();
            }
        case 'E':
            reporteEstudiantesDeUnGrupo();
            MenuReportes();
        case 'F':
            reporteEstudiantesDeUnaCarrera();
            MenuReportes();;
        case 'G':
            reporteProfesoresServicio();
            MenuReportes();;
        case 'H':
            reporteProfesoresDeUnaCarrera();
            MenuReportes();;
        case 'I':
            reporteContador();
            MenuReportes();
        case 'J':
            carreras->printAll();
            MenuReportes();
        default:
            break;
    }
}

//****METODOS PARA LOS REPORTES****
//#1
void ListaDMesas::reporteCarreras(){
    if(carreras->isVoid()){
        cout << "La lista de carreras esta vacia, no se puede generar el reporte" << endl;
    }
    else{
        NodoDCarreras *aux = carreras->head;
        string result = "Carreras:\n\n";
        do{
            result += aux->codCarrera + ", " + aux->nombre + "\n";
            aux = aux->next;
        }while(aux != carreras->head);

        string archivoAbrir = "Reportes/Carreras.txt";
        ofstream archivo(archivoAbrir.c_str());
        if (archivo.is_open()){
            archivo.clear();
            archivo << result;
            archivo.close();
        }
        cout << endl;
        cout << result << endl;
    }
}

//#2
void ListaDMesas::reporteCursosDeUnaCarrera(){
    //codigo para imprimir la lista de carreras
    NodoDCarreras *aux = carreras->head;
    int i = 1;
    do{
        cout << i << ". " << aux->nombre << endl;
        i++;
        aux = aux->next;
    }while(aux != carreras->head);
    cout << "Por favor, indique de cual carrera quiere ver los cursos: ";
    int pos;
    cin >> pos; cout << endl;
    int cont = 0;
    string result = "";
    //codigo para recorrer la lista de cursos
    do{
        if(cont == pos-1){
            if(aux->cursos->isVoid()){
                cout << "No se puede generar reporte, esta carrera no posee cursos" << endl;
                string archivoAbrir = "Reportes/CursosDeUnaCarrera.txt";
                ofstream archivo(archivoAbrir.c_str());
                if (archivo.is_open()){
                    archivo.clear();
                    archivo.close();
                }
            }
            else{
                result +="Cursos de " + aux->nombre + "\n";
                result +=  "Codigo de curso          Nombre\n";
                NodoDCursos *auxCur = aux->cursos->head;
                do{
                    result += "    " + auxCur->codCurso + "              " + auxCur->nombre + "\n";
                    auxCur = auxCur->next;
                }while(auxCur != aux->cursos->head);
            }
            break;
        }
        cont++;
        aux = aux->next;
    }while(aux != carreras->head);

    //codigo para guardar el reporte

    string archivoAbrir = "Reportes/CursosDeUnaCarrera.txt";
        ofstream archivo(archivoAbrir.c_str());
        if (archivo.is_open()){
            archivo.clear();
            archivo << result;
            archivo.close();
        }
        cout << result << endl;
}

//#3
void ListaDMesas::reporteProfesores(){
    if(profesores->isVoid()){
        cout << "La lista de profesores esta vacia, no se puede generar el reporte" << endl;
        string archivoAbrir = "Reportes/Profesores.txt";
                ofstream archivo(archivoAbrir.c_str());
                if (archivo.is_open()){
                    archivo.clear();
                    archivo.close();
                }
    }
    else{
        NodoDProfesores *aux = profesores->head;
        string result = "Codigo    Carrera      Categoria            Nombre\n";
        do{
            stringstream ss;
            string categoria;
            ss << aux->categoria;
            ss >> categoria;
            result += "  " + aux->codProfesor + "       " +aux->codCarrera + "\t" + "\t "  + categoria + "\t    " + aux->nombre + "\n";
            aux = aux->next;
        }while(aux != profesores->head);

        string archivoAbrir = "Reportes/Profesores.txt";
        ofstream archivo(archivoAbrir.c_str());
        if (archivo.is_open()){
            archivo.clear();
            archivo << result;
            archivo.close();
        }
        cout << result << endl;
    }
}

//#4
void ListaDMesas::reporteProfesoresDeUnCurso(){
    //codigo para imprimir la lista de carreras
    NodoDCarreras *aux = carreras->head;
    int i = 1;
    do{
        cout << i << ". " << aux->nombre << endl;
        i++;
        aux = aux->next;
    }while(aux != carreras->head);
    cout << "Por favor, indique de cual carrera quiere ver los cursos: ";
    int pos;
    cin >> pos; cout << endl;
    int cont = 0;
    //codigo para recorrer la lista de cursos
    do{
        if(cont == pos-1){
            if(aux->cursos->isVoid()){
                cout << "No se puede generar reporte, esta carrera no posee cursos" << endl;
                string archivoAbrir = "Reportes/ProfesoresDeUnCurso.txt";
                ofstream archivo(archivoAbrir.c_str());
                if (archivo.is_open()){
                    archivo.clear();
                    archivo.close();
                }
            }
            else{
                NodoDCursos *auxCur = aux->cursos->head;
                int j = 1;
                do{
                    cout << j << ". " << auxCur->nombre << endl;
                    j++;
                    auxCur = auxCur->next;
                }while(auxCur != aux->cursos->head);
                cout << "Por favor, indique de cual curso quiere ver los profesores: ";
                int pos2;
                cin >> pos2; cout << endl;
                NodoDCursos *curso = aux->cursos->getPosicion(pos2-1);
                reporteProfesoresDeUnCursoAux(curso, aux->nombre);
            }
            break;
        }
        cont++;
        aux = aux->next;
    }while(aux != carreras->head);
}

void ListaDMesas::reporteProfesoresDeUnCursoAux(NodoDCursos *curso, string nombreCarrera){
    if(curso->grupos->isVoid()){
        cout << "No se puede generar el reporte, este curso no tiene grupos" << endl << endl;
        string archivoAbrir = "Reportes/ProfesoresDeUnCurso.txt";
        ofstream archivo(archivoAbrir.c_str());
        if (archivo.is_open()){
            archivo.clear();
            archivo.close();
        }
    }
    else{
        NodoDGrupos *aux = curso->grupos->head;
        string result = "Profesores del curso " + curso->nombre + "\nde la carrera de " + nombreCarrera + "\n\n";
        result += "Codigo         Nombre\n";
        do{
            NodoDProfesores *auxProf = profesores->head;
            do{
                if(aux->codProfesor == auxProf->codProfesor){
                    result += "  " + auxProf->codProfesor + "        " + auxProf->nombre + "\n";
                }
                auxProf = auxProf->next;
            }while(auxProf != profesores->head);
            aux = aux->next;
        }while(aux != curso->grupos->head);
        string archivoAbrir = "Reportes/ProfesoresDeUnCurso.txt";
        ofstream archivo(archivoAbrir.c_str());
        if (archivo.is_open()){
            archivo.clear();
            archivo << result;
            archivo.close();
        }
        cout << result << endl;
    }
}

//#5
void ListaDMesas::reporteEstudiantesDeUnGrupo(){
    NodoDCarreras *aux = carreras->head;
    int i = 1;
    do{
        cout << i << ". " << aux->nombre << endl;
        i++;
        aux = aux->next;
    }while(aux != carreras->head);
    cout << "Por favor, indique de cual carrera quiere ver los cursos: ";
    int pos;
    cin >> pos; cout << endl;
    int cont = 0;
    //codigo para recorrer la lista de cursos
    do{
        if(cont == pos-1){
            if(aux->cursos->isVoid()){
                cout << "No se puede generar reporte, esta carrera no posee cursos" << endl;
                string archivoAbrir = "Reportes/EstudiantesDeUnGrupo.txt";
                ofstream archivo(archivoAbrir.c_str());
                if (archivo.is_open()){
                    archivo.clear();
                    archivo.close();
                }
            }
            else{
                NodoDCursos *auxCur = aux->cursos->head;
                int j = 1;
                do{
                    cout << j << ". " << auxCur->nombre << endl;
                    j++;
                    auxCur = auxCur->next;
                }while(auxCur != aux->cursos->head);
                cout << "Por favor, indique de cual curso quiere ver los grupos: ";
                int pos2;
                cin >> pos2; cout << endl;
                NodoDCursos *curso = aux->cursos->getPosicion(pos2-1);
                reporteEstudiantesDeUnGrupoAux(curso, aux->nombre);
            }
        }
        cont++;
        aux = aux->next;
    }while(aux != carreras->head);
}

void ListaDMesas::reporteEstudiantesDeUnGrupoAux(NodoDCursos *curso, string nombreCarrera){
    if(curso->grupos->isVoid()){
        cout << "No se puede generar el reporte, este curso no posee grupos" << endl << endl;
        string archivoAbrir = "Reportes/EstudiantesDeUnGrupo.txt";
        ofstream archivo(archivoAbrir.c_str());
        if (archivo.is_open()){
            archivo.clear();
            archivo.close();
        }
    }
    else{
        NodoDGrupos *aux = curso->grupos->head ;
        int i = 1;
        do{
            cout << i << ". Grupo " << aux->codGrupo << endl;
            i++;
            aux = aux->next;
        }while(aux != curso->grupos->head);
        cout << "Por favor, indique de cual grupo quiere ver los estudiantes: ";
        int pos;
        cin >> pos;
        NodoDGrupos *actual = curso->grupos->getPosicion(pos-1);
        string result = "Estos son los estudiantes del grupo " + actual->codGrupo + "\n" + "del curso " + curso->nombre + "\n" + "de la carrera " + nombreCarrera + "\n\n";
        if(actual->estudiantes->isVoid()){
            cout << "No hay estudiantes en ese grupo" << endl << endl;
            string archivoAbrir = "Reportes/EstudiantesDeUnGrupo.txt";
            ofstream archivo(archivoAbrir.c_str());
            if (archivo.is_open()){
                archivo.clear();
                archivo.close();
            }
        }
        else{
            NodoDEstCurs *auxEst = actual->estudiantes->head;
            do{
                stringstream ss;
                string id;
                ss << auxEst->idEstudiante;
                ss >> id;
                result += "ID: " + id + "\n" + estudiantes->direccionYTelefono(auxEst->idEstudiante);
                auxEst = auxEst->next;
            }while(auxEst != actual->estudiantes->head);
        }
        string archivoAbrir = "Reportes/EstudiantesDeUnGrupo.txt";
        ofstream archivo(archivoAbrir.c_str());
        if (archivo.is_open()){
            archivo.clear();
            archivo << result;
            archivo.close();
        }
        cout << result << endl;
    }


}

//#6
void ListaDMesas::reporteEstudiantesDeUnaCarrera(){
    NodoDCarreras *aux = carreras->head;
    int i = 1;
    do{
        cout << i << ". " << aux->nombre << endl;
        i++;
        aux = aux->next;
    }while(aux != carreras->head);
    cout << "Por favor, indique de cual carrera quiere ver los cursos: ";
    int pos;
    cin >> pos; cout << endl;
    NodoDCarreras *actual = carreras->getPosition(pos-1);
    reporteEstudiantesDeUnaCarreraAux(actual);
}

void ListaDMesas::reporteEstudiantesDeUnaCarreraAux(NodoDCarreras *carrera){
    if(!estudiantes->isVoid()){
        NodoDEstudiante *aux = estudiantes->head;
        string result = "Estudiantes de la carrera " + carrera->nombre + "\n\n";
        do{
            if(aux->codCarrera == carrera->codCarrera){
                stringstream ss;
                string id;
                ss << aux->identificacion;
                ss >> id;
                result += "ID: " + id + "\n" + estudiantes->direccionYTelefono(aux->identificacion);
            }
            aux = aux->next;
        }while(aux != estudiantes->head);
        string archivoAbrir = "Reportes/EstudiantesDeUnaCarrera.txt";
        ofstream archivo(archivoAbrir.c_str());
        if (archivo.is_open()){
            archivo.clear();
            archivo << result;
            archivo.close();
        }
        cout << result << endl;
    }
}

//#7
void ListaDMesas::reporteProfesoresServicio(){
    if(profesores->isVoid()){
        cout << "La lista de profesores esta vacia, no se puede generar el reporte" << endl;
        string archivoAbrir = "Reportes/ProfesoresDeServicio.txt";
        ofstream archivo(archivoAbrir.c_str());
        if (archivo.is_open()){
            archivo.clear();
            archivo.close();
        }
    }
    else{
        NodoDProfesores *aux = profesores->head;
        string result = "Codigo    Carrera         Nombre\n";
        do{
            if(aux->categoria == 1){
                result += "  " + aux->codProfesor + "       " +aux->codCarrera +  "\t    " + aux->nombre + "\n";
            }
            aux = aux->next;
        }while(aux != profesores->head);

        string archivoAbrir = "Reportes/ProfesoresDeServicio.txt";
        ofstream archivo(archivoAbrir.c_str());
        if (archivo.is_open()){
            archivo.clear();
            archivo << result;
            archivo.close();
        }
        cout << result << endl;
    }
}

//#8
void ListaDMesas::reporteProfesoresDeUnaCarrera(){
    NodoDCarreras *aux = carreras->head;
    int i = 1;
    do{
        cout << i << ". " << aux->nombre << endl;
        i++;
        aux = aux->next;
    }while(aux != carreras->head);
    cout << "Por favor, indique de cual carrera quiere ver los cursos: ";
    int pos;
    cin >> pos; cout << endl;
    NodoDCarreras *actual = carreras->getPosition(pos-1);
    reporteProfesoresDeUnaCarreraAux(actual);
}

void ListaDMesas::reporteProfesoresDeUnaCarreraAux(NodoDCarreras *carrera){
    if(!profesores->isVoid()){
        NodoDProfesores *aux = profesores->head;
        string result = "Profesores de la carrera " + carrera->nombre + "\n\n";
        do{
            if(aux->codCarrera == carrera->codCarrera){
                result += "Codigo: " + aux->codProfesor + "\nNombre: " + aux->nombre + "\n\n";
            }
            aux = aux->next;
        }while(aux != profesores->head);
        string archivoAbrir = "Reportes/ProfesoresDeUnaCarrera.txt";
        ofstream archivo(archivoAbrir.c_str());
        if (archivo.is_open()){
            archivo.clear();
            archivo << result;
            archivo.close();
        }
        cout << result << endl;
    }
}

//#9
void ListaDMesas::reporteContador(){
    NodoDMesas *aux = head;
    string result = "";

    do{
        stringstream s1, s2 ;
        string identificador;
        string contador;
        s1 << aux->id;
        s1 >> identificador;
        s2 << aux->contador;
        s2 >> contador;
        result += "Mostrador " + identificador + ": " + contador + "\n";
        aux = aux->next;
    }while(aux != head);
    string archivoAbrir = "Reportes/AtendidosPorMostrador.txt";
    ofstream archivo(archivoAbrir.c_str());
    if (archivo.is_open()){
        archivo.clear();
        archivo << result;
        archivo.close();
    }
    cout << result << endl;
}

//metodo que genera todas las acciones
void ListaDMesas::ejecutarAcciones(){
    //cin.get();
    int atendidos = 0;
    while (atendidos < getCantidadDeAtenciones()){
        clock_t startTime = clock(); //Start timer
        double secondsPassed;
        double secondsToDelay = 2078;
        bool flag = true;
        while(flag){
            secondsPassed = (clock() - startTime) / CLOCKS_PER_SEC;
            if(!atencion->colaVacia()){
                NodoDAtencion *actual = atencion->popElement();
                head->accion(carreras, actual->idEstudiante, actual->codCurso, actual->codGrupo, actual->accion);
                atendidos = head->contador + head->next->contador + head->next->next->contador;
            }
            if(secondsPassed >= secondsToDelay){
                flag = false;
                cout << "Atendiendo, espere.." << endl;
                cout << "han pasado " << secondsPassed << endl;
            }
        }
        atencion->cargarDatos();
    }
    //cout << atendidos << endl;
}

int ListaDMesas::getCantidadDeAtenciones(){
    string archivoAbrir = "Atencion.txt";
    fstream archivo(archivoAbrir.c_str());
    string linea;
    if (!archivo.is_open()){
        cout << "abrio el archivo" << endl;
        archivo.open(archivoAbrir.c_str(), ios::in);
    }
    int i = 0;
    while(getline(archivo, linea)){
        i++;
    }
    return i;
}
