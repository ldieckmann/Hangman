#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "time.h"

/*This function asks the player if he wants to play against the time*/
int totalAttempt = 0, wrongAttempt = 0, rightAttempt = 0;
char playername[20];
int playmode;
char toReplaceWord[25]="";
char searchWord[25]="baum";
char triedChars[50]="";



/*This function asks the player if he wants to play against the time*/
void CheckPlayMode()
{
    char yesOrNo;
    printf("Do you want to play against the time? (y/n): ");
    scanf("%c", &yesOrNo);
    while((yesOrNo != 'y') && (yesOrNo != 'n')) //Repeats an Error message until the player selects the valid playmode
    {
        printf("Do you want to play against the time? (y/n): ");
        scanf("%c", &yesOrNo);
    }
    if (yesOrNo == 'n')
    {
        playmode = 0; //playmode 0 = casual
    }
    if (yesOrNo == 'y')
    {
        playmode = 1; //playmode 1 = against the time
    }
}

void StartGame()
{
    ConvertSearchWordToConcealed();
    if (playmode==1)
    {
        PlayModeAgainstTheTime();
    }
    if (playmode ==0)
    {
        PlaymodeCasual();
    }
}

/*This function will execute the casual playmode*/
void PlaymodeCasual()
{
    if (wrongAttempt < 6)
    {
        WhileWordIsNotGuessed();

    }
    else
    {
        EndGame(totalAttempt,wrongAttempt);
    }
}

/*This function will execute the against the time playmode*/
void PlayModeAgainstTheTime()
{
    if (wrongAttempt < 6 & TimeLeft() > 0)
    {

    }
    else
    {
        EndGame(totalAttempt,wrongAttempt);
    }
}

void ConvertSearchWordToConcealed()
{
    for(int i=0; i<strlen(searchWord); i++)
    {
        toReplaceWord[i] = 95;
    }

}
/*This function will let the player guess the letters of the searchword*/
void PlayerGuess()
{
    bool exists = false;
    char userGuess;

        PrintSearchWordHidden(toReplaceWord);
        ExitTries(triedChars);
        totalAttempt ++;
        printf("Guess the letters of the searched word: ");
        scanf(" %c",&userGuess);
        //if (userGuess)
        {
                //userGuess = tolower(userGuess);
        }
        AddToTriedChars(userGuess);
        for(int i = 0; i <= strlen(searchWord); i++)
        {
            if (searchWord[i] == userGuess)
            {n
                exists = true;
                ReplaceCharInConsealedWord(i,userGuess);
            }
            if(exists == false)
            {
                if (searchWord[i] == "-")
                {
                    exists= false;
                }
            }
        }

        if (exists == true)
        {
            printf("Your guess is right.\n");
            rightAttempt++;
        }
        else
        {
            printf("Your guess is wrong.\n");
            wrongAttempt++;
            HangmanVisualize(wrongAttempt);
        }
}

void WhileWordIsNotGuessed()
{
    while (CheckIfGuessed() == 1)
    {
        PlayerGuess();
    }

}

int CheckIfGuessed()
{
    for(int i=0; i<strlen(toReplaceWord); i++)
    {
        if (toReplaceWord[i]== 95)
        {
            return(1);
        }
    }
   return(0);
}

void ReplaceCharInConsealedWord(int placeInChar,char charToPlace)
{
    toReplaceWord[placeInChar] = charToPlace;
    searchWord[i]=95;
}
void AddToTriedChars(char currentGuess)
{
    bool alreadyExists = false;
    for (i = 1; i < strlen(triedChars); i++)
    {
        if (triedChars[i]==currentGuess)
        {
            alreadyExists = true;
        }
    }
    if (!alreadyExists)
    {
        triedChars[50] = currentGuess;
    }
}
void ExitTriedChars(char triedChar)
{
    int i, j;
    char tmp;

    for (i = 1; i < strlen(triedChars); i++)
    {
        for (j = 0; j < strlen(triedChars)- 1 ; j++)
        {
            if (triedChars[j] > triedChars[j + 1])
            {
                tmp = triedChars[j];
                triedChars[j] = triedChars[j + 1];
                triedChars[j + 1] = tmp;
            }
        }
    }
}


