#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 6
#define COLS 7

/* Functions for piece dropping and cpu options and whatnot */
void printBoard(char b[ROWS][COLS]);
bool dropDaPiece(char b[ROWS][COLS], int col, char piece);
bool checkthewinman(char b[ROWS][COLS], char piece);
int EVILAlloCPUMove(char b[ROWS][COLS]);
bool boardFull(char b[ROWS][COLS]);

int main() {
    char board[ROWS][COLS];
    int mode, col;
    bool playerTurn;
    char again;

    srand(time(NULL));

    do {
        
        for (int r=0;r<ROWS;r++) for (int c=0;c<COLS;c++) board[r][c]=' ';
        playerTurn = true;

        printf("EvilConnect 4\n1) PvP  2) PvAlloCPU  3) EVILNAKLY ALLOCPU Mode\nChoose mode: ");
        scanf("%d",&mode);

        if(mode==2) printf("\nThis is Hussamallamalakly the alloCPU\n\n");
        if(mode==3) printf("\nI'm Evilnakly...Better than Hussamallamalakly!\n\n");

        while(1){
            printBoard(board);

            if(!playerTurn && (mode==2||mode==3)){ 
                if(mode==3) printf("F's for everyone\n");
                else printf("You will be graded on this....\n");

                col = (mode==3)? EVILAlloCPUMove(board) : rand()%COLS;
                dropDaPiece(board,col,'O');
                printf("AlloCPU has pointed (*) to a column %d\n\n",col+1);
            } else { 
                printf("Playerman %d (%c), enter a column bruh (1-7): ",
                       playerTurn?1:2,playerTurn?'X':'O');
                scanf("%d",&col); col--;
                if(col<0||col>=COLS||!dropDaPiece(board,col,playerTurn?'X':'O')){
                    printf("Invalid move. Be smarter.\n"); continue;
                }
            }

            char piece = playerTurn?'X':'O';
            if(checkthewinman(board,piece)){
                printBoard(board);
                if(!playerTurn&&(mode==2||mode==3)){
                    printf("AlloCPU wins!\n");
                    if(mode==3) printf("Go back to python class\n");
                    else printf("Am I the best at CS and Connect4?\n");
                } else {
                    printf("Player %d wins!\n",playerTurn?1:2);
                    if(mode==3) printf("you will be doomed for eternal for loops\n");
                    else if(mode==2) printf("Im changing your quizzes to 90s cuz I'm still a chill professor\n");
                }
                break;
            }

            if(boardFull(board)){printBoard(board); printf("It is a draw yo lowkey get better still\n");
                if(!playerTurn&&(mode==2||mode==3)){
                    printf("Damn okay you may pass my class\n");
                    if(mode==3) printf("I will dereference all your hexidecimal memory adresses.\n");}
                     break;}
            playerTurn = !playerTurn;
        }

        if(mode==3){printf("\nPlay something again yo?Try Evilnakly Lowkey..(y/n): "); scanf(" %c",&again);}
        else again='n';

    } while(again=='y'||again=='Y');

    return 0;
}

//Needed crazy help on ts part and downward from upperclassmen and online

void printBoard(char b[ROWS][COLS]){
    printf("\n");
    for(int r=0;r<ROWS;r++){
        for(int c=0;c<COLS;c++) printf("| %c ",b[r][c]);
        printf("|\n");
    }
    printf("-----------------------------\n  1   2   3   4   5   6   7\n\n");
}

bool dropDaPiece(char b[ROWS][COLS], int col, char piece){
    for(int r=ROWS-1;r>=0;r--) if(b[r][col]==' '){b[r][col]=piece; return true;}
    return false;
}

bool direction(int r,int c,int dr,int dc,char piece,char b[ROWS][COLS]){
    for(int i=0;i<4;i++){
        int nr=r+dr*i,nc=c+dc*i;
        if(nr<0||nr>=ROWS||nc<0||nc>=COLS||b[nr][nc]!=piece) return false;
    }
    return true;
}

bool checkthewinman(char b[ROWS][COLS], char piece){
    for(int r=0;r<ROWS;r++) for(int c=0;c<COLS;c++)
        if(b[r][c]==piece&&(direction(r,c,0,1,piece,b)||direction(r,c,1,0,piece,b)
                           ||direction(r,c,1,1,piece,b)||direction(r,c,1,-1,piece,b)))
            return true;
    return false;
}

bool boardFull(char b[ROWS][COLS]){
    for(int c=0;c<COLS;c++) if(b[0][c]==' ') return false;
    return true;
}
/*Code for EVILalloccpu aka evilnakly, lowkey needed help on this so i looked up how to make cpu EVIl moves */
int EVILAlloCPUMove(char b[ROWS][COLS]){
    char temp[ROWS][COLS];
    int c;
    // checks if ALLOCPU can win here
    for(c=0;c<COLS;c++){
        for(int r=0;r<ROWS;r++) for(int k=0;k<COLS;k++) temp[r][k]=b[r][k];
        if(dropDaPiece(temp,c,'O')&&checkthewinman(temp,'O')) return c;
    }
    // can playerman win blockdapiece
    for(c=0;c<COLS;c++){
        for(int r=0;r<ROWS;r++) for(int k=0;k<COLS;k++) temp[r][k]=b[r][k];
        if(dropDaPiece(temp,c,'X')&&checkthewinman(temp,'X')) return c;
    }
    // random move if not
    do{c=rand()%COLS;}while(b[0][c]!=' ');
    return c;
}
