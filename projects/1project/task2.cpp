
#include <iostream>
#include <fstream> //allows for reading and writing files
#include <string> //includes sting library
#include <math.h>
#include <iomanip>

using namespace std;

int function1(){

double x[1000]; //defines double precision array for x-values

ofstream myfile;

myfile.open("xanduvalues.txt");

int n = sizeof(x)/8; //devides by 8 because sizeof() returns bytes

for (int i = 0; i< n; i++){

    x[i] = (double) i/n;  //fills x[] with x-values between 0 and 1

    //writes x and u values in file with ", " as sepperator
    myfile<< fixed<< setprecision(3) << x[i] << ", " << setprecision(4) << 1.0-(1.0-exp(-10.0))*x[i] - exp(-10.0*x[i])<< endl;
}

myfile << 1 << ", " << 0.0 << endl; //special condition for boundary

myfile.close();

return 0;
}

int main() {
function1(); //calls function1 to complete task 2


  return 0;
}


