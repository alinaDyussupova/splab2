#include  <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include<stdlib.h>

int main(){

	int num1;
	int num2;
	printf("Enter the first number: ");
	scanf("%d", &num1);

	printf("Enter the second number: ");
	scanf("%d", &num2);

	int process1 = fork();

	if (process1 != 0){
		int process2 = fork();
		if (process2 != 0){
			int process3 = fork();
			if(process3 != 0){
				int process4 = fork();
				if (process4 != 0){
					waitpid(process1,0,0);
		            waitpid(process2,0,0);
		            waitpid(process3,0,0);
            		waitpid(process4,0,0);
					printf("Parent done\n");
				}
				else{
					int div = num1 / num2;
					printf("4th child: %d / %d = %d\n", num1, num2, div);
				}

			}
			else{
				int diff = num1 - num2;
				printf("3d child: %d - %d = %d\n", num1, num2, diff);
			}
		}
		else{
			int mul = num1 * num2;
			printf("2nd child: %d * %d = %d\n", num1, num2, mul);
		}
	}

	else{
		int sum = num1 + num2;
		printf("1st child: %d + %d = %d\n", num1, num2, sum);
	}


}

	
