#pragma once
#include "VehiculoAereo.h"

class Helicoptero : public VehiculoAereo
{
private:

public:
	Helicoptero(float x, float y, float dx, float dy);
	void Mover() override;
	void Dibujar() override;
};

Helicoptero::Helicoptero(float x, float y, float dx, float dy) : VehiculoAereo(x, y, dx, dy, 12, 3)
{
	velocidad = RandFloat(1, 1.5);
	color = 7;
}

void Helicoptero::Mover()
{
	if (x + ancho > ANCHO_CONSOLA || x < 1) 
	{
		dx *= -1;
	}
	if (y + alto + 2 > ALTO_CONSOLA || y < 4)
	{
		dy *= -1;
	}
	x += dx * velocidad;
	y += dy * velocidad;
}

void Helicoptero::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "    ---|---";
	Console::SetCursorPosition(x, y + 1);
	cout << "*>====[_]L)";
	Console::SetCursorPosition(x, y + 2);
	cout << "     -'-`-";
	Console::ResetColor();
}