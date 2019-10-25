//
//  main.c
//  exp_calculator
//
//  Created by Ben Tilden on 2018-10-08.
//  Copyright © 2018 Ben Tilden. All rights reserved.
//

#include <stdio.h>

float exp_calculator(float base, int exponent);

int main(void) {
    float base;
    int exponent;
    float result;
    printf("Enter a positive base number: \n");
    scanf(" %f", &base);
    if(base < 0){
        printf("Please enter a positive base number: \n");
        scanf(" %f", &base);
    }
    printf("Enter the exponent number: \n");
    scanf(" %d", &exponent);
    
    if(exponent > 0){
        result = exp_calculator(base, exponent);
    }
    else{
        result = exp_calculator((1/base), exponent);
    }
    printf("The result is: %f\n", result);
    
    return 0;
}

float exp_calculator(float base, int exponent)
{
    if(exponent == 0) {
        return 1;
    } else if(exponent % 2 == 0) {
        return exp_calculator(base * base, exponent / 2);
    } else {
        return base * exp_calculator(base * base, (exponent - 1) / 2);
    }
}
