#ifndef LISTADCARRERAS_H
#define LISTADCARRERAS_H
#include "NodoDCarreras.h"
#include <stdlib.h>
#include <fstream>
#include <string.h>

class ListaDCarreras
{
    public:
        ListaDCarreras();
        virtual ~ListaDCarreras();
        bool isVoid();
        void insertAtHead(string pNombre, string pCode);
        void insertAtPos(int pos, string pNombre, string pCode);
        void insertAtTail(string pNombre, string pCode);
        void deleteAtHead();
        void deleteAtPos(int pos);
        void deleteAtTail();
        void print();
        void printAll();
        void cargarDatos();
        NodoDCarreras *getPosition(int pos);

    protected:

    private:
        string getCodCarrera(string linea);
        string getNombreCarrera(string linea);
        bool carreraInLista(string pCodCarrera);
        void cargarDatosCursos();
        NodoDCarreras *head;
        int length;
        void direccionDeMemoria();
    friend class NodoDMesas;
    friend class ListaDMesas;
};

#endif // LISTADCARRERAS_H
