#include "ControladoraContacto.h"

using namespace System;

void Ventana()
{
    Console::SetWindowSize(75, 40);
}

void MostrarMenu()
{
    cout << "\t\t\tCONTACTO\n";
    cout << "\t=============================================\n";
    cout << "\t1. Registrar Contactos\n";
    cout << "\t2. Modificar Datos Contactos\n";
    cout << "\t3. Eliminar Contactos\n";
    cout << "\t4. Reporte Contactos\n";
    cout << "\t5. Reporte Contactos Cumplen Mayo\n";
    cout << "\t6. Reporte Contactos Varones\n";
    cout << "\t7. Reporte Contactos Facebook y WhatsApp\n";
    cout << "\t8. Salir\n";
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
            controladora->RegistroContactos();
            cout << "\nSE INGRESO CON EXITO LOS DATOS DEL CONTACTO!!" << endl;
            system("pause>0");
            break;
        case 2:
            system("cls");
            if (!controladora->existenContactos())
            {
                cout << "NO HAY CONTACTOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN CONTACTO." << endl;
            }
            else
            {
                controladora->ModificarDatosContactos();
            }
            system("pause>0");
            break;
        case 3:
            system("cls");
            if (!controladora->existenContactos())
            {
                cout << "NO HAY CONTACTOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN CONTACTO." << endl;
            }
            else
            {
                controladora->EliminarContactos();
            }
            system("pause>0");
            break;
        case 4:
            system("cls");
            if (!controladora->existenContactos())
            {
                cout << "NO HAY CONTACTOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN CONTACTO." << endl;
            }
            else
            {
                controladora->ReporteTodosContactos();
            }
            system("pause>0");
            break;
        case 5:
            system("cls");
            if (!controladora->existenContactos())
            {
                cout << "NO HAY CONTACTOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN CONTACTO." << endl;
            }
            else
            {
                controladora->ReporteContactosCumplenMayo();
            }
            system("pause>0");
            break;
        case 6:
            system("cls");
            if (!controladora->existenContactos())
            {
                cout << "NO HAY CONTACTOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN CONTACTO." << endl;
            }
            else
            {
                controladora->ReporteContactosVarones();
            }
            system("pause>0");
            break;
        case 7:
            system("cls");
            if (!controladora->existenContactos())
            {
                cout << "NO HAY CONTACTOS REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN CONTACTO." << endl;
            }
            else
            {
                controladora->ReporteContactosFacebookWhatsApp();
            }
            system("pause>0");
            break;
        case 8:
            delete controladora;
            break;
        default:
            cout << "Opcion Invalida!" << endl;
        }
        system("cls");
    } while (opcion != 8);

    return 0;
}
