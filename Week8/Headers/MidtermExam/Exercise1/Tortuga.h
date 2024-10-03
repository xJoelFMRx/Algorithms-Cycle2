#pragma once
#include "Animal.h"

class Tortuga : public Animal
{
private:
	double velocidad;
	double size;

public:
	Tortuga(double velocidad, double size);
	double calcularFuerza() override;
	double calcularVelocidad() override;
};

Tortuga::Tortuga(double velocidad, double size)
{
	this->velocidad = velocidad;
	this->size = size;
}

double Tortuga::calcularFuerza()
{
	return size * 1.5;
}

double Tortuga::calcularVelocidad()
{
	return velocidad;
}