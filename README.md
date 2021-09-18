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
g++ bank_operations.cpp main.cpp user_sign_up.cpp -L/usr/local/lib yml_data_access_and_updating.cpp -lyaml-cpp -o OperateBank
```
This is mostly here so that I can come here and grab it when I forget

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
* Create and implement transaction count function 
* Create GNUMakefile so that we can compile with make and not the weird g++ compilation process
* Figure out way to stop new users from inputting a username that exists but not knowing a password
and then not being able to sign up. Maybe make the sign up if statement in main.cpp a function so that
it can be called recursively whenever we run across a username/password combination that does not match
* Fix bug where "Login Successful!" is printed to the screen twice when a user signs in
* Test makefile with changes to cpp files

# Libraries
* yaml-cpp: [https://github.com/jbeder/yaml-cpp]
