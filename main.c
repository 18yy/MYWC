#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int charNum = 0; //字符符 
	int wordNum = 0; //单词数 
	int lineNum = 0; //行数
	int choice; //选项，为c或者w或者l 
	
	FILE *fp; //定义一个指向文件的指针变量fp 
	
	count(argv[2]);
	scanf("%s%s%s",argv[0],argv[1],argv[2]);
	
	if((fp = fopen(argv[2],"r")) == NULL)
        {    
        printf("cannot open this file\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
        exit(0);
        }
	
	while((choice = getopt(argc, argv, "c::w::l::")) != -1) {//选项字符串后必须带有参数 
		switch(choice){
			case 'c':
				printf("文件的字符数为:%d\n",charNum);
				break;
			case 'w':
				printf("文件的单词数为:%d\n",wordNum);
				break;
			case 'l':
				printf("文件的行数为:%d\n",lineNum);
				break;
		}
	}
	return 0;
}
void count(char * fileName){
	
} 
