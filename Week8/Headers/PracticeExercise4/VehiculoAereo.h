#pragma once
#include "Utilidades.h"

class VehiculoAereo
{
protected:
	float x;
	float y;
	float dx;
	float dy;
	float velocidad;
	int ancho; 
	int alto;
	int color;

public:
	VehiculoAereo(float x, float y, float dx, float dy, int ancho, int alto);
	void Borrar();
	virtual void Mover();
	virtual void Dibujar();
	float getX();
	float getY();
	int getAncho();
	int getAlto();
};

VehiculoAereo::VehiculoAereo(float x, float y, float dx, float dy, int ancho, int alto)
{
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	this->dx = dx;
	this->dy = dy;
	velocidad = 0;
	color = 0;
}

void VehiculoAereo::Borrar()
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

float VehiculoAereo::getX()
{
	return x;
}

float VehiculoAereo::getY()
{
	return y;
}

int VehiculoAereo::getAncho()
{
	return ancho;
}

int VehiculoAereo::getAlto()
{
	return alto;
}

void VehiculoAereo::Mover(){}

void VehiculoAereo::Dibujar(){}