#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char playername[20];
char searchword[5] = "Nokia";
int main()
{
    EnterPlayerName();
    PlayerGuess();
    return 0;
}

//This function will let the user enter his playername
void EnterPlayerName() {
    printf("Enter Player Name: ");
    scanf("%s",playername);
    printf("Your Player Name is: %s\n\n", &playername);
}

//This function will let the player guess the letters of the searchword
void PlayerGuess() {
    char userGuess;
    printf("Guess the letters of the searched word: ");
    scanf("%c",&userGuess); //Zeile Fehlerhaft!!!

    for(int i = 0; i < strlen(searchword);i++) {

        if (searchword[i] == "-") {
            printf("The letter already has been guessed.");
        }
        if (searchword[i] == userGuess) {

            searchword[i] = "-";
             printf("Your guess is right.");
        } else {
            printf("Your guess is wrong.");
        }
    }
}
