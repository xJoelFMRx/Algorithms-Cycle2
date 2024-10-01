#pragma once
#include "Utilidades.h"

class Nave
{
private:
	float x;
	float y;
	float dx;
	float dy;
	float velocidad;
	int ancho;
	int alto;
	int color;
	int vidas;

public:
	Nave();
	void BorrarNave();
	void MoverNave();
	void DibujarNave();
	void PerderVida();
	float getX();
	float getY();
	int getAncho();
	int getAlto();
	int getVidas();
};

Nave::Nave()
{
	x = 0;
	y = 4;
	dx = 1;
	dy = 1;
	velocidad = 2;
	ancho = 16;
	alto = 4;
	color = 1;
	vidas = 3;
}

void Nave::BorrarNave()
{
	for (int i = 0; i < alto; i++)
	{
		Console::SetCursorPosition(x, y + i);
		for (int j = 0; j < ancho; j++)
		{
			cout << " ";
		}
	}
}

void Nave::DibujarNave()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "      ___";
	Console::SetCursorPosition(x, y + 1);
	cout << "  ___/   \\___";
	Console::SetCursorPosition(x, y + 2);
	cout << "(    'O^O'    )";
	Console::SetCursorPosition(x, y + 3);
	cout << " '==ooooooo=='";
	Console::ResetColor();
}

void Nave::MoverNave()
{
	if (_kbhit())
	{
		char tecla = _getch();
		switch (tecla)
		{
		case 72: //Arriba
			if (y > 4)
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
			if (y + alto + 1 < ALTO_CONSOLA)
			{
				y += dy * velocidad;
			}
			break;
		}
	}
}

void Nave::PerderVida()
{
	vidas--;
}

int Nave::getVidas()
{
	return vidas;
}

float Nave::getX()
{
	return x;
}

float Nave::getY()
{
	return y;
}

int Nave::getAncho()
{
	return ancho;
}

int Nave::getAlto()
{
	return alto;
}