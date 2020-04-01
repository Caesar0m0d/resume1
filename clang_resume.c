///////*****************************************************************///////
///////		R	E	S	U	M	E		///////	
///////									///////
///////		Myeong	-	Kyu			Kim		///////
///////									///////
///////		82)10-6799-6764			hehe6764@hanmail.net	///////
///////*****************************************************************///////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<pthread.h>


#define indexxx	 	"./index.txt"
#define edu_index	"./education_index.txt"

#define lang		"./language.txt"
#define edu		"./education.txt"
#define paper		"./paper.txt"
#define studies		"./studies.txt"
#define namesize 30
#define textlength 300

int eng_skill=0;	//a.k.a. english skill


typedef struct P{
	
	char name[namesize];
	char * resume_text;
	int chk;
	struct P * sib;//a.k.a. sibling
	struct P * child;//a.k.a. sibling
}indexx;
indexx * root;
indexx ** bfs_arr;
int start,end;
char * file_set[10];
#include"education.h"
#include"language.h"

int main() {

	int d, i, j, k, s, t, r, a;
	char * file_name;
	char buf_0[textlength];
	int fd1 = open("./flush.txt",O_RDONLY);


	file_set[0]=edu;
	file_set[1]=lang;
	file_set[2]=paper;
	file_set[3]=studies;
	bfs_arr = (indexx **)malloc(sizeof(indexx *) * 10);
	root = (indexx *)malloc(sizeof(indexx) * 15);
	root->sib=0;	
	root->child =0;
	file_name = indexxx;
	node_set(root,file_name);

	file_name = edu_index;
	node_set(root->child,file_name);

	bfs(root);
		for(i=1;i<end;i++){
			
			printf("/");
			for(j=0;j<namesize;j++)
				printf("*");
			printf("/\n\n\n");
			printf("\t\t%s\n\n\n",bfs_arr[i]->name);
			printf("/");

			for(j=0;j<namesize;j++)
				printf("*");
			printf("/\n\n\n");
			int fd;
			if((fd = open(bfs_arr[i]->resume_text,O_RDONLY)) == -1)
				perror("No Open File");
			read(fd,buf_0,textlength);
			
			printf("%s\n",buf_0);
			printf("\n\n\n");
			printf("automatically scrolled down after %d seconds\n\n\n\n",15);
			
			sleep(1);
			for(k=1;k<15;k++){
				sleep(1);
				
			}
			
			close(fd);
		}
	printf("press any key to quit\n");
	getchar();
	
	return 0;
}


