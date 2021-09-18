CC = g++
CFLAGS = -L/usr/local/lib -lyaml-cpp

OperateBank: bank_operations.o main.o user_sign_up.o yml_data_access_and_updating.o
	$(CC) $(CFLAGS) -o OperateBank bank_operations.o main.o user_sign_up.o yml_data_access_and_updating.o

Bank_Operations.o: yamlIncludes.h

Main.o: yamlIncludes.h

User_Sign_Up.o: yamlIncludes.h

Yml_Data_Access_And_Updating.o: yamlIncludes.h
