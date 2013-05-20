//
//  main.c
//  Tic tac toe
//
//  Created by 王选易 on 13-5-5.
//  Copyright (c) 2013年 王选易. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>

/* Complete the function below to print 2 integers separated by a single space which will be your next move
 */

typedef struct point{
    int x;
    int y;
}POINT;

// return point in a line where there has been two players
POINT *check_horizontal_line(char player, char ar[3][3], int x, int y, int win_num, POINT *p);
POINT *check_vertical_line(char player, char ar[3][3], int x, int y, int win_num, POINT *p);
POINT *check_low_right_line(char player, char ar[3][3], int x, int y, int win_num, POINT *p);
POINT *check_low_left_line(char player, char ar[3][3], int x, int y, int win_num, POINT *p);
// check if there is a line where there has been two players in all directions
int check_lines(char player, char ar[3][3], int x, int y, int win_num, POINT *p);
int attack_on_lines(char player, char ar[3][3], int x, int y, int win_num, POINT *p);
int guard_on_lines(char player, char ar[3][3], int x, int y, int win_num, POINT *p);

void nextMove(char player, char ar[3][3])
{
    char rival = (player == 'X') ? 'O' : 'X';
    POINT next_point = {0};
    // win the game
    if(check_lines(player, ar, 3, 3, 3, &next_point))
        return;
    // stop the rival
    if(check_lines(rival, ar, 3, 3, 3, &next_point))
        return;
    // attack
    if (player == 'X'){
        if(attack_on_lines(player, ar, 3, 3, 3, &next_point))
            return;
    }
    else if(guard_on_lines(player, ar, 3, 3, 3, &next_point))
            return;
}

POINT *check_horizontal_line(char player, char ar[3][3], int x, int y, int win_num, POINT *p)
{
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j){
            if (j + win_num > y)
                continue;
            else{
                int player_num = 0;
                for (int k = 0; k < win_num; ++k)
                    if (ar[i][j + k] == player)
                        player_num++;
                if (player_num == win_num - 1)
                    for (int k = 0; k < win_num; ++k)
                        if(ar[i][j + k] == '_'){
                            p->x = i;
                            p->y = j + k;
                            return p;
                        }
            }
        }
    return NULL;
}

POINT *check_vertical_line(char player, char ar[3][3], int x, int y, int win_num, POINT *p)
{
    
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j){
            if (i + win_num > x)
                continue;
            else{
                int player_num = 0;
                for (int k = 0; k < win_num; ++k)
                    if (ar[i + k][j] == player)
                        player_num++;
                if (player_num == win_num - 1)
                    for (int k = 0; k < win_num; ++k)
                        if(ar[i + k][j] == '_'){
                            p->x = i + k;
                            p->y = j;
                            return p;
                        }
            }
        }
    return NULL;
}

POINT *check_low_right_line(char player, char ar[3][3], int x, int y, int win_num, POINT *p)
{
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j){
            if (j + win_num > y || i + win_num > x)
                continue;
            else{
                int player_num = 0;
                for (int k = 0; k < win_num; ++k)
                    if (ar[i + k][j + k] == player)
                        player_num++;
                if (player_num == win_num - 1)
                    for (int k = 0; k < win_num; ++k)
                        if(ar[i + k][j + k] == '_'){
                            p->x = i + k;
                            p->y = j + k;
                            return p;
                        }
            }
        }
    return NULL;
}

POINT *check_low_left_line(char player, char ar[3][3], int x, int y, int win_num, POINT *p)
{
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j){
            if (j - win_num < -1 || i + win_num > x)
                continue;
            else{
                int player_num = 0;
                for (int k = 0; k < win_num; ++k)
                    if (ar[i + k][j - k] == player)
                        player_num++;
                if (player_num == win_num - 1)
                    for (int k = 0; k < win_num; ++k)
                        if(ar[i + k][j - k] == '_'){
                            p->x = i + k;
                            p->y = j - k;
                            return p;
                        }
            }
        }
    return NULL;
}

int check_lines(char player, char ar[3][3], int x, int y, int win_num, POINT *p)
{
    if(check_horizontal_line(player, ar, x, y, win_num, p)){
        printf("%d %d\n", p->x, p->y);
        return 1;
    }
    if(check_vertical_line(player, ar, x, y, win_num, p)){
        printf("%d %d\n", p->x, p->y);
        return 1;
    }
    if(check_low_left_line(player, ar, x, y, win_num, p)){
        printf("%d %d\n", p->x, p->y);
        return 1;
    }
    if(check_low_right_line(player, ar, x, y, win_num, p)){
        printf("%d %d\n", p->x, p->y);
        return 1;
    }
    return 0;
}

POINT *explore_surround(char ar[3][3], int current_x, int current_y, int x, int y, POINT *p)
{
    // POINT all_around_points[4] = {
    //     {current_x - 1, current_y},
    //     {current_x, current_y - 1},
    //     {current_x + 1, current_y},
    //     {current_x, current_y + 1}
    // };

    // for (int i = 0; i < 4; ++i){
    //     int explore_x = all_around_points[i].x;
    //     int explore_y = all_around_points[i].y;
    //     if (explore_x >= 0 && explore_x < x && explore_y >= 0 && explore_y < y && ar[explore_x][explore_y] == '_'){
    //         p->x = explore_x;
    //         p->y = explore_y;
    //         return p;
    //     }
    // }
    if (current_x - 1 >= 0)
        if (ar[current_x - 1][current_y] == '_' && ar[current_x - 1][2 - current_y] == '_'){
                p->x = current_x - 1;
                p->y = current_y;
                return p;
        }
    if (current_y - 1 >= 0)
        if (ar[current_x][current_y - 1] == '_' && ar[2 - current_x][current_y - 1] == '_'){
            p->x = current_x;
            p->y = current_y - 1;
            return p;
        }
    if (current_x + 1 < x)
        if (ar[current_x + 1][current_y] == '_' && ar[current_x + 1][2 - current_y] == '_'){
            p->x = current_x + 1;
            p->y = current_y;
            return p;
        }
    if (current_y + 1 < y)
        if (ar[current_x][current_y + 1] == '_' && ar[2 - current_x][current_y + 1] == '_'){
            p->x = current_x;
            p->y = current_y + 1;
            return p;
        }
    
    return NULL;
}

int surround_rival_num(char rival, char ar[3][3], int current_x, int current_y, int x, int y, POINT *p)
{
    POINT all_around_points[4] = {
        {current_x - 1, current_y},
        {current_x, current_y - 1},
        {current_x + 1, current_y},
        {current_x, current_y + 1}
    };

    int rival_num = 0;
    for (int i = 0; i < 4; ++i){
        int explore_x = all_around_points[i].x;
        int explore_y = all_around_points[i].y;
        if (explore_x >= 0 && explore_x < x && explore_y >= 0 && explore_y < y){
            if(ar[explore_x][explore_y] == rival)
                rival_num++;
        }
    }
    return rival_num;
}

int attack_on_lines(char player, char ar[3][3], int x, int y, int win_num, POINT *p)
{
    char rival = (player == 'X') ? 'O' : 'X';
    if (ar[0][0] == '_'){
        printf("0 0\n");
        return 1;
    }
    if (ar[1][1] == '_'){
        printf("1 1\n");
        return 1;       
    }
    POINT all_around_points[4] = {
        {0, 0},
        {x - 1, y - 2},
        {x - 1, 0},
        {0, y - 1}
    };

    for (int i = 0; i < 4; ++i)
    {
        int current_x = all_around_points[i].x;
        int current_y = all_around_points[i].y;
        if (ar[current_x][current_y] != rival){
            if (ar[current_x][current_y] == '_'){
                printf("%d %d\n", current_x, current_y);
                return 1;
            }
            else if(ar[1][1] == player) {
                if(explore_surround(ar, current_x, current_y, x, y, p)){
                    printf("%d %d\n", p->x, p->y);
                    return 1;
                }
            }
        }
    }
    
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            if (ar[i][j] == '_'){
                printf("%d %d\n", i, j);
                return 1;
            }

    return 0;
}

int guard_on_lines(char player, char ar[3][3], int x, int y, int win_num, POINT *p){
    char rival = (player == 'X') ? 'O' : 'X';
    if (ar[1][1] == '_'){
        printf("1 1\n");
        return 1;
    }

    POINT all_around_points[4] = {
        {0, 0},
        {x - 1, y - 1},
        {x - 1, 0},
        {0, y - 1}
    };

    for (int i = 0; i < 4; ++i)
    {
        int current_x = all_around_points[i].x;
        int current_y = all_around_points[i].y;
        // 标志位
        if (ar[1][1] != player){
                if (ar[current_x][current_y] == '_'){
                    printf("%d %d\n", current_x, current_y);
                    return 1;
                }
        }
        else if (ar[1][1] == player){
            // if (ar[current_x][current_y] == rival) 
                if(explore_surround(ar, current_x, current_y, x, y, p)){
                        printf("%d %d\n", p->x, p->y);
                        return 1;
                }
            // else if (ar[current_x][current_y] == '_'){
            //         printf("%d %d\n", current_x, current_y);
            //         return 1;
            // }
        }
    }

    if (ar[1][1] == player){
        for (int i = 0; i < 4; ++i){
            int current_x = all_around_points[i].x;
            int current_y = all_around_points[i].y;
            if(ar[current_x][current_y] == '_')
                if(surround_rival_num(rival, ar, current_x, current_y, x, y, p) > 1){
                    printf("%d %d", current_x, current_y);
                    return 1;
                }
        }
    }

    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            if (ar[i][j] == '_'){
                printf("%d %d\n", i, j);
                return 1;
            }

    return 0;
}

int main(void) {
    
    int i;
    char player;
    char board[4][3];
    
    //If player is X, I'm the first player.
    //If player is O, I'm the second player.
    scanf("%c", &player);
    
    //Read the board now. The board is a 3x3 array filled with X, O or _.
    for(i=0; i<3; i++) {
        scanf("%s[^\n]%*c", board[i]);
    }
    
    nextMove(player,board);
    return 0;
}

