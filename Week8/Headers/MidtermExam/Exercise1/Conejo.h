#pragma once
#include "Animal.h"

class Conejo : public Animal
{
private:
	double velocidad;
	double size;

public:
	Conejo(double velocidad, double size);
	double calcularFuerza() override;
	double calcularVelocidad() override;
};

Conejo::Conejo(double velocidad, double size)
{
	this->velocidad = velocidad;
	this->size = size;
}

double Conejo::calcularFuerza()
{
	return size * 2;
}

double Conejo::calcularVelocidad()
{
	return velocidad;
}