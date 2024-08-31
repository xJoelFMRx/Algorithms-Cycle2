#pragma once
#include "iostream"
#include "string"

using namespace std;

class Contacto
{
private:
	string nombre;
	long long telefono;
	char sexo;
	string facultad;
	string fechanacimiento;
	string email;
	string redsocial;

public:
	Contacto(string nombre, long long telefono, char sexo, string facultad, string fechanacimiento, string email, string redsocial);
	string getNombre();
	long long getTelefono();
	char getSexo();
	string getFacultad();
	string getFechaNacimiento();
	string getEmail();
	string getRedSocial();
	void setNombre(string nombre);
	void setTelefono(long long telefono);
	void setSexo(char sexo);
	void setFacultad(string facultad);
	void setFechaNacimiento(string fechanacimiento);
	void setEmail(string email);
	void setRedSocial(string redsocial);
	void MostrarContacto();
};

Contacto::Contacto(string nombre, long long telefono, char sexo, string facultad, string fechanacimiento, string email, string redsocial)
{
	this->nombre = nombre;
	this->telefono = telefono;
	this->sexo = sexo;
	this->facultad = facultad;
	this->fechanacimiento = fechanacimiento;
	this->email = email;
	this->redsocial = redsocial;
}

string Contacto::getNombre()
{
	return nombre;
}

long long Contacto::getTelefono()
{
	return telefono;
}

char Contacto::getSexo()
{
	return sexo;
}

string Contacto::getFacultad()
{
	return facultad;
}

string Contacto::getFechaNacimiento()
{
	return fechanacimiento;
}

string Contacto::getEmail()
{
	return email;
}

string Contacto::getRedSocial()
{
	return redsocial;
}

void Contacto::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Contacto::setTelefono(long long telefono)
{
	this->telefono = telefono;
}

void Contacto::setSexo(char sexo)
{
	this->sexo = sexo;
}

void Contacto::setFacultad(string facultad)
{
	this->facultad = facultad;
}

void Contacto::setFechaNacimiento(string fechanacimiento)
{
	this->fechanacimiento = fechanacimiento;
}

void Contacto::setEmail(string email)
{
	this->email = email;
}

void Contacto::setRedSocial(string redsocial)
{
	this->redsocial = redsocial;
}

void Contacto::MostrarContacto()
{
	cout << "Nombre del Contacto: " << nombre << endl;
	cout << "Telefono: " << telefono << endl;
	cout << "Sexo: " << (sexo == 'V' ? "Varon" : "Mujer") << endl;
	cout << "Facultad: " << facultad << endl;
	cout << "Fecha Nacimiento: " << fechanacimiento << endl;
	cout << "Email: " << email << endl;
	cout << "Red Social: " << redsocial << endl;
}