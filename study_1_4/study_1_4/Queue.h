#pragma once
namespace AQueue
{
	struct Node
	{
		struct Node* next;
		int val;
	};

	struct Queue
	{
		struct Node* head;
		struct Node* tail;
	};

	int m;

	void QueueInit(Queue* n)
	{}
	void QueuePush(Queue* n, int val)
	{}
}