#ifndef LISTADGRUPOS_H
#define LISTADGRUPOS_H
#include <iostream>
#include "NodoDGrupos.h"
#include <fstream>
#include "string.h"
#include <sstream>
#include "ListaDProfesores.h"

using namespace std;
class ListaDGrupos
{
    public:
        ListaDGrupos();
        virtual ~ListaDGrupos();
        bool isVoid();
        void insertAtHead(string pCodCurso, string pCodCarrera, string pCodGrupo, string pCodProfesor, int pCupoTotal, int pCupoMatri, int pCupoCong);
        void insertAtPos(int pos, string pCodCurso, string pCodCarrera, string pCodGrupo, string pCodProfesor, int pCupoTotal, int pCupoMatri, int pCupoCong);
        void insertAtTail(string pCodCurso, string pCodCarrera, string pCodGrupo, string pCodProfesor, int pCupoTotal, int pCupoMatri, int pCupoCong);
        void deleteAtHead();
        void deleteAtPos(int pos);
        void deleteAtTail();
        void print();
        void printAll();
        void cargarDatos(string pCodCurso, string pCodCarrera);
        NodoDGrupos *getPosicion(int pos);

    protected:

    private:
        bool isProfesorInCarrera(string pCodCarrera, string pCodProfesor);
        bool grupoIsInLista(string pCodCarrera, string pCodGrupo);
        bool isProfesorInOtroGrupo(string pCodProfesor, string pCodGrupoActual, NodoDGrupos *head);
        void cargarDatosEstudiantes();
        string getCodCarrera(string linea);
        string getCodCurso(string linea);
        string getCodGrupo(string linea);
        string getCodProf(string linea);
        int getCupoTotal(string linea);
        int getCupoMatri(string linea);
        int getCupoConge(string linea);
        NodoDGrupos *head;
        int length;
    friend class ListaDCarreras;
    friend class NodoDMesas;
    friend class ListaDCursos;
    friend class ListaDMesas;
};

#endif // LISTADGRUPOS_H
