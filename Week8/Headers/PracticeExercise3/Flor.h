#pragma once
#include "Utilidades.h"

class Flor
{
private:
	float x;
	float y;
	int ancho;
	int alto;
	int color;
	
public:
	Flor(float x, float y);
	void BorrarFlor();
	void DibujarFlor();
	float getX();
	float getY();
	int getAncho();
	int getAlto();
};

Flor::Flor(float x, float y)
{
	this->x = x;
	this->y = y;
	ancho = 6;
	alto = 2;
	color = 10;
}

void Flor::BorrarFlor()
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

void Flor::DibujarFlor()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << " (W)";
	Console::SetCursorPosition(x, y + 1);
	cout << "_\\|/_";
	Console::ResetColor();
}

float Flor::getX()
{
	return x;
}

float Flor::getY()
{
	return y;
}

int Flor::getAncho()
{
	return ancho;
}

int Flor::getAlto()
{
	return alto;
}