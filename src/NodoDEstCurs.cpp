#include "NodoDEstCurs.h"

NodoDEstCurs::NodoDEstCurs()
{
    idEstudiante = 0;
    codCurso = "";
    codGrupo = "";
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoDEstCurs::NodoDEstCurs(int id, string pCodCurso, string pCodGrupo){
    idEstudiante = id;
    codCurso = pCodCurso;
    codGrupo = pCodGrupo;
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoDEstCurs::~NodoDEstCurs()
{
    //dtor
}
