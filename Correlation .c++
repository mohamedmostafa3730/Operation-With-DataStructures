#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    
    // Prompt for the size of arrays
    cout << "\n\t Enter the size of arrays: " << endl;
    cin >> n;
    
    // Dynamic allocation of arrays based on size n
    int* X = new int[n];
    int* Y = new int[n];
    
    // Initialize sums
    int sumX = 0, sumY = 0, sumX1 = 0, sumY1 = 0, sum = 0;

    // Input elements into arrays and calculate sums
    for (int i = 0; i < n; i++) {
        cout << "\n\t Enter the element num " << i << " for first array: " << endl;
        cin >> X[i];

        cout << "\n\t Enter the element num " << i << " for second array: " << endl;
        cin >> Y[i];

        sumX += X[i];
        sumY += Y[i];
        sumX1 += X[i] * X[i];
        sumY1 += Y[i] * Y[i];
        sum += X[i] * Y[i];
    }
    
    // Calculate the correlation coefficient r
    double a = n * sum - (sumX * sumY);
    double b = sqrt(n * sumX1 - sumX * sumX) * sqrt(n * sumY1 - sumY * sumY);

    // Avoid division by zero
    if (b == 0) {
        cout << "r is undefined (division by zero)" << endl;
    } else {
        double r = a / b;
        cout << "r = " << r << endl;
    }
    
    // Clean up dynamic memory
    delete[] X;
    delete[] Y;

    return 0;
}




#include <iostream>
#include <cmath>
using namespace std;
int main()
{
 int n, sumX, sumX1, sumY, sumY1, sum  =0;
 int X[n], Y[n];
 double a, b , r;
 
 cout << "\n \t enter the size of arrays: " << endl;
 cin >> n;
 
 for (int i=0;i<n;i++) {
  
  cout << "\n \t enter the element num " << i << " for frist array " << endl;
  cin >> X[i];
  
  cout << "\n \t enter the element num " << i << " for second array " << endl;
  cin >> Y[i];
  
  sumX += X[i];
  sumY += Y[i];
  
  sumX1 = X[i]*X[i];
  sumY1 = Y[i]*Y[i];
  
  sum = X[1] * Y[i];
 }
 
 a= n * sum - (sumX) * (sumY);
 
 b= sqrt( n * sumX1 - sumX * sumX ) * sqrt(n * sumY1 - sumY * sumY);
 
 r= a / b;
 
 cout << "r= " << r << endl;
 
}
/*
1- Dynamic Memory Allocation: The arrays 𝑋 and 𝑌 are dynamically allocated based on the user input for size n
2- Variable Initialization: The sums are initialized to zero to avoid undefined behavior.
3- Sum Calculations: The sum calculations for sumX1 and sumY1 are fixed to accumulate values correctly.
4- Error Handling: Added a check to prevent division by zero when calculating r.
5- Memory Management: Properly deallocate memory allocated for arrays.
*/