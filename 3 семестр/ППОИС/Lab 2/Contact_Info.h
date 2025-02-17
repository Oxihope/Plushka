#pragma once
#include <iostream>

using namespace std;

class Contact_Info {
public:
	Contact_Info(string name) : Name(name), ID(Generate_ID()) {}

	string Get_Name() const;

	int Get_ID() const;

private:
	string Name;
	int ID;

	int Generate_ID();
};