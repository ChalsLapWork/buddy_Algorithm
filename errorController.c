#include "errorController.h"
#include <stdlib.h>
#include <stdio.h>

void errorCritico(const char *c){

 printf("\n\n-----");
 printf("%s",c);
 printf("----\n\n");
 exit(1);
}//fin *********************************+