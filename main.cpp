#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

bool arrcheck(int arr[], int t);
int arrchange(int arr[], int t);
int ask(int arr[], int t);

int main()
{
	int t;
	cout << "Input number of array : ";
	cin >> t;
	int *arr = new int[t];
	ask(arr, t);
	if (arrcheck(arr, t))
	{
		cout << "En difference in sequence : " << arr[1] - arr[0];
	}
	else
	{
		arrchange(arr, t);
		for (int i = 0; i < t ; i++)
		{
			cout << arr[i] << endl;
		}
	}
	delete[] arr;
	return 0;
}

bool arrcheck(int arr[] , int t)
{
	int check = arr[1] - arr[0];
	int j = 1;
	for (int i = 0; i < t-1; i++)
	{
			if(arr[j]-arr[i] != check)
			{
				return 0;
			}
			j++;
	}
	return 1;
}

int arrchange(int arr[], int t)
{
	vector <int> myvec;
	int check = arr[1] - arr[0];
	myvec.push_back(check);
	int j = 1;
	int counter = 0 ;
	for (int i = 0; i < t; i++)
	{
		if (arr[j] - arr[i] != check) {
			myvec.push_back(arr[j] - arr[i]);
		}
		j++;
	}
	counter = myvec[0];
	for (int k = 0; k < myvec.size()-1; k++)
	{
		if(myvec[k] <= counter)
		{
			counter = myvec[k];
		}
	}
	for (int i = 0; i < t; i++)
	{
		if (arr[i] % 2 == 0) 
		{
			arr[i] = counter;
	    }
	}
	return *arr;
}

int ask(int arr[], int t)
{
	char result = ' ';
	cout << "do you want to enter an array of use random ? [1/2]";
	cin >> result;
	if (result == '1')
	{
		for (int i = 0; i < t; i++)
		{
			cout << "Enter an array : ";
			cin >> arr[i];
		}
	}
	else
	{
		for (int i = 0; i < t; i++)
		{
			arr[i] = rand();
		}
	}
	return *arr;
}
