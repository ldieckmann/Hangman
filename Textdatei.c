#include "Textdatei.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*This fucntion imports a word from the wordlist.txt file*/
void ImportWordsFromWordlistFile()
{

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
/*This function will safe the searched word, playername, amount of guesses and the current time */
void SafeHighscoreList()
{
    FILE *highscorelist;
    highscorelist = fopen("highscorelist.txt", "w+");
     if(highscorelist == NULL)
    {
        printf("Error: This document cannot be opened!");
    }
    else
    {
        //SOURCE: https://austinrepp.com/how-to-write-to-a-csv-file-in-c/
        //fprintf("Searchword, Playername, amount of guesses and time\n");
        //fprintf("%c, %s, %i, %i", searchword, playername, TimeMeasurement);
    }

}
/*This function saves the player name into the playername.txt textfile*/
void EnterPlayerNameIntoTextFile()
{
    FILE *playernames;
    char name[20];
    int i;

    playernames = fopen("playername.txt", "a");
    if(playernames == NULL)
    {
        printf("Error: This Document cannot be opened!\n");
    }
    else
    {
        printf("Enter your Player Name: ");
        scanf("%s", &name);
        for(i = 0; i <strlen(name); i++)
        {
            fputc(name[i], playernames);
        }
        //add new line
        fputc(10, playernames);
        fclose(playernames);

        printf("Your Player Name is: %s\n\n", &name);
    }
}
