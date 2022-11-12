// stacks using dynamic arrays
#include <stdio.h>
#include <stdlib.h>

struct stack{
	int data;
	struct stack *next;
};

int item, i;
struct stack *s, *top = NULL, *temp, *new;

int isEmpty(){
	if(top == NULL)
		return 1;
	return 0;
}

void push(){
	new = (struct stack*)malloc(sizeof(struct stack));
	printf("Enter element :");
	scanf("%d", &new->data);
	
	// head insertion
	if(s == NULL){
		new->next = NULL;
		s = new;
	} 
	else{
		temp = s;
		top->next = new;
		new->next = NULL;
	}
	top = new;
}

int pop(){
	if(isEmpty()){
		printf("Stack is empty, underflow");
		exit(1);
	}
	// head deletion
	if(s == top){
		free(top);
		top = NULL;
		s = NULL;
	}
	// normal deletion
	else{
		temp = s;
		while(temp->next != top)
			temp = temp->next;
		temp->next = NULL;
		free(top);
		top = temp;
	}
}

void traverse(){
	if(isEmpty())
		printf("Stack empty !\n");
	else{
		temp = s;
		while(temp != NULL){
			printf("%d\n", temp->data);
			temp = temp->next;
		}
	}
}

int main(){
	int choice;
	while(1){
		printf("1.PUSH\t2.POP\t3.TRAVERSE :");
		scanf("%d", &choice);
		switch(choice){
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: traverse();
				break;
			default: free(s);
				exit(1);
		}
	}
	return 0;
}	

