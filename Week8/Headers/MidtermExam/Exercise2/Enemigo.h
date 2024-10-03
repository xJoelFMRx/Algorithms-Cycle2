#pragma once
#include "Entidad.h"

class Enemigo : public Entidad
{
private:
	float dx;
	float velocidad;

public:
	Enemigo(float x, float y, float dx);
	void Mover() override;
	void Dibujar() override;
};

Enemigo::Enemigo(float x, float y, float dx) : Entidad(x, y, 4, 3)
{
	this->dx = dx;
	color = 12;
	velocidad = 0.2;
}

void Enemigo::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << " @";
	Console::SetCursorPosition(x, y + 1);
	cout << "/|\\";
	Console::SetCursorPosition(x, y + 2);
	cout << "/ \\";
	Console::ResetColor();
}

void Enemigo::Mover()
{
	if (x + ancho > ANCHO_CONSOLA || x < 1)
	{
		dx *= -1;
	}
	x += dx * velocidad;
}