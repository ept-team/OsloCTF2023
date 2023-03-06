
#include <stdio.h>
#include <stdlib.h>
int number;
int thing = 4;

void empty( void ) {
    return;
}
int add(int a, int b, int c, int d, int e, int f, int g) {
    int x = 13;
    char test[5] = "test";
    int sum = a+b+c+d+e+f+g;
    return sum;
}

void foo( void ) {
        puts("hello from foo");
        int a = 1;
        int b = 2;
        int c = 3;
        int d = 4;
        int e = 5;
        int f = 6;
        int g = 7;
        int res = add(a,b,c,d,e,f,g);
        printf("the result of %d + %d + %d + %d + %d + %d + %d = %d\n", a,b,c,d,e,f,g,res);
    }



int main(int argc, char *argv[]) {
    puts("hello from main");
    foo();
    char *str1 = malloc(100);
    empty();
    printf("the thing is %d\n", thing);
}