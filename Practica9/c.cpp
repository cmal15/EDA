#include<stdio.h>

int main(){

    int n = 10;
    for (int i = 0; i < n; i++){
        for(int j = n; j < i; j++){
            printf("1\n",j);
        }
    }
}