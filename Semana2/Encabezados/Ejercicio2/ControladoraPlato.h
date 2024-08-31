#pragma once
#include "VectorPlatos.h"

class Controladora
{
private:
	VectorPlatos* vectorplatos;

public:
	Controladora();
	~Controladora();
	void RegistroPlatos();
	void ModificarDatosPlatos();
	void EliminarPlatos();
	void ReporteTodosPlatos();
	void ReportePlatosPicantes();
	void ReportePlatosCaros();
	bool existenPlatos();
};

Controladora::Controladora()
{
	vectorplatos = new VectorPlatos();
}

Controladora::~Controladora()
{
	delete vectorplatos;
}

void Controladora::RegistroPlatos()
{
	string nombre, ardor;
	int temperatura;
	double calorias, preciopromedio;
	cout << "Ingrese Nombre Plato: ";
	cin.ignore();
	getline(cin, nombre);
	do
	{
		cout << "Ingrese Temperatura: "; cin >> temperatura;
	} while (temperatura < 1 || temperatura > 2);
	cout << "Ingrese Ardor: ";
	cin.ignore();
	getline(cin, ardor);
	do
	{
		cout << "Ingrese Cantidad Calorias: "; cin >> calorias;
	} while (calorias < 100 || calorias > 600);
	do
	{
		cout << "Ingrese Precio Promedio: "; cin >> preciopromedio;
	} while (preciopromedio < 12 || preciopromedio > 400);
	Plato* plato = new Plato(nombre, temperatura, ardor, calorias, preciopromedio);
	vectorplatos->RegistrarPlato(plato);
}

void Controladora::ModificarDatosPlatos()
{
	string nombre, ardor;
	int temperatura, indice, opcion;
	double calorias, preciopromedio;
	cout << "Ingrese el indice del plato a modificar: "; cin >> indice;
	if (indice < 0 || indice >= vectorplatos->getNumPlatos())
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	Plato* plato = vectorplatos->obtenerDatosPlato(indice);

	do
	{
		cout << "Seleccione el atributo a modificar:" << endl;
		cout << "1. Nombre del Plato" << endl;
		cout << "2. Temperatura" << endl;
		cout << "3. Ardor" << endl;
		cout << "4. Cantidad Calorias" << endl;
		cout << "5. Precio Promedio" << endl;
		cout << "0. Terminar modificaciones" << endl;
		cout << "Ingresar Opcion: "; cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case 1:
			system("cls");
			cout << "Ingrese el nuevo nombre del plato: ";
			cin.ignore();
			getline(cin, nombre);
			plato->setNombre(nombre);
			system("pause>0");
			break;
		case 2:
			system("cls");
			do
			{
				cout << "Ingrese la nueva temperatura: "; cin >> temperatura;
			} while (temperatura < 1 || temperatura > 2);
			plato->setTemperatura(temperatura);
			system("pause>0");
			break;
		case 3:
			system("cls");
			cout << "Ingrese el nuevo ardor del plato: ";
			cin.ignore();
			getline(cin, ardor);
			plato->setArdor(ardor);
			system("pause>0");
			break;
		case 4:
			system("cls");
			do
			{
				cout << "Ingrese la nueva cantidad de calorias: "; cin >> calorias;
			} while (calorias < 100 || calorias > 600);
			plato->setCalorias(calorias);
			system("pause>0");
			break;
		case 5:
			system("cls");
			do
			{
				cout << "Ingrese el nuevo precio promedio: "; cin >> preciopromedio;
			} while (preciopromedio < 12 || preciopromedio > 400);
			plato->setPrecioPromedio(preciopromedio);
			system("pause>0");
			break;
		case 0:
			break;
		}
		system("cls");
	} while (opcion != 0);
	cout << "SE MODIFICO CON EXITO LOS DATOS DEL PLATO!!" << endl;
}

void Controladora::EliminarPlatos()
{
	int indice;
	cout << "Ingrese el indice del plato a eliminar: "; cin >> indice;
	if (indice < 0 || indice >= vectorplatos->getNumPlatos())
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	vectorplatos->EliminarPlato(indice);
	cout << "\nSE ELIMINO CON EXITO EL PLATO!!" << endl;
}

void Controladora::ReporteTodosPlatos()
{
	cout << "\t\tREPORTE DE TODOS LOS PLATOS\n\n";
	for (int i = 0; i < vectorplatos->getNumPlatos(); i++)
	{
		vectorplatos->obtenerDatosPlato(i)->MostrarPlato();
		cout << endl;
	}
}

void Controladora::ReportePlatosPicantes()
{
	bool found = false;
	for (int i = 0; i < vectorplatos->getNumPlatos(); i++)
	{
		if (vectorplatos->obtenerDatosPlato(i)->getArdor() == "Picante")
		{
			if (!found)
			{
				cout << "\t\tPLATOS PICANTES\n\n";
				found = true;
			}
			vectorplatos->obtenerDatosPlato(i)->MostrarPlato();
			cout << endl;
		}
	}
	if (!found)
	{
		cout << "NO HAY PLATOS PICANTES" << endl;
	}
}

void Controladora::ReportePlatosCaros()
{
	bool found = false;
	for (int i = 0; i < vectorplatos->getNumPlatos(); i++)
	{
		if (vectorplatos->obtenerDatosPlato(i)->getPrecioPromedio() > 100)
		{
			if (!found)
			{
				cout << "\t\tPLATO MAS CAROS\n\n";
				found = true;
			}
			vectorplatos->obtenerDatosPlato(i)->MostrarPlato();
			cout << endl;
		}
	}
	if (!found)
	{
		cout << "NO HAY PLATOS MUY CAROS" << endl;
	}
}

bool Controladora::existenPlatos()
{
	return vectorplatos->getNumPlatos() > 0;
}