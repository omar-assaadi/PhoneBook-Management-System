#include<stdio.h>
#include <string.h>
#include "Mini5phone.h"




int menu() {
        int selection;
        char garbage[5];

        printf("Phonebook Menu: (1)Add, (2)Delete/Clear, (3)Find, (4)List, (5)Quit > ");
        scanf("%d", &selection);
        fgets(garbage,4,stdin);

        return selection;
}

int main() {
        int choice, record;
        char name[50], birth[50], phone[50];
       
        loadCSV("phonebook.csv");

        do {
                choice = menu();

                switch(choice) {
                        case 1:
                                printf("Name: ");  fgets(name,50,stdin);  name[strlen(name)-1]   = '\0';
                                printf("Birth: "); fgets(birth,13,stdin); birth[strlen(birth)-1] = '\0';
                                printf("Phone: "); fgets(phone,16,stdin); phone[strlen(phone)-1] = '\0';
																	
                                record = addRecord(name, birth, phone);
                                if (record != 0) printf("Unable to allocate memory\n");

                                break;

			case 2: 
				printf("(D) elete or (C) lear;"); 
				char decision[50]; 
				fgets(decision ,sizeof(decision) ,stdin);
				
	//			scanf("%s",decision);

					
//				getchar(); 
				

				if (decision[0]=='D') { 
					printf("Name: "); 
					fgets(name, 49, stdin); 
					name[strlen(name)-1] = '\0'; 

					record = delete(name);
					if (record != 0) printf("Sorry not found."); 
				}

				if (decision[0]=='C') { 
					printf("Are you sure (Y/N)> "); 
				 char decisionYN[50];
                                        fgets(decisionYN, sizeof(decisionYN), stdin);
	
					  if(strlen(decisionYN)!=2){

                                printf("wrong length\n");
                                break;
                                }


							
					if (decisionYN[0] == 'Y') { 
						clear(); 
					} 

					if (decisionYN[0] == 'N') { 
					} 
					if (decisionYN[0]!='Y' &&decisionYN[0]!='N'){
																			
                                        printf("Sorry Wrong Selection!\n");
                                }
				}
				if (decision[0]!='D'&&decision[0]!='C'){			

				   printf("Sorry Wrong Selection!\n");
					break;
				}
				break;
					
                        case 3:
                                printf("Find name: "); fgets(name,49,stdin); name[strlen(name)-1] = '\0';

								struct PHONE_NODE *result = findRecord(name);

								if (result != NULL) {
    								printf("---- NAME ---- ---- BIRTH DATE ---- ---- PHONE ----\n");
									printf("%-14s %-20s %-10s\n", result->name, result->birthdate, result->phone);
								} else {
    								printf("Record not found\n");
								}
                                break;

                        case 4:
                                record = listRecords();

                                if (record != 0) printf("Phonebook.csv does not exist\n");
                                break;

                        case 5:
                                break;

                        default:
                                printf("Sorry BOwrong selection!\n");
                }				
        } while(choice != 5);

        saveCSV("phonebook.csv");

        printf("End of phonebook program\n");

        return 0;
}

