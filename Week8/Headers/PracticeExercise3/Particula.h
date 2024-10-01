#pragma once
#include "Utilidades.h"

class Particula
{
private:
	char forma;
	float x;
	float y;
	int ancho;
	int alto;
	int color;

public:
	Particula(float x, float y);
	void BorrarParticula();
	void DibujarParticula();
	float getX();
	float getY();
	int getAncho();
	int getAlto();
};

Particula::Particula(float x, float y)
{
	this->x = x;
	this->y = y;
	forma = 111;
	ancho = 1;
	alto = 1;
	color = 11;
}

void Particula::BorrarParticula()
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

void Particula::DibujarParticula()
{
	Console::ForegroundColor = ConsoleColor(color);
	for (int i = 0; i < alto; i++)
	{
		Console::SetCursorPosition(x, y + i);
		for (int j = 0; j < ancho; j++)
		{
			cout << forma;
		}
	}
	Console::ResetColor();
}

float Particula::getX()
{
	return x;
}

float Particula::getY()
{
	return y;
}

int Particula::getAncho()
{
	return ancho;
}

int Particula::getAlto()
{
	return alto;
}