#pragma once
#include "iostream"
#include "string"

using namespace std;

class Hotel
{
private:
	string nombre;
	string ubicacion;
	int estrellas;
	char desayuno; //SI O NO 
	long long telefono;
	char servicio; //SI O NO

public:
	Hotel(string nombre, string ubicacion, int estrellas, char desayuno, long long telefono, char servicio);
	string getNombre();
	string getUbicacion();
	int getEstrellas();
	char getDesayuno();
	long long getTelefono();
	char getServicio();
	void setNombre(string nombre);
	void setUbicacion(string ubicacion);
	void setEstrellas(int estrellas);
	void setDesayuno(char desayuno);
	void setTelefono(long long telefono);
	void setServicio(char servicio);
	void mostrarHotel();
};

Hotel::Hotel(string nombre, string ubicacion, int estrellas, char desayuno, long long telefono, char servicio)
{
	this->nombre = nombre;
	this->ubicacion = ubicacion;
	this->estrellas = estrellas;
	this->desayuno = desayuno;
	this->telefono = telefono;
	this->servicio = servicio;
}

string Hotel::getNombre()
{
	return nombre;
}

string Hotel::getUbicacion()
{
	return ubicacion;
}

int Hotel::getEstrellas()
{
	return estrellas;
}

char Hotel::getDesayuno()
{
	return desayuno;
}

long long Hotel::getTelefono()
{
	return telefono;
}

char Hotel::getServicio()
{
	return servicio;
}

void Hotel::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Hotel::setServicio(char servicio)
{
	this->servicio = servicio;
}

void Hotel::setUbicacion(string ubicacion)
{
	this->ubicacion = ubicacion;
}

void Hotel::setTelefono(long long telefono)
{
	this->telefono = telefono;
}

void Hotel::setEstrellas(int estrellas)
{
	this->estrellas = estrellas;
}

void Hotel::setDesayuno(char desayuno)
{
	this->desayuno = desayuno;
}

void Hotel::mostrarHotel()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Ubicacion: " << ubicacion << endl;
	cout << "Estrellas: " << estrellas << endl;
	cout << "¿Entregan Desayuno?: " << (desayuno == 'S' ? "Si" : "No") << endl;
	cout << "Telefono: " << telefono << endl;
	cout << "¿Entregan Servicio Aereo?: " << (servicio == 'S' ? "Si" : "No") << endl;
}
