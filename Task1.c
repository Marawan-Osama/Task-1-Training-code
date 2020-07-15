#include <stdio.h>

int WinCond();
void boardShape();

char block[10] = {'0','1','2','3','4','5','6','7','8','9'};

int main(){
    int player =1 , position , i;
    char XorO;
    do{
        boardShape();
        player = (player%2)? 1:2;
        printf("Player %d, choose a position: " , player);
        scanf("%d" , &position);
        XorO = (player == 1)? 'X' : 'O';

        if(position == 1 && block[1]== '1')
            block[1] = XorO;    
        else if (position == 2 && block[2] == '2')
            block[2] = XorO;   
        else if (position == 3 && block[3] == '3')
            block[3] = XorO; 
        else if (position == 4 && block[4] == '4')
            block[4] = XorO;  
        else if (position == 5 && block[5] == '5')
            block[5] = XorO;  
        else if (position == 6 && block[6] == '6')
            block[6] = XorO;  
        else if (position == 7 && block[7] == '7')
            block[7] = XorO;   
        else if (position == 8 && block[8] == '8')
            block[8] = XorO; 
        else if (position == 9 && block[9] == '9')
            block[9] = XorO;  
        else
        {
            printf("Move Invalid");
            player--;
            getch();
        }
        i = WinCond();
        player++;
    }while(i == -1);
    
    boardShape();
    
    if(i == 1)
        printf("Player %d wins", --player);
    else
        printf("Draw");

    getch();

    return 0;
}

int WinCond(){
    if (block[1] == block[2] && block[2] == block[3])
        return 1;
        
    else if (block[4] == block[5] && block[5] == block[6])
        return 1;
        
    else if (block[7] == block[8] && block[8] == block[9])
        return 1;
        
    else if (block[1] == block[4] && block[4] == block[7])
        return 1;
        
    else if (block[2] == block[5] && block[5] == block[8])
        return 1;
        
    else if (block[3] == block[6] && block[6] == block[9])
        return 1;
        
    else if (block[1] == block[5] && block[5] == block[9])
        return 1;
        
    else if (block[3] == block[5] && block[5] == block[7])
        return 1;
        
    else if (block[1] != '1' && block[2] != '2' && block[3] != '3' &&
        block[4] != '4' && block[5] != '5' && block[6] != '6' && block[7] 
        != '7' && block[8] != '8' && block[9] != '9')

        return 0;
    else
        return  - 1;
}

void boardShape(){

    system("cls");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", block[1],block[2],block[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", block[4],block[5],block[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", block[7],block[8],block[9]);
    printf("     |     |     \n\n");
}