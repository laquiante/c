#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listitem {
    struct listitem *next;  // Zeiger auf das nächste Element
    int data;               // Der Wert
} LISTITEM;

int main(int argc, char *argv[]){

    /*
    
    Einfache Linked List
    
    */


    LISTITEM *listhead, *temp;
    listhead = NULL;

    // befüllen
    for (int i=0;i<5;i++) {
        temp = malloc(sizeof(LISTITEM));
        temp -> data = i;
        temp -> next = listhead;
        listhead = temp;
    }


    // ausgeben
    temp = listhead;
    while (temp != NULL) {
        printf("Element: aktuell haben wir temp mit %p; nächstes temp ist %p; Wert von temp ist %d\n", temp, temp -> next, temp -> data);
        temp = temp -> next;
    }

    temp = listhead;
    printf("temp -> data Grösse: %d\n", sizeof (temp -> data));
    printf("temp -> next Grösse: %d\n", sizeof (temp -> next));    

    return 0;
}
