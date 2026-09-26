#include<stdio.h>
#include<unistd.h>
#include<time.h>
int main()
{
int fd[2];
pipe(fd);
int pid,data;
int start,end,efficiency;
double timetaken;
pid=fork();
start=clock();
if(pid==0){
printf("Consumer\n");
close(fd[1]);
for(int i=0;i<5;i++){
read(fd[0],&data,sizeof(data));
printf("consumed %d\n",data);
}
close(fd[0]);
}else{
printf("producer\n");
close(fd[0]);
for(int i=1;i<=5;i++){
data=i*10;
write(fd[1],&data,sizeof(data));
printf("Produced %d\n",data);
}
close(fd[1]);
end=clock();
timetaken =(double)(end-start)/CLOCKS_PER_SEC;
printf("Time Taken :%f\n",timetaken);
efficiency=5/timetaken;
printf("Effiency: %d\n",efficiency);
}
}
