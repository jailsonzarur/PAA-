#include <bits/stdc++.h>

using namespace std;

int n;

typedef pair<double, double> dd;

int algoritmoguloso(vector<double> livros)
{
    int i = 0; int j = n-1;
    vector<dd> caixas;
    while(i < j)
    {
        if(livros[i]+livros[j] < 1.000)
        {
            caixas.push_back({livros[i], livros[j]});
            i++; j--;
            cout << "oi" << endl;
        }
        else
        {
            i++;
            caixas.push_back({livros[i], 0});
        }
        if(i == j)
        {
            caixas.push_back({livros[i], 0});
        }
    }
    return caixas.size();
}

int main()
{
    cin >> n;
    vector<double> livros(n);
    for( int i = 0 ; i < n ; i++ )
    {
        double temp; cin >> temp;
        livros.push_back(temp);
    }
    sort(livros.begin(), livros.end(), greater<double>());
    cout << algoritmoguloso(livros) << endl;
}