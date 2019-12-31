//paper
//eng
//study
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

#define buffsize 100

int node_add(char * buf);

int alert(indexx * education) {

	int fd,i,j,sd;
	char buf[buffsize];
	if((fd = open("./education.txt",O_RDONLY)) == -1)perror("No Open File");
	
	
	for(j=0;fd != -1;j++){
		i=0;
		do{
		sd=read(fd,buf+i,1);
		}while(buf[i] > 65 && buf[i++]<123);
		buf[i]='\0';
		if(j!=0){
			if(!sd)break;
			//else node_add(buf);

		}
		else if(j==0)
			education->name = buf;//address coruption

		
		
		
	}
	
	
	
	close(fd);
	return 0;
}
int node_add(char * buf){

	//indexx * node = (indexx *)malloc(sizeof(char) * 10);
	//node->name = *buf;


return 0;
}
