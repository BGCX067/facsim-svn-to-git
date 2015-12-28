#include <cstdlib>
#include <iostream>
#include <vector>


#include "simPart.h" 


#include "simobject.h"
#include "simmachine.h"
#include "simevent.h"
#include "simpart.h"
#include "simqueue.h"
#include "simclock.h"


#include "simeventlist.h"
#include "simobjectlist.h"

#include "simmodel.h"
using namespace std;

simModel theModel; 


extern void MyModel();


int main(int argc, char *argv[])
{
    cout<<"========================================\n";
	cout<<"||========  FacSim Core Test =========||\n" ;
	cout<<"||    http://code.google.com/p/facsim/||\n";
	cout<<"||    http://facsim.blogspot.com/     ||\n";
	 cout<<"=================2009=================\n\n";
    MyModel();    
    system("PAUSE");
    return EXIT_SUCCESS;
}
