#pragma once
#include "Barco.h"

class Submarino : public Barco
{
private:
	string color;

public:
	Submarino(string color, int peso);
	void getInfo() override;
	string getColor();
};

Submarino::Submarino(string color, int peso) : Barco(peso)
{
	this->color = color;
}

void Submarino::getInfo()
{
	Barco::getInfo();
	cout << "El color es: " << color << endl;
}

string Submarino::getColor()
{
	return color;
}

//2da forma
//#pragma once
//#include "Barco.h"
//
//class Submarino : public Barco
//{
//protected:
//	string color;
//
//public:
//	Submarino(string color, int peso);
//	void getInfo() override;
//};
//
//Submarino::Submarino(string color, int peso) : Barco(peso)
//{
//	this->color = color;
//}
//
//void Submarino::getInfo()
//{
//	Barco::getInfo();
//	cout << "El color es: " << color << endl;
//}

//3ra forma
//#pragma once
//#include "Barco.h"
//
//class Submarino : public Barco
//{
//private:
//	string color;
//
//public:
//	Submarino(string color, int peso);
//	void getInfo() override;
//};
//
//Submarino::Submarino(string color, int peso) : Barco(peso)
//{
//	this->color = color;
//}
//
//void Submarino::getInfo()
//{
//	Barco::getInfo();
//	cout << "El color es: " << color << endl;
//}
