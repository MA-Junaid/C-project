#include <stdio.h>
#include <string.h>
#include <dos.h>
#include "borrowBooks.h"
#include "registration.h"
#include "returnBooks.h"
#include "adminFunctions.h"

int ch;

void main()
{
    puts ("======================");
    puts ("      MAIN MENU");
    puts ("======================");
    puts("  Select user:");
    puts("  [1] Student");
    puts("  [2] Admin");
    puts("  [3] Exit");
    puts ("======================");
    printf(">> ");
    scanf("%d", &ch);
    switch (ch)
    {
        case 1:
            system("cls");
            studentPass();
            break;
        case 2:
            system("cls");
            adminPass();
            break;
        case 3:
            system("cls");
            break;
        default:
            {
                puts("Invalid Input. Please try again.");
                sleep(1);
                system("cls");
                main();
                break;
            }
    }
}

void studentPass()
{
    puts(" [1] Create an account");
    puts(" [2] Log in");
    printf(">> ");
    scanf("%d", &ch);
    switch (ch)
    {
        case 1:
            system("cls");
            registration();
            break;
        case 2:
            system("cls");
            login();
            break;
    }
}


void menuStudent()
{
    puts(" [1] Borrow books");
    puts(" [2] Return books");
    puts(" [3] Go back to main menu");
    printf(">> ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        system("cls");
        borrow();
        break;
    case 2:
        system("cls");
        returnB();
        break;
    case 3:
        system("cls");
        main();
        break;
    default:
        puts("Invalid Input. Please try again.");
        sleep(1);
        system("cls");
        menuStudent();
        break;
    }
}

void adminPass()
{
    printf("Enter password: ");
    int pass;
    scanf("%d", &pass);
    int admPass = 123456;
    if (pass == admPass)
    {
        puts("Correct password\nWait a moment....");
        sleep(1);
        system("cls");
        menuAdmin();
    }
    else
    {
        printf("The password is invalid. Please try again.");
        sleep(1);
        system("cls");
        adminPass();
    }
}

void menuAdmin()
{
    puts(" [1] Add book");
    puts(" [2] View books info");
    puts(" [3] View Student info");
    puts(" [4] Go back to main menu");
    printf(">> ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        system("cls");
        addBook();
        break;
    case 2:
        system("cls");
        viewBook();
        break;
    case 3:
        system("cls");
        puts("Student Information:");
        viewStudentData();
        break;
    case 4:
        system("cls");
        main();
        break;
    default:
        {
            puts("Invalid Input. Please try again.");
            sleep(1);
            system("cls");
            menuAdmin();
        }
        break;
    }
}

