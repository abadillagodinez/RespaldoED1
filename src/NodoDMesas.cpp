#include "NodoDMesas.h"

//template <typename E>
NodoDMesas::NodoDMesas()
{
    id = 0;
    estatus = false;
    contador = 0;
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoDMesas::NodoDMesas(int pID){
    id = pID;
    estatus = false;
    contador = 0;
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoDMesas::~NodoDMesas()
{
    //dtor
}

//METODO DE ACCION
void NodoDMesas::accion(ListaDCarreras *carreras, int idAMatricular, string cursoAMatricular, string grupoAMatricular, int accionARealizar){
    string codCarreraActual = getCodCarreraAccion(idAMatricular);
    if(!carreras->carreraInLista(codCarreraActual)){
        //cout << "   No se puede matricular a " << idAMatricular << " porque no existe la carrera con código: " << codCarreraActual << endl;
    }
    else{
        recorrer_carreras(carreras, idAMatricular, cursoAMatricular, grupoAMatricular, codCarreraActual, accionARealizar);
    }
    srand (time(NULL));
    int aMostrador = rand() % 3 + 1;
    if(aMostrador == 1){
        contador++;
    }
    else if(aMostrador == 2){
        next->contador++;
    }
    else if(aMostrador == 3){
        previous->contador++;
    }
}

//metodo que recorre la lista de las carreras hasta que se lo encuenta
void NodoDMesas::recorrer_carreras(ListaDCarreras *carreras, int idAMatricular, string cursoAMatricular, string grupoAMatricular, string carreraAMatricular, int accionARealizar){
    if(carreras->isVoid()){
        //cout << "   La lista de carreras esta vacía" << endl;
    }
    else{
        NodoDCarreras *aux = carreras->head;
        do{
            if(aux->codCarrera == carreraAMatricular){
                recorrer_cursos(aux->cursos,  idAMatricular, cursoAMatricular, grupoAMatricular, carreraAMatricular, accionARealizar);
                break;
            }
            aux = aux->next;
        }while(aux != carreras->head);
    }
}

//metodo que recorre la lista de cursos de una carrera
void NodoDMesas::recorrer_cursos(ListaDCursos *cursos,  int idAMatricular, string cursoAMatricular, string grupoAMatricular, string carreraAMatricular,int accionARealizar){
    if(cursos->isVoid()){
       // cout << "   No hay cursos en la carrera con codigo: " << carreraAMatricular << endl;
    }
    else{
        NodoDCursos *aux = cursos->head;
        do{
            if(aux->codCurso == cursoAMatricular){
                recorrer_grupos(aux->grupos, aux, idAMatricular, cursoAMatricular, grupoAMatricular, accionARealizar);
                break;
            }
            aux = aux->next;
        }while(aux != cursos->head);
    }
}

//metodo que recorre la lista de grupos de un curso y cuando lo encuentra, hace la accion
void NodoDMesas::recorrer_grupos(ListaDGrupos *grupos, NodoDCursos *cursoActual, int idAMatricular, string cursoAMatricular, string grupoAMatricular, int accionARealizar){
    if(grupos->isVoid()){
        //cout << "   No hay grupos en el curso con codigo: " << cursoAMatricular << endl;
    }
    else{
        NodoDGrupos *aux = grupos->head;
        do{
            if(aux->codGrupo == grupoAMatricular){
                if(accionARealizar == 1){
                    matricular(aux->estudiantes, aux, cursoActual, idAMatricular, cursoAMatricular, grupoAMatricular);
                    break;
                }
                else if(accionARealizar == 2){
                    desmatricular(aux->estudiantes, aux, idAMatricular);
                    break;
                }
                else if(accionARealizar == 3){
                    congelar(aux->estudiantes, aux, idAMatricular);
                    break;
                }
                else{
                    //cout << "   Ese codigo de accion no es valido" << endl;
                    break;
                }
            }
            else{
                //cout << "   No existe ese codigo de grupo en el curso: " << cursoAMatricular << endl;
                break;
            }
            aux = aux->next;
        }while(aux != grupos->head);
    }
}

//metodo para matricular
void NodoDMesas::matricular(ListaDEstCurs *estudCurs, NodoDGrupos *grupoActual, NodoDCursos *cursoActual, int idAMatricular, string cursoAMatricular, string grupoAMatricular){
    if(estudCurs->isVoid()){
        if(!grupoActual->isPosibleMatricular()){
                //cout << "   Ya no hay cupo en el grupo " << grupoAMatricular << " del curso " << cursoAMatricular << endl << "o el grupo no existe" << endl;
            }
        else{
            if(isEstudianteInOtroGrupo(idAMatricular, cursoAMatricular, grupoAMatricular, cursoActual->grupos->head)){
                //cout << "   El estudiante con carne: " << idAMatricular << " ya esta matriculado en otro grupo" << endl;
            }
            else{
                estudCurs->insertAtTail(idAMatricular, cursoAMatricular, grupoAMatricular);
                grupoActual->cupoMatriculado++;
                //cout << "   Matriculo" << endl;
            }
        }
    }
    else{
        if(estudCurs->isEstudianteInLista(idAMatricular, cursoAMatricular, grupoAMatricular)){
            //cout << "   Ya esta matriculado en el grupo " << grupoAMatricular << " del curso " << cursoAMatricular << endl;
        }
        else{
            if(!grupoActual->isPosibleMatricular()){
                //cout << "   Ya no hay cupo en el grupo " << grupoAMatricular << " del curso " << cursoAMatricular << endl;
            }
            else{
                if(isEstudianteInOtroGrupo(idAMatricular, cursoAMatricular, grupoAMatricular, cursoActual->grupos->head)){
                    //cout << "   El estudiante con carne: " << idAMatricular << " ya esta matriculado en otro grupo" << endl;
                }
                else{
                    estudCurs->insertAtTail(idAMatricular, cursoAMatricular, grupoAMatricular);
                    grupoActual->cupoMatriculado++;
                    //cout << "   Matriculo" << endl;
                }
            }
        }
    }
}

//metodo que valida que un estudiante no este en otro grupo para poder matricularlo
bool NodoDMesas::isEstudianteInOtroGrupo(int idAMatricular, string cursoAMatricular, string grupoAMatricular, NodoDGrupos *head){
    NodoDGrupos *aux = head;
    do{
        if(!aux->estudiantes->isVoid()){
            NodoDEstCurs *auxEst = aux->estudiantes->head;
            do{
                if(auxEst->idEstudiante == idAMatricular && auxEst->codCurso == cursoAMatricular){
                    return true;
                }
                auxEst = auxEst->next;
            }while(auxEst != aux->estudiantes->head);
            aux = aux->next;
        }
    }while(aux != head);
    return false;
}


//metodo para desmatricular
void NodoDMesas::desmatricular(ListaDEstCurs *estudCurs, NodoDGrupos *grupoActual, int idADesmatricular){
    if(estudCurs->isVoid()){
        //cout << "   La lista de estudiantes del grupo esta vacia" << endl;
    }
    else{
        if(posDeEstudiante(estudCurs, idADesmatricular) == -1){
            //cout << "   El estudiante no se encuentra en la lista" << endl;
        }
        else{
            estudCurs->deleteAtPos(posDeEstudiante(estudCurs, idADesmatricular));
            grupoActual->cupoMatriculado--;
            //cout << "   Desmatriculo" << endl;
        }
    }
}

//metodo que me retorna la poscision de un estudiante en la lista
int NodoDMesas::posDeEstudiante(ListaDEstCurs *estCurs, int idABuscar){
    NodoDEstCurs *aux = estCurs->head;
    int cont = 0;
    do{
        if(aux->idEstudiante == idABuscar){
            return cont;
        }
        aux = aux->next;
        cont++;
    }while(aux != estCurs->head);
    return -1;
}

//metod para congelar
void NodoDMesas::congelar(ListaDEstCurs *estudCurs, NodoDGrupos *grupoActual, int idADesmatricular){
    if(estudCurs->isVoid()){
        //cout << "   La lista de estudiantes del grupo esta vacia" << endl;
    }
    else{
        if(posDeEstudiante(estudCurs, idADesmatricular) == -1){
            //cout << "   El estudiante no se encuentra en la lista del grupo " << grupoActual->codCurso << endl << "de la carrera " << grupoActual->codCarrera << endl;
        }
        else{
            //grupoActual->cupoMatriculado++;
            grupoActual->cupoCongelado++;
            //cout << "   Congelo" << endl;
        }
    }
}

//obtiene el codigo de carrera para cualquiera de las tres acciones
string NodoDMesas::getCodCarreraAccion(int idAMatricular){
    ListaDEstudiante *estudiantes = new ListaDEstudiante();
    estudiantes->cargarDatos();
    NodoDEstudiante *aux = estudiantes->head;
    string result = "";
    do{
        if(aux->identificacion == idAMatricular){
            result = aux->codCarrera;
        }
        aux = aux->next;
    }while(aux != estudiantes->head);
    return result;
}
