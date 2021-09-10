#include <algorithm>
#include <iostream>
#include <fstream> //allows for reading and writing files
#include <string> //includes sting library
#include <math.h>
#include <iomanip>
 

using namespace std;

int main(){

//------------Task 7------------

int n= 100;

double x[n], u[n];

//reads values from task2
ifstream myreadfile("xanduvalues.txt");
string sep = ", ", myText; //defines seperator from task 2

//reads and inserts values for u and x
int i = 0;
while (getline (myreadfile, myText)) {
  x[i] = stod(myText.substr(0, myText.find(sep))); 
  u[i] = stod(myText.substr(myText.find(sep) + sep.length() , -1)); 
  i++;

}

myreadfile.close();



//defines and fills out g
double g[n];

float h = 1./n; //steplength

for (int i=1; i<=n-1; i++){ 

  g[i] = (u[i-1]-2*u[i]+u[i+1])/pow(h,2.);
  }


n = n-2; //because g will have to values less than u beacuse of boundaries.

double a[n-1];  //subdiagonal
double b[n];    //main diagonal
double c[n-1];  //superdiagonal

//filling A matrix
fill_n(a,n-1,-1);
fill_n(b,n,2);
fill_n(c,n-1,-1);

//---------------task 6 algorithm----------------------

double v[n];		   //Vector v, same size as b


double b_tilda[n], g_tilda[n];


// by Gaussian elmination:

b_tilda[0] = b[0]; g_tilda[0] = g[0]; //special cases



//forward subst. (total 6*(n-2) flops)
for (int i=1; i<=n-1; i++){ // from 1 to not go out of range, to n-1 beacuse of indexing

  b_tilda[i] = b[i]- (a[i]/b_tilda[i-1])*c[i-1];			//3 flops
  g_tilda[i] = g[i] - (a[i]/b_tilda[i-1])*g_tilda[i-1];	//3 flops



  }



v[n-1] = g_tilda[n-1]/b_tilda[n-1]; //special case for last elemtns in v(1 flop)

//back subst. (total 3*(n-2) flops)
for (int i=n-2; i>=0; i--){ // from n-2 to not go out of range, to 0

      v[i] = (g_tilda[i] - c[i]*v[i+1])/b_tilda[i];		//3 flops
  }





ofstream mywritefile;


mywritefile.open("xandv_values.txt");

for (int i = 0; i<= n; i++){
    //skips first x-value because we xant calculate v(0) due to boundary
    mywritefile<< fixed<< setprecision(3) << x[i+1] << ", " << setprecision(4) << v[i]<< endl;
}


mywritefile.close();


return 0;
}
