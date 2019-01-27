#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

typedef struct {
    char username[21];
    char password[21];
}Jogador;

extern void registar();
extern void login();

void menuJogo(Jogador j[]);
void registarMenu(Jogador j[]);
void entrarMenu(Jogador j[]);
void loadFile(Jogador j[]);
void writeFile(Jogador j[]);
void menuCheck(Jogador j[]);
void loginSegundoUser(Jogador j[]);

//void pesquisarContacto(Contacto listaTelefonica[]);
//void alterarContacto(Contacto listaTelefonica[]);


#endif // PLAYER_H_INCLUDED
