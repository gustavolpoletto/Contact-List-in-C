#include <stdio.h>

#include "contact.h"

int main ()
{
    char filename[] = {"contactList.txt"};
    int option;

    void(*functions[])(char*) = {
        NULL,
        AddContact,
        PrintContacts,
        PrintSpecificContact,
        RemoveContact ,
        ChangeContactNumber};
    do{

        printf("\n");
        printf("---OPTIONS---\n[1]Add Contact\n[2]Print Contacts\n[3]Print Specific Contact\n[4]Remove Contact\n[5]Change a Contact Number\n[6]Exit\n");

        do{
        printf("- ");
        scanf("%i", &option);
        }while(option < 1 || option > 6);

        system("clear");

        if (option >=1 && option <=5)
            functions[option](filename);

    }while (option != 6);

    return 0;
}
