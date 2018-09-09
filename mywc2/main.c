#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int charNum = 0; //字符符 
int wordNum = 0; //单词数 
int lineNum = 0; //行数

int main(int argc, char *argv[]) {
	
	char choice; 
	
	count(argv[2]);
	while((choice = getopt(argc, argv, "c:w:l:")) != -1) {//选项字符串后必须带有参数 
			switch(choice){
				case 'c':
					printf("文件的字符数为:%d\n",charNum);
					break;
				case 'w':
					printf("文件的单词数为:%d\n",wordNum);
					break;
				case 'l':
					printf("文件的行数为:%d\n",lineNum+1);
					break;
			}
		}


	return 0;
}

void count(char * file){
	FILE * fp;
    char ch;
    int flag = 0;
   
    
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("read file failed！\n");
        exit(-1);
    }
    
    while(!feof(fp)) //如果没有遇到文件的结束标志  
    {
        ch=fgetc(fp); //从文件读取一个字符，暂存在变量ch中
        
        if((ch >= 'A'&&ch <= 'z')||ispunct(ch)){//如果是字母或者标点符号，字符数加一 
        	charNum++; 
		}
        
        if(!(ch >= 'A'&&ch <= 'z')){  //如果是非字母字符，让flag为0 
			flag = 0;
		}else if(flag == 0){ //如果是字母字符且flag原值为0，flag置1，单词数加一 
			flag = 1; 
			wordNum++;
		}
         
		if(ch=='\n'){
			lineNum++;
		}
    }
    fclose(fp);
}
