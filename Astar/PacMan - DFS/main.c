//
//  main.c
//  PACMAN - DFS
//
//  Created by 王选易 on 13-5-5.
//  Copyright (c) 2013年 王选易. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
/* Head ends here */
int is_explored(int x, int y, int explored[100][2], int explored_size);
void nextMove(int x, int y, int pacman_x, int pacman_y, int food_x, int food_y, char grid[x][y]){
    int explored[1000][2] = {0};
    explored[0][0] = pacman_x;
    explored[0][1] = pacman_y;
    int explored_size = 1; 

    int path[1000][2] = {0};
    path[0][0] = pacman_x;
    path[0][1] = pacman_y; 
    int path_size = 1;

    // 2 - log the path pointer
    int stack[100][3] = {0};
    int stack_size = 0;

    int current_x = pacman_x;
    int current_y = pacman_y;
    do{
        // case UP
        if (current_x - 1 >= 0){
            if ((!is_explored(current_x - 1, current_y, explored, explored_size)) && grid[current_x - 1][current_y] != '%'){
                stack[stack_size][0] = current_x - 1;
                stack[stack_size][1] = current_y;
                stack[stack_size][2] = path_size;
                stack_size++;
            }
        }
        // case LEFT
        if (current_y - 1 >= 0){
            if ((!is_explored(current_x, current_y - 1, explored, explored_size)) && grid[current_x][current_y - 1] != '%'){
                stack[stack_size][0] = current_x;
                stack[stack_size][1] = current_y - 1;
                stack[stack_size][2] = path_size;
                stack_size++;
            }
        }
        
        // case RIGHT
        if (current_y + 1 < y){
            if ((!is_explored(current_x, current_y + 1, explored, explored_size)) && grid[current_x][current_y + 1] != '%'){
                stack[stack_size][0] = current_x;
                stack[stack_size][1] = current_y + 1;
                stack[stack_size][2] = path_size;
                stack_size++;
            }
        }
        // case DOWN
        if (current_x + 1 < x){
            if ((!is_explored(current_x + 1, current_y, explored, explored_size)) && grid[current_x + 1][current_y] != '%'){
                stack[stack_size][0] = current_x + 1;
                stack[stack_size][1] = current_y;
                stack[stack_size][2] = path_size;
                stack_size++;
            }
        }

        while (is_explored(stack[stack_size - 1][0], stack[stack_size - 1][1], explored, explored_size))
            stack_size--;
        path_size = stack[stack_size - 1][2];
        path[path_size][0] = stack[stack_size - 1][0];
        path[path_size][1] = stack[stack_size - 1][1];
        explored[explored_size][0] = path[path_size][0];
        explored[explored_size][1] = path[path_size][1];
        explored_size++;
        path_size++;
        stack_size--;

        current_x = path[path_size - 1][0];
        current_y = path[path_size - 1][1];
    } while (current_x != food_x || current_y != food_y);
    
    printf("%d\n", explored_size);
    for (int i = 0; i < explored_size; ++i)
        printf("%d %d\n", explored[i][0], explored[i][1]);

    printf("%d\n", path_size - 1);
    for (int i = 0; i < path_size; ++i)
        printf("%d %d\n", path[i][0], path[i][1]);
}
int is_explored(int x, int y, int explored[100][2], int explored_size){
    for (int i = explored_size - 1; i >= 0; i--)
        if (explored[i][0] == x && explored[i][1] == y)
            return 1;
    return 0;
}
/* Tail starts here */
int main(void) {
    
    int x, y;
    int pacman_x, pacman_y;
    int food_x, food_y;
    scanf( "%d %d", &pacman_x, &pacman_y);
    scanf( "%d %d", &food_x, &food_y);
    scanf( "%d %d", &x, &y);
    char grid[x][y];
    
    for( int i=0; i<x; i++) {
        scanf("%s[^\\n]%*c", grid[i]);
    }
    nextMove( x, y, pacman_x, pacman_y, food_x, food_y, grid);
    return 0;
}

