#include "game.h"
#include "encryption.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "time.h"
#include "visualase.h"

/*This function asks the player if he wants to play against the time*/
int totalAttempt = 0, wrongAttempt = 0, rightAttempt = 0;
char playername[20];
int playmode;
char toReplaceWord[25]="";
char searchWord[25]="";
char triedChars[50]="";
int alreadyGuessedChars=0;

/*This function let the player enter his name*/
void EnterPlayerName()
{
    printf("Please enter your username: ");
    scanf("%s",playername);
    EnterPlayerNameIntoTextFile(playername);
}
/*This function asks the player if he wants to play against the time*/
//void CheckPlayMode()
//{
//    char yesOrNo;
//    printf("Do you want to play against the time? (y/n): ");
//    scanf("%c", &yesOrNo);
//    while((yesOrNo != 'y') && (yesOrNo != 'n')) //Repeats an Error message until the player selects the valid playmode
//    {
//        scanf("%c", &yesOrNo);
//    }
//    if (yesOrNo == 'n')
//    {
//        playmode = 0; //playmode 0 = casual
//    }
//    if (yesOrNo == 'y')
//    {
//        playmode = 1; //playmode 1 = against the time
//    }
//}
/*This function gets the searched word*/
void GetSearchWord()
{
    searchWord[25] =  PickRandomWord();
}

/* This function starts the game*/
void StartGame()
{
    StartClock();
    ConvertSearchWordToConcealed();
//    if (playmode==1)
//    {
//        PlayModeAgainstTheTime();
//    }
    if (playmode ==0)
    {
        PlaymodeCasual();
    }
}

/*This function will execute the casual playmode*/
void PlaymodeCasual()
{
    while(WhilePlayCondition()==1)
    {
        PlayerGuess();
    }
    if(CheckIfGuessed()==0)
    {
        Won(playername,totalAttempt,rightAttempt);
    }
    else
    {
        Lose(playername,totalAttempt,rightAttempt);
    }
}

/*This function will execute the against the time playmode*/
//void PlayModeAgainstTheTime()
//{
//    if(WhilePlayCondition()==1)
//    {
//        EndGame(totalAttempt,wrongAttempt);
//    }
//}
/*This function will convert the searchword to concealed */
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
    ExitTriedChars();
    totalAttempt ++; //the number of attempts will count up every try
    do
    {
        printf("Guess the letters of the searched word: ");
        scanf(" %c",&userGuess); //this line will allow the user to type in his letter
        if (91 < userGuess > 64 )
        {
            userGuess = tolower(userGuess);
        }
    }
    while(96 < userGuess > 123);
    AddToTriedChars(userGuess);
    for(int i = 0; i <= strlen(searchWord); i++)
    {
        if (searchWord[i] == userGuess)
        {
            exists = true;
            ReplaceCharInConsealedWord(i,userGuess);
        }
        if(exists == false)
        {

            if (searchWord[i] == "-")

                if (searchWord[i] == userGuess)
                {
                    exists = true;
                    ReplaceCharInConsealedWord(i,userGuess);
                }
            if(exists == false)

            {
                exists= false;
            }
        }
    }

    if (exists == true)
    {
        printf("\n");
        printf("Your guess is right\n");
        rightAttempt++; //counts the number of right attempts up every time the user guess is rigt
    }
    else
    {
        printf("\n");
        printf("Your guess is wrong\n");
        wrongAttempt++; //counts the number of wrong attempts up every time the user guess is wrong
        HangmanVisualize(wrongAttempt); //Calls the function which prints the hangman itself and gives the wrong attempts as parameter.
    }
}
/*This function will check if the playing condition is adhered to */
int WhilePlayCondition()
{
    if ((CheckIfGuessed()==1)&&(wrongAttempt < 7))
    {
        return(1); //returns 1 while the game isn't over
    }
    else
    {
        EndClock(); //time measurement will stop here
        return(0); //returns 0 is the game is over
    }

}
/*This function will check if the guessed letter is right */
int CheckIfGuessed()
{
    for(int i=0; i<strlen(toReplaceWord); i++)
    {
        if (toReplaceWord[i]== 95)
        {
            return(1); //returns 1 if the right letter wasn't found
        }
    }
    return(0); //returns 0 if the right letter was found
}
/*This function will replace the char into the consealed*/
void ReplaceCharInConsealedWord(int placeInChar,char charToPlace)
{
    toReplaceWord[placeInChar] = charToPlace;
    searchWord[placeInChar]=95;
}
/*This function will add the current guesses to tried chars */
void AddToTriedChars(char currentGuess)
{
    bool alreadyExists = false;
    for (int i = 0; i < strlen(triedChars); i++)
    {
        if (triedChars[i]==currentGuess)
        {
            alreadyExists = true;
        }
    }
    if (!alreadyExists)
    {
        triedChars[alreadyGuessedChars]=currentGuess;
        alreadyGuessedChars++;
        SortTriedChars();
    }
}
/*This function will sort the tried chars ascending*/
void SortTriedChars()
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
/*This function shows the tried letters*/
void ExitTriedChars()
{
    printf("Tried letters: ");
    for(int i=0; i<strlen(triedChars); i++) //this loop will print all the tried letters
    {

        printf("%c",triedChars[i]);
    }
    printf("\n");
}





