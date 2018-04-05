#include "NodoDCarreras.h"

//template <typename E>
NodoDCarreras::NodoDCarreras()
{
    nombre = "";
    codCarrera = "";
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoDCarreras::NodoDCarreras(string pNombre, string pCod){
    nombre = pNombre;
    codCarrera = pCod;
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoDCarreras::~NodoDCarreras()
{
    //dtor
}
