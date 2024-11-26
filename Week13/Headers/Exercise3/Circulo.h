#pragma once
#include "Entidad.h"

ref class Circulo : public Entidad
{
private:
	int radio;
	Color color;

public:
	Circulo(int x, int y, int dx, int dy, int radio, Color color);
	void Mover(Graphics^ g);
	void DibujarCirculo(Graphics^ g);
	int getRadio();
};

Circulo::Circulo(int x, int y, int dx, int dy, int radio, Color color) : Entidad(x, y)
{
	this->dx = dx;
	this->dy = dy;
	this->radio = radio;
	this->color = color;
}

void Circulo::Mover(Graphics^ g)
{
	if (x < 0 || x + radio >= g->VisibleClipBounds.Width)
	{
		dx *= -1;
	}
	if (y < 0 || y + radio >= g->VisibleClipBounds.Height)
	{
		dy *= -1;
	}
	x += dx;
	y += dy;
}

void Circulo::DibujarCirculo(Graphics^ g)
{
	SolidBrush^ brocha = gcnew SolidBrush(color);
	g->FillEllipse(brocha, x, y, radio, radio);
}

int Circulo::getRadio()
{
	return radio;
}