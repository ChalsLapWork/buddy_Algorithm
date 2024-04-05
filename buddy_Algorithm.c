// buddy_Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "display2.h"

int main()
{int i=0,ret=1;
while (ret) {
	printf("\nAlgorithm Buddy v3.0.12");
	printf("\nIngrese el Proceso:");
	printf("\n      crear Proceso:(-1-)");
	printf("\n      Matar Proceso:(-2-)");
	printf("\nReset Mem d Proceso:(-3-)");
	printf("\n   Htop de  Proceso:(-4-)");
	printf("\n Salir del Programa:(-5-)");
	printf("\nvalor seleccionado:");
	scanf_s("%i", &i);
	ret=procesar_comando(i);}


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
