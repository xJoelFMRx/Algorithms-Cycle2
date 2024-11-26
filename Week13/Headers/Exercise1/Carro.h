#pragma once
#include "Utilidades.h"

enum Animacion
{
	Libre, ArbolR, ArbolV
};

ref class Carro
{
private:
	int x;
	int y;
	int ancho;
	int alto;
	int fila;
	int columna;
	Animacion animacion;

public:
	Carro(int x, int y);
	void MoverCarro();
	void DibujarCarro(Graphics^ g, Bitmap^ img);
	Animacion getAnimacion();
	void setAnimacion(Animacion animacion);
	int getX();
	int getY();
};

Carro::Carro(int x, int y)
{
	this->x = x;
	this->y = y;
	fila = 0;
	columna = 0;
	animacion = Libre;
}

void Carro::DibujarCarro(Graphics^ g, Bitmap^ img)
{
	ancho = img->Width / 5;
	alto = img->Height / 3;
	Rectangle frame = Rectangle(ancho * columna, alto * fila, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho, alto);
	g->DrawImage(img, zoom, frame, GraphicsUnit::Pixel);
}

void Carro::MoverCarro()
{
	switch (animacion)
	{
	case Libre:
		fila = 0; columna++; if (columna > 4) columna = 0;
		break;
	case ArbolR:
		fila = 1; columna++; if (columna > 4) columna = 0;
		break;
	case ArbolV:
		fila = 2; columna++; if (columna > 4) columna = 0;
		break;
	}
}

void Carro::setAnimacion(Animacion animacion)
{
	this->animacion = animacion;
}

Animacion Carro::getAnimacion()
{
	return animacion;
}

int Carro::getX()
{
	return x;
}

int Carro::getY()
{
	return y;
}