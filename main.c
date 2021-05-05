#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "encryption.h"
#include "Textdatei.h"
#include "visualase.h"
#include "game.h"
#include "encryption.h"

int main()
{

<<<<<<< HEAD
SafeHighscoreList(PickRandomWord());
//    HangmanTitle();
//    GameIntroduction();
//    CheckPlayMode();
//    StartGame();
//    AddToTriedChars('c');
//    AddToTriedChars('g');
//    AddToTriedChars('a');
//    AddToTriedChars('c');
//    ExitTriedChars();
=======
    HangmanTitle();
    GameIntroduction();
    EnterPlayerName();
    CheckPlayMode();
    GetSearchWord();
    StartGame();

>>>>>>> 3763be8c3555e63c34e17665cdecbad22c3610de
    return 0;
}


//versuche
//erraten















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
