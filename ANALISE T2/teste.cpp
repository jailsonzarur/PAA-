#include <bits/stdc++.h>
#include <ctime>
#include <random>

using namespace std;

int main()
{
    mt19937 rng(std::time(nullptr));
    uniform_int_distribution<int> dist(1, 100);

    for(int i = 0; i < 100; ++i)
    {
        int random_number = dist(rng);
        cout << random_number << endl;
    }
    return 0;
}