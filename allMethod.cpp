#include <bits/stdc++.h>
using namespace std;

double eps = 0.000001;

double func(double *coeff, double x, int n){
  double res = 0;
 
  for(int i=0 ; i<=n ; i++){       //horner f(x) = ...
    res = res*x + coeff[i];
  }
 
  return res;
}

double derivFunc(double *coeff, double x, int n){
  double res = 0;
 
  for(int i=0 ; i<n ; i++){                 //f'(x) = ...
    res = res*x + (n-i)*coeff[i];
  }
 
  return res;
}

void newtonRaphson(double x0, double *coeff, int n, double eps){
    double derivVal = 0;
    bool derivFlag = false;
    int k = 1;
    
    while(1) {
        derivVal = derivFunc(coeff, x0, n);
        if(derivVal == 0.0) {
            derivFlag = true;
            break;
        }

        double x1 = x0 - func(coeff, x0, n) / derivVal;

        cout << "itr: " << k;
        cout << ", f(x): " << func(coeff, x0, n); 
        cout << ", f'(x): " << derivVal;
        cout << ", current root: " << x0 << endl;
        k++;

        if(abs(x1 - x0) / x1 < eps) break;

        x0 = x1;
    }
    
    if(derivFlag) {
        cout << "wrong initial guess" << endl;
    } else {
        cout << "final root: " << x0 << endl << endl;
    }
}

void secantMethod(double a, double b, double *coeff, int n) {
    int k = 1;
    
    while(1) {
        double c = (a * func(coeff, b, n) - b * func(coeff, a, n)) / (func(coeff, b, n) - func(coeff, a, n));
        
        cout << "itr: " << k;
        cout << ", a: " << a; 
        cout << ", b: " << b;
        cout << ", current root: " << c << endl;
        k++;
        
        if(abs(c - b) / c < eps) break;

        a = b;
        b = c;
    }
    
    cout << "final root: " << b << endl;
}

int main() {
    double coeff[] = {3.1416 / 3, -10 * 3.1416, 0, 800};
    int n = sizeof(coeff) / sizeof(double) - 1;  
    double x0,a,b;
    
    cin >> x0;
    cout << "newton raphson: " << endl;
    newtonRaphson(x0, coeff, n, eps);
    
    cin >> a >> b;
    cout << "secant: " << endl;
    secantMethod(a, b, coeff, n);
}
