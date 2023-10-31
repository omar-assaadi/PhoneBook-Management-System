#include<stdio.h>
#include<string.h>
#include <stdlib.h>


struct PHONE_NODE {
        char name[50];
        char birthdate[12];
	char phone[15];
        struct PHONE_NODE *next;
};

struct PHONE_NODE *head = NULL; // set the head of the linked list to null

int loadCSV(char *filename) {
        FILE *p = fopen(filename, "rt");
        char buffer[1000];
        int i,j;

        if (p == NULL) {
                return 1; // error code
        }

        // otherwise, the file is open, read CSV

        fgets(buffer,999,p); // to read the CSV header (we discard it)

        fgets(buffer,999,p);

        // Initializing features of the linked list
        struct PHONE_NODE *current = NULL;
        while(!feof(p)) {
                // This creates a node for the line in the CSV file
                struct PHONE_NODE *node = (struct PHONE_NODE *)malloc(sizeof(struct PHONE_NODE));
                node->next = NULL;

                // Parsing CSV file and storing the values
                for(j=0,i=0;i<999&&buffer[i]!='\0'&&buffer[i]!=',';i++,j++){
                        node->name[j]=buffer[i];}

                node->name[j]='\0';
                i++;

                for(j=0;i<999&&buffer[i]!='\0'&&buffer[i]!=',';i++,j++){
                        node->birthdate[j]=buffer[i];}

                node->birthdate[j]='\0';
                i++;

                for(j=0;i<999&&buffer[i]!='\0'&&buffer[i]!='\n';i++,j++){
                        node->phone[j]=buffer[i];}

                node->phone[j]='\0';

                // This should add the node to the list
                if(head == NULL) {
                        head = node;
                        current = node;
                        }
                                else {
                        current->next = node;
                        current = node;
                         }
                        fgets(buffer,999,p);

        }

        fclose(p);

        return 0;
}

int saveCSV(char *filename) {
        FILE *p = fopen(filename,"wt");
        struct PHONE_NODE *current = head;

        if (p == NULL) return 1; // error code

        fprintf(p,"name,birthdate,phone\n"); // header

        while(current != NULL){
                fprintf(p,"%s,%s,%s\n", current->name, current->birthdate, current->phone);
                current = current->next;}// updating pointer to the next node in the linked list

        fclose(p);

        return 0;
}


int addRecord(char name[], char birth[], char phone[]) {
    struct PHONE_NODE *new_node = (struct PHONE_NODE *)malloc(sizeof(struct PHONE_NODE));
    if (new_node == NULL) {
        return 1; // error: unable to allocate memory
    }
    strcpy(new_node->name, name);
    strcpy(new_node->birthdate, birth);
    strcpy(new_node->phone, phone);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct PHONE_NODE *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    return 0;
}


struct PHONE_NODE *findRecord(char name[]) { // Not an int function since it returns a pointer
    struct PHONE_NODE *current = head;
    
    while(current != NULL) { // traversing over every node in the linked list
        if (strcmp(current->name, name) == 0) { // checking to see if the name parameter passed to the function is the same as the one in the current node
            return current; 
        }
        current = current->next; // moving to the next node
    }
    
    return NULL;  
}

int listRecords() {
    if (head == NULL) { // Checking if linked list is empty 
        return 1;
    }

    printf("---- NAME ---- ---- BIRTH DATE ---- ---- PHONE ----\n");

    struct PHONE_NODE *current = head;

    while (current != NULL) { // while we don't reach the end of the linked list, print the contents of the current node
		printf("%-14s %-20s %-10s\n", current->name, current->birthdate, current->phone);
        current = current->next; // pointing to the next node in the linked list
    }

    return 0;
}


int delete(char name[]) {
        struct PHONE_NODE *current = head; // initializing a variable to the head of the linked list 
        struct PHONE_NODE *prev = NULL; // initializing another variable prev to NULL to help with traversing the linked list 
        int del = 0; // initializing another variable 

        while( current != NULL) { // comparing the name field of each node to the users input  
                if (strcmp(current -> name, name) == 0){ /// if anything is found, the del variable is set to one and the current pointer is set to point to the node
                        del = 1;
                        break;
                }
                // if nothing is found, we advance to the next node in the linked list
                prev = current;
                current = current -> next;
        }

	if (del == 0) { 
			
		return 1; // error; record not found
	}

	if (del == 1) { 
		if (prev == NULL) { // node to be deleted is the first
		    head = current->next; //setting head to the next node in the list
		}
		else { 
			prev->next = current->next; // changing pointers to be able to delete properly
		}
		free(current);
		return 0; // deleted succesfully
	}

}

int clear() {
        struct PHONE_NODE *current = head;
        struct PHONE_NODE *temp;

        while ( current != NULL) { // looping through each node in the linked list
              temp = current;
              current = current -> next;
              free (temp); // garbage collecting all the nodes in the linked list
        }

        head = NULL; // setting the head pointer to NULL 
}


     
