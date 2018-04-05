#ifndef NODODESTCURS_H
#define NODODESTCURS_H
#include <iostream>


using namespace std;
class NodoDEstCurs
{
    public:
        NodoDEstCurs();
        NodoDEstCurs(int id, string pCodCurso, string pCodGrupo);
        virtual ~NodoDEstCurs();

    protected:

    private:
        int idEstudiante;
        string codCurso;
        string codGrupo;
        NodoDEstCurs *previous;
        NodoDEstCurs *next;
    friend class ListaDEstCurs;
    friend class NodoDMesas;
    friend class ListaDMesas;
};

#endif // NODODESTCURS_H
