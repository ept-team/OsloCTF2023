#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void ignore_me_init_buffering(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void launch_missiles(int n)
{
    printf("Launching %d missiles\n", n);
    // TODO: implement this function
}
void authenticate_and_launch(void)
{
    char response[8];
    int n_missiles = 2;
    bool allowaccess = false;

    printf("Secret: ");
    gets(response);
    if (strcmp(response, "Joshua") == 0)
        allowaccess = true;
    if (allowaccess) {
        puts("Access granted");
    launch_missiles(n_missiles);
}

    if (!allowaccess)
        puts("Access denied");
}
int main(int argc, char *argv[])
{
    char name[10];
    ignore_me_init_buffering();
    puts("WarGames MissileLauncher v0.1");
    puts("Enter your name: ");
    fgets(name, 10, stdin);
    printf("Welcome ");
    printf(name);
    authenticate_and_launch();
    puts("Operation complete");
}