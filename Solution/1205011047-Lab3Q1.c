#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]){
if(argc==3){
srand(time(NULL));
char filename[sizeof(argv[1])];
strcpy(filename, argv[1]);
int num=atoi(argv[2]);

int pid1,pid2,pid3;
wait(NULL);
pid1=fork();
if(pid1>0){
//PARENT
printf("[PARENT] Creating first process...\n");
wait(NULL);
pid2=fork();
if(pid2>0){

//PARENT
printf("[PARENT] Creating second process...\n");
wait(NULL);
pid3=fork();
if(pid3>0){
//PARENT
printf("[PARENT] Executing third process...\n");
wait(NULL);
}
else if(pid3==0){
//CHILD-3
FILE* file = fopen(filename, "r");
char line[256];
int min=1000,max=0;
while (fgets(line, sizeof(line), file)){
if(atoi(line)<min)
min=atoi(line);
if(atoi(line)>max)
max=atoi(line);

}
fclose(file);
printf("[CHILD3] Min: %d, max: %d\n",min,max);

}
else{
//HATA CHILD-3
printf("HATA CHILD-3 \n");



}
}
else if(pid2==0){
//CHILD-2
printf("[CHILD2] Executing sort command...\n");
char command[128];
snprintf(command, sizeof(command), "sort -n %s",filename);
system(command);
//system("cat aaa.txt");
}
else{
//HATA CHILD-2
printf("HATA CHILD-2 \n");

}
}
else if(pid1==0){
//CHILD-1
int i;
printf("[CHILD1] Creating %s with %d integers...\n",filename,num);
FILE *file;
file=fopen(filename,"w");
for(i=0;i<num;i++){
fprintf(file,"%d\n",rand()%(1000+1));
}
fclose(file);
}
else{
//HATA CHILD-1
printf("HATA CHILD-1 \n");

}

if(pid1>0)
if(pid2>0)
if(pid3>0)
printf("[PARENT] Done.\n");

}
}
