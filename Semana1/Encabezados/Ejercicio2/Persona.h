#pragma once
#include "iostream"
#include "string"
#include "sstream"

using namespace std;

char ObtenerSexo[2] = { 'H','M' };

class Persona
{
private:
	string nombre;
	int edad;
	string dni;
	char sexo;
	double peso;
	double altura;
	void comprobarSexo(char sexo);
	string generaDNI();

public:
	Persona();
	Persona(string nombre, int edad, char sexo);
	Persona(string nombre, int edad, string dni, char sexo, double peso, double altura);
	double calcularIMC();
	bool esMayorDeEdad();
	string toString();
	string getNombre();
	int getEdad();
	char getSexo();
	double getPeso();
	double getAltura();
	void setNombre(string nombre);
	void setEdad(int edad);
	void setSexo(char sexo);
	void setPeso(double peso);
	void setAltura(double altura);
};

Persona::Persona()
{
	nombre = "";
	edad = 0;
	sexo = ObtenerSexo[0];
	peso = 0;
	altura = 0;
	dni = generaDNI();
}

Persona::Persona(string nombre, int edad, char sexo)
{
	this->nombre = nombre;
	this->edad = edad;
	this->sexo = sexo;
	peso = 0;
	altura = 0;
	dni = generaDNI();
	comprobarSexo(sexo);
}

Persona::Persona(string nombre, int edad, string dni, char sexo, double peso, double altura)
{
	this->nombre = nombre;
	this->edad = edad;
	this->dni = dni;
	this->sexo = sexo;
	this->peso = peso;
	this->altura = altura;
	comprobarSexo(sexo);
}

double Persona::calcularIMC()
{
	double IMC;
	if (altura == 0) return -1;
	IMC = peso / pow(altura, 2);

	if (IMC < 20)
	{
		return -1;
	}
	else if (IMC >= 20 && IMC <= 25)
	{
		return 0;
	}
	else if (IMC > 25)
	{
		return 1;
	}
}

bool Persona::esMayorDeEdad()
{
	return edad >= 18;
}

void Persona::comprobarSexo(char sexo)
{
	if (sexo != 'H' && sexo != 'M')
	{
		this->sexo = 'H';
	}
}

string Persona::toString()
{
	stringstream ss;
	string lectsexo;
	if (sexo == 'H')
	{
		lectsexo = "Hombre";
	}
	if (sexo == 'M')
	{
		lectsexo = "Mujer";
	}
	ss << "Nombre: " << nombre << endl;
	ss << "Edad: " << edad << endl;
	ss << "DNI: " << dni << endl;
	ss << "Sexo: " << lectsexo << endl;
	ss << "Peso: " << peso << endl;
	ss << "Altura: " << altura << endl;
	return ss.str();
}

string Persona::generaDNI()
{
	stringstream ss;
	for (int i = 0; i < 8; i++)
	{
		ss << rand() % 10;
	}
	return ss.str();
}

string Persona::getNombre()
{
	return nombre;
}

int Persona::getEdad()
{
	return edad;
}

char Persona::getSexo()
{
	return sexo;
}

double Persona::getPeso()
{
	return peso;
}

double Persona::getAltura()
{
	return altura;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Persona::setEdad(int edad)
{
	this->edad = edad;
}

void Persona::setSexo(char sexo)
{
	comprobarSexo(sexo);
	this->sexo = sexo;
}

void Persona::setPeso(double peso)
{
	this->peso = peso;
}

void Persona::setAltura(double altura)
{
	this->altura = altura;
}