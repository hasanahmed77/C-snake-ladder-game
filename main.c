#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCORE 5

struct Player
{
    int name;
    int totalScore;
    int diceScore;
};

int rollDice();
int game(struct Player *p);
void printScreen(struct Player p1, struct Player p2);

int main()
{
    srand(time(NULL));

    int won = 0;

    struct Player P1 = {1, 0, 0};
    struct Player P2 = {2, 0, 0};

    printf("Welcome to Snake-Ladder game!\n");

    printScreen(P1, P2);

    while (P1.totalScore < MAX_SCORE && P2.totalScore < MAX_SCORE)
    {
        // Player 1 functionality
        printf("\nPlayer 1 roll the dice? (r): ");

        won = game(&P1);

        if (won)
        {
            printScreen(P1, P2);
            break;
        }

        printf("Player 1: %d!\n", P1.diceScore);

        // Player 2 functionality
        printf("\nPlayer 2 roll the dice? (r): ");

        won = game(&P2);

        if (won)
        {
            printScreen(P1, P2);
            break;
        }

        printf("Player 2: %d!\n", P2.diceScore);

        printScreen(P1, P2);
    }

    return 0;
}

void printScreen(struct Player p1, struct Player p2)
{
    printf("\n------------------------------------");
    printf("\nP1 Score: %d --- P2 Score: %d\n", p1.totalScore, p2.totalScore);
    printf("------------------------------------\n");
}

int rollDice()
{
    int randomNumber = (rand() % 6) + 1;

    return randomNumber;
}

// return 1 if won, else 0
int game(struct Player *P)
{
    char userInput = ' ';
    while (userInput != 'r' && userInput != 'R')
    {
        scanf(" %c", &userInput);

        if (userInput != 'r' && userInput != 'R')
            printf("Wrong input: Please enter 'r' to roll the dice: ");
    }

    P->diceScore = rollDice();
    P->totalScore += P->diceScore;

    if (P->totalScore >= MAX_SCORE)
    {
        printf("Player %d won!", P->name);
        return 1;
    }
    return 0;
}