#include "ControladoraPlato.h"

using namespace System;

void Ventana()
{
    Console::SetWindowSize(72, 40);
}

void MostrarMenu()
{
    cout << "\t\t\tPLATO\n";
    cout << "\t=============================================\n";
    cout << "\t1. Registrar Platos\n";
    cout << "\t2. Modificar Datos Platos\n";
    cout << "\t3. Eliminar Platos\n";
    cout << "\t4. Reporte Platos\n";
    cout << "\t5. Reporte Platos Picantes\n";
    cout << "\t6. Reporte Platos Mas Caros\n";
    cout << "\t7. Salir\n";
}

int main()
{
    Controladora* controladora = new Controladora();
    int opcion;

    Ventana();

    do
    {
        MostrarMenu();
        cout << "\tIngrese Opcion: "; cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            system("cls");
            controladora->RegistroPlatos();
            cout << "\nSE INGRESO CON EXITO LOS DATOS DEL PLATO!!" << endl;
            system("pause>0");
            break;
        case 2:
            system("cls");
            if (!controladora->existenPlatos())
            {
                cout << "NO HAY PLATOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN PLATO." << endl;
            }
            else
            {
                controladora->ModificarDatosPlatos();
            }
            system("pause>0");
            break;
        case 3:
            system("cls");
            if (!controladora->existenPlatos())
            {
                cout << "NO HAY PLATOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN PLATO." << endl;
            }
            else
            {
                controladora->EliminarPlatos();
            }
            system("pause>0");
            break;
        case 4:
            system("cls");
            if (!controladora->existenPlatos())
            {
                cout << "NO HAY PLATOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN PLATO." << endl;
            }
            else
            {
                controladora->ReporteTodosPlatos();
            }
            system("pause>0");
            break;
        case 5:
            system("cls");
            if (!controladora->existenPlatos())
            {
                cout << "NO HAY PLATOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN PLATO." << endl;
            }
            else
            {
                controladora->ReportePlatosPicantes();
            }
            system("pause>0");
            break;
        case 6:
            system("cls");
            if (!controladora->existenPlatos())
            {
                cout << "NO HAY PLATOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN PLATO." << endl;
            }
            else
            {
                controladora->ReportePlatosCaros();
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
