#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int charNum = 0; //�ַ��� 
	int wordNum = 0; //������ 
	int lineNum = 0; //����
	int choice; //ѡ�Ϊc����w����l 
	
	FILE *fp; //����һ��ָ���ļ���ָ�����fp 
	
	count(argv[2]);
	scanf("%s%s%s",argv[0],argv[1],argv[2]);
	
	if((fp = fopen(argv[2],"r")) == NULL)
        {    
        printf("cannot open this file\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
        exit(0);
        }
	
	while((choice = getopt(argc, argv, "c::w::l::")) != -1) {//ѡ���ַ����������в��� 
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
		}
	}
	return 0;
}
void count(char * fileName){
	
} 
