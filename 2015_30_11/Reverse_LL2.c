#include<stdio.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;
void insert();
void reverse_recursive();
void display();
int main(){
    NODE *head = NULL;
	int choice;
	struct node *cur = malloc(sizeof(NODE));
	printf("Enter the data");
	scanf("%d", &cur->data);
	cur->next = head;
	head = cur;
	do{
        printf("Enter 1 to insert, 2 for display 3.to reverse,0.exit\n");
        scanf("%d", &choice);
        switch(choice){
        case 0:
            exit(0);
            break;
        case 1:
            insert(&head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            reverse_recursive(&head);
            break;
        }
	}while(choice <= 3);
    return 0;
}
void insert(struct node** head){
    struct node *ptr = *head;
    struct node *cur = malloc(sizeof(NODE));
    printf("Enter the data");
    scanf("%d", &cur->data);
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = cur;
    cur->next = NULL;
}
void display(struct node *head){
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
}
void reverse_recursive(struct node** head)
{
    struct node* first;
    struct node* remain;
    if (*head == NULL)
       return;
    first = *head;
    remain  = first->next;

    if (remain == NULL)
       return;

    reverse_recursive(&remain);
    first->next->next  = first;
    first->next  = NULL;
    *head = remain;
}
