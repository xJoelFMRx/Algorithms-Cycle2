#pragma once
#include "Pacman.h"
#include "Pastilla.h"
#include "Fantasma.h"

class Juego
{
private:
	Pacman* pacman;
	vector<Pastilla*> pastillas;
	vector<Fantasma*> fantasmas;
	vector<float> posicionesOcupadasX;
	vector<float> posicionesOcupadasY;
	bool juegoTerminado;
	bool esPosicionOcupada(float x, float y, int ancho, int alto);
	void agregarPosicion(float x, float y);

public:
	Juego();
	~Juego();
	void Iniciar();
	void BorrarObjetos();
	void MoverObjetos();
	void DibujarObjetos();
	void Colision();
	Fantasma* generarFantasma();
	Pastilla* generarPastilla();
};

Juego::Juego()
{
	juegoTerminado = false;
	pacman = new Pacman((ANCHO_CONSOLA - 7) / 2, ALTO_CONSOLA - 4);
	for (int i = 0; i < 4; i++)
	{
		pastillas.push_back(generarPastilla());
	}
	for (int i = 0; i < 4; i++)
	{
		fantasmas.push_back(generarFantasma());
	}
}

Juego::~Juego()
{
	delete pacman;
	for (int i = 0; i < fantasmas.size(); i++)
	{
		delete fantasmas[i];
	}
	for (int i = 0; i < pastillas.size(); i++)
	{
		delete pastillas[i];
	}
	fantasmas.clear();
	pastillas.clear();
}

bool Juego::esPosicionOcupada(float x, float y, int ancho, int alto)
{
	for (int i = 0; i < posicionesOcupadasX.size(); i++)
	{
		float posX = posicionesOcupadasX[i];
		float posY = posicionesOcupadasY[i];
		if ((x < posX + ancho && x + ancho > posX) && (y < posY + alto && y + alto > posY))
		{
			return true;
		}
	}
	return false;
}

void Juego::agregarPosicion(float x, float y)
{
	posicionesOcupadasX.push_back(x);
	posicionesOcupadasY.push_back(y);
}

void Juego::Colision()
{
	for (int i = 0; i < fantasmas.size(); i++)
	{
		if (pacman->getX() < fantasmas[i]->getX() + fantasmas[i]->getAncho() &&
			pacman->getX() + pacman->getAncho() > fantasmas[i]->getX() &&
			pacman->getY() < fantasmas[i]->getY() + fantasmas[i]->getAlto() &&
			pacman->getY() + pacman->getAlto() > fantasmas[i]->getY())
		{
			system("cls");
			string mensaje = "IMPACTO PACMAN CON FANTASMA !!! - GAME OVER !!!";
			Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
			cout << mensaje;
			juegoTerminado = true;
			return;
		}
	}

	for (int i = 0; i < pastillas.size(); i++)
	{
		if (pacman->getX() < pastillas[i]->getX() + pastillas[i]->getAncho() &&
			pacman->getX() + pacman->getAncho() > pastillas[i]->getX() &&
			pacman->getY() < pastillas[i]->getY() + pastillas[i]->getAlto() &&
			pacman->getY() + pacman->getAlto() > pastillas[i]->getY())
		{
			pastillas[i]->Borrar();
			delete pastillas[i];
			pastillas.erase(pastillas.begin() + i);
			i--;

			if (pastillas.empty())
			{
				system("cls");
				string mensaje = "FELICITACIONES !!! UD. ES EL GANADOR !!!";
				Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
				cout << mensaje;
				juegoTerminado = true;
				return; 
			}
		}
	}
}

void Juego::BorrarObjetos()
{
	pacman->Borrar();
	for (int i = 0; i < fantasmas.size(); i++)
	{
		fantasmas[i]->Borrar();
	}
	for (int i = 0; i < pastillas.size(); i++)
	{
		pastillas[i]->Borrar();
	}
}

void Juego::MoverObjetos()
{
	pacman->Mover();
	for (int i = 0; i < fantasmas.size(); i++)
	{
		fantasmas[i]->Mover();
	}
}

void Juego::DibujarObjetos()
{
	pacman->Dibujar();
	for (int i = 0; i < pastillas.size(); i++)
	{
		pastillas[i]->Dibujar();
	}
	for (int i = 0; i < fantasmas.size(); i++)
	{
		fantasmas[i]->Dibujar();
	}
}

Fantasma* Juego::generarFantasma()
{
	float x;
	float y;
	do
	{
		if (RandInt(0, 1) == 0)
		{
			x = 0;
		}
		else
		{
			x = ANCHO_CONSOLA - 7;
		}
		y = RandInt(0, ALTO_CONSOLA - 5); 
	} while (esPosicionOcupada(x, y, 7, 4));
	agregarPosicion(x, y);
	return new Fantasma(x, y);
}

Pastilla* Juego::generarPastilla()
{
	float x;
	float y;
	do
	{
		x = RandInt(0, ANCHO_CONSOLA - 2);
		y = RandInt(0, ALTO_CONSOLA - 5);
	} while (esPosicionOcupada(x, y, 2, 2));
	agregarPosicion(x, y);
	return new Pastilla(x, y);
}

void Juego::Iniciar()
{
	Ventana();
	while (!juegoTerminado)
	{
		BorrarObjetos();
		MoverObjetos();
		DibujarObjetos();
		Colision();
		_sleep(50);	
	}
}