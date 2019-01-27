#include <stdio.h>
#include <stdlib.h>


void login() {
    char username[20], username1[20];
    char password[50], password1[50];
    int c;
    char line[150];
    unsigned int size = 0;

    FILE *f;
    f = fopen("userData.txt", "r");
    struct Jogador j[30];

    printf("Username: ");
    gets(username);
    fflush(stdin);


    for(i=0;i<c;i++){
        if(strcmp(listaTelefonica[i].nome,novoNome)==0){
            encontrou=1;
            break;
        }
    }


    printf("Password: ");
    scanf("%s", &password);


    while((c=getc(f)) != EOF) {
        putchar(c);
    }
    fclose(f);


}
