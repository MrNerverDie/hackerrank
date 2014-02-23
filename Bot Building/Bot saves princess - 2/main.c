//
//  main.c
//  Bot saves princess - 2
//
//  Created by 王选易 on 13-5-4.
//  Copyright (c) 2013年 王选易. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
/* Head ends here */
void nextMove(int n, int x, int y, char grid[101][101]){
    int k, m;
    
    for (k = 0; k < n; k++){
        for (m = 0; m < n; m++)
            if (grid[k][m] == 'p')
                break;
        if(m != n)
            break;
    }
    
    if (m < y)
        printf("LEFT");
    else if (m > y)
        printf("RIGHT");
    else if (k != x)
        printf((k < x) ? "UP" : "DOWN");
}
/* Tail starts here */
int main(void) {
    
    int n, x, y;
    
    scanf("%d", &n);
    scanf("%d", &x);
    scanf("%d", &y);
    
    char grid[101][101];
    
    for(int i=0; i<n; i++) {
        scanf("%s[^\n]%*c", grid[i]);
    }
    
    nextMove(n, x, y, grid);
    return 0;
}

