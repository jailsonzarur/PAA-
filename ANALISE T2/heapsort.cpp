#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

void heapSort(int arr[], int n)
{
    // Convert array to vector
    vector<int> v(arr, arr + n);

    // Convert vector to Max Heap
    make_heap(v.begin(), v.end());

    // Sort Max Heap
    sort_heap(v.begin(), v.end());

    // Copy sorted vector back to array
    copy(v.begin(), v.end(), arr);
}

int main()
{
    int tam;
    cin >> tam;

    mt19937 rng(std::time(nullptr));
    uniform_int_distribution<int> dist(1, 100);

    int arr[tam];
    for (int i = 0; i < tam; i++)
    {
        int random_number = dist(rng);
        arr[i] = random_number;
    }

    auto start = steady_clock::now();
    heapSort(arr, tam);
    auto end = steady_clock::now();

    for (int i = 0; i < tam; i++)
    {
        cout << arr[i] << endl;
    }

    auto elapsed = end - start;
    cout << duration_cast<nanoseconds>(elapsed).count() / 1000000.0 << "ms\n";
    cout << endl;
}