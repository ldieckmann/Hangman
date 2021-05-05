#include "Textdatei.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char searchWord[25];


/*This function will safe the searched word, playername, amount of guesses and the current time */
void SafeHighscoreList(char searchWord[25], char playername[20], int totalAttempt, float totalTime)
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
        fprintf(highscorelist, "Searchword;Playername;Total Attempt;Time");
        for(i = 0; i < strlen(array); i++)
        {
            fprintf(highscorelist,"%d", array[i]);
            fprintf(highscorelist, "%s;%s,%i,%f",searchWord,playername,totalAttempt,totalTime);
            /*The function fprintf() allows to write content to any file
            * which is a type of text, where you may write content to a *.csv file, too.
            */
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

char PickRandomWord()
{
    char possibleWords[12][25];
    int i = 0;
    char importWord[25];
    srand(time(NULL));
    int randomWord ;
//    randomw = rand() %3;
randomWord = 1;
    FILE *inputFile = fopen("wordlist.txt", "r");

    while(fgets(importWord, 25, inputFile))
    {
        sscanf(importWord, "%s", possibleWords[i]);
        i++;
    }

    for(int j =0; j<strlen(possibleWords[randomWord-1]); j++)
    {
        searchWord[j] =  possibleWords[randomWord-1][j];
    }
    return(searchWord);
}

