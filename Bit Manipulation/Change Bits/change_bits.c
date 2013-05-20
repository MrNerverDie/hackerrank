#include <stdio.h>

void add(unsigned char A[], unsigned char B[], unsigned char C[], unsigned char carry_table, int N, int last_carry_index);

int main()
{
	int N, Q;
	scanf("%d%d", &N, &Q);
    unsigned char A[N + 1], B[N + 1], C[N + 2], carry_table[N + 2];
    scanf("%s%s", A, B);
    char change = 'Y', signal, cmd[10], v;
    int index;

    int last_carry_index = 0;

    for(int i = 0; i < Q; i++){
    	scanf("%s %d", cmd, &index);
    	if(cmd[0] == 's'){
    		scanf(" %c", &v);
    		signal = cmd[4];
            if (signal == 'a'){
                if (A[N - 1 - index] != v){
                    A[N - 1 - index] = v;
                    change = 'Y';
                    if((N - 1 - index) > last_carry_index)
                    	last_carry_index = N - 1 - index;
                }
            }else{
                if (B[N - 1 - index] != v){
                    B[N - 1 - index] = v;
                    change = 'Y';
                    if((N - 1 - index) > last_carry_index)
                    	last_carry_index = N - 1 - index;
                }
            }
//    		(signal == 'a') ? (A[N - 1 - index] = v) : (B[N - 1 - index] = v);
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

void add(unsigned char A[], unsigned char B[], unsigned char C[], unsigned char carry_table, int N, int last_carry_index){
	unsigned char carry = carry_table[last_carry_index];
	for (int i = last_carry_index; i < N; ++i)
	{
		unsigned char sum = A[N - 1 - i] + B[N - 1 - i] + carry - '0' - '0';
		C[N - i] = (sum == 3 || sum == 1) + '0';
		carry_table[N - i] = carry = (sum > 1);
	}
	C[0] = carry + '0';
}