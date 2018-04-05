#ifndef NODODPROFESORES_H
#define NODODPROFESORES_H
#include <iostream>


using namespace std;
class NodoDProfesores
{
    public:
        NodoDProfesores();
        NodoDProfesores(string pCodProfesor, string pCodCarrera, int pCategoria, string pNombre);
        virtual ~NodoDProfesores();

    protected:

    private:
        string codProfesor;
        string codCarrera;
        int categoria; // 1 si es de cursos generales, o 2 si es de cursos de carrera
        string nombre;
        NodoDProfesores *previous;
        NodoDProfesores *next;

    friend class ListaDProfesores;
    friend class ListaDGrupos;
    friend class ListaDMesas;
};

#endif // NODODPROFESORES_H
