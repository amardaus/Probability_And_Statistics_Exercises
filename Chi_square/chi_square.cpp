#include <iostream>
#include <random>
#include <cmath>

using namespace std;

float generateY() {
    random_device rd;
    mt19937 gen(rd());
    const int n = 3;

    uniform_real_distribution<float> dist(0.0, 1.0);
    float u1 = dist(gen);
    float u2 = dist(gen);

    float x = sqrt(-2*log(u1))*cos(2*M_PI*u2);
    float y = sqrt(-2*log(u1))*sin(2*M_PI*u2);
    //box-muller transform

    u1 = dist(gen);
    u2 = dist(gen);
    float z = sqrt(-2*log(u1))*sin(2*M_PI*u2);

    float X[n] = {0};
    X[0] = x;
    X[1] = y;
    X[2] = z;


    float Q = 0;
    for (int i = 0; i < n; i++) {
        Q += X[i] * X[i];
    }
    return Q;
}

int main() {
    int N = 100000;

    const int max = 1000;
    float hist[max] = {0};
    int k;

    for(int i = 0; i < N; i++){
        k = generateY()*100;
        if(k < max) {
            hist[k]++;
        }
    }

    for(int i = 0; i < max; i++){
        cout << i/100.0 << " " << hist[i]/1000 << endl;
    }
}
