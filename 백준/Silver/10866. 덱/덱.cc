#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct Deque
{
	int num;
	struct Deque* next;
}Node;

typedef struct
{
    int size;
	Node* head;
	Node* tail;
}DQ;

void init_Deque(DQ* dq)
{
    dq->size = 0;
	dq->head = NULL;
	dq->tail = NULL;
}

int empty(DQ* dq)
{
	if (dq->head == NULL)
		return 1;
	else
		return 0;
}

void push_front(DQ* dq, int n)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->num = n;
	temp->next = NULL;
	if (dq->head == NULL)
	{
		dq->tail = temp;
	}
	else
	{
		temp->next = dq->head;
	}
	dq->head = temp;
    dq->size++;
}

void push_back(DQ* dq, int n)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->num = n;
	temp->next = NULL;
	if (dq->tail == NULL)
	{
		dq->head = temp;
	}
	else
	{
		(dq->tail)->next = temp;
	}
	dq->tail = temp;
    dq->size++;
}

int pop_front(DQ* dq)
{
	int num;
	if (!empty(dq))
	{
		Node* temp = dq->head;
		num = temp->num;
		if (dq->head == dq->tail)
		{
			dq->head = NULL;
			dq->tail = NULL;
		}
		else
		{
			dq->head = (dq->head)->next;
		}
		free(temp);
        dq->size--;
		return num;
	}
	else
		return -1;
}

int pop_back(DQ* dq)
{
	int num;
	if (!empty(dq))
	{
		Node* temp = dq->tail;
		num = temp->num;
		if (dq->head == dq->tail)
		{
			
			dq->head = NULL;
			dq->tail = NULL;
		}
		else
		{
			Node* search = dq->head;
			for (; search->next != dq->tail; search = search->next)
				;
			dq->tail = search;
			search->next = NULL;
		}
		free(temp);
        dq->size--;
		return num;
	}
	else
		return -1;
}

int size(DQ* dq)
{
	return dq->size;
}


int front(DQ* dq)
{
	if (!empty(dq))
		return (dq->head)->num;
	else
		return -1;
}

int back(DQ* dq)
{
	if (!empty(dq))
		return (dq->tail)->num;
	else
		return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	DQ dq;
	int N, n;
	string x;
	init_Deque(&dq);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == "push_front")
		{
			cin >> n;
			push_front(&dq, n);
		}
		else if (x == "push_back")
		{
			cin >> n;
			push_back(&dq, n);
		}
		else if (x == "pop_front")
			cout << pop_front(&dq) << '\n';
		else if (x == "pop_back")
			cout << pop_back(&dq) << '\n';
		else if (x == "size")
			cout << size(&dq) << '\n';
		else if (x == "empty")
			cout << empty(&dq) << '\n';
		else if (x == "front")
			cout << front(&dq) << '\n';
		else
			cout << back(&dq) << '\n';
	}
	return 0;
}