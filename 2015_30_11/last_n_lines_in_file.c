#include<stdio.h>
int main(){
    FILE *m;
    FILE *fp;
    char t;
    int K;
    printf("Enter the k value");
    scanf("%d", &K);
    int count = 0;
    m = fopen("sample.txt","r");
    if(m == NULL)
        printf("file not fount\n");
    else{
        for (t = getc(m); t != EOF; t = getc(m)){
            if (t == '\n')
                count = count + 1;
        }
    }
    m = fopen("sample.txt","r");
    int count2 = 0;
    int linestart = count - K;
    while((t = fgetc(m)) != EOF){
        if(t == '\n')
            count2++;
        if(count2 == linestart){
            break;
        }
    }
    while((t = fgetc(m)) != EOF){
        printf("%c",t);
    }
    fclose(m);
    return 0;
}
