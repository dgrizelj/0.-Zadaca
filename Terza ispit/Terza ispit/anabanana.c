#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

void sortiranje(int *polje, int pocetni, int zadnji)
{
	int i, min = pocetni, tmp;
	if (pocetni < zadnji)
	{
		for (i = pocetni + 1; i<zadnji; i++)
		{
			if (polje[i]<polje[min])
				min = i;
		}
		tmp = polje[pocetni];
		polje[pocetni] = polje[min];
		polje[min] = tmp;

		sortiranje(polje, pocetni + 1, zadnji);
	}
	return;
}



int main()
{
	int broj, i, *polje, x;
	FILE *tok1, *tok2;

	tok1 = fopen("D:/datoteka.txt", "w");
	tok2 = fopen("D:/sortirani.txt", "w");

	srand((unsigned)time(NULL));
	broj = rand() % (4000 - 500 + 1) + 500;

	polje = (int*)malloc(broj*sizeof(int));

	for (i = broj; i>0; i--)
	{
		x = rand() % 10001;
		polje[i] = x;
		fprintf(tok1, "%d\n", x);
	}

	sortiranje(polje, 0, broj);

	for (i = 0; i<broj; i++)
	{
		fprintf(tok2, "%d\n", polje[i]);
		printf("%d\n", polje[i]);
	}
	fclose(tok1);
	fclose(tok2);

	return 0;
}