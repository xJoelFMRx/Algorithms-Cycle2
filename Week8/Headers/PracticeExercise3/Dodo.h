#pragma once
#include "Ave.h"

class Dodo : public Ave
{
private:
	float dy;
	
public:
	Dodo(float x, float y);
	void Mover() override;
	void Dibujar() override;
};

Dodo::Dodo(float x, float y) : Ave(x, y, 8, 4)
{
	velocidad = RandFloat(1.5, 2.3);
	color = 5;
	dy = 1;
}

void Dodo::Mover()
{
	if (y + alto + 2 > ALTO_CONSOLA  || y < 6)
	{
		dy *= -1;
	}
	y += dy * velocidad;
}

void Dodo::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y); 
	cout << " /\\ /\\";
	Console::SetCursorPosition(x, y + 1);
	cout << "((ovo))";
	Console::SetCursorPosition(x, y + 2);
	cout << "():::()";
	Console::SetCursorPosition(x, y + 3);
	cout << "  VVV";
	Console::ResetColor();
}