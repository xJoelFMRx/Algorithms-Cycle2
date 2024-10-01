#pragma once
#include "iostream"
#include "string"

using namespace std;

class Barco
{
protected:
	int peso;
	
public:
	Barco(int peso);
	virtual void getInfo();
};

Barco::Barco(int peso)
{
	this->peso = peso;
}

void Barco::getInfo()
{
	cout << "El peso es: " << peso << endl;
}