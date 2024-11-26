#pragma once
#include "Pokebola.h"

enum Tecla
{
	Izquierda, Derecha, Arriba, Abajo, Ninguno
};

class Ash : public Entidad
{
private:
	int fila;
	int columna;
	int vidas;
	Tecla tecla;
	Tecla ultimaTecla;
	vector<Pokebola*> pokebolas;
	
public:
	Ash(int x, int y, int vidas);
	~Ash();
	void DibujarAsh(Graphics^ g, Bitmap^ imgAsh, Bitmap^ imgPokebola);
	void Mover(Graphics^ g) override;
	void setTecla(Tecla tecla);
	Rectangle mascara();
	void RegresarPosicionInicial();
	void DisminuirVidas();
	void LanzarPokebola();
	void EliminarPokebola(int posicion);
	int getVidas();
	vector<Pokebola*> getPokebolas();
};

Ash::Ash(int x, int y, int vidas) : Entidad(x, y)
{
	this->vidas = vidas;
	fila = 0;
	columna = 0;
	tecla = Ninguno;
	ultimaTecla = Abajo;
}

Ash::~Ash()
{
	for (int i = 0; i < pokebolas.size(); i++)
	{
		delete pokebolas[i];
	}
	pokebolas.clear();
}

void Ash::setTecla(Tecla tecla)
{
	this->tecla = tecla;
}

int Ash::getVidas()
{
	return vidas;
}

void Ash::DisminuirVidas()
{
	vidas--;
}

Rectangle Ash::mascara()
{
	return Rectangle(x, y, ancho, alto);
}

void Ash::EliminarPokebola(int posicion)
{
	pokebolas.erase(pokebolas.begin() + posicion);
}

vector<Pokebola*> Ash::getPokebolas()
{
	return pokebolas;
}

void Ash::DibujarAsh(Graphics^ g, Bitmap^ imgAsh, Bitmap^ imgPokebola)
{
	ancho = imgAsh->Width / 4;
	alto = imgAsh->Height / 4;
	Rectangle frame = Rectangle(ancho * columna, alto * fila, ancho, alto);
	Rectangle zoom = Rectangle(x, y, ancho, alto);
	g->DrawImage(imgAsh, zoom, frame, GraphicsUnit::Pixel);
	for (int i = 0; i < pokebolas.size(); i++)
	{
		pokebolas[i]->Dibujar(g, imgPokebola);
	}
}

void Ash::Mover(Graphics^ g)
{
	switch (tecla)
	{
	case Arriba:
		dx = 0; dy = -9; fila = 3; columna++; if (columna > 3) columna = 0; ultimaTecla = Arriba;
		break;
	case Abajo:
		dx = 0; dy = 9; fila = 0; columna++; if (columna > 3) columna = 0; ultimaTecla = Abajo;
		break;
	case Derecha:
		dx = 9; dy = 0; fila = 2; columna++; if (columna > 3) columna = 0; ultimaTecla = Derecha;
		break;
	case Izquierda:
		dx = -9; dy = 0; fila = 1; columna++; if (columna > 3) columna = 0; ultimaTecla = Izquierda;
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
	for (int i = 0; i < pokebolas.size(); i++)
	{
		pokebolas[i]->MoverPokebola();
		if (pokebolas[i]->FueraDeLimites(g))
		{
			EliminarPokebola(i);
			DisminuirVidas();
			RegresarPosicionInicial();
		}
	}
}

void Ash::LanzarPokebola()
{
	switch (ultimaTecla)
	{
	case Arriba:
		pokebolas.push_back(new Pokebola(x, y, 0, -16));
		break;
	case Abajo:
		pokebolas.push_back(new Pokebola(x, y, 0, 16));
		break;
	case Derecha:
		pokebolas.push_back(new Pokebola(x, y, 16, 0));
		break;
	case Izquierda:
		pokebolas.push_back(new Pokebola(x, y, -16, 0));
		break;
	}
}

void Ash::RegresarPosicionInicial()
{
	ifstream archivo("configuracion.txt");
	if (archivo.is_open())
	{
		string linea;
		while (getline(archivo, linea))
		{
			size_t posIgual = linea.find('=');
			if (posIgual != string::npos)
			{
				string clave = linea.substr(0, posIgual);
				int valor = stoi(linea.substr(posIgual + 1));
				if (clave == "X") x = valor;
				else if (clave == "Y") y = valor;
			}
		}
		archivo.close();
	}
	else
	{
		//Valores predeterminados si no existe el archivo
		x = 0;
		y = 282;
	}
}