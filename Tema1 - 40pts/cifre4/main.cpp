#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream fcin("cifre4.in");
ofstream fcout("cifre4.out");

// Complexitate timp: O(4^k)
// Complexitate spatiu: O(4^k) cel mai rau caz pt coada; O(p) pt vectorul de frecvente

long long findSmallestNumber(int n, int p) {
    // Folosim un vector de frecvente de dimensiunea p (pt ca impartim numarul la p, deci putem avea resturi de la 0 la p-1)
    // Il folosim pt a evita sa adaugam in coada numere care au acelasi rest la impartirea la p
    vector<bool> freq(p, false);

    // Folosim o coada pt a genera si procesa prima data numerele mai mici
    queue<long long> q;

    q.push(2);
    q.push(3);
    q.push(5);
    q.push(7);

    while (!q.empty()) {
        long long current = q.front();
        q.pop();

        int remainder = current % p;
        
        // Verific daca restul a mai fost intalnit anterior
        // Nu mai adaugam in coada numere care au acelasi rest la impartirea la p
        // deoarece daca un rest a fost deja generat de un numar, toate numerele generate prin adaugare de cifre suplimentare la acel numar
        // vor avea resturi deja explorate anterior
        if (!freq[remainder]) {
            freq[remainder] = true; 

            if (remainder == n) {
                return current; 
            }

            // Adaugam numerele in coada in ordine crescatoare
            // pt a procesa prima oara pe cele mai mici
            q.push(current * 10 + 2);
            q.push(current * 10 + 3);
            q.push(current * 10 + 5);
            q.push(current * 10 + 7);
        }
    }

    return -1;
}

int main() {

    int T, N, P;
    fcin >> T;

    for (int i = 0; i < T; i++) {
        fcin >> N >> P;
        fcout << findSmallestNumber(N, P) << endl;
    }

    fcin.close();
    fcout.close();

    return 0;
}