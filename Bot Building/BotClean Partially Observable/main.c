//
//  main.c
//  BotClean Partially Observable
//
//  Created by 王选易 on 13-5-4.
//  Copyright (c) 2013年 王选易. All rights reserved.
//

#include<stdio.h>
/* Head ends here */
void next_move(int posx, int posy, char board[5][5]) 
{

	FILE *read;
	FILE *write;
	char *filename = "myfile.txt";
	char board_record[5][5];
	read = fopen(filename, "r");
	if (read != NULL){
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				fscanf(read, "%c", &board_record[i][j]);
		fclose(read);
	}else{
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				board_record[i][j] = 'o';
	}

	for (int j = posy - 1; j <= posy + 1; ++j)
		for (int i = posx - 1; i <= posx + 1; ++i)
			if ( (!(i == posx && j == posy)) && (j >= 0 && j < 5) && (i >= 0 && i < 5) ) 
				board_record[i][j] = board[i][j];

	if (board[posx][posy] == 'd'){
		board_record[posx][posy] = '-';
        write = fopen(filename, "w");
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                fprintf(write, "%c", board_record[i][j]);
        fclose(write);
		printf("CLEAN");
//        printf("\n");
//        for (int i = 0; i < 5; ++i){
//            for (int j = 0; j < 5; ++j)
//                printf("%c", board_record[i][j]);
//            printf("\n");
//        }
		return;
	}

	//find des point
    int k, m;
    
    for (k = 0; k < 5; k++){
        for (m = 0; m < 5; m++)
            if (board_record[k][m] == 'd')
                break;
        if(m != 5)
            break;
    }

    if (k == 5 && m == 5){
	    for (k = 0; k < 5; k++){
	        for (m = 0; m < 5; m++)
	            if (board_record[k][m] == 'o')
	                break;
	        if(m != 5)
	            break;
    	}
    }
    if ((k >= 0 && k < 5) && (m >= 0 && m < 5)){
    if (m < posy)
        printf("LEFT");
    else if (m > posy)
        printf("RIGHT");
    else if (k != posx)
        printf((k < posx) ? "UP" : "DOWN");
    }
    
//    printf("\n");
//    for (int i = 0; i < 5; ++i){
//        for (int j = 0; j < 5; ++j)
//            printf("%c", board_record[i][j]);
//        printf("\n");
//    }

    write = fopen(filename, "w");
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			fprintf(write, "%c", board_record[i][j]);
	fclose(write);
}
/* Tail starts here */
int main(void) {
    int pos[2], i;
    char board[5][5];
    scanf("%d", &pos[0]);
    scanf("%d", &pos[1]);
    for(i=0; i<5; i++) {
        scanf("%s[^\\n]%*c", board[i]);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}

