// Define a struct to represent a node in the linked list.
typedef struct struktura	
{
    int fb;  // Fibonacci number
    int	szereg;  // Number from the series
    struct struktura* nastepny;  // Pointer to the next node
}lista;

// Function to calculate the nth Fibonacci number.
int	fb(int n)
{
    if (n <= 1)
        return (n);
    return (fb(n - 1) + fb(n - 2));
}

// Function to calculate the nth number in the series.
int szereg(int n)
{
    if ((n % 2) == 0)
        return (-n / 2);
    return ((n + 1) / 2);
}

int main()
{
    int n;  // Length of the sequences
    int i;  // Loop counter
    int index;  // Index of the current node

    printf("Podaj długość ciągów: ");
    scanf("%d", &n);
    
    // Check if the length is negative.
    if (n < 0)
    {
        printf("Długość ciągów nie może być ujemna!\n");
        return (-1);
    }
    
    // Initialize the head and a temporary pointer to NULL.
    lista* pierwszy = NULL;
    lista* tymczasowy = NULL;

    // Create the linked list.
    for (i = 0; i < n; i++)
    {
        // Allocate memory for a new node.
        lista* wezel = (lista*)malloc(sizeof(lista));
        if (wezel == NULL)
        {
            printf("Błąd alokacji pamięci.\n");
            return (NULL);
        }
        // Calculate the Fibonacci number and the number from the series.
        wezel->fb = fb(i);
        wezel->szereg = szereg(i);
        wezel->nastepny = NULL;

        // Add the new node to the end of the list.
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

    // Print the elements of the list.
    printf("Elementy listy:\n");
    tymczasowy = pierwszy;
    while(tymczasowy != NULL)
    {
        printf("Fibonacci: %d, Szereg: %d\n", tymczasowy->fb, tymczasowy->szereg);
        tymczasowy = tymczasowy->nastepny;
    }

    // Remove the nodes at odd indices from the list.
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

    // Print the elements of the list after removing the nodes.
    printf("Elementy listy po usunięciu elementów o nieparzystych indeksach:\n");
        tymczasowy = pierwszy;
        while (tymczasowy != NULL)
    {
        printf("Fibonacci: %d, Szereg: %d\n", tymczasowy->fb, tymczasowy->szereg);
            tymczasowy = tymczasowy->nastepny;
    }
    
    // Free the memory allocated for the nodes.
    while (pierwszy != NULL)
    {
        tymczasowy = pierwszy;
        pierwszy = pierwszy->nastepny;
        free(tymczasowy);
    }
    
    return (0);
}