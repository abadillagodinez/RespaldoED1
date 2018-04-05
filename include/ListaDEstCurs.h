#ifndef LISTADESTCURS_H
#define LISTADESTCURS_H
#include <iostream>
#include "NodoDEstCurs.h"
#include <fstream>
#include "string.h"
#include <sstream>
#include "ListaDEstudiante.h"
class NodoDGrupos;


using namespace std;
class ListaDEstCurs
{
    public:
        ListaDEstCurs();
        virtual ~ListaDEstCurs();
        bool isVoid();
        void insertAtHead(int id, string pCodCurso, string pCodGrupo);
        void insertAtPos(int pos, int id, string pCodCurso, string pCodGrupo);
        void insertAtTail(int id, string pCodCurso, string pCodGrupo);
        void deleteAtHead();
        void deleteAtPos(int pos);
        void deleteAtTail();
        void print();
        void cargarDatos(string pCodCarrera, string pCodCurso, string pCodGrupo, NodoDGrupos *headDeLista);

    protected:

    private:
        bool isEstudianteInCarrera(int id, ListaDEstudiante *estudiantes);
        bool isInOtroGrupo(int id, string pCodCurso, string pCodGrupo, NodoDGrupos *head);
        bool isEstudianteInLista(int id, string pCodCurso, string pCodGrupo);
        NodoDGrupos* getGrupoActual(string pCodGrupo, NodoDGrupos *headDeLista);
        string getCodCurso(string linea);
        string getCodGrupo(string linea);
        int getIdentificacion(string lineal);
        NodoDEstCurs *head;
        int length;
    friend class NodoDMesas;
    friend class ListaDMesas;
};

#endif // LISTADESTCURS_H
