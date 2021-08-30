#include <iostream>
#include <fstream> //allows for reading and writing files
#include <string> //includes sting library

using namespace std;

void iffunction(){
    int mytime;
    string surfix;

    cin >> mytime; //fetching an input

    //example of if/else statements

    if (mytime< 12 && mytime>0){
        cout << "it's " << mytime << "am \n";
    }
    else if (mytime>12 && mytime<24){
        cout << "it's " << mytime-12 <<"pm \n";
    }
    else{
        cout << "please give military time \n";
    }

    //shorthand if/else statement variable = (condition) ? expressionTrue : expressionFalse;
    surfix = (mytime>0 && mytime<12) ? "Surfix is am" : "Surfix is pm";

    cout << surfix;
}

void casefunction(){

    int mynumber = 3;

    /*
    Evaluates switch input towars each case
    and executes the related code block to the
    matching case. if no match is found, the default block
    is run.
    */
    switch(mynumber){
    case 1:
        cout<< "number is 1";
        break;
    case 2:
        cout << "number is 2";
        break;
    case 3:
        cout <<"number is 3";
        break;
    default:
        cout << "could not find the number";
    }
}

void loopfunction(){
    int i=0;
    while (i<=5){
        cout << i << "\n";
        i++;
    }
    //alernativly, where the condition is tested after
    do {
        i--;
        cout << i << "\n";
    }
    while(i>0);

    cout<<" \n \n";

    for (int j=0; j<=5; j++){
        cout<< j << "\n";
    }
}

void arrayfunction(){
    string cars[3] ={"bmw", "volvo","ford"};

    int mynum[3]= {1,2,3};

    cout << cars[0] << mynum[2] <<"\n";

    cars[0] = "opel"; //changing array value

    cout << cars[0] << mynum[2]<<"\n";

    cout << "\n\n All cars:\n";

    for (int i = 0; i<sizeof(cars); i++){
        cout << cars[i]<<"\n";
    }
}

void referancefunction(){
    /*
    using & will copy the memory address of a value
    */
    string food = "pizza";
    string &meal = food;
    cout << &food<< "\n" << &meal << "\n";

    //the pointer sores the memory address of "food"
    string* myptr = &food;
    cout << &food<< "\n" << &meal <<"\n"<< myptr;

    //The pointer can also print out the value at said address
    cout << "\n"<< *myptr<<"\n";

    //by changing the pointer value, we also change the source
    *myptr = "banana";
    cout << "\n"<< food <<"\n";
}

void functioninputs(string myname="Fritjof", int age = 24){
    // if no input is given when the function is called fridtjof 24 will be set as default
    cout << myname << "," << age;
}

void swapref(int &x, int &y){
    //useful function for swapping reference
    int z = x;
    x = y;
    y = z;
}

void classfunction(){
    class games{ //creating the class
        public:
            int releasedate;
            string gamename;
            string developer;
            float rating;
            void printgames(){ //declaring a class funtion
            cout<<gamename<< ", " << developer<<", "<<releasedate<< ", "<< rating<<"\n";
            }


    };

    games game1; //creates object in class

    //filling attributes
    game1.releasedate = 2021;
    game1.gamename = "Battlefield 2042";
    game1.developer = "Electronic Arts";
    game1.rating = 7.2;

    game1.printgames();

    games game2; //creating second object in class

    //filling attributes
    game2.releasedate = 2020;
    game2.gamename = "cyberpunk 2047";
    game2.developer = "CDPR";
    game2.rating = 8.2;

    game2.printgames();


}

void classconstructor(){
    //creating objects using the constructor
    class games{ //creating the class
        public:
            games(string nm, string dev, int y, float rt){ //Class constructor called an object is created
                gamename =nm;
                developer = dev;
                releasedate = y;
                rating = rt;
            }
            int releasedate;
            string gamename;
            string developer;
            float rating;
            void printgames(){ //declaring a class funtion
            cout<<gamename<< ", " << developer<<", "<<releasedate<< ", "<< rating<<"\n";
            }


    };

    games game1("Battlefield 2042", "EA", 2021, 7.2); //creates object in class

    game1.printgames();




}

void privateclass(){
    
class Message{
    private:
        string privatemessage= "hi";
    public:
        void changemessage(string pm){
            privatemessage = pm;
        }
        string getmesssage(){
            return privatemessage;
        }
};

/*
"Privatemessage" is a private attribute,
but we use functions to change or access it. Using the
protected clause, we can let other classes access information,
as poosed to the private.
*/

Message priv1;
priv1.changemessage("fuck you!");

cout<< priv1.getmesssage();

}

void classinhenretence(){
//Base class
class Electronics{
    public:
        int release;
        bool battery;
        string brand;
};
//derived class
class phone: public Electronics{
    public:
        bool smart;
        bool flip;
        int battery_mamp;
};

//derived class(3rd gen)
class phonebrand: public phone{
    public:
        string brand;
        string model;
};

phonebrand phone1;
phone1.release = 2021;
phone1.flip = true;
phone1.brand = "samsung";

/*Thus attributes are inherited through generations.
a derived class can inherit properties from different generations.
using derivedclass: public baseclass1, public baseclass2
*/


}

void readwritefunc(){

    //creating and opening a textfile
    ofstream myfile("practiceRR.txt");

    // writing to file
    myfile << "All work and no play makes Jack a dull boy";

    //closing file
    myfile.close();


    //reading from file
    ifstream myreadfile("practiceRR.txt");

    //reading from text using getline()
    string outtext;
    getline(myreadfile, outtext); //reads one line and saves it in second statement

    cout << outtext;

    myfile.close();

}

void exceprionsf(){

    try {
      int age = 15;
      if (age >= 18) {
        cout << "Access granted - you are old enough.";
      }
      throw age;
    }

    catch (int myNum) {//myNum is copied from throw
      cout << "Access denied - You must be at least 18 years old.\n";
      cout << "Age is: " << myNum;

}

}

int main() {
    int myint = 5; //stores whole values
    float myfloat = 5.5; //stores decimal value
    double mydb = 5.5; //stores decimal values w double accuracy
    char mychar = 'd'; //stores single charecter
    string mystring = "world"; //stores string
    bool myboolean = true; //stores true or false state


  cout << "Hello " << mystring << "!"<< "\n This is a new line"; // Multisting outprint

  //simple calculations
  int x = 5;
  int y = 1, z = 50; // decalring multiple variables

  int sum = x+y+z;


  const int lifevalue= 42; //declares value that cannot later be changed

  cout << "\n------main end------\n\n";

  // remove comment to use function

  //iffunction();
  //casefunction();
  //loopfunction();
  //arrayfunction();
  //referancefunction();
  //functioninputs("Maria", 25);
  //swapref(x,y)
  //classfunction();
  //classconstructor();
  //privateclass();
  //classinhenretence();
  //readwritefunc();
  exceprionsf();

  return 0;
}


/*
Multiline comment
*/
