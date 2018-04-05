#ifndef NODODGRUPOS_H
#define NODODGRUPOS_H
#include <iostream>
#include "ListaDEstCurs.h"

using namespace std;
class NodoDGrupos
{
    NodoDGrupos();
    NodoDGrupos(string pCodCurso, string pCodCarrera, string pCodGrupo, string pCodProfesor, int pCupoTotal, int pCupoMatri, int pCupoCong);
    virtual ~NodoDGrupos();
    void printEstudiantes();

    protected:

    private:
        string codCarrera;
        string codCurso;
        string codGrupo;
        string codProfesor;
        int cupoTotal;
        int cupoMatriculado;
        int cupoCongelado;
        NodoDGrupos *previous;
        NodoDGrupos *next;
        ListaDEstCurs *estudiantes = new ListaDEstCurs();
        bool isPosibleMatricular();

    friend class ListaDGrupos;
    friend class ListaDCarreras;
    friend class ListaDEstCurs;
    friend class NodoDMesas;
    friend class ListaDMesas;
};

#endif // NODODGRUPOS_H
