//
//  main.c
//  HackerRank
//
//  Created by 王选易 on 13-5-4.
//  Copyright (c) 2013年 王选易. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void displayPathtoPrincess(int n, char grid[n][n]){
    int y, x;

    for (y = 0; y < n; y++){
        for (x = 0; x < n; x++)
            if (grid[y][x] == 'm')
                break;
        if(x != n)
            break;
    }

    if(grid[n-1][n-1] == 'p'){
        for (int i = 0; i < n - 1 - y; i++)
            printf("DOWN\n");
        for (int i = 0; i < n - 1 - x; i++)
            printf("RIGHT\n");
    }
    if(grid[n-1][0] == 'p'){
        for (int i = 0; i < n - 1 - y; i++)
            printf("DOWN\n");
        for (int i = 0; i < x; i++)
            printf("LEFT\n");
    }
    if(grid[0][0] == 'p'){
        for (int i = 0; i < y; i++)
            printf("UP\n");
        for (int i = 0; i < x; i++)
            printf("LEFT\n");
    }
    if(grid[0][n-1] == 'p'){
        for (int i = 0; i < y; i++)
            printf("UP\n");
        for (int i = 0; i < n - 1 - x; i++)
            printf("RIGHT\n");
    }
}
/* Tail starts here */
int main(void) {
    
    int m;
    scanf("%d", &m);
    char grid[m][m];
    char line[m];
    
    for(int i=0; i<m; i++) {
        scanf("%s", line);
        strncpy(grid[i], line, m);
    }
    displayPathtoPrincess(m,grid);
    return 0;
}

