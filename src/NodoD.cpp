#include "NodoD.h"

//template <typename E>
NodoD::NodoD()
{
    value = NULL;
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoD::NodoD(int pVal){
    value = pVal;
    next = NULL;
    previous = NULL;
}

//template <typename E>
NodoD::~NodoD()
{
    //dtor
}
