#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;
void insert_begin();
void insert_end();
void insert_between();
void display();
int main(){
	NODE *head = NULL;
	int choice;
	struct node *cur = malloc(sizeof(NODE));
	cur = malloc(sizeof(NODE));
	printf("Enter the data");
	scanf("%d", &cur->data);
	head = cur;
	cur->next = head;
	do{
        printf("Enter 1 to insert begin, 2 for insert end 3.Inbetween elemtns 4.display 0.exit\n");
        scanf("%d", &choice);
        switch(choice){
        case 0:
            exit(0);
            break;
        case 1:
            insert_begin(&head);
            break;
        case 2:
            insert_end(&head);
            break;
        case 3:
            insert_between(&head);
            break;
        case 4:
            display(head);
            break;
        }
	}while(choice <= 4);
    return 0;
}
void insert_begin(struct node** head){
    struct node *cur = malloc(sizeof(NODE));
    printf("Enter the data");
    scanf("%d", &cur->data);
    cur->next = *head;
    struct node *ptr = *head;
    while(ptr->next != *head){
        ptr = ptr->next;
    }
    ptr->next = cur;
    *head = cur;
}
void insert_end(struct node** head){
    struct node *ptr = *head;
    struct node *cur = malloc(sizeof(NODE));
    printf("Enter the data");
    scanf("%d", &cur->data);
    while(ptr->next != *head){
        ptr = ptr->next;
    }
    ptr->next = cur;
    cur->next = *head;
}
void insert_between(struct node** head){
    int element;
    int flag = 0;
    struct node *ptr = *head;
    struct node *cur = malloc(sizeof(NODE));
    printf("Enter the data");
    scanf("%d", &cur->data);
    printf("After which element u want to insert\n");
    scanf("%d", &element);
    while(ptr->next != *head){
        if(ptr->data == element){
            flag = 1;
            cur->next = ptr->next;
            ptr->next = cur;
            break;
        }
        ptr = ptr->next;
    }
}
void display(struct node* head){
    struct node *ptr = head;
    while(ptr){
        printf("->%d",ptr->data);
        ptr = ptr->next;
        if(ptr == head)
            break;
    }
}
