#include<stdio.h>
#include<string.h>
int main() {
    FILE* fp = fopen("users.txt", "r+");
    FILE* fp1 = fopen("linshi.txt", "w+");//��д�½�һ����ʱ�ļ�
    printf("����Ҫɾ����Ӣ��\n");
    char word[20];
    scanf("%s", word);

    char new[20];
    while (fscanf(fp, "%s", new) != EOF) {//��ԭ�ļ���һ���ַ���new
        if (strcmp(word, new) != 0) {//����Ҫɾ�������� 
            fprintf(fp1, "%s ", new);        
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("users.txt");
    rename("linshi.txt", "users.txt");
    return 0;
}
