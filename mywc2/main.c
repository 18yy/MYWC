#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int charNum = 0; //字符符 
int wordNum = 0; //单词数 
int lineNum = 1; //行数
int spaceLineNum = 0;//空行 
int annotateLineNum = 0;//注释行 
int codeLineNum = 0;//代码行 

int main(int argc, char *argv[]) {
	
	char choice; 
	
	count(argv[2]);
	otherCount(argv[2]);
	
	while((choice = getopt(argc, argv, "c:w:l::a:")) != -1) {//选项字符串后必须带有参数 
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
				case 'a':
					printf("文件的空行数为:%d\n文件的代码行数为：%d\n",spaceLineNum,codeLineNum);
					break;	
				
			}
		}


	return 0;
}

void otherCount(char *file){
	FILE * fp;
	int num = 0;
	char st[200];
	
	if((fp=fopen(file,"r"))==NULL)
    {
        printf("read file failed！\n");
        exit(-1);
    }
	
	
	while(!feof(fp))                       
    {
    	fgets(st,200,fp);
    	int len=strlen(st);   
    	int i=0;
    	
    	for (i=0;i<len;i++)
    	{
    		if (st[i]!=' ' && st[i]!='\n' && st[i]!='\t')
    			num++;//一行中的其他字符数 
    	}
    	
    	if(num<1){
    		spaceLineNum++;//空行加一 
		} else{
			codeLineNum++;//代码行加一 
		}
    	
	}	
	fclose(fp);
} 

void count(char * file){
	FILE * fp;
    char ch;
    int flag = 0;
    int lineFlag = 0;

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
         
        
		if(ch=='\n'&&charNum!=0){//计算行数 
			lineNum++;
		}else if(charNum==0){//当空文件行数为0
			lineNum=0;
		}

    }
    fclose(fp);
}
