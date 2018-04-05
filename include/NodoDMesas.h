#include <iostream>
#include <stdlib.h>
#include "ListaDEstudiante.h"
#include "ListaDProfesores.h"
#include "ListaDCarreras.h"

using namespace std;


class NodoDMesas
{
    public:
        NodoDMesas();
        NodoDMesas(int pID);
        virtual ~NodoDMesas();
        void accion(ListaDCarreras *carreras, int idAMatricular, string cursoAMatricular, string grupoAMatricular, int accionARealizar);

    protected:

    private:
        string getCodCarreraAccion(int idAMatricular);
        void recorrer_carreras(ListaDCarreras *carreras, int idAMatricular, string cursoAMatricular, string grupoAMatricular, string carreraAMatricular, int accionARealizar);
        void recorrer_cursos(ListaDCursos *cursos,  int idAMatricular, string cursoAMatricular, string grupoAMatricular, string carreraAMatricular,int accionARealizar);
        void recorrer_grupos(ListaDGrupos *grupos, NodoDCursos *cursoActual, int idAMatricular, string cursoAMatricular, string grupoAMatricular, int accionARealizar);
        void matricular(ListaDEstCurs *estudCurs, NodoDGrupos *grupoActual, NodoDCursos *cursoActual, int idAMatricular, string cursoAMatricular, string grupoAMatricular);
        bool isEstudianteInOtroGrupo(int idAMatricular, string cursoAMatricular, string grupoAMatricular, NodoDGrupos *head);
        int posDeEstudiante(ListaDEstCurs *estCurs, int idABuscar);
        void desmatricular(ListaDEstCurs *estudCurs, NodoDGrupos *grupoActual, int idADesmatricular);
        void congelar(ListaDEstCurs *estudCurs, NodoDGrupos *grupoActual, int idADesmatricular);
        int id;       //identificador de la mesa
        int contador; //lleva la cantidad de atendidos
        bool estatus; //true si esta ocupado, false si no
        NodoDMesas *previous;
        NodoDMesas *next;

    friend class ListaDMesas;
};
