#pragma once
#include "iostream"
#include "vector"
#include "sstream"
#include "fstream"
#include "string"

using namespace System::Drawing;
using namespace std;
using namespace System::Collections::Generic;

int RandInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}