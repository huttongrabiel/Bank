# Bank
We Buildin' A Government Monetary Transaction Unit

# Background
Was joking around in the car on a roadtrip a built a ~30 line 'banking system' that was
basically just a calculator that did adding and subtracting. So now I am actually
trying to make my own fictional bank system. 

# Usage
IDK... Clone it and make terrible financial decisions with no repercussions?

Compilation is weird for now. I will make a GNUMakeFile some day in the near future to
make setup easier but for now this works.

```bash
g++ bank_operations.cpp main.cpp -L/usr/local/lib yml_data_access_and_updating.cpp -lyaml-cpp -o OperateBank
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
* There is some sort of precision/addding error when updating the balance of the yaml file
* We need to select whose account it is that is being updated so that it works for many users
* Create a login/sign up page which when completed adds an account to the database
* Create GNUMakefile so that we can compile with make and not the weird g++ compilation process

# WARNING
It does not work at all right now, don't even bother cloning it.
