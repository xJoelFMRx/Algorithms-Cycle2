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
	int fila;
	int columna;
	
public:
	Entidad(int x, int y);
	virtual void Dibujar(Graphics^ g, Bitmap^ img);
	virtual void Mover(Graphics^ g);
};

Entidad::Entidad(int x, int y)
{
	this->x = x;
	this->y = y;
	ancho = 0;
	alto = 0;
	dx = 0;
	dy = 0;
	fila = 0;
	columna = 0;
}

void Entidad::Dibujar(Graphics^ g, Bitmap^ img){}

void Entidad::Mover(Graphics^ g){}