#pragma once
#include "Ovni.h"

class Alfa : public Ovni
{
private:
	int color;

public:
	Alfa();
	void DibujarAlfa();
};

Alfa::Alfa() : Ovni(1.5, 19, 5)
{
	color = 14;
}

void Alfa::DibujarAlfa()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(this->x, this->y);
	cout << "      _.---._";
	Console::SetCursorPosition(this->x, this->y + 1);
	cout << "       .' '.";
	Console::SetCursorPosition(this->x, this->y + 2);
	cout << "_.-~===========~-._";
	Console::SetCursorPosition(this->x, this->y + 3);
	cout << "(_________________)";
	Console::SetCursorPosition(this->x, this->y + 4);
	cout << "     \\_______/";
	Console::ResetColor();
}