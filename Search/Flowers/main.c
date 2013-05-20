/* Sample program illustrating input/output methods */
#include<stdio.h>

int main(){

//Helpers for input/output
   int i, N, K;
   int C[102];
   
   scanf("%d %d", &N, &K);
   for(i=0; i<N; i++){
      scanf("%d", &(C[i]));
   }

   int result;

   for (int i = 0; i < N; i++){
   		result += (i / K + 1) * C[i];
   	}
   printf("%d\n", result);

}