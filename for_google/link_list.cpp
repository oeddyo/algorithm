#include <stdio.h>
#include <stdlib.h>
typedef struct my_node{
 	int value;
 	struct my_node *next;
}node;

node *initial_link_list(){
	node *head = (node *) malloc(sizeof(node));
	node *tail = (node *)malloc(sizeof(node));
	head->next = tail;
    head->value = -1;
    tail->value = -1;
	tail->next = tail;
    return head;
}
void print_link_list(node *head){
	printf("Link is ");
	node *cur = head->next;
    printf("%d ",head->value);
	while(cur->next!=cur){
		printf("%d\t", cur->value);
        cur = cur->next;
	}
    printf("%d ",cur->value);
    printf("\n");
}

node *reverse_link_list( node * head ){
    node *cur, *next, *pre;
	pre = head;
	cur = head->next;
	while(cur!=cur->next){
        next = cur->next;
		cur->next = pre;
        pre = cur;
		cur = next;
	}
    cur->next = pre;
    head->next = head;
    return cur;
}

void delete_node(node *head, int pos){
    node *cur = head;
    while(pos>0){
        pos--;
        cur = cur->next;
    }
    if(cur==cur->next){
        printf("can't delete, out range\n");
        return;
    }
    node *t = cur->next;
    cur->next = t->next;
    printf("node %d deleted \n",t->value);
    free(t);
}

void insert_link_list( node *head, int pos, int val){
	//if pos> length of list, insert behind the last one
	node *cur = head;
	// pos starts with 0
	while(pos>0 && cur->next->next!=cur->next){
		pos--;
		cur = cur->next;
	}
    node *x = (node *) malloc(sizeof(node));
    x-> value = val;
    x->next = cur->next;
    cur->next = x;
}


main(){
	//test here
	node *L = initial_link_list();
	insert_link_list(L, 0, 33);
	print_link_list(L);
	insert_link_list(L, 0, 44);
	print_link_list(L);
	insert_link_list(L, 2, 47);
	print_link_list(L);
	insert_link_list(L, 999, 2);
	print_link_list(L);
	
    node *reversed_L = reverse_link_list(L);
    print_link_list(reversed_L);

    delete_node(reversed_L, 2);
    print_link_list(reversed_L);
    delete_node(reversed_L, 333);
    print_link_list(reversed_L);
	
    return 0;
}
