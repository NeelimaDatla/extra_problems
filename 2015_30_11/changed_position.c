#include<stdio.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;
void insert();
void position_change();
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
        printf("Enter 1 to insert, 2 for display 3.correct the List i.e sort,0.exit\n");
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
            position_change(&head);
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
void position_change(struct node** head){
    struct node *ptr = *head;
    struct node *ptr2;
    struct node *ptr3;
    while(ptr->next != NULL){
        if(ptr->data > ptr->next->data){
            ptr2 = ptr;
            break;
        }
        ptr = ptr->next;
    }
    ptr = ptr2;
    while(ptr->next != NULL){
        if(ptr->data < ptr->next->data){
            ptr3 = ptr;
            break;
        }
        ptr = ptr->next;
    }
    printf("These nodes are to be swapped %d %d :\n",ptr2->data,ptr3->data);
    int x = ptr2->data;
    int y = ptr3->data;
     if (x == y) return;

   NODE *prev1 = NULL;
   NODE *curr1 = *head;
   while (curr1 && curr1->data != x)
   {
       prev1 = curr1;
       curr1 = curr1->next;
   }
   struct node *prev2 = NULL, *curr2 = *head;
   while (curr2 && curr2->data != y)
   {
       prev2 = curr2;
       curr2 = curr2->next;
   }

   if (curr1 == NULL || curr2 == NULL)
       return;

   if (prev1 != NULL)
       prev1->next = curr2;
   else
       *head = curr2;

   if (prev2 != NULL)
       prev2->next = curr1;
   else
       *head = curr1;

   struct node *temp = curr2->next;
   curr2->next = curr1->next;
   curr1->next  = temp;
}
