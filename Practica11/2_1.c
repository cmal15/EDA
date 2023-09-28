#include<stdio.h>

void cat(int num){
    if(num%2==0)
        num--;
    if(num > 0){
        printf("%d \n",num);
        cat(num-2);
    }
}

void main(){
    int i = 7;
    cat(i);
}