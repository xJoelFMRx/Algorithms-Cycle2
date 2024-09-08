#pragma once
#include "iostream"
#include "string"
#include "sstream"

using namespace std;

class Conductor
{
private:
	string DNI;
	string nombre;
	string apellido;
	int edad;
	char sexo;
	string placa;
	int kilometraje;
	string empresa;

public:
	Conductor(string nombre, string apellido, int edad, char sexo, string placa, int kilometraje, string empresa);
	string getDNI();
	string getNombre();
	string getApellido();
	int getEdad();
	char getSexo();
	string getPlaca();
	int getKilometraje();
	string getEmpresa();
	string generarDNI();
	double PrecioKilometraje();
	void setDNI(string DNI);
	void setNombre(string nombre);
	void setApellido(string apellido);
	void setEdad(int edad);
	void setSexo(char sexo);
	void setPlaca(string placa);
	void setKilometraje(int kilometraje);
	void setEmpresa(string empresa);
	void mostrarConductor();
};

Conductor::Conductor(string nombre, string apellido, int edad, char sexo, string placa, int kilometraje, string empresa)
{
	DNI = generarDNI();
	this->nombre = nombre;
	this->apellido = apellido;
	this->edad = edad;
	this->sexo = sexo;
	this->placa = placa;
	this->kilometraje = kilometraje;
	this->empresa = empresa;
}

string Conductor::getDNI()
{
	return DNI;
}

string Conductor::getNombre()
{
	return nombre;
}

string Conductor::getApellido()
{
	return apellido;
}

int Conductor::getEdad()
{
	return edad;
}

char Conductor::getSexo()
{
	return sexo;
}

string Conductor::getPlaca()
{
	return placa;
}

int Conductor::getKilometraje()
{
	return kilometraje;
}

string Conductor::getEmpresa()
{
	return empresa;
}

double Conductor::PrecioKilometraje()
{
	return 3.2 * kilometraje;
}

string Conductor::generarDNI()
{
	stringstream ss;
	for (int i = 0; i < 8; i++)
	{
		ss << rand() % 10;
	}
	return ss.str();
}

void Conductor::setDNI(string DNI)
{
	this->DNI = DNI;
}

void Conductor::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Conductor::setApellido(string apellido)
{
	this->apellido = apellido;
}

void Conductor::setEdad(int edad)
{
	this->edad = edad;
}

void Conductor::setSexo(char sexo)
{
	this->sexo = sexo;
}

void Conductor::setPlaca(string placa)
{
	this->placa = placa;
}

void Conductor::setKilometraje(int kilometraje)
{
	this->kilometraje = kilometraje;
}

void Conductor::setEmpresa(string empresa)
{
	this->empresa = empresa;
}

void Conductor::mostrarConductor()
{
	cout << "DNI: " << DNI << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Apellido: " << apellido << endl;
	cout << "Edad: " << edad << endl;
	cout << "Sexo: " << sexo << endl;
	cout << "Placa: " << placa << endl;
	cout << "Kilometraje: " << kilometraje << endl;
	cout << "Precio Kilometraje: S/." << PrecioKilometraje() << endl;
	cout << "Empresa: " << empresa << endl;
}
