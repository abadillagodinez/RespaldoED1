#include <iostream>
#include "NodoDAtencion.h"
#include <fstream>
#include "string.h"
#include <sstream>

using namespace std;

class ListaDAtencion
{
    public:
        ListaDAtencion();
        virtual ~ListaDAtencion();
        bool isVoid();
        void insertAtHead(int pIdEstudiante, string pCodCurso, string pCodGrupo, int pAccion);
        void insertAtPos(int pos, int pIdEstudiante, string pCodCurso, string pCodGrupo, int pAccion);
        void insertAtTail(int pIdEstudiante, string pCodCurso, string pCodGrupo, int pAccion);
        void deleteAtHead();
        void deleteAtPos(int pos);
        void deleteAtTail();
        void print();
        void cargarDatos();

    protected:

    private:
        bool atencionInLista(int pIdEstudiante, string pCodCurso, string pCodGrupo, int pAccion);
        int getIdEstudiante(string linea);
        string getCodCurso(string linea);
        string getCodGrupo(string linea);
        int getAccion(string linea);
        NodoDAtencion *head;
        int length;
};
