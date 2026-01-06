#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double mean = 0;
    double standardD = 0;
    double geometricM = 0;
    double harmonicM = 0;
    double max = A[0], min = A[0];

    for(int i = 0 ; i < N ; i++){
        mean += A[i];
        standardD += A[i] * A[i];
        geometricM += log(A[i]);
        harmonicM += 1/A[i];
        if(A[i]>max) max = A[i];
        if(A[i]<min) min = A[i];
    }

    B[0] = mean/N;
    B[1] = sqrt(standardD / N-B[0]*B[0]);
    B[2] = exp(geometricM/N);
    B[3] = N/harmonicM;
    B[4] = max;
    B[5] = min;
}
