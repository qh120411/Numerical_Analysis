#include<bits/stdc++.h>

using namespace std;

//jacobi

#define f1(x,y) (8-2.1*y)/6.3;
#define f2(x,y) (9-1.2*x)/4.5; 

int main() {
    float x0 = 0.5, y0 = 1.6, x1 , y1 , e1, e2, e;
    int it = 1;
    cout<< setprecision(6)<< fixed;

    cout<<"Nhap sai so: ";
    cin>>e;
    cout<< endl<<"Iter\tx\t\ty"<< endl;
    do {
        x1 = f1(x0,y0);
        y1 = f2(x0,y0);
        
        cout<< it<<"\t"<< x1<<"\t"<< y1<< endl;

        e1 = fabs(x0-x1);
        e2 = fabs(y0-y1);

        x0 = x1;
        y0 = y1;
        it++;
    }while(it <= 3);

    cout << e1 << ' ' << e2 << ' ' << max(e1,e2) << ' ' << e1-e2;

}