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
int num_rows=0;
int num_cols=0;
int impt=0;
void start();
void instructions();                             //affiche les instructions
void printboard();                             //affiche le tableau
void printnumber();                             //check la viabilité du chiffre entré et le retourne
void InstrImptTest();
void StartSwitch();
void empty_stdin ();
void BoardVarCol ();
void BoardVarRow ();
void CasualGame();
int main(){
    start();
    score_o=0;
    score_x=0;
}
void start(){
    system("COLOR 1C");
    printf("Bienvenue au puissance 4\n\n");
    printf("                                   1-partie personalisee\n"                  ////////////////////////////
           "                                   ----------------------  \n"              //                        //
           "                                   2-instructions\n"                       //    MAIN MENU           //
           "                                   ---------------------- \n"             ////////////////////////////
           "                                   3-partie casu\n"
           "                                   ----------------------"
           "\n");
    printf("choisis une des options: \n");
    printf("\n");
    StartSwitch();
}
void StartSwitch(){
    impt=scanf("%d",&choose);
    if (impt == EOF){
            fputs ("(user canceled input.)\n", stderr);
            empty_stdin();
            StartSwitch();
    }
    else if (impt == 0) {
        fputs (" error: invalid integer input.\n veuillez entrer un nombre valide\n", stderr);
            empty_stdin();
            StartSwitch();
    }
    else if (choose<1 || 3<choose){
            printf("erreur entrez un nombre valide \n");
            empty_stdin();
            StartSwitch();
        }
    else {
    switch(choose){                                                         //choix possibles pour l'utilisateur
        case 1: printnumber();break;
        case 2: instructions();break;
        case 3: CasualGame();break;
        default: printf("erreur 404 cerveau non trouve"),StartSwitch();
        }                   //retour en cas de =! 1 2 ou 3
    }
}
void CasualGame(){
     printf("entrez le nom du joueur 1: ");
    scanf("%s",&name1);
    printf("entrez le nom du joueur 2: ");
    scanf("%s",&name2);
    num_rows=7;
    num_cols=6;
    printboard();
}
void instructions(){
    system("cls");
    system("COLOR EC");                                                     //nouvel écran
    printf("          ****     comment jouer     ****          \n\n");                                                      //design des instructions
    printf("dans partie personalisee tu peux choisir la taille du tableau desire \n");
    printf("si tu choisis une partie casu alors vous jouerez dans un tableau de 6 par 7\n");
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
    else if (var<1 || 1<var){
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
    BoardVarCol();
}
void BoardVarCol(){
    printf("entrez le nombre de collones\n le nombre doit etre compris entre 4 et 50 \n");
    impt=scanf("%d",&num_cols);
    if (impt == EOF){
            fputs ("(user canceled input.)\n", stderr);
            empty_stdin();
            BoardVarCol();
    }
    else if (impt == 0) {
        fputs (" error: invalid integer input.\n veuillez entrer un nombre valide\n", stderr);
            empty_stdin();
            BoardVarCol();
    }
    else if (num_cols<4 || 50<num_cols){
            printf("erreur entrez un nombre valide \n");
            empty_stdin();
            BoardVarCol();
        }
    else {
        system("cls");
        BoardVarRow();
    }
}
BoardVarRow(){
    printf("entrez le nombre de lignes \n le nombre doit etre compris entre 4 et 50 \n");
    impt=scanf("%d",&num_rows);
    if (impt == EOF){
            fputs ("(user canceled input.)\n", stderr);
            empty_stdin();
            BoardVarRow();
    }
    else if (impt == 0) {
        fputs (" error: invalid integer input.\n veuillez entrer un nombre valide\n", stderr);
            empty_stdin();
            BoardVarRow();
    }
    else if (num_rows<4 || 50<num_rows){
            printf("erreur entrez un nombre valide \n");
            empty_stdin();
            BoardVarRow();
        }
    else {
        system("cls");
        printboard();
    }
}
void printboard(){
    int row,col,a,c;
    if(b==0){                               //INTIALIZATION TO BOARD WITH '.'
        for(a=0;a<num_rows;a++){
                for(c=0;c<num_cols;c++)
                board[a][c]='.';
        }
    }
    b++;
    system("cls");                          //TO CLEAR SCREEN AFTER EACH PLAY
    system("COLOR 4E");                     //TO COLOR THE BOARD
    for(row=0; row<num_rows; row++){        //PRINTING THE BOARD
        for(col=0; col<num_cols; col++){

            printf("| %c ",board[row][col]);
        }
        printf("|\n");
        for(a=0; a<num_cols; a++) printf("____");
        printf("\n");
    }
    for(a=0; a<num_cols; a++)printf("%*d",4,a+1);
    printf("\n");
}
