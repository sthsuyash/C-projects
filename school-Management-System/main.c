/*
    Simple project on school management system to manage the students data using C programming language.
    Author : Suyash Shrestha
    Start date : 11/16/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

int main_exit; // variable declared to check whether to exit or retry.

// contains marks of diff subjects
typedef struct
{
    int math;
    int iit;
    int dl;
    int c;
    int physics;

} marks;

// contains date,month and year of birth
typedef struct
{
    int day;
    int month;
    int year;

} dateOfBirth;

// contains temporary address and permanent address
typedef struct
{
    char permanent_city[20];
    char temp_city[20];
} addre;

// main structure where all the structures are linked
typedef struct
{
    int id;
    char fname[50];
    char lname[50];
    char phone[10];
    dateOfBirth dob;
    addre address;
    marks mark;

} addstudent, updatestudent, deletestudent, viewstudent; // naming the structure for different functions

// declaring functions
void add();       // add new students' data to the file.
void update();    // update the previous students' data in the stored file.
void delete ();   // delete the students' data on the file.
void view();      // view all the students' data from the file.
void main_menu(); // main menu where the user is prompted to after the password is correct.

// driver function
int main()
{
    int epIndex = 0; // used to iterate through each word in user entered password.
    system("color B");
    char entered_password[10], login_password[10] = "admin", c;
    system("cls"); // clears the screen from previous lines
    printf("\n\n\n\tEnter password to login: ");

    // getting password from user
    while (1)
    {
        c = getch(); // getting character from the user using getch() as it doesn't show the entered text
        if (c == 13) // if user presses enter, the loop ends
        {
            break;
        }
        else if (c == 8) // if user presses backspace
        {
            if (epIndex > 0)
            {
                epIndex--;
                entered_password[epIndex] = '\0'; // it will delete the data of latest index
                printf("\b \b");                  // it will move the cursor to the previous index, specifies the character to be " " and again goes back to the previous index.
            }
        }
        else if (c == 9 || c == 27) // if  user presses tab or esc
                                    // do not store
        {
            continue;
        }
        else
        {
            if (epIndex < 12) // if the lenth of password entered is more than 12, donot accept the values
            // only store string less than or equal to 12 characters
            {
                entered_password[epIndex] = c;
                printf("*");
                epIndex++;
            }
            else
            {
                break;
            }
        }
    }
    entered_password[epIndex] = '\0';

    // comparing user entered password with real password
    if (strcmp(entered_password, login_password) == 0)
    {
        system("cls");
        printf("\n\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME ADMIN! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\tDirecting to main page ");
        for (int i = 0; i < 10; i++)
        {
            Sleep(100); // sleep(x) -> delays the processing for the required time.
                        // present inside <windows.h> header file.
                        // the data inserted is in milliseconds.
            printf(".");
        }
        main_menu(); // calling the main menu if the password is correct.
    }
    else
    {
        printf("\n\n\n\tPassword Incorrect!\a\a\n");
    retry_login:
        printf("\n\tPress 1 to try again or 0 to quit. ");
        scanf("%d", &main_exit);
        if (main_exit == 1)
        {
            system("cls");
            main();
        }
        else if (main_exit == 0)
        {
            system("cls");
            goto end; // sends the program to end of the code where the jump statement is declared.
        }
        else
        {
            system("cls");                     // clears the previous content of the screen.
            printf("Enter valid option!\a\a"); // '\a' produces a windows error sound.
            goto retry_login;                  // if option is not among 0 or 1, it will prompt you to re-enter the value to either exit or retry password.
        }
    }
end:
    system("cls");
    printf("\n\nDeveloped by Suyash Shrestha.\n");
    printf("\n");
    system("pause"); // pauses the program at the end waiting for you to press any key.

    return 0;
}

// main menu function which shows the options where you can create and add, modify, remove & view students' data or quit.
void main_menu(void)
{
    int option;
    system("cls");
    system("color A");

    printf("\n\n\n\t\t\t\t\t");
    for (int i = 0; i < 42; i++)
    {
        printf("\xB2");
    }
    printf("\n\t\t\t\t\t\xB2\xB2\t\t\t\t\t\xB2\xB2\n");
    printf("\t\t\t\t\t\xB2\xB2\tSCHOOL MANAGEMENT SYSTEM\t\xB2\xB2");
    printf("\n\t\t\t\t\t\xB2\xB2\t\t\t\t\t\xB2\xB2\n\t\t\t\t\t");

    for (int i = 0; i < 42; i++)
    {
        printf("\xB2");
    }
    printf("\n\n\n");
re:
    printf("\t\t\t\t\t     What task do you want to perform? \n\n\t\t\t\t");
    for (int i = 0; i < 58; i++)
    {
        printf("\xB2");
    }
    printf("\n");

    printf("\t\t\t\t\xB2\xB2\t\t\t\t\t\t\t\xB2\xB2");
    printf("\n\t\t\t\t\xB2\xB2\tPress (0) to quit.                       \t\xB2\xB2\n");
    printf("\t\t\t\t\xB2\xB2\tPress (1) for creating new student data. \t\xB2\xB2\n");
    printf("\t\t\t\t\xB2\xB2\tPress (2) for updating old student data. \t\xB2\xB2\n");
    printf("\t\t\t\t\xB2\xB2\tPress (3) for removing student data.     \t\xB2\xB2\n");
    printf("\t\t\t\t\xB2\xB2\tPress (4) for viewing student's data.    \t\xB2\xB2\n");
    printf("\t\t\t\t\xB2\xB2\t\t\t\t\t\t\t\xB2\xB2\n\t\t\t\t");

    for (int i = 0; i < 58; i++)
    {
        printf("\xB2");
    }
    printf("\n\n");

    printf("\t\t\t\t\tEnter your option: ");
    scanf("%d", &option);
    printf("\n\n");
    system("cls");
    switch (option)
    {
    case 0:
        exit(0);
        return;

    case 1:
        add();
        break;

    case 2:
        // update();
        break;

    case 3:
        // delete ();
        break;

    case 4:
        view();
        break;

    default:
        system("cls");
        printf("\n\n\t\tPlease enter a valid option.\a\a\n\n");
        goto re;
        break;
    }
}

// add function which lets user add the number of students they want
void add(void)
{
    int n;
    FILE *source = fopen("students.dat", "ab+"); // opening file in append mode as you must add the students in existing file or create a entirely new file.
    addstudent *s, views;
    printf("How many students do you want to add: ");
    scanf("%d", &n);

id_again:
    system("cls");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("Enter your id no: ");
        scanf("%d", &s->id);

        while (fscanf(source, "%d %s %s %s %d/%d/%d %s %s %d %d %d %d %d", &views.id, views.fname, views.lname, views.phone, &views.dob.day, &views.dob.month, &views.dob.year, views.address.permanent_city, views.address.temp_city, &views.mark.math, &views.mark.iit, &views.mark.c, &views.mark.dl, &views.mark.physics) != EOF)
        {
            if ((s->id) == (views.id))
            {
                printf("ID already in use.\n\n");
            try_again:
                printf("Press 1 to try again or 0 to goto main menu: ");
                scanf("%d", &main_exit);
                if (main_exit == 0)
                {
                    main_menu();
                }
                else if (main_exit == 1)
                {
                    goto id_again;
                }
                else
                {
                    system("cls");
                    printf("Enter a valid option.\n");
                    goto try_again;
                }
            }
        }

        getchar();
        printf("Enter First name: ");
        scanf("%[^\n]s", (s->fname));

        getchar();
        printf("Enter Last name: ");
        scanf("%[^\n]s", (s->lname));

        getchar();
        printf("Enter phone number: ");
        scanf("%s", (s->phone));

        printf("Enter birth day: ");
        scanf("%d", (&s->dob.day));

        printf("Enter birth month: ");
        scanf("%d", (&s->dob.month));

        printf("Enter birth year: ");
        scanf("%d", (&s->dob.year));

        getchar();
        printf("Enter home city : ");
        scanf("%[^\n]s", (s->address.permanent_city));

        getchar();
        printf("Enter temporary city : ");
        scanf("%[^\n]s", (s->address.temp_city));

        printf("Enter marks in Maths: ");
        scanf("%d", (&s->mark.math));

        printf("Enter marks in IIT: ");
        scanf("%d", (&s->mark.iit));

        printf("Enter marks in C-Programming: ");
        scanf("%d", (&s->mark.c));

        printf("Enter marks in Digital Logics: ");
        scanf("%d", (&s->mark.dl));

        printf("Enter marks in Physics: ");
        scanf("%d", (&s->mark.physics));

        fprintf(source, "%d %s %s %s %d/%d/%d %s %s %d %d %d %d %d", s->id, s->fname, s->lname, s->phone, s->dob.day, s->dob.month, s->dob.year, s->address.permanent_city, s->address.temp_city, s->mark.math, s->mark.iit, s->mark.c, s->mark.dl, s->mark.physics);
        fprintf(source, "\n");
    }

    system("cls");
    printf("\n\n\t\tStudent(s) added successfully!\n\n");
again:
    printf("\n\n\tEnter 1 to goto main menu or 0 to exit: ");
    scanf("%d", &main_exit);

    if (main_exit == 1)
    {
        printf("\tRedirecting to main menu");
        for (int j = 0; j < 7; j++)
        {
            Sleep(120);
            printf(".");
        }
        main_menu();
    }
    else if (main_exit == 0)
    {
        printf("\tExiting the application");
        for (int j = 0; j < 7; j++)
        {
            Sleep(120);
            printf(".");
        }
        exit(0);
    }
    else
    {
        system("cls");
        printf("Invalid option!! Try again\n");
        goto again;
    }
}

// view function that lets user view all the data of students in the file
void view(void)
{
    int count = 0;
    viewstudent views;
    FILE *source = fopen("students.dat", "rb");

    system("cls");
    printf("\n\n\t\t\t\t\t\t\t");
    for (int i = 0; i < 34; i++)
    {
        printf("\xB2");
    }
    printf("\n");
    printf("\t\t\t\t\t\t\t\xB2\xB2\t\t\t\t\xB2\xB2\n");
    printf("\t\t\t\t\t\t\t\xB2\xB2\tStudents' Records\t\xB2\xB2\n");
    printf("\t\t\t\t\t\t\t\xB2\xB2\t\t\t\t\xB2\xB2\n");
    printf("\t\t\t\t\t\t\t");

    for (int i = 0; i < 34; i++)
    {
        printf("\xB2");
    }
    printf("\n\n\n");

    printf("I.D.\t First Name\t  Last Name\t  Phone Number \tDate of birth\t Permanent City  Temporary City  Maths\tIIT\tC\tDL\tPhysics\n");
    while (fscanf(source, "%d %s %s %s %d/%d/%d %s %s %d %d %d %d %d\n", &views.id, views.fname, views.lname, views.phone, &views.dob.day, &views.dob.month, &views.dob.year, views.address.permanent_city, views.address.temp_city, &views.mark.math, &views.mark.iit, &views.mark.c, &views.mark.dl, &views.mark.physics) != EOF)
    {
        printf("%d  \t %s    \t  %s     \t  %s\t  %d/%d/%d\t %s  \t %s \t %d\t%d\t%d\t%d\t %d\n", views.id, views.fname, views.lname, views.phone, views.dob.day, views.dob.month, views.dob.year, views.address.permanent_city, views.address.temp_city, views.mark.math, views.mark.iit, views.mark.c, views.mark.dl, views.mark.physics);
        count++;
    }
    if (count == 0)
    {
        printf("\n\nNO records!!");
    }
    fclose(source);
again:
    printf("\n\n\n\t\tEnter 1 to goto main menu or 0 to exit: ");
    scanf("%d", &main_exit);

    if (main_exit == 1)
    {
        printf("\n\t\tRedirecting to main menu");
        for (int j = 0; j < 7; j++)
        {
            Sleep(120);
            printf(".");
        }
        main_menu();
    }
    else if (main_exit == 0)
    {
        printf("\n\t\tExiting the application");
        for (int j = 0; j < 7; j++)
        {
            Sleep(120);
            printf(".");
        }
        exit(0);
    }
    else
    {
        system("cls");
        printf("Invalid option!! Try again\n");
        goto again;
    }
}
