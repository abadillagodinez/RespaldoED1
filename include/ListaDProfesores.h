#ifndef LISTADPROFESORES_H
#define LISTADPROFESORES_H
#include <iostream>
#include "NodoDProfesores.h"
#include <fstream>
#include "string.h"
#include <sstream>


using namespace std;
class ListaDProfesores
{
    public:
        ListaDProfesores();
        virtual ~ListaDProfesores();
        bool isVoid();
        void insertAtHead(string pCodProfesor, string pCodCarrera, int pCategoria, string pNombre);
        void insertAtPos(int pos, string pCodProfesor, string pCodCarrera, int pCategoria, string pNombre);
        void insertAtTail(string pCodProfesor, string pCodCarrera, int pCategoria, string pNombre);
        void deleteAtHead();
        void deleteAtPos(int pos);
        void deleteAtTail();
        void print();
        void cargarDatos();

    protected:

    private:
        string getCodProfe(string linea);
        string getCodCarrera(string linea);
        int getCategoria(string linea);
        string getNombre(string linea);
        bool isProfesorInLista(string pCodProf);
        NodoDProfesores *head;
        int length;
    friend class ListaDGrupos;
    friend class ListaDMesas;
};

#endif // LISTADPROFESORES_H
