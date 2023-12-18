#include <fstream>
#include <unordered_map>
using namespace std;

ifstream fcin("eqs.in");
ofstream fcout("eqs.out");

int pow(int x)
{
    return x * x * x;
}

int main()
{
    unordered_map<int, int> suma;
    int a1, a2, a3, a4, a5;
    int s = 0, cnt = 0;
    fcin >> a1 >> a2 >> a3 >> a4 >> a5;

    for(int i = -50; i<=50; i++){
        if(i!=0) {
            for(int j = -50; j<=50; j++) {
                if(j!=0) {
                    s = -(a1 * pow(i) + a2 * pow(j));
                    if(suma.find(s) != suma.end()) 
                        suma[s] ++;
                    else
                        suma[s] = 1;
                }
            }
        }
    }

    for(int i = -50; i<=50; i++) {
        if(i!=0) {
            for(int j = -50; j<=50; j++) {
                if(j!=0) {
                    for(int k = -50; k<=50; k++) {
                        if(k!=0) {
                            s = (a3*pow(i) + a4 * pow(j) + a5 * pow(k));
                            if(suma.find(s) != suma.end()) {
                                cnt += suma[s];
                            }
                        }
                    }
                }
            }
        }
    }
    

    fcout << cnt;

    fcin.close();
    fcout.close(); 
    return 0;
}