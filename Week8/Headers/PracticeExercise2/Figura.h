#pragma once
#include "Utilidades.h"

class Figura
{
protected:
	float x;
	float y;
	int ancho;
	int alto;
	int color;

public:
	Figura(float x, float y, int ancho, int alto);
	void Borrar();
	virtual void Dibujar();
	virtual void Mover();
	float getX();
	float getY();
	int getAncho();
	int getAlto();
};

Figura::Figura(float x, float y, int ancho, int alto)
{
	this->ancho = ancho;
	this->alto = alto;
	this->x = x;
	this->y = y;
	color = 0;
}

void Figura::Borrar()
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

//void Figura::Borrar()
//{
//	for (int i = 0; i < ancho; i++)
//	{
//		for (int j = 0; j < alto; j++)
//		{
//			Console::SetCursorPosition(static_cast<int>(x) + i, static_cast<int>(y) + j); cout << " ";
//		}
//	}
//}

void Figura::Mover() {}

void Figura::Dibujar() {}

float Figura::getX()
{
	return x;
}

float Figura::getY()
{
	return y;
}

int Figura::getAlto()
{
	return alto;
}

int Figura::getAncho()
{
	return ancho;
}