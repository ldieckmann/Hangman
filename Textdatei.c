#include "Textdatei.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char searchWord[25];
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
            searchWord[counter] = tolower(character);
            counter++;
        }
        printf(searchWord);
    }
}
/*This function will safe the searched word, playername, amount of guesses and the current time */
void SafeHighscoreList()
{

    FILE *highscorelist;
    int i;
    int array[4];
    highscorelist = fopen("highscorelist.csv", "w+");
     if(highscorelist == NULL)
    {
        printf("Error: This document cannot be opened!");
    }
    else
    {
        fprintf(highscorelist, "Searchword;Playername;Amount of guesses;Time");
        for(i = 0; i < strlen(array); i++)
        {
            /*The function fprintf() allows to write content to any file
            * which is a type of text, where you may write content to a *.csv file, too.
            */
            fprintf(highscorelist,"%d", array[i]);
        }
        fclose(highscorelist);
        highscorelist = 0;


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
/*void PickRandomWord(char searchWord[25])
{
    char array[][];
    int i = 0;
    srand(time(NULL));
    int randomIndex = rand() %67;
    FILE *inputFile = fopen("wordlist.txt", "r");
    searchWord[25];
    while(fgets(input, 63, inputFile))
    {
        sscanf(searchWord, "%s", array[i]);
        i++;
    }
}
*/
