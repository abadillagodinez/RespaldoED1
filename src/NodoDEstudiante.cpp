#include "NodoDEstudiante.h"

NodoDEstudiante::NodoDEstudiante()
{
    identificacion = 0;
    codCarrera = "";
    nombre = "";
    direccion = "";
    telefono = 0;
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoDEstudiante::NodoDEstudiante(int id, string pCodCarrera, string pNombre, string pDireccion, int pTelefono){
    identificacion = id;
    codCarrera = pCodCarrera;
    nombre = pNombre;
    direccion = pDireccion;
    telefono = pTelefono;
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoDEstudiante::~NodoDEstudiante()
{
    //dtor
}
