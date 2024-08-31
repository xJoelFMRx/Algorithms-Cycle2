#pragma once
#include "iostream"
#include "string"
#include "cmath"

using namespace std;

class CodigoAlumnoRaices
{
private:
	double a;
	double b;
	double c;

public:
	CodigoAlumnoRaices(double a, double b, double c);
	double getDiscriminante();
	bool tieneRaices();
	bool tieneRaiz();
	void calcular();
	void obtenerRaices();
	void obtenerRaiz();
};

CodigoAlumnoRaices::CodigoAlumnoRaices(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

void CodigoAlumnoRaices::obtenerRaices()
{
	if (tieneRaices())
	{
		double discriminante = getDiscriminante();
		double raiz1 = (-b + sqrt(discriminante)) / (2 * a);
		double raiz2 = (-b - sqrt(discriminante)) / (2 * a);
		cout << endl << "Raiz 1: " << raiz1 << endl;
		cout << "Raiz 2: " << raiz2 << endl;
	}
	else
	{
		cout << "No tiene dos soluciones!!" << endl;
	}
}

void CodigoAlumnoRaices::obtenerRaiz()
{
	if (tieneRaiz())
	{
		double raiz = -b / (2 * a);
		cout << endl << "Raiz: " << raiz << endl;
	}
	else
	{
		cout << "No tiene una unica solucion!!" << endl;
	}
}

double CodigoAlumnoRaices::getDiscriminante()
{
	return pow(b, 2) - 4 * a * c;
	;
}

bool CodigoAlumnoRaices::tieneRaices()
{
	return getDiscriminante() > 0;
}

bool CodigoAlumnoRaices::tieneRaiz()
{
	return getDiscriminante() == 0;
}

void CodigoAlumnoRaices::calcular()
{
	if (tieneRaices())
	{
		obtenerRaices();
	}
	else if (tieneRaiz())
	{
		obtenerRaiz();
	}
	else
	{
		cout << endl << "No exiten soluciones reales para la solucion!!" << endl;
	}
}