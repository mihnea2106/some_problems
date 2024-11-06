//Grigore Mihnea - Andrei, 331CA
#include  <stdio.h>
#include <stdlib.h>

#define NMAX 1000

typedef struct {
	int a, b, c, d, e, f, g;
} segment;

// proceseaza forma cifrei in matrice
void fill(int v1, int v2, int v3, int v4, int a[][NMAX], segment *v6);

//aplica comenzile de translatie in matrice
void modify(int v1, int v2, char v7, long v8, int a[][NMAX]);

int main(void)
{
	int a[NMAX][NMAX];
	int n, m, l;

	scanf("%d%d%d", &n, &m, &l);
	char c, buffer;

	scanf("%c%c", &buffer, &c);
	//structura defineste segmentele pentru fiecare cifra
	segment division[] = {
		{1, 1, 1, 1, 1, 1, 0}, // 0
		{0, 1, 1, 0, 0, 0, 0}, // 1
		{1, 1, 0, 1, 1, 0, 1}, // 2
		{1, 1, 1, 1, 0, 0, 1}, // 3
		{0, 1, 1, 0, 0, 1, 1}, // 4
		{1, 0, 1, 1, 0, 1, 1}, // 5
		{1, 0, 1, 1, 1, 1, 1}, // 6
		{1, 1, 1, 0, 0, 0, 0}, // 7
		{1, 1, 1, 1, 1, 1, 1}, // 8
		{1, 1, 1, 1, 0, 1, 1}  // 9
	};
	while (c != 'Q') {
		if (c == 'F') {
			int cifra;

			scanf("%d", &cifra);
			if (cifra < 0 || cifra > 9) {
				printf("The input given is not a digit.\n"); //eroare
			} else {
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						a[i][j] = 0;
				fill(n, m, cifra, l, a, division); //prelucrare
			}
		} else if (c == 'P') { //afisare
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					if (a[i][j] == 1)
						printf("^ ");
					else
						printf("  ");
			printf("\n");
			}
			printf("\n");
		} else if (c == 'W' || c == 'A' || c == 'S' || c == 'D') {
			//comanda translatie
			long count;

			scanf("%ld", &count);
			modify(n, m, c, count, a);
		} else {
			printf("Invalid command.\n"); //eroare
		}
		scanf("%c%c", &buffer, &c);
		while (buffer != '\n') { //caractere in plus
			buffer = c;
			scanf("%c", &c);
		}
	}
	return 0;
}

void fill(int n, int m, int cifra, int l, int a[][NMAX], segment *division)
{
	int h = l / 3;

	// Segment a
	if (division[cifra].a)
		for (int row = 0; row < h; row++)
			for (int i = h; i < l + h && i < m - h; i++)
				a[row][i] = 1;

	// Segment b
	if (division[cifra].b)
		for (int col = m - h; col < m; col++)
			for (int i = h; i < h + l && i < n; i++)
				a[i][col] = 1;

	// Segment c
	if (division[cifra].c)
		for (int col = m - h; col < m; col++)
			for (int i = 2 * h + l; i < 2 * h + 2 * l && i < n; i++)
				a[i][col] = 1;

	// Segment d
	if (division[cifra].d)
		for (int row = 2 * h + 2 * l; row < 2 * h + 2 * l + h && row < n; row++)
			for (int i = h; i < l + h && i < m - h; i++)
				a[row][i] = 1;

	// Segment e
	if (division[cifra].e)
		for (int col = 0; col < h; col++)
			for (int i = 2 * h + l; i < 2 * h + 2 * l && i < n; i++)
				a[i][col] = 1;

	// Segment f
	if (division[cifra].f)
		for (int col = 0; col < h; col++)
			for (int i = h; i < h + l && i < n; i++)
				a[i][col] = 1;
	// Segment g
	if (division[cifra].g)
		for (int row = h + l; row < h + l + h && row < n; row++)
			for (int i = h; i < l + h && i < m - h; i++)
				a[row][i] = 1;
}

void modify(int n, int m, char c, long count, int a[][NMAX])
{
	int temp[NMAX][NMAX] = {0};
	int effective_count;

	if (c == 'W' || c == 'S')
		effective_count = count % n;  // Sus / Jos
	else
		effective_count = count % m;  // Stanga / Dreapta
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 1) {
				int new_i = i;
				int new_j = j;

				if (c == 'W') // Sus
					new_i = (i - effective_count + n) % n;
				else if (c == 'S') // Jos
					new_i = (i + effective_count) % n;
				else if (c == 'A') // Stanga
					new_j = (j - effective_count + m) % m;
				else if (c == 'D') // Dreapta
					new_j = (j + effective_count) % m;
				temp[new_i][new_j] = 1;
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = temp[i][j]; //modificare matrice initiala
}
