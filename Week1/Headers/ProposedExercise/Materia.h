#pragma once
#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Materia
{
private:
	string codigo;
	string nombre;
	double nota; //Nota del alumno en esta materia

public:
	Materia(string codigo, string nombre);
	string getCodigo();
	string getNombre();
	double getNota();
	void setNota(double nota);
	void mostrarMateria();
};

Materia::Materia(string codigo, string nombre)
{
	this->codigo = codigo;
	this->nombre = nombre;
	nota = 0;
}

string Materia::getCodigo()
{
	return codigo;
}

string Materia::getNombre()
{
	return nombre;
}

double Materia::getNota()
{
	return nota;
}

void Materia::setNota(double nota)
{
	this->nota = nota;
}

void Materia::mostrarMateria()
{
	cout << "Materia: " << nombre << endl;
	cout << "Nota: " << nota << endl;
}