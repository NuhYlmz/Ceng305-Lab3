#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdint.h>
int numbers[10000];
void *threadfunc(void *a){
	printf("Thread %d - %d primes.\n",(intptr_t)a,checkArr((intptr_t)a));
}
int checkArr(intptr_t x){
	int i,counter=0;
	for(i=0;i<1000;i++){
		if(isPrime(numbers[i+(1000*x)])==1){
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
	srand(time(NULL));
	int x;
	for(x=0;x<10000;x++){
		numbers[x]=(rand()%9000)+1000;
	}
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
