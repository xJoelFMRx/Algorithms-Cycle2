#pragma once
#include "Utilidades.h"

class Entidad
{
protected:
	int x;
	int y;
	int dx; 
	int dy;
	int ancho;
	int alto;

public:
	Entidad(int x, int y);
	virtual void Mover(Graphics^ g);
	virtual void Dibujar(Graphics^ g, Bitmap^ img);
};

Entidad::Entidad(int x, int y)
{
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 0;
	ancho = 0;
	alto = 0;
}

void Entidad::Mover(Graphics^ g){}

void Entidad::Dibujar(Graphics^ g, Bitmap^ img){}