#include <stdio.h>
#include <stdlib.h>

void GetData();

void GetData()
{
    char jmeno[10];
    printf("Zadejte jméno:");
    scanf("%s", &jmeno);
    int vek;
    printf("Zadejte vek:");
    scanf("%i", &vek);
    char pohlavi;
    printf("Vyberte pohlavi \n a) Muž \n b) Žena \n c) Jiné \n :");
    scanf(" %c", &pohlavi);
    system("clear");
}