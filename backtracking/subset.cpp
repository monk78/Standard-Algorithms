
// CPP program to find all subsets by backtracking.
#include <bits/stdc++.h>
using namespace std;
void subsetsUtil(vector<int>& A, vector<vector<int> >& res,vector<int>& subset, int index)
{
    for (int i = index; i < A.size(); i++) {

        subset.push_back(A[i]);
        res.push_back(subset);

        // move onto the next element.
        subsetsUtil(A, res, subset, i + 1);

        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }

    return;
}

// below function returns the subsets of vector A.
vector<vector<int> > subsets(vector<int>& A)
{
    vector<int> subset;
    vector<vector<int> > res;

    // include the null element in the set.
    res.push_back(subset);

    // keeps track of current element in vector A;
    int index = 0;
    subsetsUtil(A, res, subset, index);

    return res;
}

// Driver Code.
int main()
{
    int i,num;
    // find the subsets of below vector.
    vector<int> arr;
    for(i=0;i<3;i++){
        cin>>num;
        arr.push_back(num);
    }

    // res will store all subsets.
    // O(2 ^ (number of elements inside array))
    // because at every step we have two choices
    // either include or ignore.
    vector<vector<int> > res = subsets(arr);

    // Print result
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}
