#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdint.h>
void *threadfunc(void *a){
	char chars[5000];
	int i;
	srand(time(NULL) ^ (pthread_self()+10));
	for(i=0;i<5000;i++){
		chars[i]=(rand()%(123-97))+97;
	}
	int vowels=count(chars);
	int consonants=5000-vowels;
	printf("Thread %lu: Vowels: %d, consonants: %d\n",pthread_self(),vowels,consonants);
}
int count(char x[]){
	int i,counter=0;
	for(i=0;i<5000;i++){
		if(x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u'){
			counter++;
		}
	}
	return counter;
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
