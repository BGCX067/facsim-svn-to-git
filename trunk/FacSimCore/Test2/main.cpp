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

class p
{
    public: 
   virtual void abc(){printf("this is form Parents\n") ;} 
}; 
class c: public p
{
    public: 
    void abc(); 
}; 
void c::abc() 
{
    printf("this is form child\n") ; 
} 
void test()
{
    p* pP;
    c z;
    pP=&z;
    //((c*)pP)->abc(); 
    pP->abc();
} 



int main(int argc, char *argv[])
{
    cout<<"OK,sir\n" ;
/*
    simPart *pP=(simPart *)NULL;
    simPart *pP2=pP;
    if(pP2==pP){cout<<"Two Pointer is equal"<<endl;}
    if(pP2==(simPart *)NULL){cout<<"pP2 is equal to NULL"<<endl;} 
    
    test(); 
    
*/
    MyModel();    
    system("PAUSE");
    return EXIT_SUCCESS;
}
