#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert_at_first(struct node* head,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
}
    ptr->data=data;
    ptr->next=head;
    return ptr;
}
struct node* delete_at_first(struct node* head){
    struct node* ptr =head;
    head=head->next;
    free(ptr);
    return head;

}



struct node* insert_at_index(struct node* head,int data,int index){
    struct node* ptr =(struct node*)malloc(sizeof(struct node)); //creates a empty node with the node structure
    struct node* p = head; 
    int i = 0;

    while (i!=index-1) //iterates to the node before where the new node is inseted
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct node* delete_at_index(struct node* head,int index){
    struct node* p = head;  // creates a pointer at pointing to head
    struct node*q = head->next; //creates a pointer pointing to the next noded of head
    for (int i = 0; i < index-1; i++) //creates a loop to iterate till the desired position
    {
        p = p->next;
        q= q ->next;;
    }
    p->next = q->next; //assigns p->next to q->next so that the prev node of index and next node gets connected
    free(q); //deletes q
    return head;
}

struct node* insert_at_end(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        return ptr;
    }

    struct node* p = head;
    while (p->next != NULL) {
        p = p->next;
    };
    printf("\n");
    p->next = ptr;
    return head;
}

struct node* delete_at_last(struct node* head){
    struct node* p = head;  // creates a pointer at pointing to head
    struct node*q = head->next; //creates a pointer pointing to the next noded of head
    while(q->next!=NULL) //creates a loop to iterate till the desired position
    {
        p = p->next;
        q= q ->next;;
    }
    p->next = NULL; //assigns p->next to NULL 
    free(q); //deletes q
    return head;
}


void printlist(struct node* head){
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;
    head= insert_at_first(head,44);
    head= insert_at_first(head,55);
    head= insert_at_first(head,75);
    head = insert_at_end(head,88);
    head = insert_at_index(head,46,2);
    head= delete_at_first(head);
    head = delete_at_index(head,3);
    head=delete_at_last(head);
    printlist(head);

}
