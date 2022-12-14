#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "func1.h"

int main() {
    int t;	
    char *input = (char *)calloc(81, sizeof(char));
    printf("> ");
    t = scanf("%80[^\n]", input);
    char *output;
   // while (t != -1) {
        printf("\"%s\"\n", input);
        output = func(input);
        printf("\"%s\"\n", output);
        free(input);
        free(output);
//	input = (char *)calloc(81, sizeof(char));
//	printf("> ");
     //   t = scanf("%80[^\n]", input);
  //  }
    return 0;
}
