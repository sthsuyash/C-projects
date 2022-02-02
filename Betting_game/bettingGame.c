/*  
    Betting game to guess the position of Queen
    Reference from mycodeschool memoryleak [ youtube : https://youtu.be/F2nrej6Kjww ]

    Author: Suyash Shrestha
    Contact: sthasuyash11@gmail.com
    Date made: 11 / 11 / 2021

    Description:
    Player has initially $200 that he uses in the game.
    If the guess is correct, he wins 3 x bet amount.
    If the guess is incorrect, he loses bet amount.
    Game continues till the player has lost all the money.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int cash = 200; //Initial amount of cash for player to spend

void guess(int bet)
{
    char *cards = (char *)malloc(3 * sizeof(char));
    *(cards + 0) = 'J';
    cards[1] = 'Q';
    cards[2] = 'K';

    printf("Shuffling");
    for (int i = 0; i < 7; i++)
    {
        Sleep(120);
        printf(".");
    }
    printf("\n");
    srand(time(0));
    //Running the loop 5 times to shuffle the cards five times
    for (int i = 0; i < 5; i++)
    {
        int a = rand() % 3; // Generates random value from 0 to 2
        int b = rand() % 3; // Generates random value from 0 to 2

        // bubble sort algorithm:
        // swapping the values in a and b
        // Note: a and b are randomized
        char temp = cards[a]; //stores the value of first variable in temporary variable
        cards[a] = cards[b]; //stores value of second variable in first variable
        cards[b] = temp;     //stores the value of first variable in second variable from previously stored in temp
    }

    int playerGuess;
    printf("In which position is the queen? (1, 2 or 3) ");
    scanf("%d", &playerGuess);

    if (cards[playerGuess - 1] == 'Q')
    {
        cash += 3 * bet;
        printf("You Win!! Cards order : %c %c %c .\nTotal Cash: %d.\n\n", cards[0], cards[1], cards[2], cash);
    }
    else
    {
        cash -= bet;
        printf("OOps!! You lose. Cards order : %c %c %c .\nTotal Cash: %d.\n\n", cards[0], cards[1], cards[2], cash);
    }
    free(cards);
}

void main()
{
    int bet;
    printf("----Welcome to the betting game----\n\n");
    printf("You have $%d initially.\n", cash);

    while (cash > 0)
    {

        printf("How much do you want to bet: ");
        scanf("%d", &bet);

        if (bet > cash || cash == 0)
        {
            printf("Sorry! You do not have enough cash.\n");
            break;
        }
        guess(bet);
    }
    printf("END of the game.\n");
    system("pause");
}