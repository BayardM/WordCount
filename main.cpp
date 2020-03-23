#include <stdio.h>
#include <stdlib.h>

//�ַ���
int CharacterCount(char filepath[])
{
    FILE *f1 = NULL;
    char c;
    int charcount = 0;
    f1 = fopen(filepath , "r");
    if(f1 == NULL)
    {
        printf("Can't Find!\n");
        exit(1);
    }
    c = fgetc(f1);
    while(c != EOF)
    {
        c = getc(f1);
        charcount++;
    }
    fclose(f1);
    return charcount;
}
//����
int WordCount(char filepath[])
{
    FILE *f2 = NULL;
    char w;
    int wordcount = 0;
    f2 = fopen(filepath , "r");
    if(f2 == NULL)
    {
        printf("Can't Find!\n");
        exit(1);
    }
    w = fgetc(f2);
    while(w != EOF)
    {
        if((w>='A' && w<='Z') || (w>='a' && w<='z') || (w>='0' && w<='9'))
        {
            while((w>='A' && w<='Z') || (w>='a' && w<='z') || (w>='0' && w<='9') || w == '_')
            {
                w = fgetc(f2);
            }
            wordcount++;
        }
        w = fgetc(f2);
    }
    fclose(f2);
    return wordcount;
}
//����
int LineCount(char filepath[])
{
    FILE *f3 = NULL;
    char l;
    int linecount = 1;
    f3 = fopen(filepath , "r");
    if(f3 == NULL)
    {
        printf("Can't Find!\n");
        exit(1);
    }
    l = fgetc(f3);
    while(l != EOF)
    {
        if(l == '\n')
        {
            linecount++;
            l = fgetc(f3);
        }
        else{
            l = fgetc(f3);
        }
    }
    if(CharacterCount(filepath) == 0)
        linecount = 0;
    fclose(f3);
    return linecount;
}

int main()
{
    char command[10] , fileputh[100];
    printf("�˵���c:�ַ��� w:���� l:���� q���˳� \n");
    while(1)
    {
        printf("����������ĸʹ�ù���:");
        scanf("%s", command);
        switch(command[0])
        {
            case 'c':
                printf("�����ļ�·����");
                scanf("%s", fileputh);
                printf("�ַ���Ϊ��%d\n", CharacterCount(fileputh));
                break;
            case 'w':
                printf("�����ļ�·����");
                scanf("%s", fileputh);
                printf("������Ϊ��%d\n", WordCount(fileputh));
                break;
            case 'l':
                printf("�����ļ�·����");
                scanf("%s", fileputh);
                printf("����Ϊ��%d\n", LineCount(fileputh));
                break;
            default:
                if(command[0] != 'q')
                printf("���������������\n");
                break;
        }
        if(command[0] == 'q')
        {
            printf("ʹ�ý�����");
            break;
        }
    }
    return 0;
}
