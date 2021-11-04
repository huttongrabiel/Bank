![:moneybag:](https://www.kindpng.com/picc/m/42-421449_cash-drawing-dirty-money-money-clipart-black-and.png)

# Bank
Making a fake banking system with no clue of how banking systems or the general
architecture for online bank services work

# Background
Was joking around in the car on a roadtrip a built a ~30 line 'banking system' that was
basically just a calculator that did adding and subtracting. So now I am actually
trying to make my own fictional bank system. 

# Usage
IDK... Clone it and make terrible financial decisions with no repercussions?

September 18, 2021. On this fateful day I quit being lazy about learning how to 
build a makefile and finally did it. Behold, now you can be lazy and just run
make and make clean to setup and cleanup this function. Merry christmas. 

Install yaml-cpp dependency
```bash
sudo apt-get install libyaml-cpp-dev
```

Navigate to the 'cpp' directory in the cloned directory and run make
```bash
make
```

Then Run to Start the Bank Simulation
```bash
./OperateBank
```

When Finished With the Program: In The 'cpp' directory Execute The Below Line
```bash
make clean
```

IF MAKE DOESNT WORK
```bash
g++ bank_operations.cpp main.cpp user_sign_up.cpp -L/usr/local/lib yml_data_access_and_updating.cpp -lyaml-cpp -o OperateBank
```

# To Do
* Refactor code, especially main.cpp because it's messy
* Really time to build a GUI for this, but that is so different
it may require a whole new projects just with ideas/basic functions
and design pulled from here. Still deciding. Think it would be really
difficult to add a GUI to this project.
* Build a loan function to simulate a loan
  * Include Interest Rates (Maybe pull current avg loan interest rates off bank website, 
  or just an select a random interest rate from an array of them)
  * Need to have a pool of money that the bank holds, should be added into yaml database  

# Bugs
* error with unsigned int in YAML::

# Future Ideas for This Project
* Build a GUI and in doing so, learn react.js
* User to user transactions, requires encrypting information as is passes between the two 

# Libraries
* yaml-cpp: [https://github.com/jbeder/yaml-cpp]
