#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct listnode {
	int data;
	struct listnode *next;
} Listnode;
typedef struct queue {
	int size;
	Listnode *front, *rear;
} Queue;
void init_queue(Queue *q) {
	q->size = 0;
	q->front = q->rear = NULL;
}
int is_empty(Queue *q) {
	return q->front == NULL; // return q->size == 0;
}
void enqueue(Queue *q, int data) {
	Listnode *new = (Listnode *)malloc(sizeof(Listnode));
	new->data = data;
	new->next = NULL;
	q->size ++;
	if (q->front == NULL) {
		q->front = q->rear = new;
		return;
	}
	q->rear->next = new;
	q->rear = new;
}
int dequeue(Queue *q) {
	if (is_empty(q)) {
		printf("Underflow\n");
		return INT_MIN;
	}
	Listnode *temp = q->front;
	int return_data = temp->data;
	q->front = q->front->next;
	q->size --;
	free(temp);
	return return_data;
}
int main() {
	/* Add test code */
	return 0;
}
