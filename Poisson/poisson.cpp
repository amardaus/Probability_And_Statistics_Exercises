#include <iostream>
#include <random>

using namespace std;

int poisson(){
    double lambda = 4;
    double L = exp(-lambda);
    int k = 0;
    double p = 1;
    double u;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0, 1);

    do{
        k++;
        u = dist(gen);
        p = p * u;
    }
    while(p > L);
    return k-1;
}

int main() {
    int N = 1000000;
    const int max = 20;
    float hist[max] = {0};
    int k;

    for(int i = 0; i < N; i++){
        k = poisson();
        if(k < max) {
            hist[k]++;
        }
    }

    for(int i = 0; i < max; i++){
        cout << i << " " << hist[i]/1000000 << endl;
    }
}