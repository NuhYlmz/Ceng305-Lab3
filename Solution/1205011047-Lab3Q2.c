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
printf("[PARENT] Creating third process...\n");
wait(NULL);
}
else if(pid3==0){
//CHILD-3
printf("[CHILD3] Executing ls command...\n");
char command[128];
snprintf(command, sizeof(command), " ls -l %s* | awk \'{print $5\" \"$9}\' ",filename);
system(command);

} 

else{
//HATA CHILD-3
printf("HATA CHILD-3 \n");

}
}
else if(pid2==0){
//CHILD-2
printf("[CHILD2] Executing zip command...\n");
char command[128];
snprintf(command, sizeof(command), "zip %s.zip %s.txt",filename,filename);
system(command);
}
else{
//HATA CHILD-2
printf("HATA CHILD-2 \n");

}
}
else if(pid1==0){
//CHILD-1
int i;
printf("[CHILD1] Writing %d random chars to %s.txt...\n",num,filename);
FILE *file;
char name[256];
strcpy(name,filename);
strcat(name,".txt");
file=fopen(name,"w");
for(i=0;i<num;i++){
fprintf(file,"%c\n",(rand()%(123-97))+97);
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
