#pragma once
#include "Entidad.h"

class Arco : public Entidad
{
private:
	float dx;
	float dy;
	float velocidad;
	char forma;

public:
	Arco(float x, float y, float dx, float dy);
	void MoverArco();
	void DibujarArco();
	bool fueraDeLimite();
};

Arco::Arco(float x, float y, float dx, float dy) : Entidad(x, y, 1, 1)
{
	this->dx = dx;
	this->dy = dy;
	color = 15;
	velocidad = 2;
	forma = '*';
}

void Arco::DibujarArco()
{
	for (int i = 0; i < alto; i++)
	{
		Console::SetCursorPosition(x, y + i);
		for (int j = 0; j < ancho; j++)
		{
			cout << forma;
		}
	}
}

void Arco::MoverArco()
{
	x += dx * velocidad;
	y += dy * velocidad;
}

bool Arco::fueraDeLimite()
{
	if (x + ancho > ANCHO_CONSOLA || x < 0)
	{
		return true;
	}
	if (y + alto  > ALTO_CONSOLA || y < 4)
	{
		return true;
	}
	return false;
}