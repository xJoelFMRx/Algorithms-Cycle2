#pragma once
#include "Figura.h"

class Pastilla : public Figura
{
private:
	char forma;

public:
	Pastilla(float x, float y);
	void Dibujar() override;
};

Pastilla::Pastilla(float x, float y) : Figura(x, y, 2, 2)
{
	forma = '*';
	color = 15;
}

void Pastilla::Dibujar()
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

//void Pastilla::Dibujar()
//{
//	for (int i = 0; i < ancho; i++)
//	{
//		for (int j = 0; j < alto; j++)
//		{
//			Console::SetCursorPosition(static_cast<int>(x) + j, static_cast<int>(y) + i); cout << forma;
//		}
//	}
//}