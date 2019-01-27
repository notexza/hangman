#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include "player.h"

#define TRUE 1
#define FALSE 0

void mostrarBoneco(int);

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



iniciarJogo() {
    system("cls");
    int i, contador, n, nchar, e1, e2, e3, e4, e5, certo, animacao, animacao2;
    char frase[100], resposta[100], tentativa, confirmar, continuar;

    do
    {
        system("cls");
        titulo();
        confirmar = 'n';
        while(confirmar != 'S')
        {
            certo = 0;
            nchar=0;
            n = 0;
            i=0;
            contador = 0;
            e1 = ' ';
            e2 = ' ';
            e3 = ' ';
            e4 = ' ';
            e5 = ' ';
            printf("Insira a palavra desejada: ");
            fflush(stdin);
            gets (frase);
            printf("A palavra é %s, confirmar? (digite 's' para confirmar e 'n' para digitar novamente) - ", frase);
            fflush(stdin);
            scanf("%c", &confirmar);
            switch(confirmar)
            {
            case 's':
                printf("O jogo irá iniciar...\n");
                system("PAUSE");
                system("cls");
                for(i = 0; i < 100; i++)
                {
                    resposta[i]='_';
                }
                while(contador < 6)
                {
                    n=0;
                    certo=0;
                    switch(contador)
                    {
                    case 0:
                        printf("___________   \n|         |   \n|        _|_\n|          \n|        \ \n|         \n| \n| \n| \n\n");
                        break;

                    case 1:
                        printf("___________   \n|         |   \n|        _|_\n|         O    \n|         \n|       \n| \n| \n| \n\n");
                        break;

                    case 2:
                        printf("___________   \n|         |   \n|        _|_\n|         O    \n|         |    \n|         \n| \n| \n| \n\n");
                        break;

                    case 3:
                        printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|    \n|         \n| \n| \n| \n\n");
                        break;

                    case 4:
                        printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|         \n| \n| \n| \n\n");
                        break;

                    case 5:
                        printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|        /  \n| \n| \n| \n\n");
                        break;
                    }
                    for(i=0; i < 100; i++)
                    {
                        if(frase[i]=='\0')
                        {
                            nchar = i;
                            break;
                        }
                        else
                        {
                            if(frase[i]==' ')
                            {
                                resposta[i]=' ';
                                printf("%c", resposta[i]);
                            }
                            else
                            {
                                if(frase[i]==tentativa)
                                {
                                    resposta[i]=frase[i];
                                }
                            }
                        }
                        printf("%c ", resposta[i]);
                    }
                    printf("\n\nLetras que já sairam: %c %c %c %c %c\n", e1, e2, e3, e4, e5);
                    switch(contador)
                    {
                    case 0:
                        puts("\n\nApenas pode errar 5 vezes");
                        break;
                    case 1:
                        puts("\n\nApenas pode errar 4 vezes");
                        break;
                    case 2:
                        puts("\n\nApenas pode errar 3 vezes");
                        break;
                    case 3:
                        puts("\n\nApenas pode errar 2 vezes");
                        break;
                    case 4:
                        puts("\n\nApenas pode errar mais uma vez");
                        break;
                    case 5:
                        puts("\n\nSe errar agora, perde!");
                    }
                    for(i = 0; i <= nchar; i++)
                    {
                        if(tentativa!=' ')
                        {
                            if(resposta[i]!='_')
                            {
                                certo++;
                                if(certo==nchar)
                                {
                                    contador=7;
                                    break;
                                }
                            }
                        }
                    }
                    if(certo!=nchar)
                    {
                        printf("\n\nDigite uma letra: ");
                        fflush(stdin);
                        scanf("%c", &tentativa);
                        tentativa = tolower(tentativa);
                    }
                    for(i = 0; i < nchar; i++)
                    {
                        if(tentativa!=frase[i])
                        {
                            n++;
                            if(n==nchar)
                            {
                                contador++;
                                if(contador==1)
                                {
                                    e1 = tentativa;
                                }
                                if(contador==2)
                                {
                                    e2 = tentativa;
                                }
                                if(contador==3)
                                {
                                    e3 = tentativa;
                                }
                                if(contador==4)
                                {
                                    e4 = tentativa;
                                }
                                if(contador==5)
                                {
                                    e5 = tentativa;
                                }
                            }
                        }
                    }
                    system("cls");
                }
            default:
                confirmar = 'n';
            }
            if(contador==6)
            {
                printf("___________   \n|         |   \n|        _|_\n|         O    \n|        /|\\    \n|        / \\ \n| \n| \n| \n\n");
                for(i = 0; i < nchar; i++)
                {
                    if(resposta[i]==frase[i])
                    {
                        printf("%c ", resposta[i]);
                    }
                    else
                    {
                        printf("(%c) ", frase[i]);
                    }
                }
                printf("\n\nLetras que já sairam: %c %c %c %c %c %c\n", e1, e2, e3, e4, e5, tentativa);
                printf("\n\n\nPerdeu!\n");
                system("PAUSE");
            }
            if(contador==7)
            {
                for(animacao=0; animacao<7; animacao++)
                {
                    for(animacao2=0; animacao2<5; animacao2++)
                    {
                        system("cls");
                        printf("Parabéns!! Ganhou!!\n");
                        printf("___________ \n|         | \n|        _|_\n|\n|\n|         O \n|        /|\\ \n|        / \\\n|\n\n");
                    }
                    for(animacao2=0; animacao2<5; animacao2++)
                    {
                        system("cls");
                        printf("Parabéns!! Ganhou!!\n");
                        printf("___________ \n|         | \n|        _|_\n|\n|\n|\n|        _O_\n|         | \n|        / \\\n\n");
                    }
                    for(animacao2=0; animacao2<5; animacao2++)
                    {
                        system("cls");
                        printf("Parabéns!! Ganhou!!!\n");
                        printf("___________ \n|         | \n|        _|_\n|\n|\n|        \\O/\n|         | \n|        / \\\n|\n\n");
                    }
                }
                system("cls");
                printf("Parabéns!! Ganhou!!\n");
                printf("___________ \n|         | \n|        _|_\n|\n|\n|\n|        \\O/\n|         | \n|        / \\\n\n");
                tentativa='_';
            }
            confirmar = 'S';
            printf("Deseja jogar novamente (S/N)? ");
            fflush(stdin);
            continuar = toupper(getchar());
        }
    }
    while(continuar=='S');
}


void mostrarBoneco(int escolha)
{

    switch(escolha)
    {

    case 0:
        system("cls");
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/",'\\');
        printf("\n\t||    | ");
        printf("\n\t||   / %c",'\\');
        printf("\n\t||      ");
        break;
    case 1:
        system("cls");
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/",'\\');
        printf("\n\t||    | ");
        printf("\n\t||     %c",'\\');
        printf("\n\t||      ");
        break;
    case 2:
        system("cls");
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/",'\\');
        printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 3:
        system("cls");
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/",'\\');
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 4:
        system("cls");
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO ",'\\');
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 5:
        system("cls");
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||    O ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    }//end of switch-case
    return;
}

registarMenu() {
    registar();
}

entrarMenu() {
    login();
}

loginSegundoUser() {
    system("cls");
    titulo();

    char username[10], password[20], ch;
    char user2[10], pass2[20], line[128];
    int i=0;

    printf("\nIntroduza username do segundo jogador: ");
    scanf("%s", user2);
    printf("\nIntroduza a sua palavra-passe: ");
    scanf("%s", pass2);

    FILE *file;
    file = fopen("userData.txt", "r");

    if(file) {
        while(fgets(line, sizeof line, file)) {
            if(fscanf(file, "%s %s", user2, pass2) == 2) {
                printf("\nUsername e palavra-passe corretos!\n");
                Sleep(2500);
                system("cls");
                iniciarJogo();
            } else {
                printf("\nUsername e palavra-passe incorretos!\n");
                system("PAUSE");
                loginSegundoUser();
            }
        }
        fclose(file);
    }
    system("PAUSE");
    return 0;
}

menuCheck() {
    int opc;
    system("cls");
    titulo();
    printf("Um ou dois jogadores? - ");
    scanf("%d", &opc);
    switch(opc) {
        case 1:
            break;
        case 2:
            loginSegundoUser();
            break;
    }
}

verificarAuth(char username[10], char password[20]) {
    // PARTE 2
}

menuJogo() {
    titulo();
}

main()
{
    setlocale(LC_ALL, "");
    startMenu();
}
