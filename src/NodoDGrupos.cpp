#include "NodoDGrupos.h"

NodoDGrupos::NodoDGrupos()
{
    codCurso = "";
    codCarrera = "";
    codGrupo = "";
    codProfesor = "";
    cupoTotal = 0;
    cupoMatriculado = 0;
    cupoCongelado = 0;
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoDGrupos::NodoDGrupos(string pCodCurso, string pCodCarrera, string pCodGrupo, string pCodProfesor, int pCupoTotal, int pCupoMatri, int pCupoCong){
    codCurso = pCodCurso;
    codCarrera = pCodCarrera;
    codGrupo = pCodGrupo;
    codProfesor = pCodProfesor;
    cupoTotal = pCupoTotal;
    cupoMatriculado = pCupoMatri;
    cupoCongelado = pCupoCong;
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoDGrupos::~NodoDGrupos()
{
    //dtor
}

bool NodoDGrupos::isPosibleMatricular(){
    return cupoMatriculado < cupoTotal;
}
