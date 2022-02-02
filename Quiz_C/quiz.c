#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    system("color 6");
    char user_choice;
    int correct_ans = 0;

    char qns[][200] = {
        "1) In which part of your body would you find the cruciate ligament?",
        "2) What is the name of the main antagonist in the Shakespeare play Othello?",
        "3) What element is denoted by the chemical symbol 'Sn' in the periodic table?",
        "4) What is the currency of Denmark?",
        "5) Which Tennis Grand Slam is played on a clay surface?",
        "6) In which European country would you find the Rijksmuseum?",
        "7) What was the old name for a Snickers bar before it changed in 1990?",
        "8) What is the smallest planet in our solar system?",
        "9) Who wrote the Cpp language?",
        "10) Which popular video game franchise has released games with the subtitles World At War and Black Ops?"};

    char opt[][50] = {
        "A. Mouth",
        "B. Knee",
        "C. Arms",
        "D. Foot",
        "A. Emilia",
        "B. Bianca",
        "C. Lago",
        "D. Roderigo",
        "A. Tin",
        "B. Sandenium",
        "C. Copper",
        "D. Manganese",
        "A. Dollars",
        "B. Euro",
        "C. Krone",
        "D. Yen",
        "A. The French Open",
        "B. The Swiss Open",
        "C. World Tennis Championship",
        "D. Asian Open Tour",
        "A. The United Kingdom",
        "B. Finland",
        "C. Germany",
        "D. Netherlands",
        "A. Marathon",
        "B. Snickbars",
        "C. Crunchh",
        "D. ChocolateBars",
        "A. Pluto",
        "B. Mercury",
        "C. Venus",
        "D. Mars",
        "A. Guido van Rossum",
        "B. Dennis Ritchie",
        "C. Anders Hejlsberg",
        "D. Bjarne Stroustrup",
        "A. Vanguard",
        "B. Assasin's Creed",
        "C. Far Cry",
        "D. Call of Duty",
    };

    char ans[10] = {
        'B',
        'C',
        'A',
        'C',
        'A',
        'D',
        'A',
        'B',
        'D',
        'D'};

    int no_of_qns = sizeof(qns) / sizeof(qns[0]);

    printf("\n\n\t\t\t*****************************************\n");
    printf("\t\t\t*\tWelcome to the Quiz Game\t*\n");
    printf("\t\t\t*****************************************\n\n");

    for (int i = 0; i < no_of_qns; i++)
    {
        printf("\t%s\n", qns[i]);
        for (int j = (i * 4); j < (i * 4) + 4; j++)
        {
            printf("\t\t%s\n", opt[j]);
        }
        printf("\n");
        printf("\tEnter your choice: ");
        scanf(" %c", &user_choice);
        user_choice = toupper(user_choice);

        if (user_choice == ans[i])
        {
            printf("\tCorrect Answer!!");
            correct_ans++;
        }
        else
        {
            printf("\a\tWrong Answer!!");
        }
        printf("\n\n\t*****************************************************************************************************************\n\n");
    }

    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*\tYour total score: %d out of %d.\t*\n", correct_ans, no_of_qns);
    printf("\t\t\t\t*****************************************\n\n\n");

    system("pause");
    return 0;
}