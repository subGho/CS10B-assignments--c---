#include <iostream>

using namespace std;

int specialSum(const int arr[], unsigned size) {
   // Implement me
  int negPosDiff = 0;
  if (size > 0)
  {
    negPosDiff += specialSum(arr+1,size-1);
    if (arr[0] < 0) {negPosDiff--;}  
    else if (arr[0] > 0) {negPosDiff++;}
  }
  return negPosDiff ;
}

int main() {
  int test0[] = { };
  int test1[] = { 1, 2, 3, 4 };
  int test2[] = { -1, -2, -3, -4 };
  int test3[] = { 0, 0, 0, 0 };
  int test4[] = { -1, -2, -3, -4, 1, 2, 3, 4, 0 };
  int test5[] = { 0, -1, -2, -3, -4, 3, 4, 0 };

  cout << "Enter a test case #: ";
  int testCase;
  cin >> testCase;
  cout << endl;

  cout << "Test #" << testCase << " Output: ";
  if (testCase == 0) {
    cout << specialSum(test0, 0) << endl; 
  } else if (testCase == 1) {
    cout << specialSum(test1, 4) << endl;
  } else if (testCase == 2) {
    cout << specialSum(test2, 4) << endl;
  } else if (testCase == 3) {
    cout << specialSum(test3, 4) << endl;
  } else if (testCase == 4) {
    cout << specialSum(test4, 9) << endl;
  } else if (testCase == 5) {
    cout << specialSum(test5, 8) << endl;
  }
}
