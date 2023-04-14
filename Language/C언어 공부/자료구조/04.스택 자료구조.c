💙 main.c 💙

#include <stdio.h>
#include "stack.h"

print_stack(const Stack* stack)
{
	printf("Stack : ");
	if (IsEmpty(stack) == true)
		printf("Empty");
	else
		for (int i = 0; i < stack->top; ++i)
			printf("%d ", stack->items[i].key);
	printf("\n");
}

element get_element(const int key)
{
	element new_element;
	new_element.key = key;
	return new_element;
}

int main()
{
	Stack my_stack;

	Initialize(&my_stack);
	print_stack(&my_stack);

	Push(&my_stack, get_element(1));
	print_stack(&my_stack);

	Push(&my_stack, get_element(3));
	print_stack(&my_stack);

	Push(&my_stack, get_element(4));
	print_stack(&my_stack);

	Push(&my_stack, get_element(5));
	print_stack(&my_stack);

	Push(&my_stack, get_element(6));
	print_stack(&my_stack);

	Push(&my_stack, get_element(7));
	print_stack(&my_stack);

	for (int i = 0; i < MAX_STACK_SIZE + 1; ++i)
	{
		printf("Pop : %d\n", Pop(&my_stack).key);
		print_stack(&my_stack);
	}
	return 0;
}


💙 stack.c 💙

#include <stdio.h>
#include "stack.h"

void Initialize(Stack* stack)  // stack에 쌓여있는 모든 것들 초기화
{
	stack->top = 0;  // top을 0으로 두기

	for(int i = 0; i < MAX_STACK_SIZE; ++i)
		stack->items[i].key = -1;
}

bool IsFull(const Stack* stack)  // 스택이 가득 찼음을 알리는 함수
{
	if (stack->top < MAX_STACK_SIZE)
		return true;
	else
		return false;
}

bool IsEmpty(const Stack* stack) // 스택이 비어서 더이상 팝을 못함을 알리는 함수
{
	if (stack->top == 0)
		return true;
	else
		return false;
}

void Push(Stack* stack, element item) // Push
{
	//stack->items[stack->top++].key = item.key; 
	// 이렇게 멤버대 멤버의 복사를 이용 가능

	if(IsFull(stack))
		stack->items[stack->top++].key = item.key;
	else
		printf("Stack is full. Cannot add.\n");
}

element Pop(Stack* stack)
{
	if (IsEmpty(stack))
	{
		Initialize(stack);
		printf("Stack is empty. Cannot remove.\n");
	}
	else
	{
		stack->top--;
	}
	return stack->items[stack->top];
}


💙 stack.h 💙

#pragma once

#include <stdbool.h>
#include "element.h"

#define MAX_STACK_SIZE 5

typedef struct stack
{
	element items[MAX_STACK_SIZE];
	int top;
}Stack;

void Initialize(Stack* stack);
bool IsFull(const Stack* stack);
bool IsEmpty(const Stack* stack);
void Push(Stack* stack, element item);
element Pop(Stack* stack);


💙 element.h 💙

#pragma once

typedef struct
{
	int key;
} element;
