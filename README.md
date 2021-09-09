# Bank
Making a fake banking system with no clue of how banking systems or the general
architecture for online bank services work

# Background
Was joking around in the car on a roadtrip a built a ~30 line 'banking system' that was
basically just a calculator that did adding and subtracting. So now I am actually
trying to make my own fictional bank system. 

# Usage
IDK... Clone it and make terrible financial decisions with no repercussions?

Compilation is weird for now. I will make a GNUMakeFile some day in the near future to
make setup easier but for now this works.

Navigate to the cpp file in the cloned directory and run below command to compile
```bash
g++ bank_operations.cpp main.cpp -L/usr/local/lib yml_data_access_and_updating.cpp -lyaml-cpp -o OperateBank
```

Then Run
```bash
./OperateBank
```

# Why YAML?
I work closely with yaml in my DevOps Internship and I am trying to get better 
using it. At the same time I want to write something in C++ so I used the yaml-cpp
library to access and modiy the yml file that will hold all the user information.

```bash
users:
  identifier:
    stuff : thing
    stuff : thing
```
# To Do
* Fix precision error on the long double value in the yml data base and cpp files
* Create a login/sign up page which when completed adds an account to the database
* Create GNUMakefile so that we can compile with make and not the weird g++ compilation process
* Create signup() function to add new users to the yml database
* Call signup() when user enters username that does not exist in our database but give
them option to reenter in case they mistyped
* Add password key:value pair to yaml database and begin checking for username/password
combinations before updating user bank information
* Finish writing sign up function and file
* Implement sign up function

# Libraries
* yaml-cpp: [https://github.com/jbeder/yaml-cpp]
