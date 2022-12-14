#include "choice.h"
#include "firstAssignment.h"
#include "secondAssignment.h"
#include <stdio.h>
#include <stdlib.h>



int choiceAssignment(void) {
    
    void (*firstTask)(void) = NULL;
    firstTask=firstAssignment;
    void (*secondTask)(void) = NULL;
    secondTask=secondAssignment;
    
    int assignment=0;
    printNumOfAssignment ();
    printInputAssignment ();
    assignment=scanNumberAssignment (assignment);
    switch (assignment) {
        case 1:
            firstTask();
            break;
        case 2:
            secondTask();
            break;
        case 3: return 0;
    }
    return 0;
}



void printInputAssignment (void) {
    printf("Please, Input number of Assignment: ");
}

int scanNumberAssignment (int assignment) {
    while(!scanf("%d", &assignment) || assignment <1 || assignment>3) {
        printf("Wrong input. Input number of Assignment: ");
        rewind(stdin);
    }
    return assignment;
}

void printNumOfAssignment (void) {
    printf ("Assignment: \n");
    printf ("1 - First assignment. \n");
    printf ("2 - Second assignment. \n");
    printf ("3 - Exit. \n");
}

