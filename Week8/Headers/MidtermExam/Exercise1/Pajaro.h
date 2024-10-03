#pragma once
#include "Animal.h"

class Pajaro : public Animal
{
private:
	double ancho;
	double alto;

public:
	Pajaro(double ancho, double alto);
	double calcularVelocidad() override;
};

Pajaro::Pajaro(double ancho, double alto)
{
	this->ancho = ancho;
	this->alto = alto;
}

double Pajaro::calcularVelocidad()
{
	return ancho * alto;
}