#include "visualase.h"
void HangmanVisualize(int wrongattempt)
{
    if (wrongattempt == 0)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" =======\n");
    }
    if (wrongattempt == 1)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |   O  \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" =======\n");
    }
    if (wrongattempt == 2)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |   O  \n");
        printf(" |   |  \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" =======\n");
    }
    if (wrongattempt == 3)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |   O  \n");
        printf(" |  /|  \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" =======\n");
    }
    if (wrongattempt == 4)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |   O  \n");
        printf(" |  /|\\ \n");
        printf(" |      \n");
        printf(" |      \n");
        printf(" =======\n");
    }
    if (wrongattempt == 5)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |   O  \n");
        printf(" |  /|\\ \n");
        printf(" |  /   \n");
        printf(" |      \n");
        printf(" =======\n");
    }
    if (wrongattempt == 6)
    {
        printf(" +---+\n");
        printf(" |   |  \n");
        printf(" |   O  \n");
        printf(" |  /|\\ \n");
        printf(" |  / \\ \n");
        printf(" |      \n");
        printf(" =======\n");
    }
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
