#include <iostream>
using namespace std;

template <class valeo>

class ArrayList
{
private:
	valeo *Array;
	int SizeOfArray, NumOfElements;

	void Expand()
	{
		SizeOfArray = SizeOfArray * 2;
		valeo *temp = new valeo[SizeOfArray];
		for (int i = 0; i < NumOfElements; i++)
			temp[i] = Array[i];
		delete[] Array;
		Array = temp;
	}

public:
	ArrayList()
	{
		SizeOfArray = 2;
		NumOfElements = 0;
		Array = new valeo[SizeOfArray];
	}

	~ArrayList()
	{
		delete[] Array;
	}

	void AddToFirst(valeo item)
	{
		if (SizeOfArray == NumOfElements)
			Expand();
		for (int i = NumOfElements - 1; i >= 0; i--)
			Array[i + 1] = Array[i];
		Array[0] = item;
		NumOfElements++;
	}

	void AddToLast(valeo item)
	{
		if (SizeOfArray == NumOfElements)
			Expand();
		Array[NumOfElements] = item;
		NumOfElements++;
	}

	void RemoveFromLast()
	{
		NumOfElements--;
	}

	void RemoveFromFirst()
	{
		for (int i = 0; i < NumOfElements - 1; i++)
		{
			Array[i] = Array[i + 1];
			NumOfElements--;
		}
	}

	bool Search(valeo item)
	{
		for (int i = 0; i < NumOfElements; i++)
		{
			if (Array[i] == item)
				return true;
			else
				return false;
		}
	}

	void reverse(valeo Array, int NumOfElements)
	{
		int i = 0;
		int j = NumOfElements - 1;
		int temp;
		for (; i < NumOfElements / 2; i++, j--)
		{
			Array[i] = temp;
			Array[i] = Array[j];
			Array[j] = temp;
		}
	}

	void Print()
	{
		for (int i = 0; i < NumOfElements; i++)
		{
			cout << Array[i] << ", ";
		}
	}
};

int main()
{
	ArrayList<int> A;

	for (int i = 10; i <= 100; i += 10)
	{
		A.AddToFirst(i);
	}
	A.Print();
}