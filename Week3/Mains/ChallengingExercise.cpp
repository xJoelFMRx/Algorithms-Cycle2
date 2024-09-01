#include "ControladoraHoteles.h"

using namespace System;

void Ventana()
{
	Console::SetWindowSize(75, 40);
}

void MostrarMenu()
{
	cout << "\t\t\tMMENU OPCIONES\n";
	cout << "\t=============================================\n";
	cout << "\t1. Registrar Hoteles\n";
	cout << "\t2. Mostrar Registro de Hoteles\n";
	cout << "\t3. Modificar Hoteles\n";
	cout << "\t4. Eliminar Hoteles\n";
	cout << "\t5. Integrantes del Proyecto\n";
	cout << "\t6. Reporte de Hoteles con Desayuno\n";
	cout << "\t7. Reporte de Hoteles con Servicio Aeropuerto\n";
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
			controladora->RegistroHoteles();
			cout << "\nSE INGRESO CON EXITO LOS DATOS DEL HOTEL!!" << endl;
			system("pause>0");
			break;
		case 2:
			system("cls");
			if (!controladora->existenHoteles())
			{
				cout << "NO HAY HOTELES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN HOTEL." << endl;
			}
			else
			{
				controladora->ReporteTodosHoteles();
			}
			system("pause>0");
			break;
		case 3:
			system("cls");
			if (!controladora->existenHoteles())
			{
				cout << "NO HAY HOTELES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN HOTEL." << endl;
			}
			else
			{
				controladora->ModificarDatosHoteles();
			}
			system("pause>0");
			break;
		case 4:
			system("cls");
			if (!controladora->existenHoteles())
			{
				cout << "NO HAY HOTELES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN HOTEL." << endl;
			}
			else
			{
				controladora->EliminarHoteles();
			}
			system("pause>0");
			break;
		case 5:
			system("cls");
			if (!controladora->existenHoteles())
			{
				cout << "NO HAY HOTELES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN HOTEL." << endl;
			}
			else
			{
				controladora->MostrarIntegrantes();
			}
			system("pause>0");
			break;
		case 6:
			system("cls");
			if (!controladora->existenHoteles())
			{
				cout << "NO HAY HOTELES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN HOTEL." << endl;
			}
			else
			{
				controladora->ReporteHotelesDesayuno();
			}
			system("pause>0");
			break;
		case 7:
			system("cls");
			if (!controladora->existenHoteles())
			{
				cout << "NO HAY HOTELES REGISTRADOS. POR FAVOR REGISTRE LOS DATOS DE UN HOTEL." << endl;
			}
			else
			{
				controladora->ReporteHotelesServicioAeropuerto();
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
