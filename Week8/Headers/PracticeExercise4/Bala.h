#pragma once
#include "Utilidades.h"

class Bala
{
private:
	char forma;
	float x;
	float y;
	float dx;
	float dy;
	float velocidad;
	int ancho;
	int alto;
	int color;

public:
	Bala(float x, float y, float dx, float dy);
	void BorrarBala();
	void DibujarBala();
	void MoverBala();
	bool fueraDeLimite();
	float getX();
	float getY();
	int getAncho();
	int getAlto();
};

Bala::Bala(float x, float y, float dx, float dy)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	velocidad = 2; 
	ancho = 1;
	alto = 1;
	color = 15;
	forma = '*';
}

void Bala::BorrarBala()
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

void Bala::DibujarBala()
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

void Bala::MoverBala()
{
	x += dx * velocidad;
	y += dy * velocidad;
}

bool Bala::fueraDeLimite()
{
	if (x + ancho > ANCHO_CONSOLA || x < 1)
	{
		return true;
	}
	if (y + alto > ALTO_CONSOLA || y < 3)
	{
		return true;
	}
	return false;
}

float Bala::getX()
{
	return x;
}

float Bala::getY()
{
	return y;
}

int Bala::getAncho()
{
	return ancho;
}

int Bala::getAlto()
{
	return alto;
}