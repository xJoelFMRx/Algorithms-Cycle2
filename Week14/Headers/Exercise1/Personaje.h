#pragma once
#include "Entidad.h"

enum Tecla
{
	Izquierda, Derecha, Arriba, Abajo, Ninguno
};

class Personaje : public Entidad
{
private:
	Tecla tecla;
	int vidas;

public:
	Personaje(int x, int y, int vidas);
	void Mover(Graphics^ g) override;
	void Dibujar(Graphics^ g, Bitmap^ img) override;
	void setTecla(Tecla tecla);
	int getVidas();
	void bajarVidas();
	void RegresarPosicionInicial();
	Rectangle mascara();
};

Personaje::Personaje(int x, int y, int vidas) : Entidad(x, y)
{
	tecla = Ninguno;
	this->vidas = vidas;
}

void Personaje::Mover(Graphics^ g)
{
	switch (tecla)
	{
	case Arriba:
		dx = 0; dy = -6; fila = 3; columna++; if (columna > 3) columna = 0;
		break;
	case Abajo:
		dx = 0; dy = 6; fila = 0; columna++; if (columna > 3) columna = 0;
		break;
	case Derecha:
		dx = 6; dy = 0; fila = 2; columna++; if (columna > 3) columna = 0;
		break;
	case Izquierda:
		dx = -6; dy = 0; fila = 1; columna++; if (columna > 3) columna = 0;
		break;
	case Ninguno:
		dx = 0; dy = 0;
		break;
	}
	if (x < 0)
	{
		x = 0;
	}
	if (y < 0)
	{
		y = 0;
	}
	if (x >= g->VisibleClipBounds.Width - ancho)
	{
		x = g->VisibleClipBounds.Width - ancho;
	}
	if (y >= g->VisibleClipBounds.Height - alto)
	{
		y = g->VisibleClipBounds.Height - alto;
	}
	x += dx;
	y += dy;
}

void Personaje::Dibujar(Graphics^ g, Bitmap^ img)
{
	ancho = img->Width / 4;
	alto = img->Height / 4;
	Rectangle frame = Rectangle(ancho * columna, alto * fila, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho, alto);
	g->DrawImage(img, zoom, frame, GraphicsUnit::Pixel);
}

void Personaje::setTecla(Tecla tecla)
{
	this->tecla = tecla;
}

Rectangle Personaje::mascara()
{
	return Rectangle(x, y, ancho, alto);
}

int Personaje::getVidas()
{
	return vidas;
}

void Personaje::bajarVidas()
{
	vidas--;
}

void Personaje::RegresarPosicionInicial()
{
	x = 350;
	y = 300;
}