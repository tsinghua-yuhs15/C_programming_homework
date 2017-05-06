//
//  welcome_logo.cpp
//  Human Resouce Management
//
//  Created by 于海粟 on 2017/4/17.
//  Copyright © 2017年 于海粟. All rights reserved.
//

#include "welcome_logo.hpp"
#include "math.h"
void welcome_logo_paint(){
    double x, y;
    int H = 3;
    for (y = -4; y <= 0; y += 0.3)
    {
        for (x = -4; x <= 4; x += 0.2)
            if (fabs(sqrt(x * x + y * y) - H * sin(2 * atan(y / x))) <= 1
                || fabs(sqrt(x * x + y * y) - H * sin(2 * atan(-y / x))) <= 1)
                printf("*");
            else
                printf(" ");
        printf("\n");
    }
    for (y = -1; y <= 0; y += 0.2)
    {
        for (x = -4; x <= 4; x += 0.2)
            if (fabs(y) - 0.65 * x * x >= 0.2)
                printf("*");
            else
                printf(" ");
        printf("\n");
    }
}
void welcome_string_print(){
    std::cout<<"Welcome to the Human Resource Management Project Beta!"<<std::endl;
}
void instructions_print(){
    std::cout<<"Please enter your instructions:"<<endl;
}
