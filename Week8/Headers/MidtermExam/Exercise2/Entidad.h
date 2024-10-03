#pragma once
#include "Utilidades.h"

class Entidad
{
protected:
	float x;
	float y;
	int ancho;
	int alto;
	int color;

public:
	Entidad(float x, float y, int ancho, int alto);
	void Borrar();
	virtual void Mover();
	virtual void Dibujar();
	float getX();
	float getY();
	int getAncho();
	int getAlto();
};

Entidad::Entidad(float x, float y, int ancho, int alto)
{
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	color = 0;
}

void Entidad::Borrar()
{
	for (int i = 0; i < alto; i++)
	{
		Console::SetCursorPosition(x, y + i);
		for (int j = 0; j < ancho; j++)
		{
			cout << " ";
		}
	}
}

float Entidad::getX()
{
	return x;
}

float Entidad::getY()
{
	return y;
}

int Entidad::getAncho()
{
	return ancho;
}

int Entidad::getAlto()
{
	return alto;
}

void Entidad::Mover() {}

void Entidad::Dibujar() {}