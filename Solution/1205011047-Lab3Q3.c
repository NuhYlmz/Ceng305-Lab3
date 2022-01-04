#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[]) {
	if(argc==5){
		char filename1[sizeof(argv[1])];
		char filename2[sizeof(argv[2])];
		strcpy(filename1,argv[1]);
		strcpy(filename2,argv[2]);
		int number1=atoi(argv[3]);
		int number2=atoi(argv[4]);
		int pid1,pid2,pid3;
		srand(time(NULL));
		pid1=fork();
		if(pid1>0){
			//PARENT
			printf("[PARENT] Creating first process...\n");
			printf("[PARENT] Creating second process...\n");
			wait(NULL);
			pid2=fork();
			if(pid2>0){
				//PARENT
				wait(NULL);
				pid3=fork();
				if(pid3>0){
					//PARENT
					printf("[PARENT] Creating third process...\n");
					wait(NULL);
					//waitpid(pid3,NULL,0);
				}
				else if(pid3==0){
					//Çocuk3
					//waitpid(pid2);
					printf("[CHILD3] Sorting both files:\n");
					char command[128];
					snprintf(command, sizeof(command), "cat %s %s | sort -n",filename1,filename2);
					system(command);
					
				}
			}
			else if(pid2==0){
				//Çocuk2
				srand(getpid());

				printf("[CHILD2] Writing %d random integers to %s...\n",number2,filename2);
				int i;
				FILE *file;
				file=fopen(filename2,"w");
				for(i=0;i<number2;i++){
				fprintf(file,"%d\n",rand()%100);
				}
				fclose(file);
				}
		}
		else if(pid1==0){
			//Çocuk1
			srand(getpid());
			wait(NULL);
			printf("[CHILD1] Writing %d random integers to %s...\n",number1,filename1);
			int i;
			FILE *file;
			file=fopen(filename1,"w");
			for(i=0;i<number1;i++){
			fprintf(file,"%d\n",rand()%100);
			}
			fclose(file);
		}
if(pid1>0)
if(pid2>0)
if(pid3>0)
printf("[PARENT] Done.\n");	
	}
	else
	printf("Yetersiz arg.\n");
}
