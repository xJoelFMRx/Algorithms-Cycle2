#pragma once
#include "Bala.h"

class Jugador
{
private:
	char forma;
	float x;
	float y;
	float dx;
	float dy;
	float velocidad;
	int ancho;
	int alto;
	int color;
	int vidas;
	vector<Bala*> balas;

public:
	Jugador();
	void BorrarJugador();
	void MoverJugador();
	void DibujarJugador();
	void Disparar();
	int getVidas();
	void PerderVida();
	float getX();
	float getY();
	int getAncho();
	int getAlto();
	vector<Bala*> getBalas();
};

Jugador::Jugador()
{
	forma = 219;
	x = ANCHO_CONSOLA / 2;
	y = ALTO_CONSOLA - 1;
	dx = 0;
	dy = 0;
	velocidad = 1.8;
	ancho = 1;
	alto = 1;
	color = 12;
	vidas = 3;
}

void Jugador::BorrarJugador()
{
	for (int i = 0; i < alto; i++)
	{
		Console::SetCursorPosition(x, y + i);
		for (int j = 0; j < ancho; j++)
		{
			cout << " ";
		}
	}

	for (int i = 0; i < balas.size(); i++)
	{
		balas[i]->BorrarBala();
	}
}

void Jugador::DibujarJugador()
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

	for (int i = 0; i < balas.size(); i++)
	{
		balas[i]->DibujarBala();
	}
}

void Jugador::MoverJugador()
{
	if (_kbhit())
	{
		char tecla = _getch();
		switch (tecla)
		{
		case 72: //Arriba
			if (y > 5)
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
			if (x + ancho + 1 < ANCHO_CONSOLA)
			{
				dx = 1;
				dy = 0;
			}
			break;
		case 80: //Abajo
			if (y + alto < ALTO_CONSOLA)
			{
				dx = 0;
				dy = 1;
			}
			break;
		case 32: //Espacio
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
	for (int i = 0; i < balas.size(); i++)
	{
		balas[i]->MoverBala();
		if (balas[i]->fueraDeLimite())
		{
			balas.erase(balas.begin() + i);
		}
	}
}

float Jugador::getX()
{
	return x;
}

float Jugador::getY()
{
	return y;
}

int Jugador::getAncho()
{
	return ancho;
}

int Jugador::getAlto()
{
	return alto;
}

int Jugador::getVidas()
{
	return vidas;
}

void Jugador::PerderVida()
{
	vidas--;
}

void Jugador::Disparar()
{
	balas.push_back(new Bala(x, y, dx, dy));
}

vector<Bala*> Jugador::getBalas()
{
	return balas;
}