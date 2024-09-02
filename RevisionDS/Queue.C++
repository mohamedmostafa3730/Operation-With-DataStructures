class MyQueue
{
	DNode* head;
	DNode* tail;
	int size;
public:
	MyQueue()
	{
		head = tail = NULL;
		size = 0;
	}
	void push(int val)
	{
		DNode* n = new DNode(val, NULL, NULL);
		if (head == NULL)
		{
			head = tail = n;
			return;
		}
		tail->next = n;
		n->prev = tail;
		tail = n;
		size++;
	}
	void pop()
	{
		if (head == NULL)return;
		if (head->next == NULL)
		{
			delete head;
			head = tail = NULL;
		}

		DNode* temp = head->next;
		delete head;
		head = temp;
		head->prev = NULL;
		size--;
	}
	int front()
	{
		return head->value;
	}
	bool isEmpty()
	{
		if (head == NULL || tail == NULL)return true;
		return false;
	}
	int getSize()
	{
		return size;
	}
};
// Queue FIFO        push,pop,Front,isEmpty,size