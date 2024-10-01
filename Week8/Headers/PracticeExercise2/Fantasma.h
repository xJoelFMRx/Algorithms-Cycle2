#pragma once
#include "Figura.h"

class Fantasma : public Figura
{
private:
	float dx;
	float velocidad;

public:
	Fantasma(float x, float y);
	void Mover() override;
	void Dibujar() override;
};

int seleColor[2] = { 9,12 };

Fantasma::Fantasma(float x, float y) : Figura(x, y, 7, 4) 
{
	dx = 1;
	color = seleColor[RandInt(0, 1)];
	velocidad = 1.8;
}

void Fantasma::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y); 
	cout << " ,--.";
	Console::SetCursorPosition(x, y + 1);
	cout << "| oo |";
	Console::SetCursorPosition(x, y + 2);
	cout << "| ~~ |";
	Console::SetCursorPosition(x, y + 3);
	cout << "|/\\/\\|";
	Console::ResetColor();
}

void Fantasma::Mover()
{
	if (x + ancho >= ANCHO_CONSOLA || x < 0)
	{
		dx *= -1;
	}
	x += dx * velocidad;
}