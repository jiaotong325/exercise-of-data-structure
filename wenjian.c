#include<stdio.h>
#include<string.h>
int main() {
    FILE* fp = fopen("users.txt", "r+");
    FILE* fp1 = fopen("linshi.txt", "w+");//读写新建一个临时文件
    printf("输入要删除的英语\n");
    char word[20];
    scanf("%s", word);

    char new[20];
    while (fscanf(fp, "%s", new) != EOF) {//从原文件读一个字符到new
        if (strcmp(word, new) != 0) {//不是要删除的内容 
            fprintf(fp1, "%s ", new);        
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("users.txt");
    rename("linshi.txt", "users.txt");
    return 0;
}
