#pragma once
#include "iostream"
#include "string"

using namespace std;

class Password
{
private:
	int longitud;
	string password;
	void generarPassword();

public:
	Password();
	Password(int longitud);
	bool esSeguro();
	string getPassword();
	int getLongitud();
	void setLongitud(int longitud);
};

Password::Password()
{
	longitud = 40;
	generarPassword();
}

Password::Password(int longitud)
{
	this->longitud = longitud;
	generarPassword();
}

bool Password::esSeguro()
{
	int contMayus = 0;
	int contMinus = 0;
	int contNum = 0;
	for (int i = 0; i < longitud; i++)
	{
		if (isdigit(password[i]))
		{
			contNum++;
		}
		else if (islower(password[i]))
		{
			contMinus++;
		}
		else if (isupper(password[i]))
		{
			contMayus++;
		}
	}
	if (contNum > 5 && contMayus > 2 && contMinus > 1)
	{
		return true;
	}
	return false;
}

void Password::generarPassword()
{
	string candidatos = "";
	password = "";
	for (char letra = 'a'; letra <= 'z'; letra++)
	{
		candidatos += letra;
	}
	for (char LETRA = 'A'; LETRA <= 'Z'; LETRA++)
	{
		candidatos += LETRA;
	}
	for (char num = '0'; num <= '9'; num++)
	{
		candidatos += num;
	}

	for (int i = 0; i < longitud; i++)
	{
		password += candidatos[rand() % 62];
	}
}

string Password::getPassword()
{
	return password;
}

int Password::getLongitud()
{
	return longitud;
}

void Password::setLongitud(int longitud)
{
	this->longitud = longitud;
}