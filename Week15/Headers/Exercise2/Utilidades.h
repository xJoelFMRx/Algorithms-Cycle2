#pragma once
#include "iostream"
#include "vector"
#include "fstream"
#include "string"
#include "sstream"

using namespace std;
using namespace System::Drawing;

int RandInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}