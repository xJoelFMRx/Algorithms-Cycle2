#pragma once
#include "iostream" 
#include "string"

using namespace std;

class Plato
{
private:
	string nombre;
	int temperatura;
	string ardor;
	double calorias;
	double preciopromedio;

public:
	Plato(string nombre, int temperatura, string ardor, double calorias, double preciopromedio);
	string getNombre();
	int getTemperatura();
	string getArdor();
	double getCalorias();
	double getPrecioPromedio();
	void setNombre(string nombre);
	void setTemperatura(int temperatura);
	void setArdor(string ardor);
	void setCalorias(double calorias);
	void setPrecioPromedio(double preciopromedio);
	void MostrarPlato();
};

Plato::Plato(string nombre, int temperatura, string ardor, double calorias, double preciopromedio)
{
	this->nombre = nombre;
	this->temperatura = temperatura;
	this->ardor = ardor;
	this->calorias = calorias;
	this->preciopromedio = preciopromedio;
}

string Plato::getNombre()
{
	return nombre;
}

int Plato::getTemperatura()
{
	return temperatura;
}

string Plato::getArdor()
{
	return ardor;
}

double Plato::getCalorias()
{
	return calorias;
}

double Plato::getPrecioPromedio()
{
	return preciopromedio;
}

void Plato::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Plato::setTemperatura(int temperatura)
{
	this->temperatura = temperatura;
}

void Plato::setArdor(string ardor)
{
	this->ardor = ardor;
}

void Plato::setCalorias(double calorias)
{
	this->calorias = calorias;
}

void Plato::setPrecioPromedio(double preciopromedio)
{
	this->preciopromedio = preciopromedio;
}

void Plato::MostrarPlato()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Temperatura: " << (temperatura == 1 ? "Frio" : "Caliente") << endl;
	cout << "Ardor: " << ardor << endl;
	cout << "Calorias: " << calorias << "cal" << endl;
	cout << "Precio Promedio: S/" << preciopromedio << endl;
}