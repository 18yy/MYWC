#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int charNum = 0; //�ַ��� 
int wordNum = 0; //������ 
int lineNum = 1; //����
int spaceLineNum = 1;//���� 
int annotateLineNum = 1;

int main(int argc, char *argv[]) {
	
	char choice; 
	
	count(argv[2]);
	while((choice = getopt(argc, argv, "c:w:l:a:")) != -1) {//ѡ���ַ����������в��� 
			switch(choice){
				case 'c':
					printf("�ļ����ַ���Ϊ:%d\n",charNum);
					break;
				case 'w':
					printf("�ļ��ĵ�����Ϊ:%d\n",wordNum);
					break;
				case 'l':
					printf("�ļ�������Ϊ:%d\n",lineNum);
					break;
				case 'a':
					printf("�ļ��Ŀ�����Ϊ:%d\n",spaceLineNum);
					break;	
				case 'b':
					printf("�ļ���ע������Ϊ:%d\n",annotateLineNum);
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
        printf("read file failed��\n");
        exit(-1);
    }
    
    while(!feof(fp)) //���û�������ļ��Ľ�����־  
    {
        ch=fgetc(fp); //���ļ���ȡһ���ַ����ݴ��ڱ���ch��
        
        if((ch >= 'A'&&ch <= 'z')||ispunct(ch)){//�������ĸ���߱����ţ��ַ�����һ 
        	charNum++; 
		}
        
        if(!(ch >= 'A'&&ch <= 'z')){  //����Ƿ���ĸ�ַ�����flagΪ0 
			flag = 0;
		}else if(flag == 0){ //�������ĸ�ַ���flagԭֵΪ0��flag��1����������һ 
			flag = 1; 
			wordNum++;
		}
         
		if(ch=='\n'&&charNum!=0){
			lineNum++;
		}else if(charNum==0){
			lineNum=0;
		}
		
		//��ȡ���� 
		if(ch == '\n'&&lineFlag == 0){
			lineFlag = 1;
		}else if(ch != '\n'&&lineFlag == 1){
			num++;
		}else if(ch == '\n'&&lineFlag == 1 &&num == 0){
			lineFlag = 0;
			spaceLineNum++;
			
		}
		
//		//��ȡ���У�ֻ��һ�����ŵ���������Բ�ͨ�� 
//  		if(ch == '\n'&&lineFlag == 0){
//			lineFlag = 1;
//		}else if(ispunct(ch)&&lineFlag == 1){
//			num2++;
//		}else if(ch == '\n'&&lineFlag == 1 &&num2 == 1){
//			lineFlag = 0;
//			spaceLineNum++;
//		}
		
		//��ȡע����
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
