
#include <iostream>
#include <fstream> //allows for reading and writing files
#include <string> //includes sting library
#include <math.h>
#include <iomanip>
#include <sstream>
#include <chrono>

using namespace std;

int calculate_v(int n);
int create_u(int n);


int main(){
int n;

cout<< "n=";
cin >> n;

create_u(n);
calculate_v(n);

}



int calculate_v(int n){

//------------Task 7------------
  



double x[n], u[n];

ostringstream myreadfilename;
myreadfilename << "xandu_values_n=" << n <<".txt";


//reads values from task2
ifstream myreadfile(myreadfilename.str());
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

  //orginally: g[i] = (u[i-1]-(2*u[i])+u[i+1])/(pow(h,2))
  g[i] = -(u[i-1]-(2*u[i])+u[i+1]); //NBNBNBNB

  }





double a[n-1];  //subdiagonal
double b[n];    //main diagonal
double c[n-1];  //superdiagonal

//filling A matrix
fill_n(a,n-1,-1);
fill_n(b,n,2);
fill_n(c,n-1,-1);

//---------------task 6 algorithm----------------------

double v[n];           //Vector v, same size as b


double b_tilda[n], g_tilda[n];


// by Gaussian elmination:

b_tilda[1] = b[1]; g_tilda[1] = g[1]; //special cases


auto t1 = std::chrono::high_resolution_clock::now();
//forward subst. (total 6*(n-2) flops)
for (int i=2; i<=n-1; i++){ // from 2 to be correct for g, to n-1 beacuse of indexing

  b_tilda[i] = b[i] - ((a[i]/b_tilda[i-1])*c[i-1]);         //3 flops
  g_tilda[i] = g[i] - ((a[i]/b_tilda[i-1])*g_tilda[i-1]);   //3 flops

  }



v[n-1] = g_tilda[n-1]/b_tilda[n-1]; //special case for last elemtns in v(1 flop)


//back subst. (total 3*(n-2) flops)
for (int i=n-2; i>=1; i--){ // from n-2 to not go out of range

      v[i] = (g_tilda[i] - (c[i]*v[i+1]))/(b_tilda[i]);     //3 flops
  }

v[0] = 0; v[n]=0; //applying same boundaries as for u

auto t2 = std::chrono::high_resolution_clock::now();
   
double duration_seconds = std::chrono::duration<double>(t2 - t1).count();

cout << endl << "the calculation took " << duration_seconds <<"s"<<endl;



ofstream mywritefile;

ostringstream myfilename;
myfilename << "xandv_values_n=" << n <<".txt";


mywritefile.open(myfilename.str());

for (int i = 0; i<= n; i++){
    mywritefile<< fixed<< setprecision(3) << x[i] << ", " << setprecision(4) << v[i]<< endl;
}


mywritefile.close();


return 0;
}


int create_u(int n){
//task 2


double x[n]; //defines double precision array for x-values

ostringstream myfilename;
myfilename << "xandu_values_n=" << n <<".txt";

ofstream myfile;

myfile.open(myfilename.str());

for (int i = 0; i< n; i++){

    x[i] = (double) i/n;  //fills x[] with x-values between 0 and 1

    //writes x and u values in file with ", " as sepperator
    myfile<< fixed<< setprecision(3) << x[i] << ", " << setprecision(8) << 1.0-(1.0-exp(-10.0))*x[i] - exp(-10.0*x[i])<< endl;
}

myfile << 1 << ", " << 0.0 << endl; //special condition for boundary

myfile.close();


return 0;
}






