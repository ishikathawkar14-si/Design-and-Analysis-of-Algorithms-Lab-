#include<stdio.h>
int main(){
	int m, n;
	
	if (scanf("%d %d" , &m, &n)!=2)return 0;
	int A[m][n];
	for (int i = 0; i < m; i++){
		for (int j = 0; j< n; j++){
			scanf("%d", &A[i][j]);
			
			}
		}
	int r, c;
	if (scanf("%d %d", &r, &c) != 2)return 0;
	if (n != r){
		printf("Invalid input\n");
		return 0;
	}
		int B[r][c];
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++)
				{
					scanf("%d", &B[i][j]);
					
				}
		}
		int C[m][c];
		for(int i = 0; i < m; i++){
			for(int j = 0; j < c; j++){
				C[i][j] = 0;
				for(int k = 0; k < n; k++){
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}

		for(int i=0; i<m; i++){
			for(int j = 0; j < c; j++){
				printf("%d", C[i][j]);
				if(j < c - 1){
					printf(" ");
				}
			}
			printf(" \n");
		}

		return 0;
}