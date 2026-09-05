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
void FunctionDelete(struct LinkedList *head);


int main(void){
    
    //temp
    struct LinkedList *Bananas = malloc(sizeof(struct LinkedList));
    struct LinkedList *Apples = malloc(sizeof(struct LinkedList));;
    struct LinkedList *Grapes = malloc(sizeof(struct LinkedList));;

    Bananas->id = 1;
    strcpy(Bananas->name, "Bananas");
    Bananas->quantity = 50;
    Bananas->next = Apples;

    Apples->id = 2;
    strcpy(Apples->name, "Apples");
    Apples->quantity = 30;
    Apples->next = Grapes;

    Grapes->id = 3;
    strcpy(Grapes->name, "Grapes");
    Grapes->quantity = 20;
    Grapes->next = NULL;

    
    while (1){
        printf("-show\n");
        printf("-add\n");
        printf("-del\n");
        printf("-change\n");
        printf("-quit\n");

        char action[20] ="";

        scanf("%19s",action);

        if (strcmp(action, "show")==0){
            FunctionShow(Bananas);
        }
        if (strcmp(action,"del") == 0){
            FunctionDelete(Bananas);
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

void FunctionDelete(struct LinkedList *head){
    int id;
    
    printf("id to delete: \n");
    scanf("%d", &id);

    struct LinkedList *previous = head;
    struct LinkedList *current = head->next;
//problem with deleting first one
    while (current != NULL) {
        if(current->id == id) {
            previous->next = current->next;
            free(current);

            printf("product with %d id was deleted", id);
            return;
        }

        previous = current;
        current = current->next;
    }
    printf("product not found");

}