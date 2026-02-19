#ifndef CONTACTS_H
#define CONTACTS_H

//contact struct
typedef struct contact{
    char name[20];
    long int number;
    char mail[30];
}contact;

//functions prototypes
void AddContact(char* filename);
void PrintContacts (char* filename);
void PrintSpecificContact (char* filename);
void RemoveContact (char* filename);
void ChangeContactNumber (char* filename);


#endif
