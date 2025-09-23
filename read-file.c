#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100];
    FILE *se = fopen("E:\\vscode project\\cpp2\\pratice.c","r+");
    if(se == NULL){
        printf("文件打开失败");
        exit(1);
    }
    //fscanf(se,"%[^\n]",str);
    while(fgets(str,sizeof(str),se) != NULL){
        printf("%s",str);
    }
    fclose(se);
    return 0;
}