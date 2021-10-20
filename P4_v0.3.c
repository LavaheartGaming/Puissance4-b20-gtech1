#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
char name1[0];
char name2[0];
char board[100][100];
int score_x=0;
int score_o=0;
int choose=0;
int b=0;
int num_rows=12;
int num_coll=12;
int impt=0;
void start();
void instructions();                             //affiche les instructions
void printboard();                             //affiche le tableau
void printnumber();                             //check la viabilité du chiffre entré et le retourne
void InstrImptTest();
void StartSwitch();
void empty_stdin ();
int main(){
    start();
    score_o=0;
    score_x=0;
}
void start(){
    system("COLOR 1C");
    printf("Bienvenue au puissance 4\n\n");
    printf("                                   1-new game\n"                ////////////////////////////
           "                                   ----------  \n"              //                          //
           "                                   2-instructions\n"            //    MAIN MENU            //
           "                                   -------------      "         ////////////////////////////
           "\n");
    printf("choisis une des options: \n");
    printf("\n");
    StartSwitch();
}
void StartSwitch(){
    scanf("%d",&choose);
    switch(choose){                                                         //choix possibles pour l'utilisateur
        case 1: printnumber();break;
        case 2: instructions();break;
        default: printf("erreur 404 cerveau non trouve"),StartSwitch();                   //retour en cas de =! 1 ou 2
    }
}
void instructions(){
    system("cls");
    system("COLOR EC");                                                     //nouvel écran
    printf("          ****     comment jouer     ****          \n\n");                                                      //design des instructions
    printf("le but est d'alligner 4 pions de la meme equipe diagonalement, horizontalement ou verticalement \n");           //instructions
    printf("le joueur qui alligne 4 pions le plus de fois a gagne \n");
    printf("Bonne chance et amusez vous bien !\n\n");
    printf("appuie sur 1 pour revenir au menu \n");
    InstrImptTest();
}
void InstrImptTest(){
    char var=6;
    impt=scanf("%d",&var);
    if (impt == EOF){
            fputs ("(user canceled input.)\n", stderr);
            empty_stdin();
            InstrImptTest();
    }
    else if (impt == 0) {
        fputs (" error: invalid integer input.\n veuillez appuier sur 1 pour revenir au menu.\n", stderr);
            empty_stdin();
            InstrImptTest();
    }
    else if (var=!1){
            printf("erreur appuyez sur 1: \n");
            empty_stdin();
            InstrImptTest();
        }
    else {
    system("cls");
    start();
    }
}
void empty_stdin()
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}
void printnumber(){                                                         //initialisation au jeu
    printf("entrez le nom du joueur 1: ");
    scanf("%s",&name1);
    printf("entrez le nom du joueur 2: ");
    scanf("%s",&name2);
    system("cls");
    printboard();
}
void printboard(){
    int row,col,a,c;
    if(b=0){
            for(a=0;a<num_rows;a++){
                                   for(c=0;c<num_coll;c++){
                                        board[a][c]='.';
                                   }
                                   printf("\n");

            }
}
    b++;
    for(row=0; a<num_rows; row++){
            for(col=0; col<num_coll; col++){

                    printf("| %c ",board[row][col]);
            }
        printf("|\n");
        for(a=0; a<num_coll; a++)printf("____");
        printf("\n");
    }
    for(a=0; a<num_coll; a++)printf("%*d\n",4,a+1);
    printf("\n");
}
