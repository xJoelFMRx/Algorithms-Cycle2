#pragma once
#include "iostream"
#include "string"
#include "sstream"
#include "fstream"

using namespace System::Drawing;
using namespace std;
using namespace System::Collections::Generic;

int RandInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}