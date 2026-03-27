#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& v, int start, int mid, int end)
{
    vector<int> temp(v.size());
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end)
    {
        if (v[i] <= v[j]) temp[k++] = v[i++];  
        else temp[k++] = v[j++];                 
    }
    while (i <= mid) temp[k++] = v[i++];
    while (j <= end) temp[k++] = v[j++];

    for (int i = start; i <= end; i++)
        v[i] = temp[i];
}

void mergeSort(vector<int>& v, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(v, start, mid);
        mergeSort(v, mid + 1, end);
        merge(v, start, mid, end);
    }
}

void dataSet(int n, vector<int>& a)
{
    unordered_set<int> used;

    while (used.size() < n)
    {
        int x = rand() % 1000000 + 1;
        if (used.insert(x).second)
            a.push_back(x);
    }
}

int main()
{
    srand(time(0));
    vector<int> a;
    dataSet(1000, a);

    clock_t start = clock();
    mergeSort(a, 0, a.size() - 1);
    clock_t end = clock();
    double durationMs = (double)(end - start) * 1000 ;
    cout << fixed << setprecision(3);
    cout << "Name : Tanvir Sheikh" << endl;
    cout << "ID: C243010" << endl;
    cout << "Algo Name : Merge Sort" << endl;
    cout << "Input Time : 1000" << endl;
    cout << "Sorting time: " << durationMs << " ms" << endl;

    return 0;
}