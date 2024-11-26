#pragma once
#include "Utilidades.h"

ref class Entidad
{
protected:
	int x;
	int y;
	int dx;
	int dy;

public:
	Entidad(int x, int y);
};

Entidad::Entidad(int x, int y)
{
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 0;
}