#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "contact.h"

void AddContact(char* filename)
{
    //open contact file
    FILE* fp = fopen(filename , "a");
    if (fp == NULL)
    {
        printf("error to open contact file\n");
        return;
    }

    // get (scan) new contact info
    contact* c = malloc(sizeof(contact));

    printf("Enter Contacts Name: ");
    scanf("%19s", c->name);
    printf("Enter Contacts Number: ");
    scanf("%li", &(c->number));
    printf("Enter Contacts E-mail: ");
    scanf("%29s", c->mail);

    //writes contact to file
    fprintf(fp, "%s-%li-%s\n",
            c->name , c->number, c->mail);


    free(c);
    fclose(fp);

}

void PrintContacts (char* filename)
{

    //open contact file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("error to open contact file\n");
        return;
    }

    //contact index
    int i = 1;
    //contact buffer
    char line[100];

    //prints each contact information
    while(fgets(line, sizeof(line), fp))
    {
        printf("%i: %s", i, line);
        i++;
    }

    fclose(fp);
    return;
}

void PrintSpecificContact (char* filename)
{
    //open contact file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("error to open contact file\n");
        return;
    }

    //gets specific name
    char contactName[20];
    printf("Enter Contacts Name you want info: ");
    scanf("%19s", contactName);

    char line[100];

    //print infos for the name specified
    while(fgets(line, sizeof(line), fp))
    {
        line[strcspn(line, "\n")] = 0;
        char *name = strtok(line, "-");
        char *phone = strtok(NULL, "-");
        char *mail = strtok(NULL, "-");

        if (strcmp(name, contactName) == 0)
        {
            printf("%s - %s - %s\n", name, phone, mail);
            fclose(fp);
            return;
        }
    }

    //if no contact was found
    printf("No contact Found\n");
    fclose(fp);

}

void RemoveContact (char* filename)
{
    //open contact file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("error to open contact file\n");
        return;
    }

    //open temp file to rewrite other contacts
    FILE* temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        printf("error to open temp file\n");
        return;
    }

    //gets contact to be removed
    char contactName[20];
    printf("Enter Contact Name to remove: ");
    scanf("%19s", contactName);

    char line[100];

    //if is not the contact to be removed, write at the temp file
    while(fgets(line, sizeof(line), fp))
    {
        char contact[100];
        strcpy(contact, line);

        line[strcspn(line, "\n")] = 0;
        char *name = strtok(line, "-");

        if (strcmp(name, contactName) != 0)
            fputs(contact, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);
    printf("Contact Sucessfully Removed\n");
}

void ChangeContactNumber (char* filename)
{
    //open contact file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("error to open contact file\n");
        return;
    }

    //open temp file to rewrite other contacts
    FILE* temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        printf("error to open temp file\n");
        return;
    }

    //gets contact name and new number
    char contactName[20];
    long int newNum;

    printf("Enter Contact Name: ");
    scanf("%19s", contactName);
    printf("Enter Contact new Number: ");
    scanf("%li", &newNum);

    char line[100];

    //if is not the contact to be removed, write at the temp file
    while(fgets(line, sizeof(line), fp))
    {
        char contact[100];
        strcpy(contact, line);

        line[strcspn(line, "\n")] = 0;
        char *name = strtok(line, "-");
        char *phone = strtok(NULL, "-");
        char *mail = strtok(NULL, "-");

        if (strcmp(name, contactName) == 0)
            fprintf(temp, "%s-%li-%s\n",name , newNum, mail);
        else
            fputs(contact, temp);
    }
    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);
}
