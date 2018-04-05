#include <iostream>
using namespace std;


class NodoD
{
    public:
        NodoD();
        NodoD(int pVal);
        virtual ~NodoD();

    protected:

    private:
        int value;
        NodoD *previous;
        NodoD *next;

    friend class ListaCircularDoble;
};
