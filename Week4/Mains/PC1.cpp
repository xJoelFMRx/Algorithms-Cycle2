#include "ControladoraConductor.h"

using namespace System;

void Ventana()
{
    Console::SetWindowSize(78, 40);
}

void MostrarMenu()
{
    cout << "\t\t\t\t\tMENU\n";
    cout << "\t\t================================================\n";
    cout << "\t\t1. Agregar Conductor\n";
    cout << "\t\t2. Eliminar Conductor (por DNI)\n";
    cout << "\t\t3. Modificar Conductor (por placa de vehiculo)\n";
    cout << "\t\t4. Mostrar Todos los Conductores\n";
    cout << "\t\t5. Reporte de Conductores Mayores a 50\n";
    cout << "\t\t6. Reporte de Conductores Mujeres\n";
    cout << "\t\t7. Salir\n";
}

int main()
{
    srand(time(nullptr));
    Controladora* controladora = new Controladora();
    int opcion;

    Ventana();

    do
    {
        MostrarMenu();
        cout << "\t\tIngrese opcion: "; cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            system("cls");
            controladora->AgregarConductor();
            cout << "\nSE INGRESO CON EXITO LOS DATOS DEL CONDUCTOR!!\n";
            system("pause>0");
            break;
        case 2:
            system("cls");
            if (!controladora->existenConductores())
            {
                cout << "NO HAY CONDUCTORES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN CONDUCTOR." << endl;
            }
            else
            {
                controladora->EliminarConductor();
            }
            system("pause>0");
            break;
        case 3:
            system("cls");
            if (!controladora->existenConductores())
            {
                cout << "NO HAY CONDUCTORES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN CONDUCTOR." << endl;
            }
            else
            {
                controladora->ModificarConductor();
            }
            system("pause>0");
            break;
        case 4:
            system("cls");
            if (!controladora->existenConductores())
            {
                cout << "NO HAY CONDUCTORES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN CONDUCTOR." << endl;
            }
            else
            {
                controladora->MostrarTodosConductores();
            }
            system("pause>0");
            break;
        case 5:
            system("cls");
            if (!controladora->existenConductores())
            {
                cout << "NO HAY CONDUCTORES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN CONDUCTOR." << endl;
            }
            else
            {
                controladora->MostrarConductoresMayores50();
            }
            system("pause>0");
            break;
        case 6:
            system("cls");
            if (!controladora->existenConductores())
            {
                cout << "NO HAY CONDUCTORES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN CONDUCTOR." << endl;
            }
            else
            {
                controladora->MostrarConductoresMujeres();
            }
            system("pause>0");
            break;
        case 7:
            delete controladora;
            break;
        default:
            cout << "Opcion Invalida!" << endl;
        }
        system("cls");
    } while (opcion != 7);

    return 0;
}
