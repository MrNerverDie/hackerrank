#include <stdio.h>

void add(unsigned char A[], unsigned char B[], unsigned char C[], int N);

int main()
{
	int N, Q;
	scanf("%d%d", &N, &Q);
    unsigned char A[N + 1], B[N + 1], C[N + 2];
    scanf("%s%s", A, B);
    char change = 'Y', signal, cmd[10], v;
    for(int i = 0; i < Q; i++){
    	int index;
    	scanf("%s %d", cmd, &index);
    	if(cmd[0] == 's'){
    		scanf(" %c", &v);
    		signal = cmd[4];
    		(signal == 'a') ? (A[N - 1 - index] = v) : (B[N - 1 - index] = v);
    		change = 'Y';
    	}else{
    		if (change == 'Y'){
    			add(A, B, C, N);
    			change = 'N';
    		}
    		printf("%c", C[N - index]);
    	}
    }
    return 0;
}

void add(unsigned char A[], unsigned char B[], unsigned char C[], int N){
	unsigned char carry = 0;
	for (int i = 0; i < N; ++i)
	{
		unsigned char sum = A[N - 1 - i] + B[N - 1 - i] + carry - '0' - '0';
		C[N - i] = (sum == 3 || sum == 1) + '0';
		carry = (sum > 1);
	}
	C[0] = carry + '0';
}