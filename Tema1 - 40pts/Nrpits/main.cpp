#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fcin("nrpits.in");
ofstream fcout("nrpits.out");

// Complexitate timp: O(n)
// Complexitate spatiu: O(n) stiva

// Am ales sa folosesc stack deoarece este o structura de date buna pentru a verifica daca un sir de numere este sortat 
// si pentru ca a fost cea mai usoara structura de date pentru a manipula sirul de numere

int main()
{
    stack<int> s;
    int n, x, cnt = 0;
    fcin >> n;

    fcin>>x;
    s.push(x);

    for(int i = 1; i<n; i++)
    {
        fcin >> x;
        int top = s.top();

        // Verificam daca bagam un element nou stiva noastra va fi mereu sortata descrescator
        if(x < top) {
            s.push(x);
        // Daca gasim un element mai mare decat cel din varful stivei, atunci am gasit un "pit" in drumul nostru
        } else if (!s.empty() && x > top) {
            // iar toate elementele mai mici decat cel curent (x) nu mai sunt relevante pentru ca nu mai putem forma un "pit" cu ele
            // deci le scoatem din stiva ca sa avem doar elemente mai mari decat x si sa pastram conditia noastra initiala
            // adica ca stiva sa fie mereu sortata descrescator
            while(!s.empty() && x > s.top())
            {
                // Ca in drumul sa poata fi considerat un "pit" trebuie sa aiba cel putin 2 elemente in stiva
                if(s.size() > 1)
                    cnt++;
                s.pop();
            }
            s.push(x);
        }
    }
    fcout<<cnt;

    fcin.close();
    fcout.close();
    return 0;
}