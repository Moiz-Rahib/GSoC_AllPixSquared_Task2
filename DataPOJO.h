#ifndef DATAPOJO_H 
#define DATAPOJO_H

//This is a pojo class that will store the data needed from each module
//and will return that data to main for printing purposes
class DataPOJO
{
private:
long long first; //this variable will store first number generated by PRNG
long long second; //this variable will store second number generated by PRNG
char* name; //this variable will store name of the module
public:
DataPOJO();
DataPOJO(long long first,long long second,char* name);
void setFirst(long long first);
void setSecond(long long second);
void setName(char* name);
long long getFirst();
long long getSecond();
char* getName();
};
#endif
