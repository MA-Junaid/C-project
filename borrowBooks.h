struct bookInfo
{
    int serial;
    char title[50];
    char author[50];
    int quantity;
} book;

void borrow()
{
    int cho;
    puts("  [1] View books collection");
    puts("  [2] Search books");
    puts("  [3] Show Selected books");
    puts("  [4] Go back");
    printf(">> ");
    scanf("%d", &cho);
    FILE *fpB;
    fpB = fopen("bookDatabase.txt", "r");
    switch (cho)
    {
        case 1:
            system("cls");
            while(fread(&book, sizeof(book), 1, fpB) == 1)
            {
                printf("\t%d", book.serial);
                printf("\t%s", book.title);
                printf("\t%s", book.author);
                printf("\t%d", book.quantity);
                printf("\n");
            }
            printf("\nEnter book serial to issue: ");
            int add;
            scanf("%d", &add);
            issueBook(add);

            getch();
            sleep(1);
            system("cls");
            borrow();
            break;
        case 2:
            system("cls");
            searchBook();
            break;
        case 3:
            system("cls");
            showBook();
            break;
        case 4:
            system("cls");
            menuStudent();
            break;
        default:
            {
                puts("Invalid Input. Please try again.");
                sleep(1);
                system("cls");
                borrow();
                break;
            }
        borrow();
    }
    fclose(fpB);
}

void searchBook()
{
    FILE *fpB;
    fpB = fopen("bookDatabase.txt", "r");
    int serialS, count = 0;
    printf("\nEnter the serial: ");
    scanf("%d", &serialS);
    while(fread(&book, sizeof(book), 1, fpB) == 1)
    {
        if(serialS == book.serial)
            {
                printf("\nThe book is FOUND");
                printf("\n\nTitle: %s", book.title);
                printf("\nAuthor: %s", book.author);
                printf("\nQuantity: %d", book.quantity);
                count = 1;
                printf("\nDo you want to take this book? (y/n): ");
                char ans = getchar();
                scanf("%c", &ans);
                if(ans == 'y')
                {
                    int tempo = book.serial;
                    issueBook(tempo);
                    printf("\nBook Added");
                }
            }
    }
    if(count == 0)
            printf("\n\t\tBook is not found\n");
    getch();
    sleep(1);
    system("cls");
    borrow();

    fclose(fpB);
}

void issueBook(int idI)
{
    FILE *fpB;
    FILE *fpTemp;
    fpB = fopen("bookDatabase.txt", "r");
    fpTemp = fopen("bookIssue.txt", "w");
    while(fread(&book, sizeof(book), 1, fpB) == 1)
    {
        if(idI == book.serial)
            {
                fwrite(&book, sizeof(book), 1, fpTemp);
            }
    }
    fclose(fpB);
    fclose(fpTemp);
}

void showBook()
{
    FILE *fpTemp;
    fpTemp = fopen("bookIssue.txt", "r");
    while(fread(&book, sizeof(book), 1, fpTemp) == 1)
    {
        printf("\t%d", book.serial);
        printf("\t%s", book.title);
        printf("\t%s", book.author);
        printf("\t%d", book.quantity);
        printf("\n");
    }
    fclose(fpTemp);
}






