#include "NodoDCursos.h"


NodoDCursos::NodoDCursos()
{
    nombre = "";
    codCurso = "";
    codCarrera = "";
    next = NULL;
    previous = NULL;
}


NodoDCursos::NodoDCursos(string pNombre, string pCodCurso, string pCodCarrera){
    nombre = pNombre;
    codCurso = pCodCurso;
    codCarrera = pCodCarrera;
    next = NULL;
    previous = NULL;
}


NodoDCursos::~NodoDCursos()
{
    //dtor
}
