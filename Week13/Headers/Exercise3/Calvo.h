#pragma once
#include "Entidad.h"

enum Tecla
{
	Izquierda, Derecha, Arriba, Abajo
};

ref class Calvo : public Entidad
{
private:
	int ancho;
	int alto;
	int fila;
	int columna;
	bool enBorde;
	Tecla tecla;

public:
	Calvo(int x, int y);
	bool Mover(Graphics^ g);
	void DibujarCalvo(Graphics^ g, Bitmap^ img);
	void setTecla(Tecla tecla);
};

int Direccion[2] = { Izquierda, Derecha };

Calvo::Calvo(int x, int y) : Entidad(x, y)
{
	fila = 0;
	columna = 0;
	tecla = static_cast<Tecla>(Direccion[RandInt(0, 1)]); 
	enBorde = false;
}

bool Calvo::Mover(Graphics^ g)
{
	bool mensajeMostrado = false;
	switch (tecla)
	{
	case Arriba:
		dx = 0; dy = -7; fila = 3; columna++; if (columna > 7) columna = 0;
		break;
	case Abajo:
		dx = 0; dy = 7; fila = 0; columna++; if (columna > 7) columna = 0; 
		break;
	case Izquierda:
		dx = -7; dy = 0; fila = 1; columna++; if (columna > 7) columna = 0;
		break;
	case Derecha:
		dx = 7; dy = 0; fila = 2; columna++; if (columna > 7) columna = 0;
		break;
	}
	if (x <= 0)
	{
		x = 0;
		if (!enBorde)
		{
			mensajeMostrado = true;
			enBorde = true;
		}
	}
	else if (y <= 0)
	{
		y = 0;
		if (!enBorde)
		{
			mensajeMostrado = true;
			enBorde = true;
		}
	}
	else if (x >= g->VisibleClipBounds.Width - ancho)
	{
		x = g->VisibleClipBounds.Width - ancho;
		if (!enBorde)
		{
			mensajeMostrado = true;
			enBorde = true;
		}
	}
	else if (y >= g->VisibleClipBounds.Height - alto)
	{
		y = g->VisibleClipBounds.Height - alto;
		if (!enBorde)
		{
			mensajeMostrado = true;
			enBorde = true;
		}
	}
	else
	{
		//Si ya no está en el borde, restablecer el estado
		enBorde = false;
	}
	x += dx;
	y += dy;
	return mensajeMostrado;
}

void Calvo::setTecla(Tecla tecla)
{
	this->tecla = tecla;
}

void Calvo::DibujarCalvo(Graphics^ g, Bitmap^ img)
{
	ancho = img->Width / 8;
	alto = img->Height / 4;
	Rectangle frame = Rectangle(ancho * columna, alto * fila, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho, alto);
	g->DrawImage(img, zoom, frame, GraphicsUnit::Pixel);
}