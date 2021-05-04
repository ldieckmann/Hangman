#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Textdatei.h"
#include "visualase.h"
#include "game.h"

int main()
{
    HangmanTitle();
    GameIntroduction();
    CheckPlayMode();

    return 0;
}














/*This function returns the chars which where already tried*/


/*This function does read the word from the textfile (wordlist.txt)*/

/*This function will suggest player names from the textfile (playername.txt)*/
/*
void SuggestPlayerName()
{
FILE *suggestFile;
suggestFile = fopen("playername.txt", "r");

if(suggestFile == NULL)
    {
        printf("Error: This document cannot be opened!");
    }
        else
    {
        while((character = fgetc(inputFile)) != EOF)
        {

        }

    }
}
*/
