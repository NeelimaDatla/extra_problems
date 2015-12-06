#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;
void insert(struct node**);
void merge(struct node**,struct node**);
void display(struct node*,struct node*);
int main(){
    NODE *head1 = NULL;
    NODE *head2 = NULL;
	int choice;
	struct node *cur = malloc(sizeof(NODE));
	printf("Enter the data into Linked list 1");
	scanf("%d", &cur->data);
	cur->next = head1;
	head1 = cur;
	struct node *cur2 = malloc(sizeof(NODE));
	printf("Enter the data into linked list 2");
	scanf("%d", &cur2->data);
	cur2->next = head2;
	head2 = cur2;
	do{
        printf("Enter 1 to insert in List1 2. to insert in List 2, 3 for display 4.to merge 0.exit\n");
        scanf("%d", &choice);
        switch(choice){
        case 0:
            exit(0);
            break;
        case 1:
            insert(&head1);
            break;
        case 2:
            insert(&head2);
            break;
        case 3:
            display(head1,head2);
            break;
        case 4:
            merge(&head1,&head2);
            break;
        }
	}while(choice <= 4);
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
void display(struct node *head1,struct node *head2){
    struct node *ptr = head1;
    printf("list 1 is\n");
    while(ptr != NULL){
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    printf("\nList 2 is\n");
    struct node *ptr2 = head2;
    while(ptr2 != NULL){
        printf("%d->",ptr2->data);
        ptr2 = ptr2->next;
    }
}
void merge(struct node** head1,struct node** head2){
    struct node *l1 = *head1;
    struct node *l2 = *head2;
    struct node *head;
    struct node *ptr4;
		if (l1->data < l2->data) {
			head = l1;
		}
		else {
			head = l2;
			l2 = l1;
			l1 = head;
		}
		while (l1->next != NULL && l2 != NULL) {
			if (l1->next->data <= l2->data) {
				l1 = l1->next;
			}
			else {
				ptr4 = l1->next;
				l1->next = l2;
				l2 = ptr4;
			}
		}
		if (l1->next == NULL)
			l1->next = l2;

		printf("The merged list is:\n");
		while(head != NULL){
            printf("%d->",head->data);
            head = head->next;
		}
}
