#include <iostream>
#include <sstream>
#include "NodoDMesas.h"
#include "ListaDCarreras.h"
#include "ListaDEstCurs.h"
#include "ListaDEstudiante.h"
#include "ListaDProfesores.h"
#include "ColaDeAtencion.h"
#include <fstream>
#include <time.h>
#include <ctime>
#include <math.h>
#include <chrono>
#include <unistd.h>

using namespace std;
using namespace std::chrono;

//template <typename E>
class ListaDMesas
{
    public:
        ListaDMesas();
        virtual ~ListaDMesas();
        bool isVoid();
        void insertAtHead(int pNewElement);
        void insertAtPos(int pos, int pNewElement);
        void insertAtTail(int pNewElement);
        void deleteAtHead();
        void deleteAtPos(int pos);
        void deleteAtTail();
        void print();
        void cargaEstructura();
        void MenuReportes();
        int getCantidadDeAtenciones();
        void ejecutarAcciones();


    protected:

    private:
        void reporteCarreras();
        void reporteCursosDeUnaCarrera();
        void reporteProfesores();
        void reporteProfesoresDeUnCurso();
        void reporteProfesoresDeUnCursoAux(NodoDCursos *curso, string nombreCarrera);
        void reporteEstudiantesDeUnGrupo();
        void reporteEstudiantesDeUnGrupoAux(NodoDCursos *curso, string nombreCarrera);
        void reporteEstudiantesDeUnaCarrera();
        void reporteEstudiantesDeUnaCarreraAux(NodoDCarreras *carrera);
        void reporteProfesoresServicio();
        void reporteProfesoresDeUnaCarrera();
        void reporteProfesoresDeUnaCarreraAux(NodoDCarreras *carrera);
        void reporteContador();

        NodoDMesas *head;
        int length;
        ListaDCarreras *carreras = new ListaDCarreras();
        ListaDProfesores *profesores = new ListaDProfesores();
        ListaDEstudiante *estudiantes = new ListaDEstudiante();
        ColaDeAtencion *atencion = new ColaDeAtencion();
};
