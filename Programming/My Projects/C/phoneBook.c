#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This a PhoneBook Application

typedef struct PhoneBook
{
    char Fname[20], Lname[10];
    long int mobile_no;
    char email[20], address[30];
    char DOB[10];

} PhoneBook;

// Adding contacts
int addContact(PhoneBook *Contact, int contactNo)
{
    PhoneBook *PB;
    FILE *ptr;
    ptr=fopen("data.txt","a+");
    PB=(PhoneBook *)calloc(sizeof(PhoneBook),1);
    printf("Enter the Details for the contact:\n");
    printf("Name: ");
    scanf("%s", &(Contact->Fname));
    printf("Name: ");
    scanf("%s", &(Contact->Lname));
    printf("Mobile No : ");
    scanf("%ld", &(Contact->mobile_no));
    printf("Email: ");
    scanf("%s", &(Contact->email));
    printf("Address: ");
    scanf("%s", &(Contact->address));
    printf("Date of Birth(DD/MM/YY): ");
    scanf("%s", &(Contact->DOB));

    fwrite(&PB,sizeof(PhoneBook),1,ptr);
    fclose(ptr);
}

// Display All contacts
void Display(PhoneBook *Contact, int No)
{
    PhoneBook PB;
    FILE *ptr;
    if(ptr==NULL)
    {
        printf("Error opening the file...\n");
    }
    ptr=fopen("data.txt","r");
    while(fread(&PB,sizeof(PhoneBook),1,ptr))
    {
        printf("The saved contacts are:\n");
        printf("Name: %s\n", Contact->Fname);
        printf("Mobile No : %ld\n", Contact->mobile_no);
        printf("Nickname: %s\n", Contact->Lname);
        printf("Email: %s\n", Contact->email);
        printf("Address: %s\n", Contact->address);
        printf("Date of Birth: %s\n", Contact->DOB);
    }
    fclose(ptr);

}

// Searching a contact
int Search()
{
}

// Deleting a contact
int Delete(int contactNo)
{
}

// Saarch & Edit a contact
int searchEdit()
{
}

// Contacts in favourite list
int favouriteContacts()
{
}

// Contact in Blacklist
int blackList()
{
}

// Driver's Code
int main()
{
    printf("\n\t\t---------------------------------------\n");
    printf("\t\t   Wel-Come To The Contact Application");
    printf("\n\t\t---------------------------------------\n\n");

    // Dynamic memory allocation
    PhoneBook *Contact = (PhoneBook *)malloc(10 * sizeof(PhoneBook));
    int serial_no = 0, x;
    int No = 0;

    while (x != 7)
    {
        printf("Enter your choice\n");
        printf("1) Add number\n2) Show all list\n3) Search Contact\n4) Search & Edit a contact\n");
        printf("5) Favourite Contact list\n6) Blacklist Contacts\n7) Exit\n==> :: ");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            addContact(Contact, No);
            No++;
            break;
        case 2:
            Display(Contact, No);
            break;
        case 3:
            Search();
            break;
        case 4:
            searchEdit();
            break;
        case 5:
            favouriteContacts();
            break;
        case 6:
            blackList();
            break;
        default:
            printf("Invalid Option\n");
            break;
        }
        printf("\n\t\t-------------------EXIT-----------------------\n");
        return 0;
    }
}
