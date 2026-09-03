#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    struct LinkedList {
        int id;
        char name[50];
        int quantity;
        struct LinkedList *next;
    };
    //temp
    struct LinkedList Bananas;
    struct LinkedList Apples;
    struct LinkedList Grapes;

    Bananas.id = 1;
    strcpy(Bananas.name, "Mouse");
    Bananas.quantity = 50;
    Bananas.next = &Apples;

    Apples.id = 2;
    strcpy(Apples.name, "Mouse");
    Apples.quantity = 30;
    Apples.next = &Grapes;

    Grapes.id = 3;
    strcpy(Grapes.name, "Mouse");
    Grapes.quantity = 20;
    Grapes.next = NULL;

    
    while (1){

    }
}
