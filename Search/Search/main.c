//
//  main.c
//  Search
//
//  Created by 王选易 on 13-5-16.
//  Copyright (c) 2013年 王选易. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void find_pairs(int ar[], int size, int diff){
	int count = 0, res = 0;
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if ((res = ar[i] - ar[j]) == diff || res == -diff)
				count++;
	printf("%d\n", count);
}

int main() {

   	int N, K;
   	scanf("%d%d", &N, &K);
   	int nums[N];
   	for (int i = 0; i < N; i++)
   		scanf("%d", &nums[i]);
 	find_pairs(nums, N, K);
    return 0;
}


