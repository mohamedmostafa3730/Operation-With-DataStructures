#include <iostream>
using namespace std;
class Array {
        private:
    int size;
    int length;
    int *items;
    public:
    Array(int arrsize) {
        size = arrsize;
        length = 0;
        items = new int[arrsize];
    }
    void fill() {
        int numOfItem;
        cout << " How many items you want to fill " << endl;
        cin >> numOfItem;
        if (numOfItem>size) {
            cout << "You cannot exceed the array size" << endl;
            return;
        }
        else {
            for (int i=0;i<numOfItem;i++) {
                cout<< "Enter item of " << i <<endl;
                cin>>items[i];
                length++;
            }
        }
    }
    void display() {
        cout << " Display Array content " << endl;
        for(int i=0;i<length;i++) {
            cout << items[i] << "\t";
        }
        cout << endl;
    }
    int getSize() {
        return size;
    }
    int getLength() {
        return length;
    }
    int search(int key) {
        int index = -1;
		for(int i=0;i<length;i++) {
			if (items[i]==key) { 
				index = i;
				break;
			}
		}
		return index;
    }
    void append(int newItem) {
        if (length<size) {
            items[length] = newItem;
            length++;
        }
        else {
            cout << " Array is full " << endl;
        }
    }
    void insert(int index,int newItem) {
        if (index>0&&index<size) {
            for (int i=length;i>index;i--) {
                items[i]=items[i-1];
            }
            items[index] = newItem;
            length++;
        }
        else {
            cout << "Error-index out of rande" << endl;
        }
}
    void Dealcat(int index) {
    if(index >= 0 && index < size) {
        for(int i = index ; i < length - 1 ; i++) {
            items[i] = items[i+1];
            length--;
        }
    }
    else {
        cout << " index out of Array range " << endl;
    }
}
    void Enlarge(int newSize) {
        if (newSize<=size) {
            cout << " new size must be larger than current size " << endl;
            return;
        }
        else {
            size = newSize;
            int* old = items;
            items = new int[newSize];
            for (int i=0;i<newSize;i++) {
                items[i]=old[i];
            }
            delete[]old;
        }
    }
    void Merge(Array other) {
        int newSize = size + other.getSize();
        size = newSize;
        int* old = items;
        items = new int[newSize];
        int i;
        for (i=0;i<length;i++) {
            items[i] = old[i];
        }
        delete[]old;
        int j=i;
        for (int i=0;i<other.getLength();i++) {
            items[j++] = other.items[i];
            length++;
        }
    }
};
int main() {
    cout << "Hello This is Array ADT demo" << endl;
    int arrsize;
    cout << " Enter the Array size " << endl;
    cin >> arrsize;
    Array myarray(arrsize);
    myarray.fill();
    myarray.display();
    cout << " the length = " << myarray.getLength() << "\t" 
	     << " the size = " << myarray.getSize() << endl;
	cout << " Enter the element to search it " << endl;
	int key;
	cin >> key;
	int index = myarray.search(key);
	if ( index == -1 ) {
		cout << " this item is not fond " << endl;
	}
	else {
		cout << " the item is " << index << endl;
	}
    int newItem;
    cout << "Enter the new item in the Array " << endl;
    cin >> newItem;
    myarray.append(newItem);
    myarray.display();
    int newItem1,index1;
    cout << "Enter the valeo to insert" << endl; 
    cin >> newItem1;
    cout << "Enter the index to put in " << endl;
    cin >> index1;
    myarray.insert(index1,newItem1);
    myarray.display();
    int index2;
    cout << " Enter the index you need to deleted " << endl;
    cin >> index2;
    myarray.Dealcat(index2);
    myarray.display();
   int newSize;
   cout << " Enter the new size of array " << endl;
   cin >> newSize;
   myarray.Enlarge(newSize);
   cout << " the length = " << myarray.getLength() << "\t" 
	     << " the size = " << myarray.getSize() << endl;
   myarray.display();
  Array other(5);
  other.fill();
  myarray.Merge(other);
  cout << " the length = " << myarray.getLength() << "\t" 
	     << " the size = " << myarray.getSize() << endl;
   myarray.display();
}