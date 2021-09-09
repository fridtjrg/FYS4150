#include <algorithm>
#include <iostream>
#include <fstream> //allows for reading and writing files
#include <string> //includes sting library
#include <math.h>
#include <iomanip>

using namespace std;

int main(){

int n = 4;



double a[n-1];  //subdiagonal
double b[n];    //main diagonal
double c[n-1];  //superdiagonal
double g[n];

//filling A matrix
fill_n(a,n-1,-1);
fill_n(b,n,2);
fill_n(c,n-1,-1);


fill_n(g,n,2); //Fill with what?


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


  //prints ans to terminal
  cout << "\n V = (";
  for (int i=0; i<=n-2; i++){

        cout << v[i] << ", ";
    }
  cout << v[-1] << ") \n";


return 0;
}
