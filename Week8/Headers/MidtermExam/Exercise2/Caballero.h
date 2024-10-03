#pragma once
#include "Arco.h"

class Caballero : public Entidad
{
private:
	float dx;
	float dy;
	float velocidad;
	int vidas;
	vector<Arco*> flechas;

public:
	Caballero(float x, float y);
	void Mover() override;
	void Dibujar() override;
	void BorrarCaballero();
	void Disparar();
	void PerderVida();
	int getVidas();
	vector<Arco*> getFlechas();
};

Caballero::Caballero(float x, float y) : Entidad(x, y, 4, 3)
{
	color = 9;
	dx = 0;
	dy = 0;
	velocidad = 1.8;
	vidas = 3;
}

void Caballero::BorrarCaballero()
{
	for (int i = 0; i < alto; i++)
	{
		Console::SetCursorPosition(x, y + i);
		for (int j = 0; j < ancho; j++)
		{
			cout << " ";
		}
	}

	for (int i = 0; i < flechas.size(); i++)
	{
		flechas[i]->Borrar();
	}
}

void Caballero::Dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << " O";
	Console::SetCursorPosition(x, y + 1);
	cout << "/|\\";
	Console::SetCursorPosition(x, y + 2);
	cout << "/ \\";
	Console::ResetColor();

	for (int i = 0; i < flechas.size(); i++)
	{
		flechas[i]->DibujarArco();
	}
}

void Caballero::Mover()
{
	if (_kbhit())
	{
		char tecla = _getch();
		switch (tecla)
		{
		case 72: //Arriba
			if (y > 4)
			{
				dx = 0;
				dy = -1;
			}
			break;
		case 75: //Izquierda
			if (x > 1)
			{
				dx = -1;
				dy = 0;
			}
			break;
		case 77: //Derecha
			if (x + ancho < ANCHO_CONSOLA)
			{
				dx = 1;
				dy = 0;
			}
			break;
		case 80: //Abajo
			if (y + alto  < ALTO_CONSOLA)
			{
				dx = 0;
				dy = 1;
			}
			break;
		case 'p':
			Disparar();
			break;
		default:
			dx = 0;
			dy = 0;
			break;
		}
		x += dx * velocidad;
		y += dy * velocidad;
	}

	for (int i = 0; i < flechas.size(); i++)
	{
		flechas[i]->MoverArco();
		if (flechas[i]->fueraDeLimite())
		{
			flechas.erase(flechas.begin() + i);
		}
	}
}

void Caballero::Disparar()
{
	flechas.push_back(new Arco(x + 2, y + 1, dx, dy));
}

void Caballero::PerderVida()
{
	vidas--;
}

int Caballero::getVidas()
{
	return vidas;
}

vector<Arco*> Caballero::getFlechas()
{
	return flechas;
}