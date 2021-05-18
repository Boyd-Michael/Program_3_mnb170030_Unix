/*
 * Program 3 Source File
 * March 1 2020
 * Michael Boyd
 * mnb170030@utdallas.edu
 * CS 3377.501 Spring 2020
 * Version 1.0
 * Copyright 2020, All Rights Reserved
 *
 * Calling the gawk program, showing that a c++ file
 * can call on the shell.
 *
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

string callShell(const char* cmd);

int main(int argc, char** argv)
{
  //calling programs
 cout << "\nThe call to gawk returned:\n\n" <<  callShell("gawk --version") << endl;
  cout << "\nThe second call to gawk returned: ";
  callShell("gawk -f gawk.code number.txt");
  return 0;
}

string callShell(const char* cmd)
{
  char caught[2000];
  FILE* prog = popen(cmd, "r");
  int x = 0;
  int y = 0;
  string display = "";
  string delimiter = " ";
  string token;
  size_t pos = 0;

  //if the file could not open.
  if(!prog)
    cerr << "Command not executed, program failed.\n";
   else
      {
	while(fgets(caught, sizeof caught, prog) != NULL)
	  {
	    //text file caught sent to string called display
	    display += caught;
	    x++;
	  }
	if(x<14)
	  {
	    while((pos = display.find(delimiter)) != string::npos)
	      {
		//Taking the int
		//token is first int
		//display is second int
		token = display.substr(0, pos);
		display.erase(0, pos + delimiter.length());
  	      }
	    cout << token << " " << display << endl;
	    //changing string to int
	    istringstream(token) >> x;
	    istringstream(display) >> y;
	    cout << "\nThe sum of Column 1: " << x
		 << "\nThe sum of Column 4: " << y << endl;
	    //adding the two int
	    cout << "\nThe Sum of the two number is: " << x + y << "\n" << endl;
	  }
	else;
      }
  //closing file
  pclose(prog);
  return display;
}
