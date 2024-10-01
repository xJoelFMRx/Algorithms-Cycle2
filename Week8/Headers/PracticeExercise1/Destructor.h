#pragma once
#include "Barco.h"

class Destructor : public Barco
{
private:
	double velocidad;

public:
	Destructor(double velocidad, int peso);
	void getInfo() override;
	double getVelocidad();
};

Destructor::Destructor(double velocidad, int peso) : Barco(peso)
{
	this->velocidad = velocidad;
}

void Destructor::getInfo()
{
	Barco::getInfo();
	cout << "La velocidad es: " << velocidad << "km/h" << endl;
}

double Destructor::getVelocidad()
{
	return velocidad;
}

//2da forma
//class Destructor : public Barco
//{
//protected:
//	double velocidad;
//
//public:
//	Destructor(double velocidad, int peso);
//	void getInfo() override;
//};
//
//Destructor::Destructor(double velocidad, int peso) : Barco(peso)
//{
//	this->velocidad = velocidad;
//}
//
//void Destructor::getInfo()
//{
//	Barco::getInfo();
//	cout << "La velocidad es: " << velocidad << endl;
//}

//3ra forma
//#pragma once
//#include "Barco.h"
//
//class Destructor : public Barco
//{
//private:
//	double velocidad;
//
//public:
//	Destructor(double velocidad, int peso);
//	void getInfo() override;
//};
//
//Destructor::Destructor(double velocidad, int peso) : Barco(peso)
//{
//	this->velocidad = velocidad;
//}
//
//void Destructor::getInfo()
//{
//	Barco::getInfo();
//	cout << "La velocidad es: " << velocidad << "km/h" << endl;
//}