#include "Textdatei.h"
void ImportWordsFromWordlistFile()
{
    //char adfjhnfdj[25];
    int counter = 0;
    FILE *inputFile;
    inputFile = fopen("wordlist.txt", "r");
    if(inputFile == NULL)
    {
        printf("Error: This document cannot be opened!");
    }
    else
    {
        char character;
        while((character = fgetc(inputFile)) != EOF)
        {
            searchword[counter] = tolower(character);
            counter++;
        }
        printf(searchword);
    }
}
