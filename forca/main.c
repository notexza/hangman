#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
    }
}

entrarMenu() {
    system("cls");
    titulo();

    char username[10], password[20], ch;
    int i=0;

    printf("\nIntroduza o seu nome: ");
    scanf("%s", &username[10]);
    printf("\nIntroduza a sua palavra-passe: ");

    for(i=0;i<19;i++) {
        ch = getch();
        password[i] = ch;
        ch = '*' ;
        printf("%c",ch);
    }
}

main()
{
    setlocale(LC_ALL, "");
    startMenu();
}
