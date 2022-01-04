#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdint.h>
void *threadfunc(void* a){
	srand(time(NULL) ^ pthread_self());
	int nums[2000];
	int digit[5]={0,0,0,0,0};
	int i,j;
	for(i=0;i<2000;i++){
		nums[i]=rand()%50001;
	}
	for(j=0;j<2000;j++){
		int temp=countDigit(nums[j]);
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
