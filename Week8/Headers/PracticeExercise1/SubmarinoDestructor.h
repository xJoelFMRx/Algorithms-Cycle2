#pragma once
#include "Submarino.h"
#include "Destructor.h"

class SubmarinoDestructor : public Destructor, public Submarino
{
private:
	
public:
	SubmarinoDestructor(int peso, string color, double velocidad);
	void getInfo() override; //no es necesario
};

SubmarinoDestructor::SubmarinoDestructor(int peso, string color, double velocidad) : Destructor(velocidad, peso), Submarino(color, peso) {}

void SubmarinoDestructor::getInfo()
{
	Barco::getInfo();
	cout << "La velocidad del submarino destructor es: " << Destructor::getVelocidad() << "km/h" << endl;
	cout << "El color del submarino destructor es: " << Submarino::getColor() << endl;
}

//2da forma
//#pragma once
//#include "Submarino.h"
//#include "Destructor.h"
//
//class SubmarinoDestructor : public Destructor, public Submarino
//{
//private:
//
//public:
//	SubmarinoDestructor(int peso, string color, double velocidad);
//	void getInfo() override; //no es necesario
//};
//
//SubmarinoDestructor::SubmarinoDestructor(int peso, string color, double velocidad) : Destructor(velocidad, peso), Submarino(color, peso) {}
//
//void SubmarinoDestructor::getInfo()
//{
//	Barco::getInfo();
//	cout << "La velocidad del submarino destructor es: " << velocidad << endl;
//	cout << "El color del submarino destructor es: " << color << endl;
//}

//3ra forma
//#pragma once
//#include "Submarino.h"
//#include "Destructor.h"
//
//class SubmarinoDestructor : public Destructor, public Submarino
//{
//private:
//	
//public:
//	SubmarinoDestructor(int peso, string color, double velocidad);
//	void getInfo(); //Si lo tomo como otro barco si se coloca override
//};
//
//SubmarinoDestructor::SubmarinoDestructor(int peso, string color, double velocidad) : Destructor(velocidad, peso), Submarino(color, peso) {}
//
//void SubmarinoDestructor::getInfo() //Con esta forma me da dos veces el peso
//{
//	Submarino::getInfo();
//	Destructor::getInfo();
//}