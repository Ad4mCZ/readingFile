#include <stdio.h>
#define MAX_LINES 100
#define MAX_LENGTH 20

int main()
{
    char data[MAX_LINES][MAX_LENGTH] = {{0}}; // 2d pole pro uchovavani radku
    char otazky[MAX_LINES][MAX_LENGTH] = {{0}};

    FILE *file = fopen("questions.txt", "r"); // otevreni souboru
    if (file == NULL)                         // kontrola jestli existuje
    {
        printf("no such file.");
        return 1;
    }

    int line = 0; // pocitani radku

    while (!feof(file) && !ferror(file)) // pokud neni end of file nebo chyba
    {
        if (fgets(data[line], MAX_LENGTH, file) != NULL) // kontrola jestli nejsme na konci
        {
            line++;
        }
    }
    fclose(file); // zavreni souboru

    for (int i = 0, indexOtazky = 0; i < line; i++) // prochazeni dat
    {
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            if (data[i][j] == '[')
            {
                for (int k = 1; data[i][j + k] != ']'; k++)
                {
                    otazky[indexOtazky][k - 1] = data[i][j + k];
                }
                indexOtazky++;
            }
        }
    }
    int body = 0;
    char spravna_odpoved = 0;
    char vysledek = 0;
    int odpovedi = 0;
    for (int i = 0; (i < sizeof(otazky) / sizeof(otazky[0])) && (otazky[i][0] != '\0'); i++) // vypsani serie
    {
        printf("%s\n", otazky[i]); // vypsani otazky

        for (int j = 1; j <= 4; j++) // vypis odpovedi
        {
            if (data[j + odpovedi][0] == '!')
            {
                printf("%c \n", data[j + odpovedi][1]); // spravne odpovedi
                spravna_odpoved = data[j + odpovedi][1];
            }
            else
            {
                printf("%s", data[j + odpovedi]); // spatne odpovedi
            }
        }
        odpovedi += 6;
        printf("Zadejte odpoved:"); // dostani vysledku
        scanf(" %c", &vysledek);
        if (spravna_odpoved == vysledek) // porovnani vysledku s odpovedi
        {
            printf("ahoj \n");
            body++;
            spravna_odpoved = 0;
        }
        else
            continue;
    }
    printf("Mate %d bodu", body);

    return 0;
}