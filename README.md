# GSoC_AllPixSquared_Task2

## 1. Prerequisites
* The only dependency required to run this piece of code is a gcc compiler.


## 2. How to run the code
* Open a terminal / Command prompt and browse to the directory where you have unzipped the zip file
* Type cd moizgsoc to enter the folder of the project.
  Note:- replace moizgsoc with any name you have given to the folder while unzipping it.
* Type the following Command for compiling the code:
  * For windows:
    **_g++ -std=c++11 -pthread main.cpp DataPOJO.cpp BaseModule.cpp Module1.cpp Module2.cpp -o main.exe_**
  * For Linux:
    **_g++ -std=c++11 -pthread main.cpp DataPOJO.cpp BaseModule.cpp Module1.cpp Module2.cpp -o main.out_**
* The above command will generate main.out file for Unix and main.exe file for Windows
* Now to run the software:
  * For Windows type:
    **_main.exe_**
  * For Linux type:
    **_./main.out_**
* Now the code will run and ask you to enter the value of ‘n’, enter any integer value for ‘n’. This represents the number of times the event has to repeat itself.
* As you enter the value for ‘n’ and hit enter the code will run by itself and show you the results.


## 3. About the code/Task
* This code is fully developed in c++ using multi threading.
* The source code is available in the zip file (moizgsoc.zip).
* This code runs a series of events in a particular order ‘n’ times where is provided by the user.
* In the output of every event the code will print the output of Base Module and then wait for 5 seconds for Module1 to finish its task as a delay of 5 seconds is given in Module1’s run method to show that the code is printing the value of modules in the same order as they were executed even though they were running in parallel due to Multithreading.
* To achieve the above scenario Thread.join() is used to make the other threads wait that are started after the start of previous thread.
* The code in the source files is well commented for a better understanding of the developer reading it.
* Two images of sample run **‘output1.png’** and **‘output2.png’** are also present in the output folder for reference.
