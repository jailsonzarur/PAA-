#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

bool cmp(ii a, ii b)
{
    if(a.s != b.s) return a.s < b.s;
    else return a.f < b.f;

    //sort(v.begin(), v.end(), cmp)
    //Vai ordenar de forma crescente utilizando o second dos pares como parametro
}

int main()
{
    int n; cin >> n;
    vector<ii> v;
    for( int i = 0 ; i < n ; i++ )
    {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);

    int ans = 0;
    int fim = -1;
    for( int i = 0 ; i < n ; i++ )
    {
        if(v[i].f >= fim)
        {
            ans++;
            fim = v[i].s;
            cout << v[i].f << " " << v[i].s << endl;
        }
    }
    cout << ans << endl;
}