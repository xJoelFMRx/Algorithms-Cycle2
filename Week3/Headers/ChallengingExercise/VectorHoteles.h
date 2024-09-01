#pragma once
#include "Hotel.h"

class VectorHoteles
{
private:
	int numHoteles;
	Hotel** hoteles;

public:
	VectorHoteles();
	~VectorHoteles();
	void RegistrarHotel(Hotel* hotel);
	void ModificarHotel(int indice, Hotel* NuevoHotel);
	void EliminarHotel(int indice);
	int getNumHoteles();
	Hotel* obtenerDatosHotel(int indice);
};

VectorHoteles::VectorHoteles()
{
	numHoteles = 0;
	hoteles = nullptr;
}

VectorHoteles::~VectorHoteles()
{
	if (hoteles != nullptr)
	{
		for (int i = 0; i < numHoteles; i++)
		{
			delete hoteles[i];
		}
		delete[] hoteles;
	}
}

void VectorHoteles::RegistrarHotel(Hotel* hotel)
{
	Hotel** temp = new Hotel * [numHoteles + 1];
	for (int i = 0; i < numHoteles; i++)
	{
		temp[i] = hoteles[i];
	}
	temp[numHoteles] = hotel;
	numHoteles++;
	delete[] hoteles;
	hoteles = temp;
}

void VectorHoteles::ModificarHotel(int indice, Hotel* nuevoHotel)
{
	if (indice < 0 || indice >= numHoteles)
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	delete hoteles[indice];
	hoteles[indice] = nuevoHotel;

}
int VectorHoteles::getNumHoteles()
{
	return numHoteles;
}

void VectorHoteles::EliminarHotel(int indice)
{
	if (indice < 0 || indice >= numHoteles)
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	delete hoteles[indice];
	Hotel** temp = new Hotel * [numHoteles - 1];
	for (int i = 0, j = 0; i < numHoteles; i++)
	{
		if (i != indice)
		{
			temp[j++] = hoteles[i];
		}
	}
	numHoteles--;
	delete[] hoteles;
	hoteles = temp;
}

Hotel* VectorHoteles::obtenerDatosHotel(int indice)
{
	if (indice < 0 || indice >= numHoteles)
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return nullptr;
	}
	return hoteles[indice];
}

