#pragma once
#include "Jugador.h"
#include "Avion.h"
#include "Helicoptero.h"

class Juego
{
private:
	Jugador* jugador;
	vector<Avion*> aviones;
	vector<Helicoptero*> helicopteros;
	int tiempoInvulnerabilidadAviones;
	int contadorAvionesDerribados;
	int contadorHelicopteros;
	int contadorColisionesConVehiculos;

public:
	Juego();
	~Juego();
	void Iniciar();
	void BorrarObjetos();
	void MoverObjetos();
	void DibujarObjetos();
	void Colisiones();
	void MostrarEstadisticas();
	void MostrarReporte();
	bool JuegoTerminado();
};

Juego::Juego()
{
	tiempoInvulnerabilidadAviones = 0;
	contadorAvionesDerribados = 0;
	contadorHelicopteros = 1;
	contadorColisionesConVehiculos = 0;
	jugador = new Jugador();
	for (int i = 0; i < 6; i++)
	{
		float x = RandInt(2, ANCHO_CONSOLA - 12);
		float y = RandInt(3, ALTO_CONSOLA - 4);
		float dx = RandInt(0, 1) == 0 ? -1 : 1;
		float dy = RandInt(0, 1) == 0 ? -1 : 1;
		aviones.push_back(new Avion(x, y, dx, dy));
	}
	float hx = RandInt(2, ANCHO_CONSOLA - 12);
	float hy = RandInt(3, ALTO_CONSOLA - 4);
	float hdx = RandInt(0, 1) == 0 ? -1 : 1;
	float hdy = RandInt(0, 1) == 0 ? -1 : 1;
	helicopteros.push_back(new Helicoptero(hx, hy, hdx, hdy));
}

Juego::~Juego()
{
	delete jugador;
	for (int i = 0; i < aviones.size(); i++)
	{
		delete aviones[i];
	}
	for (int i = 0; i < helicopteros.size(); i++)
	{
		delete helicopteros[i];
	}
	aviones.clear();
	helicopteros.clear();
}

void Juego::BorrarObjetos()
{
	jugador->BorrarJugador();
	for (int i = 0; i < aviones.size(); i++)
	{
		aviones[i]->Borrar();
	}
	for (int i = 0; i < helicopteros.size(); i++)
	{
		helicopteros[i]->Borrar();
	}
}

void Juego::MoverObjetos()
{
	jugador->MoverJugador();
	for (int i = 0; i < aviones.size(); i++)
	{
		aviones[i]->Mover();
	}
	for (int i = 0; i < helicopteros.size(); i++)
	{
		helicopteros[i]->Mover();
	}
}

void Juego::DibujarObjetos()
{
	jugador->DibujarJugador();
	for (int i = 0; i < aviones.size(); i++)
	{
		aviones[i]->Dibujar();
	}
	for (int i = 0; i < helicopteros.size(); i++)
	{
		helicopteros[i]->Dibujar();
	}
}

void Juego::Colisiones()
{
	if (tiempoInvulnerabilidadAviones > 0)
	{
		tiempoInvulnerabilidadAviones--;
	}
	vector<Bala*> balas = jugador->getBalas();
	for (int i = 0; i < aviones.size(); i++)
	{
		for (int j = 0; j < balas.size(); j++)
		{
			if (balas[j]->getX() >= aviones[i]->getX() && balas[j]->getX() <= aviones[i]->getX() + aviones[i]->getAncho() &&
				balas[j]->getY() >= aviones[i]->getY() && balas[j]->getY() <= aviones[i]->getY() + aviones[i]->getAlto())
			{
				contadorColisionesConVehiculos++;
				aviones[i]->Borrar();
				aviones.erase(aviones.begin() + i);
				contadorAvionesDerribados++;

				balas[j]->BorrarBala();
				delete balas[j];
				balas.erase(balas.begin() + j);
				break;
			}
		}
	}

	for (int i = 0; i < helicopteros.size(); i++)
	{
		for (int j = 0; j < balas.size(); j++)
		{
			if (balas[j]->getX() >= helicopteros[i]->getX() && balas[j]->getX() <= helicopteros[i]->getX() + helicopteros[i]->getAncho() &&
				balas[j]->getY() >= helicopteros[i]->getY() && balas[j]->getY() <= helicopteros[i]->getY() + helicopteros[i]->getAlto())
			{
				contadorColisionesConVehiculos++;
				float hx = RandInt(1, ANCHO_CONSOLA - 12);
				float hy = RandInt(3, ALTO_CONSOLA - 4);
				float hdx = RandInt(0, 1) == 0 ? -1 : 1;
				float hdy = RandInt(0, 1) == 0 ? -1 : 1;
				helicopteros.push_back(new Helicoptero(hx, hy, hdx, hdy));
				contadorHelicopteros++;

				balas[j]->BorrarBala();
				delete balas[j] ;
				balas.erase(balas.begin() + j);
				break;
			}
		}
	}

	for (int i = 0; i < aviones.size(); i++)
	{
		if (tiempoInvulnerabilidadAviones == 0 && jugador->getX() >= aviones[i]->getX() && jugador->getX() <= aviones[i]->getX() + aviones[i]->getAncho() &&
			jugador->getY() >= aviones[i]->getY() && jugador->getY() <= aviones[i]->getY() + aviones[i]->getAlto())
		{
			jugador->PerderVida();
			tiempoInvulnerabilidadAviones = 30;
			if (jugador->getVidas() <= 0)
			{
				break;
			}
		}
	}
}

void Juego::MostrarEstadisticas()
{
	Console::SetCursorPosition(0, 0);
	cout << "Colisiones Bala - Vehiculos: " << contadorColisionesConVehiculos;
	Console::SetCursorPosition(40, 0);
	cout << "Cantidad Helicopteros: " << contadorHelicopteros;
	Console::SetCursorPosition(72, 0);
	cout << "Aviones Derribados: " << contadorAvionesDerribados;
	Console::SetCursorPosition(102, 0);
	cout << "Vidas: " << jugador->getVidas() << "/3";
}

void Juego::MostrarReporte()
{
	if (aviones.size() == 0)
	{
		system("cls");
		Console::SetCursorPosition(57, 16);
		cout << "===== FIN DEL JUEGO - GANASTE! =====";
		Console::SetCursorPosition(57, 17);
		cout << "Total Colisiones Bala - Vehiculos: " << contadorColisionesConVehiculos;
		Console::SetCursorPosition(57, 18);
		cout << "Total Aviones Derribados: " << contadorAvionesDerribados;
		Console::SetCursorPosition(57, 19);
		cout << "Total de Helicopteros: " << contadorHelicopteros;
	}
	else
	{
		system("cls");
		Console::SetCursorPosition(57, 16);
		cout << "===== FIN DEL JUEGO - PERDISTE! =====";
		Console::SetCursorPosition(57, 17);
		cout << "Total Colisiones Bala - Vehiculos: " << contadorColisionesConVehiculos;
		Console::SetCursorPosition(57, 18);
		cout << "Total Aviones Derribados: " << contadorAvionesDerribados;
		Console::SetCursorPosition(57, 19);
		cout << "Total de Helicopteros: " << contadorHelicopteros;
	}
}

bool Juego::JuegoTerminado()
{
	return jugador->getVidas() <= 0 || aviones.size() == 0; //o aviones.empty()
}

void Juego::Iniciar()
{
	Ventana();
	while (!JuegoTerminado())
	{
		BorrarObjetos();
		MoverObjetos();
		DibujarObjetos();
		Colisiones();
		MostrarEstadisticas();
		_sleep(40);
	}
	MostrarReporte();
}