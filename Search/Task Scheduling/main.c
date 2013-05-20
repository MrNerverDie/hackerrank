//
//  main.c
//  Task Scheduling
//
//  Created by 王选易 on 13-5-16.
//  Copyright (c) 2013年 王选易. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define deadline 0
#define complete_time 1
#define time_left 2

int main() {

    int N;
    scanf("%d", &N);
    int tasks[N][3];
    for (int i = 0; i < N; i++)
    	scanf("%d%d", &tasks[i][deadline], &tasks[i][complete_time]);
    int exceed_time = 0, current_time = 0, completed[N];
    for (int i = 0; i < N; i++){
    	//init
    	current_time = 0;
    	exceed_time = 0;
    	for (int j = 0; j < i + 1; j++)
    		completed[j] = 0;

    	while(true){
    		int j;
    		for (j = 0; j < i + 1; j++){
    			if (completed[j] == 0 && (current_time - tasks[j][deadline] >= exceed_time){
    				exceed_time = current_time - tasks[j][deadline] + 1;
    				current_time += (exceed_time - 1);
    				continue;
    			}else if (completed[j] == 0){
    				current_time++;
    			}
    		}
    	}
    }
    return 0;
}


