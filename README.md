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
* Figure out way to stop new users from inputting a username that exists but not knowing a password
and then not being able to sign up. Maybe make the sign up if statement in main.cpp a function so that
it can be called recursively whenever we run across a username/password combination that does not match

# Libraries
* yaml-cpp: [https://github.com/jbeder/yaml-cpp]
