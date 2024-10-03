#pragma once
#include "Animal.h"

class Gato : public Animal
{
private:
	double size;
	double peso;

public:
	Gato(double peso, double size);
	double calcularAgilidad() override;
	double calcularVelocidad() override;
};

Gato::Gato(double peso, double size)
{
	this->peso = peso;
	this->size = size;
}

double Gato::calcularAgilidad()
{
	return peso * 4;
}

double Gato::calcularVelocidad()
{
	return size * 3;
}