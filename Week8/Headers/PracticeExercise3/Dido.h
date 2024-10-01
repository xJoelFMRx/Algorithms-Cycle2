#pragma once
#include "Ave.h"

class Dido : public Ave
{
private:
	float dx;
	float xOriginal;

public:
	Dido(float x, float y, float dx);
	void Mover() override;
	void Dibujar() override;
};

Dido::Dido(float x, float y, float dx) : Ave(x, y, 4, 2)
{
	color = 12;
	this->dx = dx;
	velocidad = RandFloat(1.7, 2.7);
	xOriginal = x;
}

void Dido::Mover()
{
	if (x + ancho > ANCHO_CONSOLA || x < 1)
	{
		x = xOriginal;
	}
	else
	{
		x += dx * velocidad;
	}
}

void Dido::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	if (dx == 1)
	{
		Console::SetCursorPosition(x, y);
		cout << "(U<";
		Console::SetCursorPosition(x, y + 1);
		cout << "<_)";
	}
	else if (dx == -1)
	{
		Console::SetCursorPosition(x, y);
		cout << ">U)";
		Console::SetCursorPosition(x, y + 1);
		cout << "(_>";
	}
	Console::ResetColor();
}