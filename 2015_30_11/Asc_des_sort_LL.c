#include<stdio.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;
void insert();
void sort();
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
        printf("Enter 1 to insert, 2 for display 3.to sort,0.exit\n");
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
            sort(&head);
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
void sort(struct node** head){
    struct node *ptr = *head;
    struct node *ptr2 = NULL;
    struct node *ptr3 = NULL;
    while(ptr != NULL){
        if(ptr->data <= ptr->next->data){
            ptr3 = ptr;
        }
        else{
            ptr2 = ptr;
            break;
        }
        ptr = ptr->next;
    }
    struct node* prev = NULL;
    ptr = ptr2;
    struct node* next;
    while (ptr != NULL)
    {
        next  = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    ptr3->next = prev;
}
