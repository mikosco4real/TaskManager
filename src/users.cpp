#include "users.h"

// Definitions for users goes here

User::User(std::string aFirstName, std::string aLastName,
	std::string aUsername, std::string aEmail, std::string aPassword,
	std::string aPhone, std::string aAddress, time_t aCreated_at)
{
	this->firstName = aFirstName;
	this->lastName = aLastName;
	this->username = aUsername;
	this->email = aEmail;
	this->password = aPassword;
	this->phone = aPhone;
	this->address = aAddress;
	this->created_at = aCreated_at;
}


User::~User()
{	
	firstName.clear();
	lastName.clear();
	username.clear();
	email.clear();
	password.clear();
	phone.clear();
	address.clear();
	std::cout << "Object is being deleted" << std::endl;
}

/*
// define the setFirstName() function in the User class
void User::setFirstName(std::string name)
{
	// set the firstName variable in the User class to the given argument name
	firstName = name;
}

// define the setLastName() function in the User class
void User::setLastName(std::string surname)
{
	// set the lastName variable in the User class to the given argument surname
	lastName = surname;
}

// define the setUsername() function in the User class
void User::setUsername(std::string username)
{
	// set the username variable in the User class to the given argument username
	username = username;
}

// define the setEmail() function in the User class
void User::setEmail(std::string userEmail)
{
	// set the lastName variable in the User class to the given argument userEmail
	email = userEmail;
}

// define the setPassword() function in the User class
void User::setPassword(std::string UserPassword)
{
	// set the password variable in the User class to the given argument UserPassword
	password = UserPassword;
}

// define the setPhone() function in the User class
void User::setPhone(std::string UserPhone)
{
	// set the phone variable in the User class to the given argument UserPhone
	phone = UserPhone;
}

// define the setAddress() function in the User class
void User::setAddress(std::string UserAddress)
{
	// set the address variable in the User class to the given argument UserAddress
	address = UserAddress;
}

// define the setCreatedAt() function in the User class
void User::setCreatedAt(time_t created_at)
{
	// set the created_at variable in the User class to the given argument created_at
	created_at = created_at;
}*/

void User::registerUser()
{
	//call model
	//created_at
	//model::update(firstName, lastName, username, email, password, phone, address, created_at)


}
void User::update()
{
	//call model
	//created_at
	//model::update(firstName, lastName, username, email, password, phone, address )

}
void User::getUserInfo()
{
	//call model
	//username email
	//model::load(username)

}
void User::resetPassword()
{
	//call model
	//username email as key to identify the user
	//model::load(username)
	//::generateNewPassword(username)

}
void User::updatePassword()
{
	//call model
	//username or email as key to identify the user
	//model::updatePassword(email, newpassword)

}