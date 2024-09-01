#pragma once
#include "VectorHoteles.h"

class Controladora
{
private:
	VectorHoteles* vectorhoteles;

public:
	Controladora();
	~Controladora();
	void RegistroHoteles();
	void ModificarDatosHoteles();
	void EliminarHoteles();
	void ReporteTodosHoteles();
	void ReporteHotelesDesayuno();
	void MostrarIntegrantes();
	void ReporteHotelesServicioAeropuerto();
	bool existenHoteles();
};

Controladora::Controladora()
{
	vectorhoteles = new VectorHoteles();
}

Controladora::~Controladora()
{
	delete vectorhoteles;
}

void Controladora::RegistroHoteles()
{
	string nombre, ubicacion;
	int estrellas;
	char desayuno, servicio;
	long long telefono;
	cout << "Ingrese nombre: ";
	cin.ignore();
	getline(cin, nombre);
	cout << "Ingrese Ubicacion: ";
	getline(cin, ubicacion);
	do
	{
		cout << "Ingrese el numero de estrellas: "; cin >> estrellas;
	} while (estrellas < 1 || estrellas > 5);
	do
	{
		cout << "¿Entregan Desayuno?: "; cin >> desayuno;
		desayuno = toupper(desayuno);
	} while (desayuno != 'S' && desayuno != 'N');
	do
	{
		cout << "¿Entregan Servicio Aereo?: "; cin >> servicio;
		servicio = toupper(servicio);
	} while (servicio != 'S' && servicio != 'N');
	do
	{
		cout << "Ingrese telefono: "; cin >> telefono;
	} while (telefono < 100000000 || telefono > 999999999);
	Hotel* hotel = new Hotel(nombre, ubicacion, estrellas, desayuno, telefono, servicio);
	vectorhoteles->RegistrarHotel(hotel);
}

void Controladora::ModificarDatosHoteles()
{
	string nombre, ubicacion;
	int estrellas, indice, opcion;
	char desayuno, servicio;
	long long telefono;
	cout << "Ingrese el indice del hotel a modificar: "; cin >> indice;
	if (indice < 0 || indice >= vectorhoteles->getNumHoteles())
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	Hotel* hotel = vectorhoteles->obtenerDatosHotel(indice);

	do
	{
		cout << "Seleccion el atributo a modificar:" << endl;
		cout << "1. Nombre del Hotel" << endl;
		cout << "2. Ubicacion del Hotel" << endl;
		cout << "3. Estrellas" << endl;
		cout << "4. Desayuno" << endl;
		cout << "5. Servicio" << endl;
		cout << "6. Telefono" << endl;
		cout << "0. Terminar modificaciones" << endl;
		cout << "Ingresar Opcion: "; cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case 1:
			system("cls");
			cout << "Ingrese el nuevo nombre del hotel: ";
			cin.ignore();
			getline(cin, nombre);
			hotel->setNombre(nombre);
			system("pause>0");
			break;
		case 2:
			system("cls");
			cout << "Ingrese la nueva ubicacion del hotel: ";
			cin.ignore();
			getline(cin, ubicacion);
			hotel->setUbicacion(ubicacion);
			system("pause>0");
			break;
		case 3:
			system("cls");
			do
			{
				cout << "Ingrese el nuevo numero de estrellas: "; cin >> estrellas;
			} while (estrellas < 1 || estrellas > 5);
			hotel->setEstrellas(estrellas);
			system("pause>0");
			break;
		case 4:
			system("cls");
			do
			{
				cout << "Vuelva a ingresar si ¿Entregan Desayuno?: "; cin >> desayuno;
				desayuno = toupper(desayuno);
			} while (desayuno != 'S' && desayuno != 'N');
			hotel->setDesayuno(desayuno);
			system("pause>0");
			break;
		case 5:
			system("cls");
			do
			{
				cout << "Vuelva a ingresar si ¿Entregan Servicio Aereo?: "; cin >> servicio;
				servicio = toupper(servicio);
			} while (servicio != 'S' && servicio != 'N');
			hotel->setServicio(servicio);
			system("pause>0");
			break;
		case 6:
			system("cls");
			do
			{
				cout << "Ingrese el nuevo telefono: "; cin >> telefono;
			} while (telefono < 100000000 || telefono > 999999999);
			hotel->setTelefono(telefono);
			system("pause>0");
			break;
		case 0:
			break;
		}
		system("cls");
	} while (opcion != 0);
	cout << "SE MODIFICO CON EXITO LOS DATOS DEL CONTACTO!!" << endl;
}

void Controladora::EliminarHoteles()
{
	int indice;
	cout << "Ingrese el indice del hotel a eliminar: "; cin >> indice;
	if (indice < 0 || indice >= vectorhoteles->getNumHoteles())
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;

	}
	vectorhoteles->EliminarHotel(indice);

	cout << "SE ELIMINO CON EXITO EL HOTEL!" << endl;
}

void Controladora::ReporteTodosHoteles()
{
	cout << "\t\t\tREPORTE DE TODOS LOS HOTELES\n\n";
	for (int i = 0; i < vectorhoteles->getNumHoteles(); i++)
	{
		vectorhoteles->obtenerDatosHotel(i)->mostrarHotel();
		cout << endl;
	}
}

void Controladora::ReporteHotelesDesayuno()
{
	bool found = false;
	for (int i = 0; i < vectorhoteles->getNumHoteles(); i++)
	{
		if (vectorhoteles->obtenerDatosHotel(i)->getDesayuno() == 'S')
		{
			if (!found)
			{
				cout << "\t\t\tHOTELES QUE INCLUYEN DESAYUNO\n\n";
				found = true;
			}
			vectorhoteles->obtenerDatosHotel(i)->mostrarHotel();
			cout << endl;
		}
	}
	if (!found)
	{
		cout << "NO HAY HOTELES CON DESAYUNO INCLUIDO!!" << endl;
	}
}

void Controladora::MostrarIntegrantes()
{
	cout << "\t\tINTEGRANTES DEL PROYECTO\n";
	cout << "\t\t========================\n\n";
	cout << "1. Joel Fernando Mora Rivera - U20241B227\n";
	cout << "2. Elias Daniel Ramos Cerdan - U20201A277\n";
}

void Controladora::ReporteHotelesServicioAeropuerto()
{
	bool found = false;
	for (int i = 0; i < vectorhoteles->getNumHoteles(); i++)
	{
		if (vectorhoteles->obtenerDatosHotel(i)->getServicio() == 'S')
		{
			if (!found)
			{
				cout << "\t\t\tHOTELES SERVICIO AEROPUERTO\n\n";
				found = true;
			}
			vectorhoteles->obtenerDatosHotel(i)->mostrarHotel();
			cout << endl;
		}
	}
	if (!found)
	{
		cout << "NO HAY HOTELES CON SERVICIO AEROPUERTO!!" << endl;
	}
}

bool Controladora::existenHoteles()
{
	return vectorhoteles->getNumHoteles() > 0;
}