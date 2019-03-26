#ifndef BaseModule_H
#define BaseModule_H
#include "DataPOJO.h"
#include<random>
#include<future>
#include<thread>
using namespace std;

//This is the base class that will be inherited by other Modules
class BaseModule
{
private:
//this pointer to DataPOJO class will contain an object that
//will store all the information required about this module
//that is : first PRNG number generated, Second PRNG Number generated and the Name of the module
DataPOJO* data;
public:
BaseModule();
virtual void run(promise<DataPOJO*> p,long long seed);
};
#endif
