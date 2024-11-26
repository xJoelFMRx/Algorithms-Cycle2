#pragma once
#include "Entidad.h"

class Pokebola : public Entidad
{
private:

public:
	Pokebola(int x, int y, int dx, int dy);
	void MoverPokebola();
	void Dibujar(Graphics^ g, Bitmap^ img) override;
	Rectangle mascara();
	bool FueraDeLimites(Graphics^ g);
};

Pokebola::Pokebola(int x, int y, int dx, int dy) : Entidad(x, y)
{
	this->dx = dx;
	this->dy = dy;
	ancho = 20;
	alto = 20;
}

void Pokebola::Dibujar(Graphics^ g, Bitmap^ img)
{
	g->DrawImage(img, x + 20, y + 20, ancho, alto);
}

void Pokebola::MoverPokebola()
{
	x += dx;
	y += dy;
}

Rectangle Pokebola::mascara()
{
	return Rectangle(x, y, ancho, alto);
}

bool Pokebola::FueraDeLimites(Graphics^ g)
{
	return (x < 0 || y < 0 || x + ancho >= g->VisibleClipBounds.Width || y + alto >= g->VisibleClipBounds.Height); 
}