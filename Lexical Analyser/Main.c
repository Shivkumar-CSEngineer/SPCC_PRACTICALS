#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char terminals[][50] = {
    "=",
    "{",
    "}",
    ">",
    "<",
    "!",
    "(",
    ")"};

char keyword[][50] = {
    "void",
    "int",
    "float",
    "char",
    "include",
    "while",
    "if",
    "else",
    "switch",
    "void",
};

void main()
{
    FILE *FilePointer = NULL;
    FilePointer = fopen("./input.c", "r");
    char *result, codeline[100], comparing_string[20];
    int counter = 0;

    result = fgets(codeline, 100, FilePointer);
    while (result != NULL)
    {
        printf("\n%s", codeline);
        for (int i = 0; i < strlen(codeline); i++)
        {
            printf("\ncomparision %c -> %d", codeline[i], isalnum(codeline[i]));
            if (isdigit(codeline[i]) != 0)
            {
                printf("\nit is an digit\n");
                counter = 0;
                for (int j = i; j < strlen(codeline); j++)
                {
                    comparing_string[counter++] = codeline[i++];
                    if (isalnum(codeline[i]) == 0 || isdigit(codeline[i]) == 0)
                    {
                        break;
                    }
                }
                printf("\n%s\n", comparing_string);
            }
            else if (isalnum(codeline[i]) != 0)
            {
                printf("\nvariable started\n");
                counter = 0;
                for (int j = i; j < strlen(codeline); j++)
                {
                    printf("\n%c\n",codeline[i]);
                    comparing_string[counter++] = codeline[i++];
                    if (isalnum(codeline[i]) == 0 || isdigit(codeline[i]) == 0)
                    {
                        break;
                    }
                }
                printf("\n%s\n", comparing_string);
            }
            else
            {
                comparing_string[0] = codeline[i];
            }
            printf("\ncomparing string --> %s\n", comparing_string);
            // for (int k = 0; k < 10; k++)
            // {
            //     if (strcmp(comparing_string, keyword[k]) == 0)
            //     {
            //         printf("\n%s ---> %s\n", comparing_string, keyword[k]);
            //     }
            // }
            // for (int k = 0; k < 8; k++)
            // {
            //     if (strcmp(comparing_string, terminals[k]) == 0)
            //     {
            //         printf("\n%s ---> %s\n", comparing_string, terminals[k]);
            //     }
            // }
            for (int z = 0; z < strlen(comparing_string); z++)
            {
                comparing_string[z] = '\0';
            }
        }

        result = fgets(codeline, 100, FilePointer);
    }
    free(result);
    fclose(FilePointer);
}