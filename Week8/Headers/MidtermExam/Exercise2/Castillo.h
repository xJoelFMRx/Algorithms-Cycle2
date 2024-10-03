#pragma once
#include "Entidad.h"

class Castillo : public Entidad
{
private:

public:
	Castillo(float x, float y);
	void Dibujar() override;
};

Castillo::Castillo(float x, float y) : Entidad(x, y, 8, 4)
{
	color = 7;
}

void Castillo::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << " |||||";
	Console::SetCursorPosition(x, y + 1);
	cout << " |||||";
	Console::SetCursorPosition(x, y + 2);
	cout << "|||||||";
	Console::SetCursorPosition(x, y + 3);
	cout << "=======";
	Console::ResetColor();
}