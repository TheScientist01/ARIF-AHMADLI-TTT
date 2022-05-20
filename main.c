#include <stdio.h>
#include <stdlib.h>


char* init_board(){
    char *board=(char *)malloc(9*sizeof(char));
    for (int i = 0; i < 9; i++)
    {
        board[i]=' ';
    }
    return board;
}

void draw_board(char *board){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j< 3; j++)
        {
            printf("%c", board[i*3+j]);
            if(j!=2){
                printf("|");
            }
        }
        printf("\n");
        
    }
    
}

int ask_coord(){
   
    char col;
    int row;
    int loc=0;
    while (1)
    {
        printf("Enter the column\n");
        scanf(" %c",&col);
        if(col=='A'||col=='B' || col=='C'){
            loc+=(int)col-65;
            break;
        }
        else{
            printf("Wrong column input!");
        }
    }
    while (1)
    {
        printf("Enter the row\n");
        scanf("%d",&row);
        if(row==1||row==2 || row==3){
            loc=loc*3+row;
            return loc;
        }
        else{
            printf("Wrong column input!");
        }
    }
    

        
}

char check(char*board, int k){
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
            
    //     }
        
    // }
     int i, contor = 0;
     char whoWon=' ';
 
     if(board[ 0 ] == 'X' && board[ 1 ] == 'X' && board[ 2 ] == 'X') {

        whoWon = 'X';

     } else if(board[ 3 ] == 'X' && board[ 4 ] == 'X' && board[ 5 ] == 'X') {

        whoWon = 'X';

     } else if(board[ 6 ] == 'X' && board[ 7 ] == 'X' && board[ 8 ] == 'X') {

        whoWon = 'X';

     } else if(board[ 0 ] == 'X' && board[ 3 ] == 'X' && board[ 6 ] == 'X') {

        whoWon = 'X';

     } else if(board[ 1 ] == 'X' && board[ 4 ] == 'X' && board[ 7 ] == 'X') {

        whoWon = 'X';

     } else if(board[ 2 ] == 'X' && board[ 5 ] == 'X' && board[ 8 ] == 'X') {

        whoWon = 'X';

     } else 

     if(board[ 0 ] == 'O' && board[ 1 ] == 'O' && board[ 2 ] == 'O') {

        whoWon = 'O';

     } else if(board[ 3 ] == 'O' && board[ 4 ] == 'O' && board[ 5 ] == 'O') {

        whoWon = 'O';

     } else if(board[ 6 ] == 'O' && board[ 7 ] == 'O' && board[ 8 ] == 'O') {

        whoWon = 'O';

     } else if(board[ 0 ] == 'O' && board[ 3 ] == 'O' && board[ 6 ] == 'O') {

        whoWon = 'O';

     } else if(board[ 1 ] == 'O' && board[ 4 ] == 'O' && board[ 7 ] == 'O') {

        whoWon = 'O';

     } else if(board[ 2 ] == 'O' && board[ 5 ] == 'O' && board[ 8 ] == 'O') {

        whoWon = 'O';

    }     

     //for diagonals
     if(board[ 0 ] == 'X' && board[ 4 ] == 'X' && board[ 8 ] == 'X') {

        whoWon = 'X';

     } else if(board[ 2 ] == 'X' && board[ 4 ] == 'X' && board[ 6 ] == 'X') {

        whoWon = 'X';
     }


     if(board[ 0 ] == 'O' && board[ 4 ] == 'O' && board[ 8 ] == 'O') {

        whoWon = 'O';

     } else if(board[ 2 ] == 'O' && board[ 4 ] == 'O' && board[ 6 ] == 'O') {

        whoWon = 'O';
     }

     for(i = 0; i < 9; i++) 
         if(board[i] != ' ') 
               contor++;
 
     if(contor == 9) {
        return ' ';
     } 

     if(whoWon==' '){
         return ' ';
     }
     else{
         return whoWon;
     }
}

int play_turn(char* board, char player){
    int c=ask_coord();
    if(board[c]!=' '){
        return -1;
    }
    board[c]=player;
    if(check(board,c)==player){
        return 1;
    }
    return 0;
}

void game(){
    char *board=init_board();
    char turn[]={'X','O'};
    int counter=1;
    char whoWon=' ';
    while (whoWon==' ')
    {
        int check=play_turn(board, turn[counter%2]);
        if(check==1){
            printf("The winner is %s",turn[counter%2]);
            draw_board(board);
            break;
        }
        else if(check==-1){
            printf("cell is full\n");
        }
        else{
            counter++;
        }
        draw_board(board);
    }
    
}

int main(){
    game();
    
    

    return 0;
}
