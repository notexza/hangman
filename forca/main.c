#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>


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
        ch = getch();
        password[i] = ch;
        if(ch==13) {
            break;
        }
        ch = '*' ;
        printf("%c",ch);
    }

    FILE *f = fopen("userData.txt", "ab+");
    fprintf(f, "%s %s", username, password);
    fclose(f);

}

entrarMenu(char username[10], char password[20]) {
    system("cls");
    titulo();

    char username2[10], password2[20], ch;
    int i=0;

    printf("\nIntroduza o seu nome: ");
    scanf("%s", username2);
    printf("\nIntroduza a sua palavra-passe: ");

    for(i=0;i<19;i++) {
        ch = getch();
        password2[i] = ch;
        if(ch==13) {
            break;
        }
        ch = '*' ;
        printf("%c",ch);
    }

    FILE *file;
    file = fopen("userData.txt", "r");
    if(file) {
        char line[128];
        while(fgets(line, sizeof line, file)) {
                if(sscanf(line, "%s %s", username2, password2) == 2) {
                    printf("\nUsername e palavra-passe corretos!\n");
                    system("cls");
                    startMenu();
                } else { // FIX THIS LINE, DOESNT WORK
                    printf("\nUsername e palavra-passe incorretos!\n");
                    break;
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
