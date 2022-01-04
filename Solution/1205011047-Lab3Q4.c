#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdint.h>
void *threadfunc(void *a){
	int nums[1000];
	int i;
	srand(time(NULL) ^ pthread_self());
	for(i=0;i<1000;i++){
		nums[i]=(rand()%9000)+1000;
	}
	printf("Thread %d - %d primes.\n",(intptr_t)a,checkArr(nums));
}
int checkArr(int x[]){
	int i,counter=0;
	for(i=0;i<1000;i++){
		if(isPrime(x[i])==1){
			counter++;
		}
	}
	return counter;
}
int isPrime(int n){
	int i,a=1;
	for(i = 2; i <= n / 2; ++i)
  {
      if(n % i == 0)
      {
          a = 0;
          break;
      }
  }
  return a;
}
main() {
	pthread_t thread_id[10];
	int i, j;
	 for(i=0; i < 10; i++)
	    {
		pthread_create( &thread_id[i], NULL, &threadfunc, (void *)(intptr_t)i);
		}
	 for(j=0; j < 10; j++)
	    {
		pthread_join( thread_id[j], NULL);
		}
	exit(EXIT_SUCCESS);
}
