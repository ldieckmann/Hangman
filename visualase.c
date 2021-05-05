#include "visualase.h"
/*This function will visualize the Hangman during the attemps of the user*/
void HangmanVisualize(int wrongAttempt)
{
    if (wrongAttempt == 1)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" =======\n");
        printf("\n");
    }
    if (wrongAttempt == 2)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |   O  \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" =======\n");
        printf("\n");
    }
    if (wrongAttempt == 3)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |   O  \n");
        printf(" |   |  \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" =======\n");
        printf("\n");
    }
    if (wrongAttempt == 4)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |   O  \n");
        printf(" |  /|  \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" =======\n");
        printf("\n");
    }
    if (wrongAttempt == 5)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |   O  \n");
        printf(" |  /|\\ \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" =======\n");
        printf("\n");
    }
    if (wrongAttempt == 6)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |   O  \n");
        printf(" |  /|\\ \n");
        printf(" |  /   \n");
        printf(" |      \n");
        printf(" =======\n");
        printf("\n");
    }
    if (wrongAttempt == 7)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |   O  \n");
        printf(" |  /|\\ \n");
        printf(" |  / \\ \n");
        printf(" |      \n");
        printf(" =======\n");
        printf("\n");
    }
}
/*This function will print the game introductions*/
void GameIntroduction()
{
    printf("---------------------------------------------------------\n");
    printf("|**************** Welcome to Hangman *******************|\n");
    printf("|Authors: David Nguyen, Louis Dieckmann, Sedad Deeg\t|\n");
    printf("---------------------------------------------------------\n\n");
    printf("\n");
}
/*This function will print the Word Hangman as the headline*/
void HangmanTitle()
{
    printf("  _   _ \n");
    printf(" | | | |   __ _   _ __     __ _   _ __ ___     __ _   _ __ \n");
    printf(" | |_| |  / _` | | '_ \\   / _` | | '_ ` _ \\   / _` | | '_ \\  \n");
    printf(" |  _  | | (_| | | | | | | (_| | | | | | | | | (_| | | | | | \n");
    printf(" |_| |_|  \\__,_| |_| |_|  \\__, | |_| |_| |_|  \\__,_| |_| |_| \n");
    printf("                          |___/ \n");
}

/*This function prints the searchword, but with hidden letters.*/
void PrintSearchWordHidden(char searchWord[25])
{
    printf("Searchword: ");
    printf("%s\n",searchWord);
}
/*This function will be called at the end of the game, whether the player lost or won*/
void ExitAttempt(int totalAttempt,int rightAttempt)
{
    printf("total amount of tries: %i and %i right attemts\n",totalAttempt,rightAttempt);
}
/*This function willl be executed if the player has won the game*/
void Won(char playername[20],int totalAttempt,int rightAttempt)
{
    printf("%s has won with ",playername);
    EndGame(totalAttempt,rightAttempt); //shows the number of total attempts and right attempts
    TimeMeasurement(); //the time measurement function is called here
    ExitTriedChars(); //the exit tried chars function is called here
    SafeHighscoreList(playername,totalAttempt);
}
/*This function will be executed if the player has lost the game*/
void Lose(char playername[20],int totalAttempt,int rightAttempt)
{
    printf("Gameover\n");
    printf("%s has lost with ",playername);
    ExitAttempt(totalAttempt,rightAttempt); //shows the number of total attempts and right attempts
    TimeMeasurement(); //the time measurement function is called here
    ExitTriedChars(); //the exit tried chars function is called here
}
