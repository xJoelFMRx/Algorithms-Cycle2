#pragma once
#include "iostream"
#include "string"
#include "vector"
#include "Materia.h"

using namespace std;

class Alumno
{
private:
	string DNI;
	string apellidos;
	string nombres;
	string carrera;
	string mail;
	int edad;
	vector<Materia>materias;//Materias inscritas por el alumno

public:
	Alumno(string DNI, string apellidos, string nombres, string carrera, string mail, int edad);
	void modificarDatos(string apellidos, string nombres, string mail, int edad);
	void inscribirMateria(Materia& materia);
	bool estaInscritoEnMateria(string& codigoMateria);
	void cargarNota(string& codigoMateria, int nota);
	string getDNI();
	string getNombreCompleto();
	string getCarrera();
	string getMail();
	int getEdad();
};

Alumno::Alumno(string DNI, string apellidos, string nombres, string carrera, string mail, int edad)
{
	this->DNI = DNI;
	this->apellidos = apellidos;
	this->nombres = nombres;
	this->carrera = carrera;
	this->mail = mail;
	this->edad = edad;
}

void Alumno::modificarDatos(string apellidos, string nombres, string mail, int edad)
{
	this->apellidos = apellidos;
	this->nombres = nombres;
	this->mail = mail;
	this->edad = edad;
}

void Alumno::inscribirMateria(Materia& materia)
{
	materias.push_back(materia);
}

bool Alumno::estaInscritoEnMateria(string& codigoMateria)
{
	for (int i = 0; i < materias.size(); i++)
	{
		if (materias[i].getCodigo() == codigoMateria)
		{
			return true;
		}
	}
	return false;
}

void Alumno::cargarNota(string& codigoMateria, int nota)
{
	for (int i = 0; i < materias.size(); i++)
	{
		if (materias[i].getCodigo() == codigoMateria)
		{
			materias[i].setNota(nota);
			return;
		}
	}
	cout << "El alumno no esta inscrito en esta materia!!" << endl;
}

string Alumno::getDNI()
{
	return DNI;
}

string Alumno::getNombreCompleto()
{
	return nombres + " " + apellidos;
}

string Alumno::getCarrera()
{
	return carrera;
}

string Alumno::getMail()
{
	return mail;
}

int Alumno::getEdad()
{
	return edad;
}