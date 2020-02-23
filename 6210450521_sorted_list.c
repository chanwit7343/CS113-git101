//6210450521 Chanwit Saisin
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *list = NULL;
struct node *sort(struct node *list){
    struct node *ptr1, *ptr2;
    int tmp;
    ptr1 = list;
    while (ptr1 -> next != NULL){
        ptr2 = ptr1 -> next;
        while (ptr2 != NULL){
            if (ptr1 -> data > ptr2 -> data){
                tmp = ptr1 -> data;
                ptr1 -> data = ptr2 -> data;
                ptr2 -> data = tmp;
            }
            ptr2 = ptr2 -> next;
        }
        ptr1 = ptr1 -> next;
    }
    return list; 
}
struct node *create_list(struct node *list){
    struct node *new_node, *ptr;
    int num;
    scanf("%d", &num);
    while (num != -1) {
        new_node = (struct node *) malloc(sizeof(struct node));
        new_node -> data = num;
        if (list == NULL){
            new_node -> next = NULL;
            list = new_node;
        } else {
            ptr = list;
            while (ptr -> next != NULL){ 
                ptr = ptr -> next; //เลื่อนไปท้ายแถว
            }
            ptr -> next = new_node;
            new_node -> next = NULL;
        }
        list = sort(list);
        scanf("%d", &num);
    }
    return list;
}

int main(){
    struct node *tmp;
    for (tmp = create_list(list); tmp; tmp = tmp->next){
        printf("%d\n", tmp->data);
    }
}