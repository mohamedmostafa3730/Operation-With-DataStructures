#include <iostream>
using namespace std;

template<class T>

class ArrayList{
 private:
 T* arr; //pointer of Array
 int cap; //size of Array
 int numOfItem; // number of element 

 //to make biger than Array*2 & copy all of elements from ald array to new array
	
	void expand(){    
		cap *= 2;
		T* temp = new T[cap];
		for (int i = 0; i < numOfItem; i++){
			temp[i] = arr[i];
		}
		delete []arr;
		arr = temp;
	}

public:

 //cons
	ArrayList(){
		cap = 2;
		numOfItem = 0;
		arr = new T[cap];
	}

 //des
	~ArrayList(){
		delete arr;
	}

 //Methods
	void addToLast(T value){
		if (numOfItem == cap){
			expand();
		}
		arr[numOfItem] = value;
		numOfItem++;
	}

	void removeFromLast(){
		numOfItem--;
	}

	void addToFirst(T value){
		if (numOfItem == cap){
			expand();
		}

		for (int i = numOfItem - 1; i >= 0; i--){
			arr[i + 1] = arr[i];
		}

		arr[0] = value;
		numOfItem++;
	}

	void removeFromFirst(){
		for (int i = 0; i < numOfItem - 1; i++){
			arr[i] = arr[i + 1];
		}
		numOfItem--;
	}

	bool search(T value){
		for (int i = 0; i < numOfItem; i++){
			if (arr[i] == value){
				return true;
			}
		}
		return false;
	}

	void print(){
		for (int i = 0; i < numOfItem; i++){
			cout << arr[i] << " ";
		}
		cout << endl;

	}
	
	void setCap(int cap){
		this->cap = cap;
	}

};


int main() {
	ArrayList <int> l;
	for (int i = 10; i <= 90; i+=10) {
		l.addToLast(i);
	}
	l.print();
}