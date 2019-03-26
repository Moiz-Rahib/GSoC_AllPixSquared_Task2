#include<iostream>
#include<random>
#include<string>
#include<future>
#include<thread>
#include "DataPOJO.h"
#include "BaseModule.h"
#include "Module1.h"
#include "Module2.h"
using namespace std;

//The main driving method of the whole code
int main ()
{
	int n;//For running events n times;
	DataPOJO* data;//DataPOJO Object used to retrieve and print data of modules
        BaseModule *base;//A base class pointer for storing objects of different modules
        long long temp;//just a temporary variable
	random_device rnd{};//Standard to for providing initializing seed to merssene twister
	cout<<"Please enter the the value of n: ";
	cin>>n;
	cout<<endl;	

        for(int i=0;i<n;i++)
	{
		cout<<"****************"<<"Start of EVENT "<<i+1<<"****************"<<endl;
		mt19937 generator (rnd());//Object and intialisation of Merssene Twister PRNG
	
		//Here we push base module on a thread	
		temp = generator();//seed for module is generated
		base = new BaseModule();
		promise<DataPOJO*> prms1;
		auto ftr1= prms1.get_future();
		thread thrd1(&BaseModule::run,base,move(prms1),temp); //pushing run method on thread with its required arguments
		thrd1.join();//this will make the program wait for thread completion
		data = ftr1.get();//Here future returns the result of run method
		cout<<"Name: "<<data->getName()<<" First: "<<data->getFirst()<<" Second: "<<data->getSecond()<<endl;//here we print the results

		//Here we push module1 on a thread  
		temp = generator();//seed for module is generated
		base = new Module1();
		promise<DataPOJO*> prms2;
		auto ftr2= prms2.get_future();
		thread thrd2(&BaseModule::run,base,move(prms2),temp);//pushing overridden run method on thread with its required arguments
		thrd2.join();//this will make the program wait for thread completion
		data = ftr2.get();//Here future returns the result of run method
		cout<<"Name: "<<data->getName()<<" First: "<<data->getFirst()<<" Second: "<<data->getSecond()<<endl;//here we print the results
		
		//Here we push module2 on a thread  
		temp = generator();//seed for module is generated
		base = new Module2();
		promise<DataPOJO*> prms3;
		auto ftr3= prms3.get_future();
		thread thrd3(&BaseModule::run,base,move(prms3),temp);//pushing overridden run method on thread with its required arguments
		thrd3.join();//this will make the program wait for thread completion
		data = ftr3.get();//Here future returns the result of run method
		cout<<"Name: "<<data->getName()<<" First: "<<data->getFirst()<<" Second: "<<data->getSecond()<<endl;//here we print the results

		cout<<"****************"<<"End of EVENT "<<i+1<<"****************"<<endl;
		cout<<endl;
	}	
	return 0;
}
