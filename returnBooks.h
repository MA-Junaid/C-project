void returnB()
{
    int d[2], m[2];
    puts("Enter Borrowing date:");
    printf("\nEnter day: ");
    scanf("%d", &d[0]);
    printf("Enter month: ");
    scanf("%d", &m[0]);
    puts("\nEnter Returning date:");
    printf("\nEnter day: ");
    scanf("%d", &d[1]);
    printf("Enter month: ");
    scanf("%d", &m[1]);

    int a = fineCalculator(d[0], d[1], m[0], m[1]);
    int dueFine = (a - 14) * 20;

    if(dueFine == 0 || dueFine <=0)
        printf("\nYou have no due fines!!");
    else
    {
        printf("\nYour book has expired %d days ago", a-14);
        printf("\nYour total fine is: %d taka", dueFine);
    }
    getch();
    sleep(1);
    system("cls");
    menuStudent();
}

void fineCalculator(int day, int day2, int month, int month2)
{
    int prevDays[2] = {0, 0};
    int totDays[2];
    int borrowDays;
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int i;
    for(i=0; i<month-1; i++)
    {
        prevDays[0] = prevDays[0] + monthDays[i];
    }
    totDays[0] = prevDays[0] + day;

    for(i=0; i<month2-1; i++)
    {
        prevDays[1] = prevDays[1] + monthDays[i];
    }
    totDays[1] = prevDays[1] + day2;

    borrowDays = totDays[1] - totDays[0];
    return borrowDays;
}
