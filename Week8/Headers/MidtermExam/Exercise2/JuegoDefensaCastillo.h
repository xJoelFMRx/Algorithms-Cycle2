#pragma once
#include "Castillo.h"
#include "Caballero.h"
#include "Enemigo.h"

class Juego
{
private:
    Castillo* castillo;
    Caballero* caballero;
    vector<Enemigo*> enemigos;
    char formaCorazon;

public:
    Juego();
    ~Juego();
    void Iniciar();
    void DibujarCorazones(int vidas);
    void BorrarCorazones(int vidas);
	void BorrarObjetos();
	void MoverObjetos();
	void DibujarObjetos();
	void Colisiones();
	void MostrarEstadisticas();
	bool JuegoTerminado();
};

Juego::Juego()
{
    formaCorazon = 3;
    caballero = new Caballero((ANCHO_CONSOLA - 4) / 2, ALTO_CONSOLA - 4);
    castillo = new Castillo((ANCHO_CONSOLA - 8) / 2, ALTO_CONSOLA / 2);
    int y_castillo = castillo->getY();
    int separacion = 10;  
    int distancia_extra = 20;  
    bool izquierda_primero = RandInt(0, 1);

    if (izquierda_primero)
    {
        // Posicionar 3 enemigos a la izquierda
        for (int i = 0; i < 3; i++)
        {
            float x = castillo->getX() - distancia_extra - 10 - (i * separacion);
            enemigos.push_back(new Enemigo(x, y_castillo, 1));  
        }

        // Posicionar 2 enemigos a la derecha
        for (int i = 0; i < 2; i++)
        {
            float x = castillo->getX() + castillo->getAncho() + distancia_extra + 5 + (i * separacion);
            enemigos.push_back(new Enemigo(x, y_castillo, -1));  
        }
    }
    else
    {
        // Posicionar 2 enemigos a la izquierda
        for (int i = 0; i < 2; i++)
        {
            float x = castillo->getX() - distancia_extra - 10 - (i * separacion);
            enemigos.push_back(new Enemigo(x, y_castillo, 1)); 
        }

        // Posicionar 3 enemigos a la derecha
        for (int i = 0; i < 3; i++)
        {
            float x = castillo->getX() + castillo->getAncho() + distancia_extra + 5 + (i * separacion);
            enemigos.push_back(new Enemigo(x, y_castillo, -1));  
        }
    }
}

Juego::~Juego()
{
    delete castillo;
    delete caballero;
    for (int i = 0; i < enemigos.size(); i++)
    {
        delete enemigos[i];
    }
    enemigos.clear();
}

void Juego::BorrarObjetos()
{
    castillo->Borrar();
    caballero->BorrarCaballero();
    for (int i = 0; i < enemigos.size(); i++)
    {
        enemigos[i]->Borrar();
    }
}

void Juego::MoverObjetos()
{
    caballero->Mover();
    for (int i = 0; i < enemigos.size(); i++)
    {
        enemigos[i]->Mover();
    }
}

void Juego::DibujarObjetos()
{
    castillo->Dibujar();
    caballero->Dibujar();
    for (int i = 0; i < enemigos.size(); i++)
    {
        enemigos[i]->Dibujar();
    }
}

void Juego::Colisiones()
{
    vector<Arco*> flechas = caballero->getFlechas();
    for (int i = 0; i < enemigos.size(); i++)
    {
        for (int j = 0; j < flechas.size(); j++)
        {
            if (flechas[j]->getX() < enemigos[i]->getX() + enemigos[i]->getAncho() &&
                flechas[j]->getX() + flechas[j]->getAncho() > enemigos[i]->getX() &&
                flechas[j]->getY() < enemigos[i]->getY() + enemigos[i]->getAlto() &&
                flechas[j]->getY() + flechas[j]->getAlto() > enemigos[i]->getY())
            {
                enemigos[i]->Borrar();
                enemigos.erase(enemigos.begin() + i);

                flechas[j]->Borrar();
                delete flechas[j];
                flechas.erase(flechas.begin() + j);
                break;
            }
        }
    }

    for (int i = 0; i < enemigos.size(); i++)
    {
        if (enemigos[i]->getX() < castillo->getX() + castillo->getAncho() &&
            enemigos[i]->getX() + enemigos[i]->getAncho() > castillo->getX() &&
            enemigos[i]->getY() < castillo->getY() + castillo->getAlto() &&
            enemigos[i]->getY() + enemigos[i]->getAlto() > castillo->getY())
        {
            caballero->PerderVida();
            BorrarCorazones(caballero->getVidas());
            enemigos[i]->Borrar();
            enemigos.erase(enemigos.begin() + i);
        }
    }
}

void Juego::DibujarCorazones(int vidas)
{
    Console::SetCursorPosition(40, 0);
    cout << "Vidas: ";
    for (int i = 0; i < vidas; i++)
    {
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(48 + i, 0); cout << formaCorazon;
        Console::ResetColor();
    }
}

void Juego::BorrarCorazones(int vidas)
{
    for (int i = 0; i <= vidas; i++)
    {
        Console::SetCursorPosition(48 + i, 0); cout << "                ";
    }
}

bool Juego::JuegoTerminado()
{
    if (caballero->getVidas() <= 0)
    {
        system("cls");
        string mensaje = "DERROTA!!";
        Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
        cout << mensaje;
        return true;
    }
    if (enemigos.empty())
    {
        system("cls");
        string mensaje = "VICTORIA!!";
        Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
        cout << mensaje;
        return true;
    }
    return false;
}

void Juego::MostrarEstadisticas()
{
    BorrarCorazones(caballero->getVidas());
    DibujarCorazones(caballero->getVidas());
    Console::SetCursorPosition(88, 0);
    cout << "Enemigos: " << enemigos.size();
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
        _sleep(50);
    }
}