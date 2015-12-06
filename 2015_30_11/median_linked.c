#include<stdio.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *head = NULL;
NODE *cur;
NODE *ptr;
int count = 1;
int main(){
	int choice;
	cur = malloc(sizeof(NODE));
	printf("Enter the data");
	scanf("%d", &cur->data);
	cur->next = head;
	head = cur;
	do{
        printf("Enter 1 to insert, 2 for median 0.exit\n");
        scanf("%d", &choice);
        switch(choice){
        case 0:
            exit(0);
            break;
        case 1:
            insert();
            break;
        case 2:
            median();
            break;
        }
	}while(choice <= 2);
    return 0;
}
void insert(){
    count++;
    ptr = head;
    cur = malloc(sizeof(NODE));
    printf("Enter the data");
    scanf("%d", &cur->data);
    cur->next = NULL;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = cur;
}
void median(){
    ptr = head;
    int median = count / 2;
    int i = 0;
    if(count == 2)
        printf("median is %d %d\n", ptr->data,ptr->next->data);
    while(i != median){
            ptr = ptr->next;
            i++;
        }
    if(count % 2 == 0 && count > 2){
        printf("median is :%d\n",ptr->data);
        ptr = ptr->next;
        printf("median is %d\n",ptr->data);
    }
    else if(count % 2 != 0)
        printf("median is :%d\n",ptr->data);
}
