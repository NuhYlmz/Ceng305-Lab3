#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdint.h>
int numbers[10000];
void *threadfunc(void* a){
	int digit[5]={0,0,0,0,0};
	int i;
	int x=(intptr_t)a;
	for(i=0;i<2000;i++){
		int temp=countDigit(numbers[i+(2000*x)]);
		digit[temp-1]++;
	}
	printf("Thread %d: 1-9 %d, 10-99 %d, 100-999 %d, 1000-9999 %d, 10000-99999 %d\n",(intptr_t)a,digit[0],digit[1],digit[2],digit[3],digit[4]);
}
int countDigit(int x){
	int counter=0;
	int n=x;
	while(n != 0)
    {
        n = n/10;
        ++counter;
    }
	return counter;
}
main() {
	srand(time(NULL));
	int x;
	for(x=0;x<10000;x++){
		numbers[x]=rand()%50001;
	}
	pthread_t thread_id[5];
	int i, j;
	 for(i=0; i<5; i++)
	    {
		pthread_create( &thread_id[i], NULL, &threadfunc, (void *)(intptr_t)i);
		}
	 for(j=0; j<5; j++)
	    {
		pthread_join( thread_id[j], NULL);
		}
	exit(EXIT_SUCCESS);
}
