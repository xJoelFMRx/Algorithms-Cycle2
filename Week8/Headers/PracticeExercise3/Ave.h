#pragma once
#include "Utilidades.h"

class Ave
{
protected:
	float x;
	float y;
	float velocidad;
	int ancho;
	int alto;
	int color;
	
public:
	Ave(float x, float y, int ancho, int alto);
	void Borrar();
	virtual void Dibujar();
	virtual void Mover();
	float getX();
	float getY();
	int getAncho();
	int getAlto();
};

Ave::Ave(float x, float y, int ancho, int alto)
{
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	velocidad = 0;
	color = 0;
}

void Ave::Borrar()
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

float Ave::getX()
{
	return x;
}

float Ave::getY()
{
	return y;
}

int Ave::getAncho()
{
	return ancho;
}

int Ave::getAlto()
{
	return alto;
}

void Ave::Mover(){}

void Ave::Dibujar(){}