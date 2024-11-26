#pragma once
#include "Entidad.h"

class Disco : public Entidad
{
private:
	int typeDisco;	
	int typeDireccion;

public:
	Disco(int x, int y);
	void Mover(Graphics^ g) override;
	void Dibujar(Graphics^ g, Bitmap^ img) override;
	int getTypeDisco();
	void setTypeDisco(int typeDisco);
	Rectangle mascara();
};

Disco::Disco(int x, int y) : Entidad(x, y)
{
	typeDisco = RandInt(1, 2);
	typeDireccion = RandInt(1, 2);
}

void Disco::Mover(Graphics^ g)
{
	ancho = ancho * 0.2;
	alto = alto * 0.2;
	switch (typeDisco)
	{
	case 1: //Movimiento horizontal
		if (typeDireccion == 1 && x + ancho >= g->VisibleClipBounds.Width) typeDireccion = 2; //Cambiar a izquierda
		else if (typeDireccion == 2 && x <= 0) typeDireccion = 1; //Cambiar a derecha
		dx = (typeDireccion == 1) ? 7 : -7;
		dy = 0;
		fila = 0; columna++;
		if (columna > 3) columna = 0;
		break;

	case 2: //Movimiento vertical
		if (typeDireccion == 1 && y + alto >= g->VisibleClipBounds.Height) typeDireccion = 2; //Cambiar a arriba
		else if (typeDireccion == 2 && y <= 0) typeDireccion = 1; //Cambiar a abajo
		dx = 0; 
		dy = (typeDireccion == 1) ? 7 : -7; 
		fila = 1; columna++;
		if (columna > 3) columna = 0;
		break;

	case 3: //Movimiento diagonal aleatorio
		//Detectar colisiones con bordes y ajustar dirección
		if (x <= 0 || x + ancho >= g->VisibleClipBounds.Width)
			dx *= -1; //Invertir dirección horizontal
		if (y <= 0 || y + alto >= g->VisibleClipBounds.Height)
			dy *= -1; //Invertir dirección vertical
		//Si el disco se queda sin dirección (dx = 0 o dy = 0), reasignar valores iniciales
		if (dx == 0 || dy == 0)
		{
			int nuevaDireccion = RandInt(1, 4);
			switch (nuevaDireccion)
			{
			case 1: dx = 7; dy = 7; break;  
			case 2: dx = -7; dy = 7; break; 
			case 3: dx = -7; dy = -7; break;  
			case 4: dx = 7; dy = -7; break;  
			}
		}
		fila = 2; columna++;
		if (columna > 3) columna = 0;
		break;
	}
	x += dx;
	y += dy;
	if (x < 0) x = 0;
	if (x + ancho > g->VisibleClipBounds.Width) x = g->VisibleClipBounds.Width - ancho;
	if (y < 0) y = 0;
	if (y + alto > g->VisibleClipBounds.Height) y = g->VisibleClipBounds.Height - alto;
}

void Disco::Dibujar(Graphics^ g, Bitmap^ img)
{
	ancho = img->Width / 4;
	alto = img->Height / 3;
	Rectangle frame = Rectangle(ancho * columna, alto * fila, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho * 0.2, alto * 0.2);
	g->DrawImage(img, zoom, frame, GraphicsUnit::Pixel);
}

int Disco::getTypeDisco()
{
	return typeDisco;
}

void Disco::setTypeDisco(int typeDisco)
{
	this->typeDisco = typeDisco;
}

Rectangle Disco::mascara()
{
	return Rectangle(x, y, ancho * 0.2, alto * 0.2);
}