#pragma once
#include "Entidad.h"

class Pikachu : public Entidad
{
private:
	int fila;
	int columna;
	int typeDireccion;
	int velocidad;

public:
	Pikachu(int x, int y);
	void Dibujar(Graphics^ g, Bitmap^ img) override;
	void Mover(Graphics^ g) override;
	Rectangle mascara();
};

Pikachu::Pikachu(int x, int y) : Entidad(x, y)
{
	fila = 0;
	columna = 0;
	typeDireccion = RandInt(1, 4);
	velocidad = RandInt(4, 8);
}

void Pikachu::Dibujar(Graphics^ g, Bitmap^ img)
{
	ancho = img->Width / 4;
	alto = img->Height / 4;
	Rectangle frame = Rectangle(ancho * columna, alto * fila, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho, alto);
	g->DrawImage(img, zoom, frame, GraphicsUnit::Pixel);
}

void Pikachu::Mover(Graphics^ g)
{
	if (typeDireccion == 1 && x + ancho >= g->VisibleClipBounds.Width)
	{
		typeDireccion = 2;
	}
	else if (typeDireccion == 2 && x <= 0)
	{
		typeDireccion = 1;
	}
	else if (typeDireccion == 3 && y + alto >= g->VisibleClipBounds.Height)
	{
		typeDireccion = 4;
	}
	else if (typeDireccion == 4 && y <= 0)
	{
		typeDireccion = 3;
	}
	switch (typeDireccion)
	{
	case 1:
		dx = 1; dy = 0; fila = 2; columna++; if (columna > 3) columna = 0;
		break;
	case 2:
		dx = -1; dy = 0; fila = 1; columna++; if (columna > 3) columna = 0;
		break;
	case 3:
		dx = 0; dy = 1; fila = 0; columna++; if (columna > 3) columna = 0;
		break;
	case 4:
		dx = 0; dy = -1; fila = 3; columna++; if (columna > 3) columna = 0;
		break;
	}
	x += dx * velocidad;
	y += dy * velocidad;
	if (x < 0)
	{
		x = 0;
	}
	if (y < 0)
	{
		y = 0;
	}
	if (x + ancho > g->VisibleClipBounds.Width) 
	{
		x = g->VisibleClipBounds.Width - ancho;
	}
	if (y + alto > g->VisibleClipBounds.Height) 
	{
		y = g->VisibleClipBounds.Height - alto;
	}
}

Rectangle Pikachu::mascara()
{
	return Rectangle(x, y, ancho, alto);
}