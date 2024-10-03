#pragma once
#include "Animal.h"

class Perro : public Animal
{
private:
	string raza;
	double size;

public:
	Perro(string raza, double size);
	double calcularVelocidad() override;
	double calcularFuerza() override;
};

Perro::Perro(string raza, double size)
{
	this->raza = raza;
	this->size = size;
}

double Perro::calcularVelocidad()
{
	return size * 2;
}

double Perro::calcularFuerza()
{
	return size * 3;
}