#pragma once
#include "iostream"
#include "vector"
#include "fstream"
#include "sstream"
#include "string"

using namespace System::Drawing;
using namespace std;

int RandInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}