//
// Created by zhanghao on 22-8-9.
//

#include "MathFunctions.h"
double power(double base,int exponent){
    int result = base;
    int i;

    if(exponent == 0){
        return 1;
    }

    for(int i = 1;i < exponent;i++){
        result = result*base;
    }

    return result;
}