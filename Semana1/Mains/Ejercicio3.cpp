#include "Cuenta.h"

using namespace System;

void Ventana()
{
    Console::SetWindowSize(70, 30);
}

void MostrarMenu()
{
    cout << "\t\t\tAPP BANCO BCP\n";
    cout << "\t\t===============================\n";
    cout << "\t\t[1] Crear una cuenta\n";
    cout << "\t\t[2] Ingresar una cantidad\n";
    cout << "\t\t[3] Retirar una cantidad\n";
    cout << "\t\t[4] Mostrar datos de la cuenta\n";
    cout << "\t\t[5] Salir\n";
}

int main()
{
    Cuenta* cuenta = nullptr;
    int opc = 0;
    string titular;
    double cantidad;

    Ventana();

    do
    {
        MostrarMenu();
        cout << "\t\tIngrese una opcion: "; cin >> opc;
        system("cls");

        switch (opc)
        {
        case 1:
            system("cls");
            cout << "Ingrese nombre del titular: ";
            cin.ignore();
            getline(cin, titular);
            cout << "Ingrese una cantidad inicial (opcional): "; cin >> cantidad;
            cuenta = new Cuenta(titular, cantidad);
            cout << "\nCuenta creada con exito!!\n";
            system("pause>0");
            break;
        case 2:
            system("cls");
            if (cuenta != nullptr)
            {
                cout << "Ingrese una cantidad a ingresar: "; cin >> cantidad;
                cuenta->Ingresar(cantidad);
                if (cantidad >= 0)
                {
                    cout << "\nCantidad ingresada con exito!!\n";
                }
            }
            else
            {
                cout << "Primero cree una cuenta\n";
            }
            system("pause>0");
            break;
        case 3:
            system("cls");
            if (cuenta != nullptr)
            {
                cout << "Ingrese una cantidad a retirar: "; cin >> cantidad;
                cuenta->Retirar(cantidad);
                if (cantidad >= 0)
                {
                    cout << "\nCantidad retirada con exito!!\n";
                }
            }
            else
            {
                cout << "Primero cree una cuenta\n";
            }
            system("pause>0");
            break;
        case 4:
            system("cls");
            if (cuenta != nullptr)
            {
                cout << "Titular: " << cuenta->getTitular() << endl;
                cout << "Ingresos Totales: " << cuenta->getCantidad() << endl;
            }
            else
            {
                cout << "Primero cree una cuenta\n";
            }
            system("pause>0");
            break;
        case 5:
            cout << "Saliendo del aplicativo. Esperamos tenga o halla tenido un buen dia!!\n";
            system("pause>0");
            delete cuenta;
            break;
        default:
            cout << "Opcion Invalida!" << endl;
        }
        system("cls");
    } while (opc != 5);

    return 0;
}
