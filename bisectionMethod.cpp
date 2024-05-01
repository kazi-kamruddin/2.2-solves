#include<bits/stdc++.h>
using namespace std;

double f(float x){
    return(x*x*x*x - 1600*x*x + 466489);
}

int main(){
    float a=19, b=20;
    float root,f0,f1,f2,prevRoot;

    if(f(a)*f(b) > 0)
        cout << "wrong guess" << endl;

    do{
        f1 = f(a);
        f2 = f(b);
        
        root = (a+b)/2;
        f0 = f(root);

        cout << "root = " << root <<  ", f(root) = " << f(root) << endl;

        if(f1*f0<0){
            b = root;
            f2=f0;
        }
        else{
            a = root;
            f1=f0;
        }
        

    }while(abs(f(root)) >= 0.01);

    cout << "final ans, root = " << root << endl;
}