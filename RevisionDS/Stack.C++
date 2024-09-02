class DNode
{
public:
	int value;
	DNode* next;
	DNode* prev;
	DNode()
	{
		value = 0;
		next = prev = NULL;
	}

	DNode(int val, DNode* p, DNode* n)
	{
		value = val;
		next = n;
		prev = p;
	}
};


class MyStack
{
	DNode* head;
	DNode* tail;
	int size;
public:
	MyStack()
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
		DNode* temp = tail->prev;
		delete tail;
		tail = temp;
		tail->next = NULL;
		size--;
	}
	int top()
	{
		return tail->value;
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
// Stack FILO	     push,pop,Top,isEmpty,size