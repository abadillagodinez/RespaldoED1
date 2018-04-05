#ifndef NODODCURSOS_H
#define NODODCURSOS_H
#include <iostream>
#include "ListaDGrupos.h"

using namespace std;
class NodoDCursos
{
    public:
        NodoDCursos();
        NodoDCursos(string pNombre, string pCodCurso, string pCodCarrera);
        virtual ~NodoDCursos();

    protected:

    private:

        NodoDCursos *previous;
        NodoDCursos *next;
        string codCarrera;
        string codCurso;
        string nombre;
        ListaDGrupos *grupos = new ListaDGrupos();

    friend class ListaDCursos;
    friend class ListaDCarreras;
    friend class NodoDMesas;
    friend class ListaDMesas;
};

#endif // NODODCURSOS_H
