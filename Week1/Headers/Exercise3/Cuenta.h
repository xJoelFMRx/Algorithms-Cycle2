#pragma once
#include "iostream"
#include "string"

using namespace std;

class Cuenta
{
private:
	string titular;
	double cantidad;

public:
	Cuenta(string titular);
	Cuenta(string titular, double cantidad = 0.0);
	string getTitular();
	double getCantidad();
	void setTitular(string titular);
	void setCantidad(double cantidad);
	void Ingresar(double cantidad);
	void Retirar(double cantidad);
};

Cuenta::Cuenta(string titular)
{
	this->titular = titular;
	cantidad = 0.0;
}

Cuenta::Cuenta(string titular, double cantidad)
{
	this->titular = titular;
	this->cantidad = cantidad;
}

string Cuenta::getTitular()
{
	return titular;
}

double Cuenta::getCantidad()
{
	return cantidad;
}

void Cuenta::setTitular(string titular)
{
	this->titular = titular;
}

void Cuenta::setCantidad(double cantidad)
{
	this->cantidad = cantidad;
}

void Cuenta::Ingresar(double cantidad)
{
	if (cantidad > 0)
	{
		this->cantidad += cantidad;
	}
	else
	{
		cout << endl << "La cantidad ingresada deber ser positiva." << endl;
	}
}

void Cuenta::Retirar(double cantidad)
{
	if (cantidad > 0)
	{
		if (this->cantidad - cantidad >= 0)
		{
			this->cantidad -= cantidad;
		}
		else
		{
			this->cantidad = 0;
		}
	}
	else
	{
		cout << endl << "La cantidad retirada debe de ser positiva." << endl;
	}
}