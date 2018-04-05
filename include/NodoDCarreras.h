#ifndef NodoDCarrerasCARRERAS_H
#define NodoDCarrerasCARRERAS_H
#include <iostream>
#include "ListaDCursos.h"

using namespace std;
class NodoDCarreras
{
   public:
        NodoDCarreras();
        NodoDCarreras(string pNombre, string pCod);
        virtual ~NodoDCarreras();
        NodoDCarreras *getPosition(int pos);

    protected:

    private:
        NodoDCarreras *previous;
        string codCarrera;
        string nombre;
        NodoDCarreras *next;
        ListaDCursos *cursos = new ListaDCursos();

    friend class ListaDCarreras;
    friend class NodoDMesas;
    friend class ListaDMesas;
};

#endif // NodoDCarrerasCARRERAS_H
