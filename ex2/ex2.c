
#include <stdio.h>
#include <stdlib.h>
#pragma GCC diagnostic ignored "-Wstringop-overflow="
void ignore_me_init_buffering( void ) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}


void win( void ) {
    system("/bin/sh");
}

void vuln() {
char input[50];
    
    puts("Write something");
    fgets(input, 200, stdin);
    puts("hello from main after fgets");
    return;
}

int main(int argc, char *argv[]) {
    ignore_me_init_buffering();
    vuln();
    return 0;
}