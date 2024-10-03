#pragma once
#include "Figura.h"

class Pacman : public Figura
{
private:
	float dx;
	float dy;
	float velocidad;

public:
	Pacman(float x, float y);
	void Mover() override;
	void Dibujar() override;
};

Pacman::Pacman(float x, float y) : Figura(x, y, 7, 4) 
{
	dx = 1;
	dy = 1;
	velocidad = 1.4;
	color = 14;
}

void Pacman::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "  .--.";
	Console::SetCursorPosition(x, y + 1);
	cout << "/ _.-'";
	Console::SetCursorPosition(x, y + 2);
	cout << "\\  '-.";
	Console::SetCursorPosition(x, y + 3);
	cout << " '--'";
	Console::ResetColor();
}

void Pacman::Mover()
{
	if (_kbhit())
	{
		char tecla = _getch();
		switch (tecla)
		{
		case 72: //Arriba
			if (y > 1)
			{
				y -= dy * velocidad;
			}
			break;
		case 75: //Izquierda
			if (x > 1)
			{
				x -= dx * velocidad;
			}
			break;
		case 77: //Derecha
			if (x + ancho < ANCHO_CONSOLA)
			{
				x += dx * velocidad;
			}
			break;
		case 80: //Abajo
			if (y + alto < ALTO_CONSOLA)
			{
				y += dy * velocidad;
			}
			break;
		}
	}
}