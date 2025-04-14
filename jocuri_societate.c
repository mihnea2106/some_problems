// Copyright Grigore Mihnea - Andrei
#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

void vector_sort(int v1, long *v2); // sorteaza vectorul descrescator
long boss_fight(long v3, int v4, long *v5); // gaseste shieldul potrivit

int main(void)
{
	int n;
	long v[MAX];
	long hp;

	scanf("%ld%d", &hp, &n);
	long s = 0;
	int count = 0;

	for (int i = 0; i < n; i++) {
		char c, buffer;

		scanf("%c %c", &buffer, &c);
		if (c == 'S') { // caz SHIELD
			long read;

			scanf("%ld", &read);
			if (read) {
				v[count] = read;
				count++;
			}
		} else if (c == 'H') { // caz HEAL
			long x;

			scanf("%ld", &x);
			s += x;
		} else {
			printf("Invalid item type.\n");
			int aux;

			scanf("%d", &aux);
		}
	}
	hp += s; // adauga HEAL
	printf("Initial health points: %ld\n", hp);
	vector_sort(count, v);
	int boss;

	scanf("%d", &boss);
	for (int i = 1; i <= boss; i++) { // prelucrare damage
		long x; // valoare boss curent --> damage = boss - shield

		scanf("%ld", &x);
		long rez = boss_fight(x, count, v); // shield ales

		if (hp - x + rez > 0) {
			if (rez <= x)
				hp = hp - x + rez;
			if (rez != 0)
				printf("%ld %ld\n", hp, rez);
			else
				printf("%ld\n", hp);
		} else {
			if (rez != 0) {
				hp = hp - x + rez;
				if (hp > 0)
					printf("%ld %ld\n", hp, rez);
				else
					printf("0 %ld\n", rez);
				printf("You died.\n");
			} else {
				printf("0\nYou died.\n");
			}
		return 0;
		}
		count--;
	}
	printf("Foe Vanquished!\n");
	return 0;
}

void vector_sort(int n, long *v) //ok
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] < v[j]) {
				long aux = v[j];

				v[j] = v[i];
				v[i] = aux;
			}
		}
	}
}

long boss_fight(long x, int count, long *v) // ok ambele cazuri
{
	int i;
	long rez = 0;
	bool pass = 1;

	for (i = 0; i < count; i++) { // shield mai mic sau egal
		if (x >= v[i] && v[i] != -1) {
			rez = v[i];
			v[i] = -1;
			pass = 0;
			break;
		}
	}
	// nu mai sunt shielduri mai mici, aleg primul mai mare
	for (i = count - 1; i >= 0 && pass; i--) {
		if (x <= v[i]) {
			rez = v[i];
			v[i] = -1;
			break;
		}
	}
	vector_sort(count, v);
	return rez; // shield ales
}
