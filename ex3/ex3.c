#include <stdio.h>
#include <stdlib.h>
#pragma GCC diagnostic ignored "-Wstringop-overflow="

char importantString[10] = "/bin/sh";
void ignore_me_init_buffering( void ) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main(int argc, char *argv[]) {
    ignore_me_init_buffering();
    char input[50];
    
    printf("Write something, for example %s?\n", importantString);
    fgets(input, 200, stdin);
    
}