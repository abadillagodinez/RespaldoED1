#include <iostream>
#include "NodoD.h"

using namespace std;

//template <typename E>
class ListaCircularDoble
{
    public:
        ListaCircularDoble();
        virtual ~ListaCircularDoble();
        bool isVoid();
        void insertAtHead(int pNewElement);
        void insertAtPos(int pos, int pNewElement);
        void insertAtTail(int pNewElement);
        void deleteAtHead();
        void deleteAtPos(int pos);
        void deleteAtTail();
        void print();

    protected:

    private:
        NodoD *head;
        int length;
};
