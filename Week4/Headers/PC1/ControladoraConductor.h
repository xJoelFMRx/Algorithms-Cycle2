#pragma once
#include "ListaConductores.h"

class Controladora
{
private:
	ListaConductores* listaconductores;

public:
	Controladora();
	~Controladora();
	void AgregarConductor();
	void EliminarConductor();
	void ModificarConductor();
	void MostrarTodosConductores();
	void MostrarConductoresMayores50();
	void MostrarConductoresMujeres();
	bool existenConductores();
};

Controladora::Controladora()
{
	listaconductores = new ListaConductores();
}

Controladora::~Controladora()
{
	delete listaconductores;
}

void Controladora::AgregarConductor()
{
	string nombre, apellido, empresa, placa;
	int edad, kilometraje;
	char sexo;
	do
	{
		cout << "Ingrese Nombre: "; cin >> nombre;
	} while (nombre.empty());
	do
	{
		cout << "Ingrese Apellido: "; cin >> apellido;
	} while (apellido.empty());
	do
	{
		cout << "Ingrese Edad: "; cin >> edad;
	} while (edad < 18 || edad > 100);
	do
	{
		cout << "Ingrese Sexo (M/F): "; cin >> sexo;
		sexo = toupper(sexo);
	} while (sexo != 'M' && sexo != 'F');
	do
	{
		cout << "Ingrese Placa: "; cin >> placa;
	} while (placa.empty());
	do
	{
		cout << "Ingrese Kilometraje: "; cin >> kilometraje;
	} while (kilometraje < 1);
	do
	{
		cout << "Ingrese Empresa: "; 
		cin.ignore();
		getline(cin, empresa);
	} while (empresa.empty());
	Conductor* conductor = new Conductor(nombre, apellido, edad, sexo, placa, kilometraje, empresa);
	listaconductores->agregarConductor(conductor);
}

void Controladora::EliminarConductor()
{
	string DNI;
	do
	{
		cout << "Ingrese el DNI del conductor a eliminar: "; cin >> DNI;
	} while (DNI.empty());
	listaconductores->eliminarConductor(DNI);
}

void Controladora::ModificarConductor()
{
	string placaVehiculo;
	do
	{
		cout << "Ingrese la placa del vehiculo: "; cin >> placaVehiculo;
	} while (placaVehiculo.empty());
	listaconductores->modificarConductor(placaVehiculo);
}

void Controladora::MostrarTodosConductores()
{
	listaconductores->mostrarConductores();
}

void Controladora::MostrarConductoresMayores50()
{
	listaconductores->reporteConductoresMayores50();
}

void Controladora::MostrarConductoresMujeres()
{
	listaconductores->reporteConductoresMujeres();
}

bool Controladora::existenConductores()
{
	return listaconductores->getNumConductores() > 0;
}
