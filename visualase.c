#include "visualase.h"
int wrongattempt;
void HangmanVisualize(){
    if (wrongattempt == 0)
    {
        printf("+---+\n");
        printf("|   |  \n");
        printf("|      \n");
        printf("|      \n");
        printf("|      \n");
        printf("|      \n");
        printf("=======\n");
    }
    if (wrongattempt == 1)
    {
        printf("+---+\n");
        printf("|   |  \n");
        printf("|   O  \n");
        printf("|      \n");
        printf("|      \n");
        printf("|      \n");
        printf("=======\n");
    }
    if (wrongattempt == 2)
    {
        printf("+---+\n");
        printf("|   |  \n");
        printf("|   O  \n");
        printf("|   |  \n");
        printf("|      \n");
        printf("|      \n");
        printf("=======\n");
    }
    if (wrongattempt == 3)
    {
        printf("+---+\n");
        printf("|   |  \n");
        printf("|   O  \n");
        printf("|  /|  \n");
        printf("|      \n");
        printf("|      \n");
        printf("=======\n");
    }
    if (wrongattempt == 4)
    {
        printf("+---+\n");
        printf("|   |  \n");
        printf("|   O  \n");
        printf("|  /|\ \n");
        printf("|      \n");
        printf("|      \n");
        printf("=======\n");
    }
    if (wrongattempt == 5)
    {
        printf("+---+\n");
        printf("|   |  \n");
        printf("|   O  \n");
        printf("|  /|\ \n");
        printf("|  /   \n");
        printf("|      \n");
        printf("=======\n");
    }
    if (wrongattempt == 6)
    {
        printf("+---+\n");
        printf("|   |  \n");
        printf("|   O  \n");
        printf("|  /|\ \n");
        printf("|  / \ \n");
        printf("|      \n");
        printf("=======\n");
    }
}

void HangmanTitle()
{
    printf("      \n");
    printf(" | | | |                             __ \n");
    printf(" | || |  / ` | | ' \   / ` | | '  _ \\   / _ | | ' \  \n");
    printf(" |    | | (| | | | | | | (| | | | | | | | | (| | | | | | \n");
    printf(" || ||  \__,| || ||  \, | || || |_|  \,| || || \n");
    printf("                          |__/ \n");
}
