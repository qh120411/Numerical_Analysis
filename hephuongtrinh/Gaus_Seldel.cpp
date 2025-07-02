#include<iostream>
#include<iomanip>
#include<math.h>

//Gaus-Seldel


/* Arrange systems of linear
   equations to be solved in
   diagonally dominant form
   and form equation for each
   unknown and define here
*/
/* In this example we are solving
   10x + 2y + z = 10
   x + 10y + 2z = 12
   x + y +10z = 8
*/
/* Equations:
   x = -0.2y-0.1z+1
   y = -0.1x-0.2z+1.2
   z = -0.1x-0.1y+0.8
*/
/* Defining function */
#define f1(x,y,z)  (10-2*y-z)/10
#define f2(x,y,z)  (12-x-2*z)/10
#define f3(x,y,z)  (8-x-y)/10
/*
float f1(float x,float y,float z){
	return (-0.2*y-0.1*z+1);
}
float f2(float x,float y,float z){
	return (-0.1*x-0.2*z+1.2);
}
float f3(float x,float y,float z){
	return (-0.1*x-0.1*y+0.8);
}
*/
using namespace std;

int main()
{
 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int it=1;

 cout<< setprecision(6)<< fixed;

 /* Input */
 /* Reading tolerable error */
 cout<<"Nhap sai so: ";
 cin>>e;

 cout<< endl<<"Iter\tx\t\ty\t\tz"<< endl;
 do
 {
  /* Calculation */
  x1 = f1(x0,y0,z0);
  y1 = f2(x1,y0,z0);
  z1 = f3(x1,y1,z0);
  cout<< it<<"\t"<< x1<<"\t"<< y1<<"\t"<< z1<< endl;

  /* Error */
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);
  //err_r=findLargest(e1,e2,e3);
  it++;

  /* Set value for next iteration */
  x0 = x1;
  y0 = y1;
  z0 = z1;
 }while (e1>e || e2>e || e3>e);

 cout<< endl<<"Nghiem: x = "<< x1<<", y = "<< y1<<" and z = "<< z1;
 return 0;
}
