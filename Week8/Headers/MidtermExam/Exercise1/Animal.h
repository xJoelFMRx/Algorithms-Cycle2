#pragma once
#include "iostream"
#include "string"

using namespace std;
using namespace System;

class Animal
{
public:
	virtual double calcularVelocidad();
	virtual double calcularFuerza();
	virtual double calcularAgilidad();
};

double Animal::calcularFuerza() { return 0.0; }

double Animal::calcularVelocidad(){ return 0.0; }

double Animal::calcularAgilidad(){ return 0.0; }