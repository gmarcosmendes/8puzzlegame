// ALUNO: GABRIEL MARCOS MENDES
// TURMA DE ALGORITMOS E PROGRAMACAO 2
// 2o PERIODO DE CIENCIA DA COMPUTAÇAO

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

#define size 3

static int __BACKGROUND = 15;
static int __FOREGROUND = 0;

void textcolor (int letras, int fundo){/*para mudar a cor de fundo mude o background*/
    __FOREGROUND = letras;
    __BACKGROUND = fundo;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    letras + (__BACKGROUND << 4));
}

void gerar_matriz_aleatoria(int matriz[][size]){
    srand(time(NULL));
    for(int x=0;x<size;x++){
        for(int y=0;y<size;y++){
            matriz[x][y]=0;
        }
    }
    for(int i=1;i<9;i++){
        int rand_x, rand_y;
        do{
            rand_x = rand() % 3;
            rand_y = rand() % 3;
        } while(matriz[rand_x][rand_y]!=0);
        matriz[rand_x][rand_y] = i;
    }
}

void mostrar_matriz(int matriz[][size]){
    cout << "\t";
    for(int x=0;x<size;x++){
        for(int y=0;y<size;y++){
            if(matriz[x][y]!=0){
                cout << matriz[x][y] << "  ";
            } else{
               textcolor(4,15);
               cout << "#  ";
               textcolor(0,15);
            }
        }
        cout << endl << "\t";
    }
}

void mover_pra_baixo(int matriz[][size]){
    for(int x=0;x<=size-1;x++){
        for(int y=0;y<=size-1;y++){
            if(matriz[x][y]==0){
                if(x!=2){
                    matriz[x][y] = matriz[x+1][y];
                    matriz[x+1][y] = 0;
                    return;
                } else{
                    cout << "Jogada impossivel.";
                    system("pause");
                }
            }
        }
    }
}

void mover_pra_cima(int matriz[][size]){
    for(int x=0;x<=size-1;x++){
        for(int y=0;y<=size-1;y++){
            if(matriz[x][y]==0){
                if(x!=0){
                    matriz[x][y] = matriz[x-1][y];
                    matriz[x-1][y] = 0;
                    return;
                } else{
                cout << "Jogada impossivel.";
                system("pause");
                }
            }
        }
    }
}

void mover_pra_esquerda(int matriz[][size]){
    for(int x=0;x<=size-1;x++){
        for(int y=0;y<=size-1;y++){
            if(matriz[x][y]==0){
                if(y!=0){
                matriz[x][y] = matriz[x][y-1];
                matriz[x][y-1] = 0;
                return;
                } else{
                    cout << "Jogada impossivel.";
                    system("pause");
                }
            }
        }
    }
}

void mover_pra_direita(int matriz[][size]){
    for(int x=0;x<=size-1;x++){
        for(int y=0;y<=size-1;y++){
            if(matriz[x][y]==0){
                if(y!=2){
                    matriz[x][y] = matriz[x][y+1];
                    matriz[x][y+1] = 0;
                    return;
                } else{
                    cout << "Jogada impossivel.";
                    system("pause");
                }
            }
        }
    }
}

bool checar_matriz(int puzzle[size][size], int matriz[][size]){
    int contador=0;
    for(int x=0;x<=size-1;x++){
        for(int y=0;y<=size-1;y++){
            if(puzzle[x][y]==matriz[x][y]){
                contador++;
            }
        }
    }
    if(contador==9){
        return true;
    } else{
        return false;
    }
}

int main(){
    system("color F0");

    int jogadas=1;
    int conferir[size][size]{{1,2,3},{8,0,4},{7,6,5}};
    int puzzle[size][size];
    bool jogo=false, teste=false;
    char entrada;
    int ent_menu;
    gerar_matriz_aleatoria(puzzle);
    // loop do jogo
    ent_menu=0;
    while(ent_menu!=2){
        cout << "\n\t8Puzzle por Gabriel Mendes"
                "\n\n\tAbril de 2023"
                "\n\n\t1) Jogar"
                "\n\t2) Sair\n\n\t";
        cin >> ent_menu;
        system("cls");
        switch(ent_menu){
        case 1:
        do{
            cout << "\n\n\n\n\t8Puzzle\n\tResolva essa charada colocando em ordem crescente os numeros."
                    "\n\tO resultado final deve ser assim:\n\n\t1  2  3\n\t8  #  4\n\t7  6  5\n";
            cout << "\n\tUse como seta as teclas 'w', 'a', 's' e 'd' para movimentar a casa '#'.\n\tBasta digitar a tecla e pressionar Enter.\n\n";
            mostrar_matriz(puzzle);
            cout << endl << "\tEssa eh sua jogada de numero: " << jogadas << endl << "\n\t";
            cin >> entrada;
            switch(entrada){
            case 'w':
                mover_pra_cima(puzzle);
                jogadas++;
                break;
            case 's':
                mover_pra_baixo(puzzle);
                jogadas++;
                break;
            case 'a':
                mover_pra_esquerda(puzzle);
                jogadas++;
                break;
            case 'd':
                mover_pra_direita(puzzle);
                jogadas++;
                break;
            default:
                cout << "Essa nao eh uma opcao valida, tente novamente" << endl;
                system("pause");
            }
            system("cls");
            // checar posições corretas
            teste=checar_matriz(puzzle,conferir);
            if(teste==true){
                jogo=true;
                cout << "\n\n\tParabens, voce ganhou!\n\n\tVoce fez tudo em " << jogadas << " jogadas\n\n\tAte mais!\n\n\t";
                system("pause");
                system("cls");
            }
        } while(jogo==false);
            break;
        case 2:
            return 0;
            break;
        default:
            cout << "\n\tOpcao invalida\n" << endl;
            system("pause");
            system("cls");
        }
    }
}
