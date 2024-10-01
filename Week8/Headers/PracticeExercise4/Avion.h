#pragma once
#include "VehiculoAereo.h"

class Avion : public VehiculoAereo
{
private:

public:
	Avion(float x, float y, float dx, float dy);
	void Mover() override;
	void Dibujar() override;
};

Avion::Avion(float x, float y, float dx, float dy) : VehiculoAereo(x, y, dx, dy, 12, 3)
{
	velocidad = RandFloat(1.3, 1.7);
	color = 3;
}

void Avion::Mover()
{
	if (x + ancho > ANCHO_CONSOLA || x < 1)
	{
		dx *= -1;
	}
	if (y + alto + 2 > ALTO_CONSOLA || y < 5)
	{
		dy *= -1;
	}
	x += dx * velocidad;
	y += dy * velocidad;
}

void Avion::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y); 
	cout << "   __!__";
	Console::SetCursorPosition(x, y + 1);
	cout << "____(_)____";
	Console::SetCursorPosition(x, y + 2);
	cout << "    o o";
	Console::ResetColor();
}