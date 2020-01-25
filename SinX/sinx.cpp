//
// Created by olcia on 14.01.2020.
//
#include <random>
#include <iostream>

using namespace std;

int main(){
    const int N = 1000000;
    double u,x,y;
    default_random_engine gen;
    uniform_real_distribution<double> dist(0,1.0);

    const int max = 1000;
    float hist[max] = {0};
    int k;


    for(int i = 0; i < N; i++){
        u = dist(gen);
        x = acos(1-2*u);
        y = sin(x);

        k = y*max;
        if(k < max) {
            hist[k]++;
        }
    }

    for(int i = 0; i < max-1; i++){
        cout << i/double(max) << " " << hist[i]/(double(N)/double(max)) << endl;
    }

}
