#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int charNum = 0; //�ַ��� 
int wordNum = 0; //������ 
int lineNum = 1; //����
int spaceLineNum = 0;//���� 
int annotateLineNum = 0;//ע���� 
int codeLineNum = 0;//������ 

int main(int argc, char *argv[]) {
	
	char choice; 
	
	count(argv[2]);
	otherCount(argv[2]);
	
	while((choice = getopt(argc, argv, "c:w:l::a:")) != -1) {//ѡ���ַ����������в��� 
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
					printf("�ļ��Ŀ�����Ϊ:%d\n�ļ��Ĵ�������Ϊ��%d\n",spaceLineNum,codeLineNum);
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
        printf("read file failed��\n");
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
    			num++;//һ���е������ַ��� 
    	}
    	
    	if(num<1){
    		spaceLineNum++;//���м�һ 
		} else{
			codeLineNum++;//�����м�һ 
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
         
        
		if(ch=='\n'&&charNum!=0){//�������� 
			lineNum++;
		}else if(charNum==0){//�����ļ�����Ϊ0
			lineNum=0;
		}

    }
    fclose(fp);
}
