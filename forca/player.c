#include <stdio.h>
#include <stdlib.h>
#include "player.h"

struct Jogador {
    char username[20];
    char password[50];
};

void registar() {
    FILE *f;

    f = fopen("userData.txt", "a");
    if(!f) {
        printf("Erro ao abrir ficheiro.");
        getchar();
        return -1;
    }

    struct Jogador j;
    printf("Username: ");
    scanf("%s", &j.username);
    printf("Password: ");
    scanf("%s", &j.password);

    fprintf(f, "%s %s\n", j.username, j.password);

    fclose(f);
}

void login() {
    char username[20], username1[20];
    char password[50], password1[50];
    int c;

    FILE *f;
    f = fopen("userData.txt", "r");
    struct Jogador j, j1;

    while((c=getc(f)) != EOF) {
        putchar(c);
    }
    fclose(f);


}
