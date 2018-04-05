#include <iostream>
#include <unistd.h>
#include "ListaDMesas.h"
#include "ColaDeAtencion.h"
#include "NodoDAtencion.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int main(int args,char* argv[])
{
    ListaDMesas *mesas = new ListaDMesas();
    mesas->insertAtTail(1);
    mesas->insertAtTail(2);
    mesas->insertAtTail(3);
    mesas->cargaEstructura();
    mesas->ejecutarAcciones();
    mesas->MenuReportes();
}

