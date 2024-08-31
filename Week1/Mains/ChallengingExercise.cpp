#include "CodigoAlumnoRaices.h"

using namespace System;

void Ventana()
{
    Console::SetWindowSize(72, 40);
}

int main()
{
    Ventana();
    double a, b, c;

    cout << "Ingrese el coeficiente a: "; cin >> a;
    cout << "Ingrese el coeficiente b: "; cin >> b;
    cout << "Ingrese el coeficiente c: "; cin >> c;
    CodigoAlumnoRaices* codigoalumnoraices = new CodigoAlumnoRaices(a, b, c);

    codigoalumnoraices->calcular();

    delete codigoalumnoraices;

    system("pause>0");
    return 0;
}
