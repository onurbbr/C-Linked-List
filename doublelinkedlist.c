#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *addfront (struct node *head, int key) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = key;
    temp->next = head;
    temp->prev = NULL;
    if (head == NULL)
        head = temp;
    else {
        head->prev = temp;
        head = temp;
    }
    return head;
}

struct node *delete (struct node *head, int key) {
    if (head != NULL) {
        struct node *temp = head;
        if (head->data == key) {
            head = head->next;
            head->prev = NULL;
            free(temp);
        } else {
            while(temp != NULL && temp->data != key)
                temp = temp->next;
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp);
        }
    }
    return head;
}

struct node *destroy(struct node **head) {
    if (!*head)
        return *head;
    else {
        return destroy(&((*head)->next)), *head = NULL;
    }
}

void print (struct node *head) {
    if (head == NULL) {
        printf("Listede eleman yoh\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    head = addfront(head, 5);
    head = addfront(head, 8);
    head = addfront(head, 9);
    head = addfront(head, 6);
    head = addfront(head, 4);
    head = addfront(head, 1);
    head = addfront(head, 3);
    head = addfront(head, 2);
    print(head);
    printf("\n");
    head = delete(head, 6);
    head = delete(head, 8);
    head = delete(head, 1);
    head = delete(head, 3);
    //destroy(&head);
    print(head);
    return 0;
}