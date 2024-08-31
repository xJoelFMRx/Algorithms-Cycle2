#pragma once
#include "iostream"
#include "string"
#include "vector"
#include "Materia.h"

using namespace std;

class Docente
{
private:
	string DNI;
	string apellidos;
	string nombres;
	string mail;
	string titulo;
	vector<Materia> materias; //Materias que enseña

public:
	Docente(string DNI, string apellidos, string nombres, string mail, string titulo);
	void modificarDatos(string apellidos, string nombres, string mail, string titulo);
	void anotarMateria(Materia& materia);
	string getDNI();
	string getNombreCompleto();
	string getMail();
	string getTitulo();
};

Docente::Docente(string DNI, string apellidos, string nombres, string mail, string titulo)
{
	this->DNI = DNI;
	this->apellidos = apellidos;
	this->nombres = nombres;
	this->mail = mail;
	this->titulo = titulo;
}

void Docente::modificarDatos(string apellidos, string nombres, string mail, string titulo)
{
	this->apellidos = apellidos;
	this->nombres = nombres;
	this->mail = mail;
	this->titulo = titulo;
}

void Docente::anotarMateria(Materia& materia)
{
	materias.push_back(materia);
}

string Docente::getDNI()
{
	return DNI;
}

string Docente::getNombreCompleto()
{
	return nombres + " " + apellidos;
}

string Docente::getMail()
{
	return mail;
}

string Docente::getTitulo()
{
	return titulo;
}