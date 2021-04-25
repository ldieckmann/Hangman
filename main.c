#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>
char playername[20];
char searchword[5] = "Nokia";

/*Time measurement variables*/
long i;
float totalTime;
clock_t start, end;

int main()
{
    /*start gets the current CPU time*/
    start = clock();

    EnterPlayerName();
    /*PlayerGuess();*/





    /*Call of the function which measures the total game time*/
    TimeMeasurement();

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
    char userGuess;
    printf("Guess the letters of the searched word: ");
    scanf("%c",&userGuess); //Zeile Fehlerhaft!!!

    for(int i = 0; i < strlen(searchword); i++)
    {

        if (searchword[i] == "-")
        {
            printf("The letter already has been guessed.");
        }
        if (searchword[i] == userGuess)
        {

            searchword[i] = "-";
            printf("Your guess is right.");
        }
        else
        {
            printf("Your guess is wrong.");
        }
    }
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
