#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& a)
{
    for (int j = 1; j < a.size(); j++)
    {
        int key = a[j];
        int i = j - 1;
        while (i > 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
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
    insertionSort(a);
    clock_t end = clock();

    double durationMs = (double)(end - start) * 1000 ;

    cout << fixed << setprecision(3);
    cout << "Name : tanvir sheikh"  << endl;
    cout << "ID: C243010"               << endl;
    cout << "Algo Name : Insertion Sort" << endl;
    cout << "Input Time : 10000"          << endl;
    cout << "Sorting time: " << durationMs << " ms" << endl;

    return 0;
}