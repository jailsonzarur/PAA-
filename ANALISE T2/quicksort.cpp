#include <bits/stdc++.h>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

vector<long long> tempos(5);

void troca(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// Retorna a posição do pivo
int particao(int arr[], int e, int d)
{
    int pos = e, pivo = arr[d];

    for (int i = e; i < d; i++)
    {
        if (arr[i] <= pivo)
        {
            troca(arr, pos, i);
            pos++;
        }
    }

    troca(arr, pos, d);

    return pos;
}

void QuickSort(int arr[], int e, int d)
{
    if (e >= d)
        return; // condição de parada

    int q = particao(arr, e, d);
    QuickSort(arr, e, q - 1);
    QuickSort(arr, q + 1, d);
}

double calcularDesvioPadrao(double media) {
    double soma_diferencas_quadradas = 0.0;
    for (long long tempo : tempos) {
        soma_diferencas_quadradas += (tempo - media) * (tempo - media);
    }
    return sqrt(soma_diferencas_quadradas / tempos.size());
}

int main()
{
    int n;
    cin >> n;

    int valores[n];

    mt19937 rng(std::time(nullptr));
    uniform_int_distribution<int> dist(1, 100);

    for (int i = 0; i < 5; i++)
    {
        for (int i = 0; i < n; i++)
        {
            int random_number = dist(rng);
            valores[i] = random_number;
        }

        auto start = steady_clock::now();
        QuickSort(valores, 0, n - 1);
        auto end = steady_clock::now();

        auto elapsed = end - start;
        cout << duration_cast<nanoseconds>(elapsed).count() / 1000000.0 << "ms\n";
        tempos[i] = duration_cast<nanoseconds>(elapsed).count();
    }

    long long soma_tempos = accumulate(tempos.begin(), tempos.end(), 0LL);
    double media_tempos = soma_tempos/5.0;
    double desvio_padrao = calcularDesvioPadrao(media_tempos);
    cout << "Tempo médio: " << media_tempos/1000000.0 << " ms\n";
    cout << "Desvio padrão: " << desvio_padrao/1000000.0 << " ms\n";

    return 0;
}