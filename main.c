#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>
char playername[20];
char searchword[5] = "Nokia";
int wrongattempt = 0, rightattempt = 0;

/*Time measurement variables*/
long i;
float totalTime;
clock_t start, end;

int main()
{

    EnterPlayerName();
    /*start gets the current CPU time*/
    start = clock();
    PlayerGuess();

    /*Call of the function which measures the total game time*/
    TimeMeasurement();
    ExitAttempt();
    printf("%s",searchword);
    return 0;
}

/*This function will let the user enter his playername*/
void EnterPlayerName()
{
    printf("Enter Player Name: ");
    scanf("%s",playername);
    printf("Your Player Name is: %s\n\n", &playername);
}

/*This function will let the player guess the letters of the searchword*/
void PlayerGuess()
{
    bool exists = false;
    char userGuess;
    printf("Guess the letters of the searched word: ");
    scanf("%c",&userGuess); //Zeile Fehlerhaft!!!
    userGuess = getchar();
    printf("\n");
    for(int i = 0; i < strlen(searchword); i++)
    {
        if (searchword[i] == userGuess)
        {
            exists = true;
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
}
void ReplaceChar(int j)
{
    searchword[j] = 124;
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

/**
void player()
{
    FILE *playernames;
    char playername[20];

    printf("Enter your playername: ");
    scanf("%c", &playername);

    playernames("playername.txt", "w+")
    if(inputFile == NULL)
    {
        printf("This Document cannot be opened!\n");
    }
}
**/
