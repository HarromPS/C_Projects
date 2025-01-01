#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact
{
    char name[30];
    char address[4];
    long int mobile_no;
    char gender[8];
    char email[100];
} contact;

// All function declaration.
void start();
void remove_all();
void print_menu();
void add_contact();
void list_record();
void search_contact();
void remove_contact();
void update_contact();
void take_input(contact *p);

// Program starts here.
int main()
{
    system("color 4f");
    system("cls");
    printf("\n\t\t---------------------------------------\n");
    printf("\t\t   Wel-Come To The Contact Application");
    printf("\n\t\t---------------------------------------\n\n");
    int ok = 0, i;
    char user_name[20];
    char password[9], temp[9];
    while (ok != 1)
    {
        printf("\t\tENTER USERNAME: ");
        scanf("%s", user_name);
        printf("\n\t\tENTER PASSWORD: ");
        for (i = 0; i < 8; i++)
        {
            // scanf("%c",&temp[i]);
            password[i] = getch();
            ;
            printf("*");
        }
        password[i] = '\0';
        if (!strcmp(user_name, "admin") && !strcmp(password, "12345678"))
        {

            break;
        }
        else
        {
            system("cls");

            printf("\n\n\t\t    INCORRECT USERNAME OR PASSWORD\n");
            printf("\n\t\t---------------------------------------\n");
            printf("\n\t\t\t\tTRY AGAIN\n\n");
        }
    }
    system("cls");
    printf("\n\t\t---------------------------------------\n");
    printf("\n\t\t\tLOGGED IN SUCCESSFULLY\n");
    printf("\n\t\t---------------------------------------\n");

    start();
    return 0;
}

// This function will start our program.
void start()
{
    system("cls");
    int choice;
    while (choice != 8)
    {
        print_menu();
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            add_contact();
            getchar();
            getchar();
            break;
        case 2:
            list_record();
            getchar();
            getchar();
            break;
        case 3:
            search_contact();
            getchar();
            getchar();
            break;

        case 4:
            update_contact();
            getchar();
            getchar();
            break;
        case 5:
            remove_contact();
            getchar();
            getchar();
            break;
        case 6:

            system("cls");
            printf("\tThis Phonebook application is a set of basic functions of Adding\n");
            printf("\t\tDeleting, Updating & Searching new contacts.\n");
            printf("It has used the concepts of file handling & Data Structures in this project.\n\n\t\t   Thank You for using this App\n\n");
            printf("\t\tDeveloped by ~ Hariom Pravin Shivhare\n\n");
            printf("\n\n\t\t\t\tENTER ANY KEY\n\n");
            getch();
            system("cls");

            break;
        case 7:
            remove_all();
            getchar();
            getchar();
            break;
        case 8:
            printf("\n\t\t-------------------EXIT-----------------------\n");
            break;
        default:
            system("cls");
            printf("\n\n\t\tENTER BETWEEN 1 TO87 \n");
            getchar();
            getchar();
            exit(1);
        }
    }
}

// This will print main menu.
void print_menu()
{
    printf("1) Add Contact\n2) Show all contact\n3) Search Contact\n4) Modify Contact\n");
    printf("5) Delete contact\n6) App Info\n7) Delete all data\n8) Exit\n==> :: ");
    printf("\t\t\t\tEnter your Choice : ");
}

void add_contact()
{
    system("cls");
    FILE *fp;
    fp = fopen("phonebook_db", "ab+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        contact p;
        take_input(&p);
        fwrite(&p, sizeof(p), 1, fp);
        fflush(stdin);
        fclose(fp);
        system("cls");
        printf("\n \tContact Saved Successfully\n\n");
        printf("\n\n\t\tEnter any key: ");
    }
}

// By this we take contact information.
void take_input(contact *p)
{
    system("cls");
    // This getchar is for taking \n occured by previous functions.
    // So that scanset in scanf will work properly.
    getchar();
    printf("\nEnter name : ");
    // Here we are using scanset '^' - >  until get
    scanf("%[^\n]s", p->name);

    printf("\nEnter country code : ");
    scanf("%s", p->address);

    printf("\nEnter mobile no : ");
    scanf("%ld", &p->mobile_no);

    printf("\nEnter gender : ");
    scanf("%s", p->gender);

    printf("\nEnter email : ");
    scanf("%s", p->email);
}

// This function will list contact available in phonebook.
void list_record()
{
    system("cls");
    FILE *fp;
    fp = fopen("phonebook_db", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        contact p;

        printf("\t\t\t\tTHE SAVED CONTACT ARE\n");

        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            // printf("\nTHE SAVED CONTACT ARE:\n\n");
            printf("\nName: %s", p.name);
            printf("\nAddress:%s", p.address);
            printf("\nMobile No: %ld", p.mobile_no);
            printf("\nGender: %s", p.gender);
            printf("\nEmail: %s", p.email);
            printf("\n");
            fflush(stdin);
        }
        fflush(stdin);
        fclose(fp);
        system("cls");
        printf("\n\n\t\tEnter any key: ");
    }
}

// This function will search contact in phonebook.
void search_contact()
{
    system("cls");
    long int phone;
    printf("Search by Name - '1'\nSearch by Mobile No- '2'\n==>");
    int x, flag = 0;
    ;
    scanf("%d", &x);
    char name[20];

    FILE *fp;
    contact p;
    fp = fopen("phonebook_db", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        if (x == 2)
        {
            printf("Enter Phone number of the contact you want to search \n==>");
            scanf("%ld", &phone);

            while (fread(&p, sizeof(p), 1, fp) == 1)
            {
                if (p.mobile_no == phone)
                {
                    printf("\nName: %s", p.name);
                    printf("\nAddress:%s", p.address);
                    printf("\nMobile No: %ld", p.mobile_no);
                    printf("\nGender: %s", p.gender);
                    printf("\nEmail: %s", p.email);
                    printf("\n");

                    flag = 1;
                    break;
                }
                else
                    continue;
                // fflush(stdin);
            }
        }
        else if (x == 1)
        {
            printf("\n\t\tEnter Name: ");
            scanf("%s", &name);
            while (fread(&p, sizeof(p), 1, fp) == 1)
            {
                if (p.name == name)
                {
                    printf("\nName: %s", p.name);
                    printf("\nAddress:%s", p.address);
                    printf("\nMobile No: %ld", p.mobile_no);
                    printf("\nGender: %s", p.gender);
                    printf("\nEmail: %s", p.email);
                    printf("\n");

                    flag = 1;
                    break;
                }
                else
                    continue;
            }
        }
        if (flag == 0)
        {
            system("cls");
            printf("\n\n\tCONTACT NOT FOUND\n");
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\n\t\tEnter any key: ");
    }
}

// This function will remove contact from phonebook.
void remove_contact()
{
    system("cls");
    long int phone;
    printf("Enter Phone number of the contact you want to delete from phonebook : ");
    scanf("%ld", &phone);

    FILE *fp, *temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp", "wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        contact p;
        int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (p.mobile_no == phone)
            {
                system("cls");
                printf("Contact removed successfully\n");
                flag = 1;
            }
            else
                fwrite(&p, sizeof(p), 1, temp);
            fflush(stdin);
        }
        if (flag == 0)
        {
            system("cls");
            printf("No record found for %d number\n", phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp", "phonebook_db");
        fflush(stdin);
        printf("\n\n\t\tEnter any key: ");
    }
}

// This function will update contact information.
void update_contact()
{

    system("cls");
    long int phone;
    printf("Enter Phone number of the contact you want to update details : ");
    scanf("%ld", &phone);

    FILE *fp, *temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp", "wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("\n\n\t\tEnter any key: ");
        return;
    }
    else
    {
        int flag = 0;
        contact p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (p.mobile_no == phone)
            {
                take_input(&p);
                fwrite(&p, sizeof(p), 1, temp);
                system("cls");
                printf("Data updated successfully\n");
                flag = 1;
            }
            else
                fwrite(&p, sizeof(p), 1, temp);
            fflush(stdin);
        }
        if (flag == 0)
        {
            system("cls");
            printf("No record found for %d number\n", phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp", "phonebook_db");
        fflush(stdin);
        printf("\n\n\t\tEnter any key: ");
    }
}

// This function will clear all the data of phonebook.
void remove_all()
{
    char choice;
    system("cls");
    remove("./phonebook_db");
    printf("All data in the phonebook is deleted successfully\n");
    printf("\n\n\t\tEnter any key: ");
}
