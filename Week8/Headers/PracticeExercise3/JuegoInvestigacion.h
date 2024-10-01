#pragma once
#include "Flor.h"
#include "Nave.h"
#include "Dido.h"
#include "Dodo.h"
#include "Particula.h"

class Juego
{
private:
	Nave* nave;
	Dodo* dodo;
	vector<Particula*> particulas;
	vector<Flor*> flores;
	vector<Dido*> didos;
	vector<bool> colisionFlor;
	vector<bool> colisionDido;
	int tiempoInvulnerabilidadDodo;
	int contadorParticulas;
	int contadorVidaVegetal;
	int contadorVidaAnimal;

public:
	Juego();
	~Juego();
	void Iniciar();
	void BorrarObjetos();
	void MoverObjetos();
	void DibujarObjetos();
	void Colision();
	void MostrarEstadisticas();
	bool JuegoTerminado();
};	

Juego::Juego()
{
	contadorParticulas = 0;
	contadorVidaAnimal = 0;
	contadorVidaVegetal = 0;
	tiempoInvulnerabilidadDodo = 0;
	nave = new Nave();
	dodo = new Dodo(RandInt(20, ANCHO_CONSOLA - 8), 6);
	for (int i = 0; i < 6; i++)
	{
		particulas.push_back(new Particula(RandInt(0, ANCHO_CONSOLA - 1), RandInt(4, ALTO_CONSOLA - 1)));
	}
	int numFlores = RandInt(2, 5);
	for (int i = 0; i < numFlores; i++)
	{
		flores.push_back(new Flor(RandInt(0, ANCHO_CONSOLA - 6), RandInt(4, ALTO_CONSOLA - 2)));
		colisionFlor.push_back(false);
	}
	for (int i = 0; i < 4; i++)
	{
		didos.push_back(new Dido(i < 2 ? 1 : ANCHO_CONSOLA - 4, (i + 2) * 6, i < 2 ? 1 : -1));
		colisionDido.push_back(false);  
	}
}

Juego::~Juego()
{
	delete nave;
	delete dodo;
	for (int i = 0; i < particulas.size(); i++)
	{
		delete particulas[i];
	}
	for (int i = 0; i < flores.size(); i++)
	{
		delete flores[i];
	}
	for (int i = 0; i < didos.size(); i++)
	{
		delete didos[i];
	}
	particulas.clear();
	flores.clear();
	didos.clear();
}

void Juego::BorrarObjetos()
{
	nave->BorrarNave();
	dodo->Borrar();
	for (int i = 0; i < particulas.size(); i++)
	{
		particulas[i]->BorrarParticula();
	}
	for (int i = 0; i < flores.size(); i++)
	{
		flores[i]->BorrarFlor();
	}
	for (int i = 0; i < didos.size(); i++)
	{
		didos[i]->Borrar();
	}
}

void Juego::MoverObjetos()
{
	nave->MoverNave();
	dodo->Mover();
	for (int i = 0; i < didos.size(); i++)
	{
		didos[i]->Mover();
	}
	if (tiempoInvulnerabilidadDodo > 0)
	{
		tiempoInvulnerabilidadDodo--;
	}
}

void Juego::DibujarObjetos()
{
	nave->DibujarNave();
	dodo->Dibujar();
	for (int i = 0; i < didos.size(); i++)
	{
		didos[i]->Dibujar();
	}
	for (int i = 0; i < flores.size(); i++)
	{
		flores[i]->DibujarFlor();
	}
	for (int i = 0; i < particulas.size(); i++)
	{
		particulas[i]->DibujarParticula();
	}
}

void Juego::Colision()
{
	for (int i = 0; i < particulas.size(); i++)
	{
		if (nave->getX() < particulas[i]->getX() + particulas[i]->getAncho() &&
			nave->getX() + nave->getAncho() > particulas[i]->getX() &&
			nave->getY() < particulas[i]->getY() + particulas[i]->getAlto() &&
			nave->getY() + nave->getAlto() > particulas[i]->getY())
		{
			particulas[i]->BorrarParticula();
			particulas.erase(particulas.begin() + i);
			contadorParticulas++; 
			i--;
		}
	}

	for (int i = 0; i < flores.size(); i++)
	{
		if (!colisionFlor[i] && nave->getX() < flores[i]->getX() + flores[i]->getAncho() &&
			nave->getX() + nave->getAncho() > flores[i]->getX() &&
			nave->getY() < flores[i]->getY() + flores[i]->getAlto() &&
			nave->getY() + nave->getAlto() > flores[i]->getY())
		{
			colisionFlor[i] = true;
			contadorVidaVegetal++;
		}
	}

	for (int i = 0; i < didos.size(); i++)
	{
		if (!colisionDido[i] && nave->getX() < didos[i]->getX() + didos[i]->getAncho() &&
			nave->getX() + nave->getAncho() > didos[i]->getX() &&
			nave->getY() < didos[i]->getY() + didos[i]->getAlto() &&
			nave->getY() + nave->getAlto() > didos[i]->getY())
		{
			colisionDido[i] = true;
			contadorVidaAnimal++;
		}
	}

	if (tiempoInvulnerabilidadDodo == 0 && nave->getX() < dodo->getX() + dodo->getAncho() &&
		nave->getX() + nave->getAncho() > dodo->getX() &&
		nave->getY() < dodo->getY() + dodo->getAlto() &&
		nave->getY() + nave->getAlto() > dodo->getY())
	{
		contadorVidaAnimal++;
		nave->PerderVida();
		tiempoInvulnerabilidadDodo = 30;
	}
}

void Juego::MostrarEstadisticas()
{
	Console::SetCursorPosition(0, 0);
	cout << "Vida Animal: " << contadorVidaAnimal << "/1";
	Console::SetCursorPosition(30, 0);
	cout << "Vida Vegetal: " << contadorVidaVegetal << "/1";
	Console::SetCursorPosition(60, 0);
	cout << "Pariculas O2: " << contadorParticulas << "/6";
	Console::SetCursorPosition(90, 0);
	cout << "Vida: " << nave->getVidas() << "/3";
}

bool Juego::JuegoTerminado()
{
	if (nave->getVidas() <= 0)
	{
		system("cls");
		string mensaje = "LOST";
		Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
		cout << mensaje;
		return true;
	}
	if (contadorParticulas >= 6 && contadorVidaAnimal >= 1 && contadorVidaVegetal >= 1)
	{
		system("cls");
		string mensaje = "YOU WIN";
		Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
		cout << mensaje;
		return true;
	}
	return false;
}

void Juego::Iniciar()
{
	Ventana();
	while (!JuegoTerminado())
	{
		BorrarObjetos();
		MoverObjetos();
		DibujarObjetos();
		Colision();
		MostrarEstadisticas();
		_sleep(40);
	}
}