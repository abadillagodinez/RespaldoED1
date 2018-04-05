#ifndef LISTADCURSOS_H
#define LISTADCURSOS_H
#include "NodoDCursos.h"
#include <iostream>
#include <fstream>
#include "string.h"

using namespace std;
class ListaDCursos
{
    public:
        ListaDCursos();
        virtual ~ListaDCursos();
        bool isVoid();
        void insertAtHead(string pNombre, string pCodCurso, string pCodCarrera);
        void insertAtPos(int pos, string pNombre, string pCodCurso, string pCodCarrera);
        void insertAtTail(string pNombre, string pCodCurso, string pCodCarrera);
        void deleteAtHead();
        void deleteAtPos(int pos);
        void deleteAtTail();
        void print();
        void printAll();
        void cargarDatos(string pCodCarrera);
        void cargarDatosGrupos();
        NodoDCursos *getPosicion(int pos);

    protected:

    private:
        bool cursoInLista(string pCodCurso);
        string getCodCurso(string linea);
        string getNombreCurso(string linea);
        string getCodCarrera(string linea);
        NodoDCursos *head;
        int length;
        friend class ListaDCarreras;
        friend class NodoDMesas;
        friend class ListaDMesas;
};

#endif // LISTADCURSOS_H
