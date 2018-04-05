#include "NodoDProfesores.h"

NodoDProfesores::NodoDProfesores()
{
    codProfesor = "";
    codCarrera = "";
    categoria = 0;
    nombre = "";
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoDProfesores::NodoDProfesores(string pCodProfesor, string pCodCarrera, int pCategoria, string pNombre){
    codProfesor = pCodProfesor;
    codCarrera = pCodCarrera;
    categoria = pCategoria;
    nombre = pNombre;
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoDProfesores::~NodoDProfesores()
{
    //dtor
}
