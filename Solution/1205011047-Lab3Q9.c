#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdint.h>
char chars[50000];
void *threadfunc(void* a){
	int vowels=count((intptr_t)a);
	int consonants=5000-vowels;
	printf("Thread %lu: Vowels: %d, consonants: %d\n",pthread_self(),vowels,consonants);
	}
int count(int x){
	int i,counter=0;
	for(i=0;i<5000;i++){
		if(chars[i+(5000*x)] == 'a' || chars[i+(5000*x)] == 'e' || chars[i+(5000*x)] == 'i' || chars[i+(5000*x)] == 'o' || chars[i+(5000*x)] == 'u'){
			counter++;
		}
	}
	return counter;
}
main() {
	srand(time(NULL));
	int x;
	for(x=0;x<50000;x++){
		chars[x]=(rand()%(123-97))+97;
	}
	pthread_t thread_id[10];
	int i, j;
	 for(i=0; i<10; i++)
	    {
		pthread_create( &thread_id[i], NULL, &threadfunc, (void *)(intptr_t)i);
		}
	 for(j=0; j<10; j++)
	    {
		pthread_join( thread_id[j], NULL);
		}
	exit(EXIT_SUCCESS);
}
