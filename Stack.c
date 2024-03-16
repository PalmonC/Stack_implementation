#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node * next;
}node;

int isEmpty(node * top){
    return !top;
}

/*Push: When you push a new element onto the stack, you create a new node and make it the new top of the stack. To do this, you must modify the root pointer to point to this new node.
 If you were to pass root as a single pointer, the function would receive a copy of the pointer, and changes made to this copy wouldn't affect the original root pointer outside the function.
 By passing a double pointer, you're passing the address of the root pointer itself, allowing the function to modify the original root pointer to point to the new top node.*/
bool push(int input, node ** top){
    node *new_node = (node *) malloc(sizeof(node));
    new_node->value = input;
    if (*top == NULL){
        *top = new_node;
        new_node->next = NULL;
        return true;
    }
    new_node->next = *top;
    *top = new_node;
    return true;
}

int pop(node ** top){
    if(isEmpty(*top))
    {
        return 69;
    }
    else
    {
        node* temp = * top;
        * top = (* top)->next;
        int top_num = temp->value;
        free(temp);
        return top_num;
    }
}

bool peek(node * top){
    if (!isEmpty(top)){
        printf("\ntop number = %D\n", top->value);
        return true;
    }
    printf("Stack is empty\n");
    return false;
}

int main(){
    node * top = NULL;
    push(3, &top);
    push(2, &top);
    push(1, &top);
    push(0, &top);
    peek(top);
    printf("item popped = %d\n", pop(&top));
    peek(top);
    printf("item popped = %d\n", pop(&top));
    peek(top);
    printf("item popped = %d\n", pop(&top));
    peek(top);
    printf("item popped = %d\n", pop(&top));
    peek(top);
}