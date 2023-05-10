#include<stdio.h>
#include<stdlib.h>
int main() {
    int* i = (int*) calloc(3, sizeof(int));
    i[0] = 6;
    i[1] = 9;
    printf("%d %d\n", i[0], i[1]);

}