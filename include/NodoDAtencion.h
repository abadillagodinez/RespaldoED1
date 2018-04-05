#pragma once
#include <iostream>
using namespace std;


class NodoDAtencion
{
    public:
        NodoDAtencion();
        NodoDAtencion(int pIdEstudiante, string pCodCurso, string pCodGrupo, int pAccion);
        virtual ~NodoDAtencion();

    protected:

    private:
        int idEstudiante;
        string codGrupo;
        string codCurso;
        int accion;
        NodoDAtencion *previous;
        NodoDAtencion *next;

    friend class ListaDAtencion;
    friend class ColaDeAtencion;
    friend class ListaDMesas;
};
