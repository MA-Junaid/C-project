void addBook()
{
    FILE *fpB;
    fpB = fopen("bookDatabase.txt", "a");
    puts("Enter book details: ");
    printf("\nSerial: ");
    scanf("%d", &book.serial);
    printf("\nTitle: ");
    scanf("%s", book.title);
    printf("\nAuthor: ");
    scanf("%s", book.author);
    printf("\nQuantity: ");
    scanf("%d", &book.quantity);

    fseek(fpB, 0, SEEK_END);
    fwrite(&book, sizeof(book), 1, fpB);
    fclose(fpB);
    sleep(1);
    system("cls");
    menuAdmin();
}

void viewBook()
{
    FILE *fpB;
    fpB = fopen("bookDatabase.txt", "r");
    while(fread(&book, sizeof(book), 1, fpB) == 1)
        {
            printf("\t%d", book.serial);
            printf("\t%s", book.title);
            printf("\t%s", book.author);
            printf("\t%d", book.quantity);
            printf("\n");
        }
    fclose(fpB);
    getch();
    sleep(1);
    system("cls");
    menuAdmin();
}

