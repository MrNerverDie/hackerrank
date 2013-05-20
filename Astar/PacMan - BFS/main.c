//
//  main.c
//  PacMan - BFS
//
//  Created by 王选易 on 13-5-5.
//  Copyright (c) 2013年 王选易. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
/* Head ends here */
#define QUEUE_LENGTH 100
int is_explored(int x, int y, int explored[1000][2], int explored_size);
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
    int queue[QUEUE_LENGTH][3] = {0};
    int front = 0;
    int rear = 0;

    int current_x = pacman_x;
    int current_y = pacman_y;
    do{
        // case UP
        if (current_x - 1 >= 0){
            if ((!is_explored(current_x - 1, current_y, explored, explored_size)) && (grid[current_x - 1][current_y] != '%')){
                queue[rear][0] = current_x - 1;
                queue[rear][1] = current_y;
                queue[rear][2] = path_size;
                (rear > 0) ? (rear--) : (rear+=QUEUE_LENGTH - 1);
            }
        }
        // case LEFT
        if (current_y - 1 >= 0){
            if ((!is_explored(current_x, current_y - 1, explored, explored_size)) && grid[current_x][current_y - 1] != '%'){
                queue[rear][0] = current_x;
                queue[rear][1] = current_y - 1;
                queue[rear][2] = path_size;
                (rear > 0) ? (rear--) : (rear+=QUEUE_LENGTH - 1);
            }
        }
        
        // case RIGHT
        if (current_y + 1 < y){
            if ((!is_explored(current_x, current_y + 1, explored, explored_size)) && grid[current_x][current_y + 1] != '%'){
                queue[rear][0] = current_x;
                queue[rear][1] = current_y + 1;
                queue[rear][2] = path_size;
                (rear > 0) ? (rear--) : (rear+=QUEUE_LENGTH - 1);
            }
        }
        // case DOWN
        if (current_x + 1 < x){
            if ((!is_explored(current_x + 1, current_y, explored, explored_size)) && grid[current_x + 1][current_y] != '%'){
                queue[rear][0] = current_x + 1;
                queue[rear][1] = current_y;
                queue[rear][2] = path_size;
                (rear > 0) ? (rear--) : (rear+=QUEUE_LENGTH - 1);
            }
        }
        
        while (is_explored(queue[front][0], queue[front][1], explored, explored_size))
            (front > 0) ? (front--) : (front+=QUEUE_LENGTH - 1);
        path_size = queue[front][2];
        path[path_size][0] = queue[front][0];
        path[path_size][1] = queue[front][1];
        explored[explored_size][0] = path[path_size][0];
        explored[explored_size][1] = path[path_size][1];
        explored_size++;
        path_size++;
        (front > 0) ? (front--) : (front+=QUEUE_LENGTH - 1);
        
        current_x = path[path_size - 1][0];
        current_y = path[path_size - 1][1];
        
        if (current_x == 0 && current_y == 0) {
            break;
        }
    } while (current_x != food_x || current_y != food_y);
    
    printf("%d\n", explored_size);
    for (int i = 0; i < explored_size; ++i)
        printf("%d %d\n", explored[i][0], explored[i][1]);
    
    printf("%d\n", path_size - 1);
    for (int i = 0; i < path_size; ++i)
        printf("%d %d\n", path[i][0], path[i][1]);
}
int is_explored(int x, int y, int explored[1000][2], int explored_size){
    for (int i = explored_size - 1; i >= 0; i--)
        if ((explored[i][0] == x) && (explored[i][1] == y))
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

