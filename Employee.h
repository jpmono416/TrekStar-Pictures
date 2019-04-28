#pragma once
#include <string>
#include <ctime>
class Employee
{
public:
	Employee();
	~Employee();
private:
	std::string fullName;
	float salary;
	tm dateOfBirth;
	std::string phoneNumber;
	std::string address;
	std::string postcode;
};

