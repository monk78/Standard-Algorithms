#include <bits/stdc++.h>
	using namespace std;
	void swap(int &a, int &b);
	void QuickSortVecMain(vector<int> &list);
	void QuickSortVec(vector<int> &list, int start, int end);
	int PartitionVec(int bot, int top, int pivot, vector<int> &list);
	void swap(int &a, int&b)
	{

	    int temp = a;

	    a = b;

	    b = temp;

	}

	void QuickSortVec(vector<int> &list, int start, int end)

	{

	    int pivot = list[start];
	    int pivot_point;
	    if (end > start)

	    {

	        pivot_point = PartitionVec(start, end, pivot, list);

	        list[pivot_point] = pivot;

	        QuickSortVec(list, start, pivot_point - 1);

	        QuickSortVec(list, pivot_point + 1, end);

	    }

	}

	int PartitionVec(int bot, int top, int pivot, vector<int> &list)

	{
	    int left = bot;

	    int right = top;
	    while (left < right)
	    {

	        while(pivot < list[right] && right > left)
	        {

	            right--;

	        }
	        swap(list[left], list[right]);

	        while(pivot >= list[left] && left < right)
	        {

	            left++;

	        }
	        swap(list[right], list[left]);

	    }
	    return left;

	}

	int main()

	{
	    vector <int,int> QuickS1;

	    for (int i = 0; i < 32000; i++)
	    {
	        QuickS1.push_back(rand());

	    }
	    QuickSortVec(QuickS1, 0, QuickS1.size() - 1);

	    QuickSortVec(QuickS2, 0, QuickS2.size() - 1);

	    for (int i = 0; i < 40; i++)

	    {

	        cout << QuickS1[i] << " ";

	    }

	    cout << endl;



	    return 0;

	}
