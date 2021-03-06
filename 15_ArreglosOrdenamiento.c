// Ejemplos.cpp: define el punto de entrada de la aplicaci�n de consola.
// Mario Alberto Ibarra Manzano
/*	Universidad de Guanajuato
	Divisi�n de Ingenier�as del Campus Irapuato-Salamanca
	Programaci�n en Ingenier�a*/

/*
Función: Calcular la media de un arreglo y ordenarlo.
Además de los calculos para obtener la media de un arreglo vistas en el programa anterior, en este se ordena un vector por el método de burbuja y de intercambio.
En el ordenamiento de burbuja se hacen dos ciclos for. Lo que hace este algoritmo es comparar desde el primer elemento del arreglo con todos los siguientes.
si encuentra qu el elemento tomado es mayor que el elemento que sigue entonces hace un intercambio. Este algoritmo no es efiicente.
El algoritmo de intercambio sólo ocupa un ciclo for. En este se asume que los elementos anteriores ya están ordenados así que empieza comparando el primer y segundo elemento, se guarda el elemento en una variable auxiliar.
Se compara si es menor que el siguiente e intercambia los elementos. En la siguiente iteracion se comparan el segundo con el tercero y así subsiguientemente.
En la función main se pide el número de datos el cual tiene como máximo 100 y mínimo 1. Luego se piden los valores máximos y mínimos.
En caso de que el valor máximo sea menos que el mínimo se intercambian.
Los datos del arreglo son calculados aleatoriamente con la librería time.h y srand(time(NULL)). Se multiplica el rango por rand() y se divide entre RAND_MAX + min.
También se calcula la media por los dos métodos y al final se imprimen los resultados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

float media(float X[], int n)
{
	int i;
	float med;
	for (i = 0, med = 0; i < n; med+=X[i++]);
	return med/n;
}

float media2(float x[], int n)
{
	static int i = 0;
	float c;
	if (i < n)
	{
		c = x[i++] / n;
		return media2(x, n) + c;
	}
	else
		return 0;
}

// Algoritmo burbuja
int burbuja(float X[], int n)
{
	int i, j;
	for (i = 0; i < (n - 1); i++)
		for (j = i + 1; j < n; j++)
			if (X[i] > X[j])
			{
				X[i] = X[i] + X[j];
				X[j] = X[i] - X[j];
				X[i] = X[i] - X[j];
			}
	return 0;
}

int intercambio(float X[], int n)
{
	int i, j;
	float aux;
	for (i = 1; i < n; i++)
	{
		j = i-1;
		aux = X[i];
		while (aux<X[j])
		{
			X[j + 1] = X[j];
			j--;
			if (j == -1)
				break;
		}
		X[j+1] = aux;
	}
	return 0;
}

int main()
{
	float X[N], med, med2, max, min, aux;
	int n, i;
	srand(time(NULL));
	do {
		printf("Ingrese el numero de datos: ");
		scanf("%d", &n);
	} while ((n<1)||(n>N));
	printf("Ingrese el valor maximo: ");
	scanf("%f", &max);
	printf("Ingrese el valor minimo: ");
	scanf("%f", &min);
	if (min > max)
	{
		min = min + max;
		max = min - max;
		min = min - max;
		/*
		aux = min;
		min = max;
		max = aux;
		*/
	}
	printf("Maximo: %f\nMinimo: %f\n", max, min);
	printf("El valor del vector generado es:\n");
	for (i = 0; i < n; i++)
	{
		X[i] = (max - min)*rand() / RAND_MAX + min;
		printf("X[%d] = %f\n", i+1, X[i]);
	}
	med = media(X, n);
	med2 = media2(X, n);
	intercambio(X, n);
	printf("El valor del vector ordenado es:\n");
	for (i = 0; i < n; i++)
		printf("X[%d] = %f\n", i+1, X[i]);
	printf("La media es %f\n", med);
	printf("La media es %f\n", med2);
	getchar();
	getchar();
    return 0;
}
