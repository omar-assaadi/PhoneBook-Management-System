#ifndef MINI5PHONE_H
#define MINI5PHONE_H

struct PHONE_NODE {
        char name[50];
        char birthdate[12];
        char phone[15];
        struct PHONE_NODE *next;
};


extern struct PHONE_NODE *head;

int loadCSV(char *filename);

int saveCSV(char *filename);

int addRecord(char name[], char birth[], char phone[]);

struct PHONE_NODE *findRecord(char name[]);

int listRecords();

int delete(char name[]);

int clear();


#endif /* MINI5PHONE_H */




