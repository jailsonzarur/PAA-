#include <bits/stdc++.h>

using namespace std;

void algoritmoguloso(vector<double> moedas, double troco) {
    vector<double> S(100);
    double soma = 0;
    int n = 0;
    int y = 0;
    double epsilon = 1e-9; 
    while (abs(soma - troco) > epsilon) {
        if(troco >= soma + moedas[n]) {
            S[y] = moedas[n];
            soma += moedas[n];
            y++;
        }
        n++;
    }
    for(int i = 0; i < y; i++) cout << S[i] << " ";
}

int main(){
    vector<double> moedas = {10, 10, 5, 5, 2, 0.75, 0.50, 0.50, 0.50, 0.25, 0.25, 0.10, 0.10, 0.5, 0.01, 0.01};
    double troco; cin >> troco;
    algoritmoguloso(moedas, troco);
    return 0;
}