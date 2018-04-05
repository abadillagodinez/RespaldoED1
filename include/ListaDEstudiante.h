#ifndef LISTADESTUDIANTE_H
#define LISTADESTUDIANTE_H
#include <iostream>
#include "NodoDEstudiante.h"
#include <fstream>
#include "string.h"
#include <sstream>


using namespace std;
class ListaDEstudiante
{
    public:
        ListaDEstudiante();
        virtual ~ListaDEstudiante();
        bool isVoid();
        void insertAtHead(int id, string pCodCarrera, string pNombre, string pDireccion, int pTelefono);
        void insertAtPos(int pos, int id, string pCodCarrera, string pNombre, string pDireccion, int pTelefono);
        void insertAtTail(int id, string pCodCarrera, string pNombre, string pDireccion, int pTelefono);
        void deleteAtHead();
        void deleteAtPos(int pos);
        void deleteAtTail();
        void print();
        void cargarDatos();
        NodoDEstudiante *head;
        string direccionYTelefono(int id);

    protected:

    private:
        string getCarreraPorEstudiante(int id, string carrera);
        string getNombre(string linea);
        string getCodCarrera(string linea);
        int getIdentificacion(string linea);
        int getTelefono(string linea);
        string getDireccion(string linea);
        bool isEstudianteInLista(int id, string carrera, string nombre);
        int length;
    friend class ListaDEstCurs;
};

#endif // LISTADESTUDIANTE_H
