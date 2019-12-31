//paper
//eng
//study
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

#define buffsize 100

static int edge_stat=0;
	//0 is child
	//1 is sibling


int node_add(char * buf,int edge_stat,indexx * parent);
int copy(indexx * s_truct, char * buf);
int bfs(indexx * root);

int node_set(indexx * node, char * file_name) {

	
	int fd,i,j,sd;
	char buf[buffsize];
	if((fd = open(file_name,O_RDONLY)) == -1)perror("No Open File");
	
	
	for(j=0;fd != -1;j++){
		i=0;
		do{
		sd=read(fd,buf+i,1);
		}while(buf[i] > 64 && buf[i++]<123);
		buf[i]='\0';
		
		if(j!=0){
			if(!sd)break;
			else node_add(buf,edge_stat,node);

		}
		else if(j==0)
			copy(node,buf);//address coruption

		
		
		
	}
	
	
	
	close(fd);
	return 0;
}
int node_add(char * buf,int edge_stat, indexx * parent){
	
	int i;
	indexx * temp = (indexx *)malloc(sizeof(indexx) * 10);
	indexx * node = (indexx *)malloc(sizeof(indexx) * 10);
	node->sib = 0;
	node->child = 0;
	node->chk = 0;
	temp = parent->child;
	copy(node,buf);
	if(parent->child == 0){
		parent->child = node;
		
	}
		
	else {
		
		for(;;){
			if(temp->sib == 0){
				temp->sib = node;
				break;
			}
			else temp = temp->sib;
			
		}
		
	}

return 0;
}
int copy(indexx * s_truct, char * buf){

	int i;
	char temp[10];
	
	for(i=0;buf[i]!='\0';i++)s_truct->name[i] = buf[i];



return 0;

}
int bfs(indexx * root){

	int i;
	start=0,end=1;
	
	indexx * temp = (indexx *)malloc(sizeof(indexx) * 10);
	bfs_arr[0] = root;


	while(start != end){

	temp = bfs_arr[start]->child;


		if(temp != 0){
			bfs_arr[end++]=temp;
		
		while(temp->sib != 0){
			bfs_arr[end++]=temp->sib;
			temp = temp->sib;
		
		}
		}
	start++;
	}

for(i=1;i<end;i++)bfs_arr[i]->resume_text=file_set[i-1];
}



























