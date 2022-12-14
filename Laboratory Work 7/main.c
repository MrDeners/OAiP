#include "choice.h"
#include <stdio.h>

int main () {
    
    int (*elementsOfMenu)(void) = NULL;
    elementsOfMenu=choiceAssignment;
    
    elementsOfMenu();
    return 0;
}
