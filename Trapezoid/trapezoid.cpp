#include <iostream>
#include <random>

using namespace std;

double F(double x){
    if(x < -1){
        return 0;
    }
    else if(-1 <= x && x < 0){
        return ((x*x)/2+x+0.5)/3;
    }
    else if(0 <= x && x < 2){
        return (x+0.5)/3;
    }
    else if(2 <= x && x < 3){
        return -1.0/3*x;
    }
    else{   //x > 3
        return 1;
    }
}

double f_1(double y){
    if(y >= 0 && y <= 1.0/6){
        return (-1+sqrt(6*y));
    }
    if(y > 1.0/6 && y <= 5.0/6){
        return (3*y-0.5);
    }
    if(y > 5.0/6 && y <= 1){
        return (3-sqrt(6-6*y));
    }
    return -1;
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0, 1);
    double u, y;

    const int N = 12;              //liczba binow
    double xk = 3.0, x0 = -1.0;
    double hist[N] = {0};
    double w = (xk-x0)/N;   //szerokosc binu
    int j = 0;

    for(int i = 0; i < 10000; i++){
        y = dist(gen);
        u = f_1(y);

        for(j = 0; j < N; j++){
            if((x0+j*w < u)&&(x0+(j+1)*w) > u){
                cout << u << ": " << "[" << x0+j*w << ", " << x0+(j+1)*w << "]" << endl;
                hist[j]++;
                break;
            }
        }
    }

    for(j = 0; j < N; j++){
        cout << hist[j] << endl;
    }
}