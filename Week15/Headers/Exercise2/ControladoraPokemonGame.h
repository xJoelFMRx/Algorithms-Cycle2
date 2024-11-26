#pragma once
#include "Ash.h"
#include "Pikachu.h"

class Controladora
{
private:
	Ash* ash;
	vector<Pikachu*> pikachus;
	int tiempoTotal;
	clock_t tiempoInicio;

public:
	Controladora();
	~Controladora();
	void Iniciar(Graphics^ g, Bitmap^ imgAsh, Bitmap^ imgPikachu, Bitmap^ imgPokebola, Bitmap^ imgEscenario);
	void MoverObjetos(Graphics^ g);
	void DibujarObjetos(Graphics^ g, Bitmap^ imgAsh, Bitmap^ imgPikachu, Bitmap^ imgPokebola);
	void ColisionesPokebolaPokemon();
	void MostrarEscenario(Graphics^ g, Bitmap^ imgEscenario);
	void AgregarPikachus();
	Ash* getAsh();
	void LeerConfiguracion();
	bool JugadorGano();
	bool JuegoTerminado();
	int getTiempoJuego();
};

Controladora::Controladora()
{
	ash = nullptr;
	tiempoTotal = 0;
	tiempoInicio = 0;
	AgregarPikachus();
}

Controladora::~Controladora()
{
	delete ash;
	for (int i = 0; i < pikachus.size(); i++)
	{
		delete pikachus[i];
	}
	pikachus.clear();
}

void Controladora::MoverObjetos(Graphics^ g)
{
	ash->Mover(g);
	for (int i = 0; i < pikachus.size(); i++)
	{
		pikachus[i]->Mover(g);
	}
}

void Controladora::DibujarObjetos(Graphics^ g, Bitmap^ imgAsh, Bitmap^ imgPikachu, Bitmap^ imgPokebola)
{
	ash->DibujarAsh(g, imgAsh, imgPokebola);
	for (int i = 0; i < pikachus.size(); i++)
	{
		pikachus[i]->Dibujar(g, imgPikachu);
	}
}

Ash* Controladora::getAsh()
{
	return ash;
}

void Controladora::AgregarPikachus()
{
	int cantidad = RandInt(2, 5);
	for (int i = 0; i < cantidad; i++)
	{
		int x = RandInt(0, 890);
		int y = RandInt(0, 487);
		pikachus.push_back(new Pikachu(x, y));
	}
}

void Controladora::MostrarEscenario(Graphics^ g, Bitmap^ imgEscenario)
{
	g->DrawImage(imgEscenario, 0, 0, 1000, 600);
}

int Controladora::getTiempoJuego()
{
	//Calcula el tiempo transcurrido en segundos
	clock_t tiempoActual = clock();
	int tiempoTranscurrido = (tiempoActual - tiempoInicio) / CLOCKS_PER_SEC;
	//Devuelve el tiempo restante
	return max(0, tiempoTotal - tiempoTranscurrido); //Asegura que no devuelva un valor negativo
}

bool Controladora::JuegoTerminado()
{
	return (ash->getVidas() <= 0 || getTiempoJuego() <= 0);
}

bool Controladora::JugadorGano()
{
	return getTiempoJuego() > 0 && pikachus.empty();
}

void Controladora::LeerConfiguracion()
{
	ifstream archivo("configuracion.txt");
	if (!archivo.is_open())
	{
		//Si el archivo no existe o no se puede abrir, no hacer nada.
		cout << "Error: El archivo de configuracion no existe." << endl;
		return;
	}
	int x = 0, y = 282, vidas = 5, tiempo = 20; //Valores predeterminados de respaldo
	//A partir de aca lee el archivo si se abre correctamente
	string linea;
	//Leer cada linea del archivo
	while (getline(archivo, linea))
	{
		size_t posIgual = linea.find('=');
		if (posIgual != string::npos)
		{
			string clave = linea.substr(0, posIgual);
			int valor = stoi(linea.substr(posIgual + 1));
			//Asignar los valores leidos a las variables correspondientes
			if (clave == "X") x = valor;
			else if (clave == "Y") y = valor;
			else if (clave == "N") vidas = valor;
			else if (clave == "T") tiempo = valor;
		}
	}
	//Crear un nuevo personaje Ash con los valores leidos
	ash = new Ash(x, y, vidas);
	tiempoTotal = tiempo;
	tiempoInicio = clock();
	archivo.close();
}

void Controladora::ColisionesPokebolaPokemon()
{
	for (int i = 0; i < pikachus.size(); i++)
	{
		for (int j = 0; j < ash->getPokebolas().size(); j++)
		{
			if (pikachus[i]->mascara().IntersectsWith(ash->getPokebolas()[j]->mascara()))
			{
				pikachus.erase(pikachus.begin() + i);
				ash->EliminarPokebola(j);
				break;
			}
		}
	}
}

void Controladora::Iniciar(Graphics^ g, Bitmap^ imgAsh, Bitmap^ imgPikachu, Bitmap^ imgPokebola, Bitmap^ imgEscenario)
{
	MostrarEscenario(g, imgEscenario);
	MoverObjetos(g);
	DibujarObjetos(g, imgAsh, imgPikachu, imgPokebola);
	ColisionesPokebolaPokemon();
}