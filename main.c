#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include "safe-math.h"

int main(void){
    long A, B;
    char input1[128], input2[128];
    char charProduct; 
    int intProduct = 0; 
    long longProduct; 

    //Read A and B
    if(fgets(input1, 128, stdin) == NULL) {
        A = 0; 
    }
    if(fgets(input2, 128, stdin) == NULL) {
        B = 0; 
    }
    A = strtol(input1, NULL, 10);
    if(errno) {
        input1[strcspn(input1, "\n")] = 0; // Trim new line character from string
        input2[strcspn(input2, "\n")] = 0; // Trim new line character from string
        printf("%s and %s cannot be multiplied as longs.", input1, input2);
        return 0;
    }
    B = strtol(input2, NULL, 10);
    if(errno) {
        input2[strcspn(input2, "\n")] = 0; // Trim new line character from string
        printf("%ld and %s cannot be multiplied as longs.", A, input2);
        return 0;
    }
    
    if(CHAR_MIN <= A && A<= CHAR_MAX && CHAR_MIN <= B && B <= CHAR_MAX){
        if (psnip_safe_char_mul(&charProduct, A, B)) {

            printf("%ld and %ld cannot be multiplied as chars, producing product %hhd", A, B, charProduct);
            return 0;

        }
    }
    
    if((INT_MIN <= A) && (A<= INT_MAX) && (INT_MIN <= B) && (B <= INT_MAX)){
        if (psnip_safe_int_mul(&intProduct, A, B)) {

            printf("%ld and %ld cannot be multiplied as ints, producing product %d", A, B, intProduct);
            return 0;

        }
    }

    if((LONG_MIN <= A) && (A<= LONG_MAX) && (LONG_MIN <= B) && (B <= LONG_MAX)){
        if (psnip_safe_long_mul(&longProduct, A, B)) {

            printf("%ld and %ld cannot be multiplied as longs, producing product %ld", A, B, longProduct);
            return 0;

        }
        printf("%ld and %ld cannot be multiplied as longs", A,B);


     return 0;
}
}

   

