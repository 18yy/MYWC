#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int charNum = 0; //字符符 
int wordNum = 0; //单词数 
int lineNum = 1; //行数
int spaceLineNum = 1;//空行 
int annotateLineNum = 1;

int main(int argc, char *argv[]) {
	
	char choice; 
	
	count(argv[2]);
	while((choice = getopt(argc, argv, "c:w:l:a:")) != -1) {//选项字符串后必须带有参数 
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
					printf("文件的空行数为:%d\n",spaceLineNum);
					break;	
				case 'b':
					printf("文件的注释行数为:%d\n",annotateLineNum);
					break;	
			}
		}


	return 0;
}

void count(char * file){
	FILE * fp;
    char ch;
    int flag = 0;
    int num = 0; 
    int num2 = 0;
    int lineFlag = 0;
    int annotateLineFlag = 0;
   
    
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
         
		if(ch=='\n'&&charNum!=0){
			lineNum++;
		}else if(charNum==0){
			lineNum=0;
		}
		
		//获取空行 
		if(ch == '\n'&&lineFlag == 0){
			lineFlag = 1;
		}else if(ch != '\n'&&lineFlag == 1){
			num++;
		}else if(ch == '\n'&&lineFlag == 1 &&num == 0){
			lineFlag = 0;
			spaceLineNum++;
			
		}
		
//		//获取空行：只有一个符号的情况，测试不通过 
//  		if(ch == '\n'&&lineFlag == 0){
//			lineFlag = 1;
//		}else if(ispunct(ch)&&lineFlag == 1){
//			num2++;
//		}else if(ch == '\n'&&lineFlag == 1 &&num2 == 1){
//			lineFlag = 0;
//			spaceLineNum++;
//		}
		
		//获取注释行
		if(ch == '//'&&annotateLineFlag==0){
			annotateLineFlag = 1;
		}else if(ch == '\n'&&annotateLineFlag==1){
			annotateLineNum++;
			annotateLineFlag = 0;
		}
		
//		if(ch == '/*'&&annotateLineFlag == 0){
//			annotateLineFlag = 1;
//		}else if(ch == '\n'&&annotateLineFlag == 1){
//			annotateLineNum++;
//		}else if(ch == '*/'&&annotateLineNum == 1){
//			annotateLineNum++;
//			annotateLineFlag = 0;
//		}
    }
    fclose(fp);
}
