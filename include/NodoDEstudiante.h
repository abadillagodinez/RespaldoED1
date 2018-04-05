#ifndef NODODESTUDIANTE_H
#define NODODESTUDIANTE_H
#include <iostream>

using namespace std;
class NodoDEstudiante
{
    public:
        NodoDEstudiante();
        NodoDEstudiante(int id, string pCodCarrera, string pNombre, string pDireccion, int pTelefono);
        ~NodoDEstudiante();
        int identificacion;
        string codCarrera;
        string nombre;
        string direccion;
        int telefono;
        NodoDEstudiante *previous;
        NodoDEstudiante *next;

    protected:

    private:
};

#endif // NODODESTUDIANTE_H
