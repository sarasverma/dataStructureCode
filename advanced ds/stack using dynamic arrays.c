// stacks using dynamic arrays
#include <stdio.h>
#include <stdlib.h>

struct stack{
	int data;
};

int top = -1, capacity = 1, item, i;
struct stack *s;

int isEmpty(){
	if(top == - 1)
		return 1;
	return 0;
}

int isFull(){
	if(top == capacity - 1){
		capacity *= 2; // double capacity
		s = (struct stack *)realloc(s, capacity*sizeof(struct stack));
	}
}

void push(){
	printf("Enter element :");
	scanf("%d", &item);
	
	if(top == capacity -1) isFull(); // increase capacity
	(s + ++top)->data = item;
}

int pop(){
	if(isEmpty()){
		printf("Stack is empty, underflow");
		exit(1);
	}
	return (s + top--)->data;
}

void traverse(){
	if(isEmpty())
		printf("Stack empty !\n");
	else{
		for(i = top; i >= 0; --i)
			printf("%d\n", (s + i)->data);
	}
}

int main(){
	s = (struct stack*)malloc(capacity*sizeof(struct stack));
	
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

