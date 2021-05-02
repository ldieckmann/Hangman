#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>
char playername[20];
char searchword[25]; //The word which is searched for (imported from textfile)
char guessedWord[25];
int wrongattempt = 0, rightattempt = 0;

/*Time measurement variables*/
long i;
float totalTime;
clock_t start, end;

int main()
{
    GameIntroduction();
    ImportWordsFromWordlistFile();
    printf("\n");
    PrintSearchWordHidden();
    EnterPlayerNameIntoTextFile();
    //EnterPlayerName();
    /*start gets the current CPU time*/
    start = clock();
    PlayerGuess();

    /*Call of the function which measures the total game time*/
    TimeMeasurement();
    ExitAttempt();
    //printf("%s",searchword);
    return 0;
}
/*This function will print the game introductions*/
void GameIntroduction()
{
    printf("---------------------------------------------------------\n");
    printf("|**************** Welcome to Hangman *******************|\n");
    printf("|Authors: David Nguyen, Louis Dieckmann, Sedad Deeg\t|\n");
    printf("---------------------------------------------------------\n\n");
}

/*This function will let the user enter his playername*/
void EnterPlayerName()
{
    printf("Enter your Player Name: ");
    scanf("%s",playername);
    printf("Your Player Name is: %s\n\n", &playername);
}

/*This function will let the player guess the letters of the searchword*/
void PlayerGuess()
{
    int CompareCharacters = 0;
    bool exists = false;
    char userGuess;

    do
    {
        exists = false;
        printf("Guess the letters of the searched word: ");
        scanf("%c",&userGuess);
        userGuess = getchar();
        printf("\n");
        for(int i = 0; i < strlen(searchword); i++)
        {
            if (searchword[i] == userGuess)
            {
                exists = true;
                CompareCharacters = CompareCharacters + 1;
                ReplaceChar(i);
            }
            if(exists == false)
            {
                if (searchword[i] == "-")
                {
                    exists= false;
                }
            }
        }
        if (exists == true)
        {
            printf("Your guess is right.\n");
            rightattempt+=1;
        }
        else
        {
            wrongattempt+=1;
            printf("Your guess is wrong.\n");
        }
    } while(CompareCharacters != strlen(searchword));
}
void ReplaceChar(int j)
{
    searchword[j] = 42;
}
/*This function prints the searchword, but with hidden letters.*/
void PrintSearchWordHidden()
{
    char searchwordHidden[strlen(searchword)];
    printf("Try to guess the hidden word: ");
    for(i=0; i<strlen(searchword); i++)
    {
        searchwordHidden[i] = 95;
        printf("%s ",&searchwordHidden[i]);
    }
    printf("\n\n");
}

/*This function measures the game time in seconds*/
void TimeMeasurement()
{
    /*time measurement*/
    for(i=0; i<200000000; i++);

    /*stop gets the current CPU time*/
    end = clock();

    /*Result of the Runtime measuring in seconds*/
    totalTime = (float)(end-start) / (float)CLOCKS_PER_SEC;

    printf("The Game was running %.2f seconds\n",totalTime);
}

void ExitAttempt()
{
    printf("You had %i right and %i wrong attempts\n",rightattempt,wrongattempt);
}

void GameCountdown()
{
    clock_t currTime;
    clock_t endTime;

    int countdownSec = 30;

    /**
    printf("Bitte Sekunden eingeben ");
    scanf("%d",&countdownSec);
    **/

    while(countdownSec!=0)
    {
        // Ausgabe
        printf("Nur noch %d\n",countdownSec);
        // Ende_Zeit berechnen
        endTime=clock()+CLOCKS_PER_SEC;
        do
        {
            // Aktuelle_Zeit auslesen
            currTime=clock();
        }
        while(currTime<endTime);
        // eine Sekunde ist um
        countdownSec--;
    }
}
/*This function saves the player name into the playername.txt textfile*/
void EnterPlayerNameIntoTextFile()
{
    FILE *playernames;
    char name[20];

    playernames = fopen("playername.txt", "a");
    if(playernames == NULL)
    {
        printf("Error: This Document cannot be opened!\n");
    }
    else
    {
        printf("Enter your Player Name: ");
        scanf("%s", &name);
        fprintf(playernames, name);
        fprintf(playernames, "\n");

        printf("Your Player Name is: %s\n\n", &name);
    }
    fclose(playernames);
}
/*This function does read the word from the textfile (wordlist.txt)*/
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
            searchword[counter] = character;
            //printf("%c", character); //prints the unhidden word.
            counter++;
        }
    }
}
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
