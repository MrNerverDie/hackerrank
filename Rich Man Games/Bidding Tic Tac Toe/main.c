#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

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

int cal_first_bids_num(int *first_player_bids, int *second_player_bids);

/* Head ends here */
void next_move(char player, int *first_player_bids, int *second_player_bids, char board[3][3], char *move) {
    char rival = (player == 'X') ? 'O' : 'X';
    POINT next_point = {0};
    if (*move == 'P'){
        // win the game
        if(check_lines(player, board, 3, 3, 3, &next_point)){
            printf("%d %d\n", next_point.x, next_point.y);
            return;
        }
        // stop the rival
        if(check_lines(rival, board, 3, 3, 3, &next_point)){
            printf("%d %d\n", next_point.x, next_point.y);
            return;
        }
        // attack
        if (player == 'X'){
            if(attack_on_lines(player, board, 3, 3, 3, &next_point))
                return;
        }
        else if(guard_on_lines(player, board, 3, 3, 3, &next_point))
            return;
    }else{
        int player_num = 0;
        player_num = (player == 'X') ? (cal_first_bids_num(first_player_bids, second_player_bids)) 
                    : (8 - cal_first_bids_num(first_player_bids, second_player_bids));
        int rival_num = 8 - player_num;
        if(check_lines(player, board, 3, 3, 3, &next_point) || check_lines(rival, board, 3, 3, 3, &next_point)){
            printf("%d\n", (player_num > rival_num) ? (rival_num + 1) : (player_num));
            return;
        }else if (player_num > 6){
            printf("%d\n", rival_num + 1);
            return;
        }else{
            printf("1\n");
            return;
        }
    }
}

int cal_first_bids_num(int *first_player_bids, int *second_player_bids){
    int bids_num = 4;
    int same_num = 0;
    for (int i = 0; !(first_player_bids[i] == 0 && second_player_bids[i] == 0); i++){
        if(first_player_bids[i] < second_player_bids[i])
            bids_num += second_player_bids[i];
        else if (first_player_bids[i] > second_player_bids[i])
            bids_num -= first_player_bids[i];
        else {
            same_num++;
            if (same_num % 2 == 0)
                bids_num += first_player_bids[i];
            else
                bids_num -= first_player_bids[i];
        }
    }
    return bids_num;
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
        // printf("%d %d\n", p->x, p->y);
        return 1;
    }
    if(check_vertical_line(player, ar, x, y, win_num, p)){
        // printf("%d %d\n", p->x, p->y);
        return 1;
    }
    if(check_low_left_line(player, ar, x, y, win_num, p)){
        // printf("%d %d\n", p->x, p->y);
        return 1;
    }
    if(check_low_right_line(player, ar, x, y, win_num, p)){
        // printf("%d %d\n", p->x, p->y);
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

/* Tail starts here */
int main(void) {
    
    char player;                                          //1 if first player 2 if second
    int first_player_bids[100] = {0};
    int second_player_bids[100] = {0};
    int i = 0;
    char board[4][3];
    char* move = (char *)malloc(5);
    
    char test;
    
    player = getchar();
    scanf("%s", move);
    
    test = getchar();
    while ((test = getchar()) != '\n') {
        if(isdigit(test))
            first_player_bids[i++] = (int) (test - '0');
    }
    
    i = 0;
    while ((test = getchar()) != '\n') {
        if(isdigit(test))
            second_player_bids[i++] = (int) (test - '0');
    }

    for(i=0;i<3;i++) {
        scanf("%s", board[i]);
    }
    
    next_move(player, first_player_bids, second_player_bids, board, move);
    return 0;
    
}