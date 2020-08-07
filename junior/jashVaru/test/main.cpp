#include <iostream>

using namespace std;

int *arr = 0;
int fibonacciArr[20] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765};

int search(int startPt, int endPt);
int add(int num1, int num2);

int main()
{
    int arrSize = 0;

    cout << "Enter the size of arr" << endl;
    cin >> arrSize;

    arr = new int[arrSize];

    cout << "Enter data of arr" << endl;
    for(int i = 0; i < arrSize; i++)
    {
    	cin >> arr[i];
    }

    search(0,4);
    add(3,5);
    search(0,4);
}

int search(int startPt, int endPt)
{
	for(int i = startPt; i <= endPt; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(arr[i] == fibonacciArr[j])
			{
				cout << arr[i] << " ";
			}
		}
	}
	cout << endl;
	return 0;
}

int add(int index, int value)
{
	arr[index] = value;
	return 0;
}
