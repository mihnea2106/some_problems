// Copyright Grigore Mihnea - Andrei
#include <stdio.h>
#include <stdlib.h>

void patrat(int v1, long v2);
void dreptunghi(int v1, int v2);
void triunghi(int v1, long v2);
void cruce(int v1, long v2);
void window(int v1);

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		if (i)
			printf("\n");
		char c, buffer;
		scanf("%c%c", &buffer, &c);
		if (c == 'p') { //patrat
			long dimensiune, unghi;
			scanf("%ld %ld", &dimensiune, &unghi);
			if (dimensiune < 0)// invalid
				if (i != n - 1)
					printf("Unsupported size to display shape\n");
				else
					printf("Unsupported size to display shape");
			else if (unghi % 45 != 0)
				if (i != n - 1)
					printf("Unsupported angle to display shape\n");
				else
					printf("Unsupported angle to display shape");
			else
				patrat(dimensiune, unghi);
		}
		if (c == 'd') { //dreptunghi
			int l, h;
			scanf("%d %d", &l, &h);
			if (l <= 0 || h <= 0)//dimensiune negativa
				if (i != n - 1)
					printf("Unsupported size to display shape\n");
				else
					printf("Unsupported size to display shape");
			else
				dreptunghi(l, h);
		}
		if (c == 't') {
			long dimensiune, unghi;
			scanf("%ld %ld", &dimensiune, &unghi);
			if (dimensiune < 0)//dimensiune negativa
				if (i != n - 1)
					printf("Unsupported size to display shape\n");
				else
					printf("Unsupported size to display shape");
			else if (llabs(unghi) % 90 != 0)
				if (i != n - 1)
					printf("Unsupported angle to display shape\n");
				else
					printf("Unsupported angle to display shape");
			else
				triunghi(dimensiune, unghi);
		}
		if (c == 'c') {
			long dimensiune, unghi;
			scanf("%ld %ld", &dimensiune, &unghi);
			if (dimensiune < 0 || dimensiune % 2 == 0)//dimensiune negativa
				if (i != n - 1)
					printf("Unsupported size to display shape\n");
				else
					printf("Unsupported size to display shape");
			else if (llabs(unghi) % 45 != 0)
				if (i != n - 1)
					printf("Unsupported angle to display shape\n");
				else
					printf("Unsupported angle to display shape");
			else
				cruce(dimensiune, unghi);
		}
		if (c == 'f') {
			int n;
			scanf("%d", &n);
			if (n % 2 == 0)
				if (i != n - 1)
					printf("Unsupported size to display shape\n");
				else
					printf("Unsupported size to display shape");
			else
				window(n);
		}
	}
}

void patrat(int dimensiune, long unghi) //ok
{
	if ((llabs(unghi) / 45) % 2 == 0) { //patrat
		for (int i = 0; i < dimensiune; i++) {
			for (int j = 0; j < dimensiune; j++)
				printf("*");
			printf("\n");
		}
		return;
	}
	for (int i = 0; i < dimensiune; i++) { //romb
		for (int j = 0; j < dimensiune - i - 1; j++)
			printf(" ");
		for (int j = 0; j < 2 * i + 1; j++)
			printf("*");
		printf("\n");
	}
	for (int i = dimensiune - 2; i >= 0; i--) {
		for (int j = 0; j < dimensiune - i - 1; j++)
			printf(" ");
		for (int j = 0; j < 2 * i + 1; j++)
			printf("*");
		printf("\n");
	}
}

void dreptunghi(int l, int h) //ok
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < l; j++)
			printf("*");
		printf("\n");
	}
}

void triunghi(int dimensiune, long unghi) //ok
{
	int k = llabs(unghi) / 360 + 1;

	if (unghi < 0)
		unghi = 360 * k + unghi;
	int caz = unghi / 90;

	caz = caz % 4;
	if (caz == 0) { //ok - 0 grade
		for (int i = 0; i < dimensiune; i++) {
			for (int j = 0; j <= i; j++)
				printf("*");
			printf("\n");
		}
		return;
	}
	if (caz == 1) { //ok - 90 grade
		for (int i = 0; i < dimensiune; i++) {
			for (int j = dimensiune; j > i; j--)
				printf("*");
			printf("\n");
		}
		return;
	}
	if (caz == 2) { //ok - 180 grade
		for (int i = 0; i < dimensiune; i++) {
			for (int j = 0; j < i; j++)
				printf(" ");
			for (int j = dimensiune; j > i; j--)
				printf("*");
			printf("\n");
		}
		return;
	}
	if (caz == 3) { //ok - 270
		for (int i = 0; i < dimensiune; i++) {
			for (int j = 0; j < dimensiune - i; j++)
				printf(" ");
			for (int j = 0; j <= i; j++)
				printf("*");
			printf("\n");
		}
		return;
	}
}

void cruce(int dimensiune, long unghi) //ok
{
	if (llabs(unghi) % 90 == 0) {
		for (int i = 0; i < dimensiune / 2; i++) {
			for (int j = 0; j < dimensiune / 2; j++)
				printf(" ");
			printf("*");
			for (int j = dimensiune / + 1; j < dimensiune; j++)
				printf(" ");
			printf("\n");
		}
		for (int i = 0; i < dimensiune; i++)
			printf("*");
		printf("\n");
		for (int i = dimensiune / 2 + 1; i < dimensiune; i++) {
			for (int j = 0; j < dimensiune / 2; j++)
				printf(" ");
			printf("*");
			for (int j = dimensiune / + 1; j < dimensiune; j++)
				printf(" ");
			printf("\n");
		}
		return;
	}
	// cruce in X
	for (int i = 0; i < dimensiune; i++) {
		for (int j = 0; j < dimensiune; j++)
			if (i == j || i + j == dimensiune - 1)
				printf("*");
			else
				printf(" ");
		printf("\n");
	}
}

void window(int n) //ok
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (i == 0 || i == n - 1 || j == 0 ||
				j == n - 1 || i == n / 2 || j == n / 2)
				printf("*");
			else
				printf(" ");
		printf("\n");
	}
}
