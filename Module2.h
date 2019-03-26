#ifndef Module2_H /* any name uniquely mapped to file name */
#define Module2_H
#include "DataPOJO.h"
#include "BaseModule.h"
#include<random>
#include<future>
#include<thread>
using namespace std;

//this is the derived module from the base module
class Module2:public BaseModule
{
private:
//this pointer to DataPOJO class will contain an object that
////will store all the information required about this module
////that is : first PRNG number generated, Second PRNG Number generated and the Name of the module
DataPOJO* data;
public:
Module2();
void run(promise<DataPOJO*> p,long long seed);
};
#endif
