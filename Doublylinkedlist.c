#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* insert_at_first(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;

    if (head != NULL) {
        head->prev = ptr;
    }

    return ptr;
}

struct Node* delete_at_first(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Node* ptr = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(ptr);
    return head;
}

struct Node* insert_at_index(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    struct Node* p = head;
    int i = 0;

    while (i != index - 1 && p != NULL) {
        p = p->next;
        i++;
    }

    if (p == NULL) {
        printf("Invalid index.\n");
        free(ptr);
        return head;
    }

    ptr->data = data;
    ptr->next = p->next;
    ptr->prev = p;
    
    if (p->next != NULL) {
        p->next->prev = ptr;
    }

    p->next = ptr;

    return head;
}

struct Node* delete_at_index(struct Node* head, int index) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Node* p = head;
    int i = 0;

    while (i != index - 1 && p != NULL) {
        p = p->next;
        i++;
    }

    if (p == NULL || p->next == NULL) {
        printf("Invalid index.\n");
        return head;
    }

    struct Node* q = p->next;
    p->next = q->next;

    if (q->next != NULL) {
        q->next->prev = p;
    }

    free(q);
    return head;
}

struct Node* insert_at_end(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        ptr->prev = NULL;
        return ptr;
    }

    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = ptr;
    ptr->prev = p;

    return head;
}

struct Node* delete_at_last(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Node* p = head;

    while (p->next != NULL) {
        p = p->next;
    }

    if (p->prev != NULL) {
        p->prev->next = NULL;
    } else {
        head = NULL;
    }

    free(p);
    return head;
}

void printlist(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);

        if (head->next != NULL) {
            printf(" <-> ");
        }

        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = insert_at_first(head, 44);
    head = insert_at_first(head, 55);
    head = insert_at_first(head, 75);
    head = insert_at_end(head, 88);
    head = insert_at_index(head, 46, 2);
    head = delete_at_first(head);
    head = delete_at_index(head, 3);
    head = delete_at_last(head);
    printlist(head);

    return 0;
}
