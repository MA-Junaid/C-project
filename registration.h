struct user
{
    int id;
    int name[100];
    int password;
} person;

void registration()
{
    FILE *log;
    log = fopen("studentDatabase.txt", "a");
    rewind(log);
    puts("Please enter your details:\n");
    printf("\nEnter your NSU ID: ");
    scanf("%d", &person.id);
    printf("\nEnter your name: ");
    scanf("%s", person.name);
    printf("\nEnter your password: ");
    scanf("%d", &person.password);
    fseek(log, 0, SEEK_END);
    fwrite(&person, sizeof(person), 1, log);
    puts("Registration successful!! Please log in...");
    fclose(log);
    sleep(1);
    system("cls");
    login();
}

void login()
{
    int id2;
    char username[20];
    int password2;
    int count = 0;
    FILE *log;
    log = fopen("studentDatabase.txt", "r");
    //rewind(log);
    printf("\nNSU ID: ");
    scanf("%d", &id2);
    printf("\nName: ");
    scanf("%s", username);
    printf("\nPassword: ");
    scanf("%d", &password2);
    while (fread(&person, sizeof(person), 1, log)==1)
    {
        if((id2 == person.id) && (password2 == person.password) && (strcmp(username, person.name)==0))
        {
            printf("\nLog in successful!!");
            sleep(1);
            system("cls");
            menuStudent();
            count =1;
        }
    }
    if(count == 0)
        {
            printf("\nIncorrect....\n\nPlease try again");
            sleep(1);
            system("cls");
            login();
        }
    fclose(log);
}

void viewStudentData()
{
    FILE *log;
    log =fopen("studentDatabase.txt","r");
    while(fread(&person,sizeof(person),1,log)==1)
    {
        printf("\t%d",person.id);
        printf("\t%s",person.name);
        printf("\t%d",person.password);
        printf("\n");
    }
    puts("Press any key to continue....");
    getch();
    fclose(log);
    sleep(1);
    system("cls");
    menuAdmin();
}


