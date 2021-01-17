#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *addfront (struct node *head, int key) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = key;
    temp->next = head;
    head = temp;
    return head;
}

struct node *addlast (struct node *head, int key) {
    if (head == NULL) {
        head = malloc(sizeof(struct node));
        head->data = key;
        head->next = NULL;
    } else {
        struct node *temp = malloc(sizeof(struct node));
        temp->data = key;
        temp->next = NULL;
        struct node *last = head;
        while (last->next != NULL)
            last = last->next;
        last->next = temp;
    }
    return head;
}

struct node *delete (struct node *head, int key) {
    if (head != NULL) {
        struct node *temp = head;
        if (head->data == key) {
            head = head->next;
            free(temp);
        } else {
            while (temp->next != NULL && temp->next->data != key)
                temp = temp->next;
            if (temp->next == NULL)
                return head;
            struct node *delete = temp->next;
            temp->next = delete->next;
            free(delete);
        }
    }
    return head;
}

void listinfo (struct node *head) {
    int i = 1;
    while (head != NULL) {
        printf("\nListenin %d. Dugumunun Adresi: %p", i, head);
        printf("\nListenin %d. Dugumunun verisi: %d", i, head->data);
        printf("\nListenin %d. Dugumunun Bagli oldugu dugumun adresi: %p", i, head->next);
        head = head->next;
        i++;
    }
}

void print (struct node *head) {
    if (head == NULL) {
        printf("Listede eleman yoh");
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
    head = addlast(head, 0);
    print(head);
    printf("\n");
    head = delete(head, 4);
    print(head);
    return 0;
}