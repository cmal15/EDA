#include<stdio.h>

void activities(int s[], int f[], int n){
    int i, j;
    printf("Selected Activities are:\n");
    i = 0;
    printf("-A%d ", i+1);
    for(j = 1; j < n; j++){
        if(s[j] >= f[i]){
            printf("+A%d ", j+1);
            i = j;
        }
    }
}

void main(){
    int s[] = {1, 2, 3, 2, 4, 5, 6, 8, 7}; //horarios inicio de actividades
    int f[] = {4, 5, 6, 8, 6, 7, 7, 12, 9}; //horario fin de actividades
    int n = sizeof(s)/sizeof(s[0]);
    activities(s, f, n);
    getchar();
}