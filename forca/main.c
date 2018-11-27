#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0

titulo() {
    // TITULO BLYAT
    printf("   ___                         _        ______\n");
    printf("  |_  |                       | |       |  ___|\n");
    printf("    | | ___   __ _  ___     __| | __ _  | |_ ___  _ __ ___ __ _ \n");
    printf("    | |/ _ \\ / _` |/ _ \\   / _` |/ _` | |  _/ _ \\| '__/ __/ _` |\n");
    printf("/\\__/ / (_) | (_| | (_) | | (_| | (_| | | || (_) | | | (_| (_| |\n");
    printf("\\____/ \\___/ \\__, |\\___/   \\__,_|\\__,_| \\_| \\___/|_|  \\___\\__,_|\n");
    printf("             __ / |                                             \n");
    printf("             |___/                                              \n");
}

startMenu() {
    titulo();

    int opc;

    printf("1 - Entrar\n");
    printf("2 - Registar\n");
    printf("3 - Sair\n");
    printf("\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opc);

    switch(opc) {
        case 1:
            entrarMenu();
            break;
        case 2:
            registarMenu();
            break;
    }
}


registarMenu() {
    system("cls");
    titulo();

    char username[10], password[20], password2[20], ch, ch1;
    int i=0;

    printf("\nIntroduza o seu nome: ");
    scanf("%s", username);

    printf("\nIntroduza a sua palavra-passe: ");
    for(i=0;i<19;i++) {
        password[i] = _getch();

        if(password[i]==13) {
            break;
        } // BUG 02: Se usas o backspace, ele lê como caractere, tem de apagar o ultimo inserido

        printf("*");
    }
    password[i]='\0';

    FILE *f = fopen("userData.txt", "ab+");
    fprintf(f, "%s %s", username, password);
    fclose(f);

}


entrarMenu() {
    system("cls");
    titulo();

    char username[10], password[20], ch;
    int i=0;

    printf("\nIntroduza o seu nome: ");
    scanf("%s", username);
    printf("\nIntroduza a sua palavra-passe: ");

     for(i=0;i<19;i++) {
        password[i] = getch();
        if(password[i]==13) {
            break;
        }
        printf("*");
    }
    password[i]='\0';
    verificarAuth(username, password);
    _getch();
    system("PAUSE");
    return 0;
}

verificarAuth(char username[10], char password[20]) {
    FILE *file;
    file = fopen("userData.txt", "r");
    char user2[10], pass2[20], line[128];

    if(file) {
        while(fscanf(file, "%s %s", user2, pass2) == 2) {
            if((strcmp(username, user2) == 0) && (strcmp(password, pass2) == 0)) {
                printf("\nUsername e palavra-passe corretos!\n");
                Sleep(2500);
                system("cls");
                startMenu();
            } else {
                printf("\nUsername e palavra-passe incorretos!\n");
                system("PAUSE");
                entrarMenu(username, password);
            }
        }
        fclose(file);
    }
}

main()
{
    setlocale(LC_ALL, "");
    startMenu();
}
