#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int charNum = 0; //�ַ��� 
int wordNum = 0; //������ 
int lineNum = 0; //����

int main(int argc, char *argv[]) {
	
	char choice; 
	
	count(argv[2]);
	while((choice = getopt(argc, argv, "c:w:l:")) != -1) {//ѡ���ַ����������в��� 
			switch(choice){
				case 'c':
					printf("�ļ����ַ���Ϊ:%d\n",charNum);
					break;
				case 'w':
					printf("�ļ��ĵ�����Ϊ:%d\n",wordNum);
					break;
				case 'l':
					printf("�ļ�������Ϊ:%d\n",lineNum+1);
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
         
		if(ch=='\n'){
			lineNum++;
		}
    }
    fclose(fp);
}
