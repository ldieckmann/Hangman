#include "Textdatei.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char searchWord[25];
/*This function will safe the searched word, playername, amount of guesses and the current time */
void SafeHighscoreList(char playername[25],int totalAttempt,char toReplaceWord[25])
{
    FILE *highscorelist;
    highscorelist = fopen("highscorelist.csv", "w+");
    if(highscorelist == NULL)
    {
        printf("Error: This document cannot be opened!");
    }
    else
    {
        fprintf(highscorelist, "Searchword;Playername;Total Attempt");
        fprintf(highscorelist, "\n%s;%s;%i",toReplaceWord,playername,totalAttempt);
            /*The function fprintf() allows to write content to any file
            * which is a type of text, where you may write content to a *.csv file, too.
            */
        fclose(highscorelist);
    }

}
/*This function saves the playername name into the playername.txt textfile*/
void EnterPlayerNameIntoTextFile(char playername[25])
{
    FILE *playernames;
    int i;

    playernames = fopen("playername.txt", "a");
    if(playernames == NULL)
    {
        printf("Error: This Document cannot be opened!\n");
    }
    else
    {
        for(i = 0; i <strlen(playername); i++)
        {
            fputc(playername[i], playernames);
        }
        //add new line
        fputc(10, playernames);
        fclose(playernames);


    }
}

char PickRandomWord()
{
    char possibleWords[12][25];
    int i = 0;
    char importWord[25];
    srand(time(NULL));
    int randomWord ;
    randomWord = rand() %10;
    FILE *inputFile = fopen("wordlist.txt", "r");

    while(fgets(importWord, 25, inputFile))
    {
        for(int j =0;j<strlen(importWord);j++)
        {
            if(91 < importWord[j]> 64)
            {
                importWord[j]=tolower(importWord[j]);
            }
        }
        sscanf(importWord, "%s", possibleWords[i]);
        i++;
    }

    for(int j =0; j<strlen(possibleWords[randomWord-1]); j++)
    {
        searchWord[j] =  possibleWords[randomWord-1][j];
    }
    return(searchWord);
}

