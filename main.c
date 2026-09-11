
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
void FunctionDelete(struct LinkedList **head);
void FunctionAdd(struct LinkedList **head);
void FunctionChange(struct LinkedList *head);
void FunctionFree(struct LinkedList *head);

int main(void){

    // temp
    struct LinkedList *Bananas = malloc(sizeof(struct LinkedList));
    struct LinkedList *Apples = malloc(sizeof(struct LinkedList));
    struct LinkedList *Grapes = malloc(sizeof(struct LinkedList));

    if (Bananas == NULL || Apples == NULL || Grapes == NULL) {
        printf("memory allocation failed\n");
        free(Bananas);
        free(Apples);
        free(Grapes);
        return 1;
    }

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

    struct LinkedList *listHead = Bananas;

    while (1) {
        printf("\n-show\n");
        printf("-add\n");
        printf("-del\n");
        printf("-change\n");
        printf("-quit\n");

        char action[20] = "";

        scanf("%19s", action);

        if (strcmp(action, "show") == 0) {
            FunctionShow(listHead);
        }
        else if (strcmp(action, "del") == 0) {
            FunctionDelete(&listHead);
        }
        else if (strcmp(action, "add") == 0) {
            FunctionAdd(&listHead);
        }
        else if (strcmp(action, "change") == 0) {
            FunctionChange(listHead);
        }
        else if (strcmp(action, "quit") == 0) {
            FunctionFree(listHead);
            break;
        }
    }
}

void FunctionShow(struct LinkedList *head) {
    struct LinkedList *current = head;

    printf("id | name | quantity\n");

    while (current != NULL) {
        printf("%d ", current->id);
        printf("%s ", current->name);
        printf("%d\n", current->quantity);

        current = current->next;
    }
}

void FunctionDelete(struct LinkedList **head) {

    int id;

    if (*head == NULL) {
        printf("list is empty\n");
        return;
    }

    printf("id to delete: \n");
    scanf("%d", &id);

    struct LinkedList *previous = NULL;
    struct LinkedList *current = *head;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("product not found\n");
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    }
    else {
        previous->next = current->next;
    }

    free(current);

    printf("product with %d id was deleted\n", id);
}

void FunctionAdd(struct LinkedList **head) {

    char name[50];
    int quantity;

    printf("give the name: \n");
    scanf("%49s", name);

    printf("specify quantity: \n");
    scanf("%d", &quantity);

    // Empty list
    if (*head == NULL) {

        *head = malloc(sizeof(struct LinkedList));

        if (*head == NULL) {
            printf("memory allocation failed\n");
            return;
        }

        (*head)->id = 1;
        strcpy((*head)->name, name);
        (*head)->quantity = quantity;
        (*head)->next = NULL;

        printf("item added\n");
        return;
    }

    // Non-empty list
    struct LinkedList *last = *head;

    while (last->next != NULL) {
        last = last->next;
    }

    struct LinkedList *newNode = malloc(sizeof(struct LinkedList));

    if (newNode == NULL) {
        printf("memory allocation failed\n");
        return;
    }

    newNode->id = last->id + 1;
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    last->next = newNode;

    printf("item added\n");
}

void FunctionChange(struct LinkedList *head) {

    int id;
    char action[10];
    char newName[50];
    int newQuantity;

    printf("item with what id do you want to change [id]\n");
    scanf("%d", &id);

    printf("what do you want to change? [name][quantity]\n");
    scanf("%9s", action);

    struct LinkedList *wantedNode = head;

    while (wantedNode != NULL && wantedNode->id != id) {
        wantedNode = wantedNode->next;
    }

    if (wantedNode == NULL) {
        printf("product not found\n");
        return;
    }

    if (strcmp(action, "name") == 0) {
        printf("give new name: \n");
        scanf("%49s", newName);

        strcpy(wantedNode->name, newName);
    }
    else if (strcmp(action, "quantity") == 0) {
        printf("give new quantity: \n");
        scanf("%d", &newQuantity);

        wantedNode->quantity = newQuantity;
    }
    else {
        printf("wrong action was given\n");
        return;
    }
}

void FunctionFree(struct LinkedList *head){
    struct LinkedList *current = head;

    while(current != NULL){
        struct LinkedList *next = current->next;
        free(current);
        current = next;
    }



}