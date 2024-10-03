#pragma once
#include "Animal.h"

class Caballo : public Animal
{
private:
	double altura;
	double peso;

public:
	Caballo(double altura, double peso);
	double calcularFuerza() override;
	double calcularVelocidad() override;
};

Caballo::Caballo(double altura, double peso)
{
	this->altura = altura;
	this->peso = peso;
}

double Caballo::calcularFuerza()
{
	return altura * 4.2;
}

double Caballo::calcularVelocidad()
{
	return peso * 6;
}