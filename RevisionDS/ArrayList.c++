#include <iostream>
using namespace std;

template <class t>

class ArrayList {
    private:
    t* arr;
    int c, n; //c = size of Array n = number of items

    public:
    //cons
    ArrayList() {
        c = 2;
        n = 0;
        arr = new t[cap] // مش فاهمها 
    }
    //Des
    ~ArrayList() {
        delete[]arr;
    }

    //Methods
    void AddToLast(t item) {
        
    }




    
};