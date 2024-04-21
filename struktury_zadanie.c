#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct struktura	
{
	int fb;
	int	szereg;
	struct struktura* nastepny;
}lista;

int	fb(int n)
{
	if (n <= 1)
		return (n);
	return (fb(n - 1) + fb(n - 2));
}

int szereg(int n)
{
	if ((n % 2) == 0)
		return (-n / 2);
	return ((n + 1) / 2);
}

int main()
{
	int n;
	int i;
	int index;

	printf("Podaj długość ciągów: ");
	scanf("%d", &n);
	
	if (n < 0)
	{
		printf("Długość ciągów nie może być ujemna!\n");
		return (-1);
	}
	
	lista* pierwszy = NULL;
	lista* tymczasowy = NULL;

	for (i = 0; i < n; i++)
	{
		lista* wezel = (lista*)malloc(sizeof(lista));
		if (wezel == NULL)
		{
			printf("Błąd alokacji pamięci.\n");
			return (-1);
		}
		wezel->fb = fb(i);
		wezel->szereg = szereg(i);
		wezel->nastepny = NULL;

		if (pierwszy == NULL)
		{
        		pierwszy = wezel;
        		tymczasowy = pierwszy;
        	}
		else
		{
        		tymczasowy->nastepny = wezel;
        		tymczasowy = tymczasowy->nastepny;
        	}
	}

	printf("Elementy listy:\n");
	tymczasowy = pierwszy;
	while(tymczasowy != NULL)
	{
		printf("Fibonacci: %d, Szereg: %d\n", tymczasowy->fb, tymczasowy->szereg);
		tymczasowy = tymczasowy->nastepny;
	}

	lista* obecny = pierwszy;
	lista* poprzedni = NULL;
	index = 0;
	while (obecny != NULL)
	{
		if (index % 2 != 0)
		{
    			if (poprzedni == NULL)
			{
            		pierwszy = obecny->nastepny;
        		free(obecny);
            		obecny = pierwszy;
            		}
			else
			{
            		poprzedni->nastepny = obecny->nastepny;
            		free(obecny);
            		obecny = poprzedni->nastepny;
        		}
        	}
		else
		{
            		poprzedni = obecny;
            		obecny = obecny->nastepny;
        	}
		index++;
	}

	printf("Elementy listy po usunięciu elementów o nieparzystych indeksach:\n");
    	tymczasowy = pierwszy;
    	while (tymczasowy != NULL)
	{
		printf("Fibonacci: %d, Szereg: %d\n", tymczasowy->fb, tymczasowy->szereg);
    		tymczasowy = tymczasowy->nastepny;
	}
	
	while (pierwszy != NULL)
	{
		tymczasowy = pierwszy;
		pierwszy = pierwszy->nastepny;
		free(tymczasowy);
	}
	
	return (0);
}
