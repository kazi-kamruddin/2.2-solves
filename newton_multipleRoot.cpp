#include <bits/stdc++.h>
using namespace std;

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

int main() {
    double coeff[] = {3.1416/3, -10*3.1416, 0, 800};
    int n = sizeof(coeff) / sizeof(double) - 1,k=1;
   
    double x0,prevRoot,root,x1,derivVal=0,derivFlag=0;
    double eps = 0.000001;
    cin >> x0;
   
    while(n>0){
        while(1){
          derivVal = derivFunc(coeff,x0,n);
          if(derivVal == 0.0) {
              derivFlag = 1; break;
          }
         
          x1 = x0 - func(coeff,x0,n)/derivFunc(coeff,x0,n);
         
          if(abs(x1-x0)/x1 < eps) break;
         
          x0 = x1;
         
          cout << "current root: " << x0 << endl;
        }
       
        if(derivFlag == 1)  cout << "wrong initial guess";
        else{
          cout << "iteration no: " << k << endl;
          cout << "f(x): " << func(coeff,x0,n) << endl; 
          cout << "f'(x): " << derivFunc(coeff,x0,n) << endl;
          cout << "final root: " << x0 << endl;
          k++;
        }  
     
        double temp[n+1];
        temp[0] = coeff[0];
       
        for(int i=1 ; i<=n; i++){
            temp[i] = temp[i-1]*x1 + coeff[i];
        }
        n--;
       
        cout << endl;
        for(int i=0 ; i<=n ; i++){
            coeff[i] = temp[i];
            //cout << i << " : " << coeff[i] << endl;
        }
        cout << endl;
    }
}