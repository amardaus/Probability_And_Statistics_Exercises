#include <iostream>
#include <random>

using namespace std;

constexpr int R = 1;

double countPI(int N){
    double x, y;
    double pi;
    int ok = 0;

    default_random_engine generator;
    uniform_real_distribution<> distribution(0, R);

    for(int i = 0; i < N; i++){
        x = distribution(generator);
        y = distribution(generator);
        if(x <= sqrt(1-y*y)){
            ok++;
        }
    }

    pi = (4.0*ok)/N;
    return pi;
}

int main() {
    for(int i = 1; i < 8; i++){
        cout << countPI(pow(10,i)) << endl;
    }
}