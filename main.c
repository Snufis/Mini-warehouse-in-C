#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedList {
        int id;
        char name[50];
        int quantity;
        struct LinkedList *next;
};

void FunctionShow(struct LinkedList *head);



int main(void){
    
    //temp
    struct LinkedList Bananas;
    struct LinkedList Apples;
    struct LinkedList Grapes;

    Bananas.id = 1;
    strcpy(Bananas.name, "Bananas");
    Bananas.quantity = 50;
    Bananas.next = &Apples;

    Apples.id = 2;
    strcpy(Apples.name, "Apples");
    Apples.quantity = 30;
    Apples.next = &Grapes;

    Grapes.id = 3;
    strcpy(Grapes.name, "Grapes");
    Grapes.quantity = 20;
    Grapes.next = NULL;

    
    while (1){
        printf("1.show\n");
        printf("2.add\n");
        printf("3.del\n");
        printf("4.change\n");
        printf("5.quit\n");

        char action[20] ="";

        scanf("%19s",action);

        if (strcmp(action, "show")==0){
            FunctionShow(&Bananas);
        }
    }
}



void FunctionShow(struct LinkedList *head){
    struct LinkedList *current = head;
    printf("id | name | quantity\n");
    while (current != NULL) {
        printf("%d ",current->id);
        printf("%s ",current->name);
        printf("%d\n",current->quantity);
        current = current->next;
    }
}