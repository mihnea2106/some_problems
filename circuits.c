// Copyright Grigore Mihnea - Andrei
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define NMAX 1000

//trateaza circuitul Kirchhoff I
void kirchhoff_1(double *v1, double *v2);
//trateaza circuitul Kirchhoff II
void kirchhoff_2(void);

int main(void)
{
	char c, buffer;

	scanf("%c", &c);
	scanf("%c", &buffer);
	if (c == 'I' && buffer == '\n') { //kirchhoff_1
		double intrari[NMAX] = {0}, iesiri[NMAX] = {0};

		kirchhoff_1(intrari, iesiri);
	}
	if (c == 'I' && buffer == 'I') {
		char buffer2;

		scanf("%c", &buffer2);
		if (buffer2 != '\n')
			printf("Legile existente sunt doar Legea 1 si Legea a 2-a\n");
		else
			kirchhoff_2();
	}
	return 0;
}

void kirchhoff_1(double *intrari, double *iesiri) // ok
{
	int n, w;

	scanf("%d %d", &n, &w);
	int nod1, nod2, nod = NMAX + 1;
	double val;
	int pass[NMAX] = {0};

	for (int i = 0; i < w; i++) {
		scanf("%d %d", &nod1, &nod2);
		scanf("%lf", &val);
		intrari[nod1] += val;
		iesiri[nod2] += val;
		pass[nod1]++;
		pass[nod2]++;
	}
	for (int i = 0; i < n; i++)
		if (iesiri[i] == 0 && intrari[i] != 0)
			if (pass[i] == 0 || pass[i] == 1) {
				printf("Circuitul este deschis in nodul %d.\n", i);
				return;
		}
	bool ok = 1;
	int i;

	for (i = 0; i < n; i++) {
		bool deschis = 1;

		if (intrari[i] == 0 && iesiri[i] == 0) {
			for (int j = i; j <= n; j++)
				if (intrari[j] != 0 || iesiri[j] != 0) {
					deschis = 0;
					break;
				}
			if (deschis) {
				printf("Circuitul este deschis in nodul %d.\n", i);
				return;
			}
		}
		if (fabs(intrari[i] - iesiri[i]) > 0.00000001 && nod > i) {
			ok = 0;
			nod = i;
		}
	}
	if (ok) {
		printf("Legea 1 a lui Kirchhoff se respecta pentru circuitul dat.\n");
	} else {
		printf("Legea 1 a lui Kirchhoff nu se respecta pentru egalitatea ");
		printf("%.9lfA = %.9lfA in nodul %d", iesiri[nod], intrari[nod], nod);
		printf(".\n");
	}
}

void kirchhoff_2(void)//ok
{
	int n, w, negative = 0;
	double plus = 0, minus = 0;

	scanf("%d %d", &n, &w);
	for (int i = 0; i < w; i++) {
		int nod1, nod2;

		scanf("%d %d", &nod1, &nod2);
		double curent;
		int k;
		double cplus = plus, cminus = minus;

		scanf("%lf %d", &curent, &k);
		for (int j = 0; j < k; j++) {
			char type, buffer;
			double rez;

			scanf("%c %c %lf", &buffer, &type, &rez);
			if (type == 'E' && rez < 0) {
				printf("Sursa de tensiune nu poate fi negativa.\n");
				return;
			}
			if (rez < 0) {
				negative++;
				plus = cplus;
				minus = cminus;
				break;
			}
			if (type == 'R')
				minus += curent * rez;
			else if (type == 'E')
				plus += rez;
			else
				printf("Componenta dorita nu exista.\n");
		}
	}
	for (int i = 0; i < negative; i++)
		printf("Componenta dorita nu exista.\n");
	if (fabs(minus - plus) < 0.0000000001) {
		printf("Legea a 2-a lui Kirchhoff se respecta pentru circuitul dat.\n");
	} else {
		printf("Legea a 2-a lui Kirchhoff nu se respecta pentru egalitatea ");
		printf("%.9lfV = %.9lfV.\n", minus, plus);
	}
}
