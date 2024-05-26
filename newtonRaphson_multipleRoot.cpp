#include <bits/stdc++.h>
using namespace std;

double horner(vector<double> coeffs, double x) {
    double res = 0;
    for(int i=0 ; i<coeffs.size() ; i++){       //horner f(x) = ...
        res = res*x + coeffs[i];
    } 
    return res;
}

double derivFunc(vector<double> coeffs, double x) {
    double result = 0;
    for (int i = 0; i < coeffs.size() - 1; ++i) {
        result += coeffs[i] * (coeffs.size() - 1 - i) * pow(x, coeffs.size() - 2 - i);
    }
    return result;
}

vector<double> synthDiv(vector<double> coeffs, double root) {
    int n = coeffs.size();
    vector<double> newCoeffs(n - 1);
    newCoeffs[0] = coeffs[0];
    for (int i = 1; i < n - 1; ++i) {
        newCoeffs[i] = coeffs[i] + newCoeffs[i - 1] * root;
    }
    return newCoeffs;
}

int main() {
    vector<double> coeffs = {3,-8,2,5,-1};
    double x = 4,f1,f2;
    double err = 0.000001;
    int n = coeffs.size() - 1;
    int ct=0;
    int it=0;
    while (n > 1) {
        double e;
        do {
            f1 = horner(coeffs, x);
            f2 = derivFunc(coeffs, x);
            double x1 = x - (f1 / f2);
            e = fabs(x1 - x);
            x = x1;
            it++;
        } while (e > err);
         ct++;

        //cout << "iteration :"<< it <<" Root found" << ct <<":" << x  << endl;
        cout << "root "<< ct <<": "<<x<<", iteration No: "<<it<<", ";
        cout << "f(x) = "<<f1<<",  f'(x) = "<<f2<<endl;

        coeffs = synthDiv(coeffs, x);
        n = coeffs.size() - 1;
    }
    
    double finalRoot = -coeffs[1] / coeffs[0];

    //cout << "iteration :"<< it << "  Final root"<<ct+1 <<":"<< -coeffs[1] / coeffs[0] << endl;
    cout << "root "<<++ct<<": "<<finalRoot<<", iteration No: "<<++it<<", ";
    cout << "f(x) = "<<horner(coeffs, finalRoot)<<",  f'(x) = "<<derivFunc(coeffs,finalRoot)<<endl;
    

    return 0;
}