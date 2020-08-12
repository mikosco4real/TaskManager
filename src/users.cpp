#include "users.h"
// Definitions for User goes here

User::User(std::string aFirstName, std::string aLastName,
	std::string aUsername, std::string aEmail, std::string aPassword,
	std::string aPhone, std::string aAddress, time_t aCreated_at)
{
	firstName = aFirstName;
	lastName = aLastName;
	username = aUsername;
	email = aEmail;
	password = aPassword;
	phone = aPhone;
	address = aAddress;
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


void User::registerUser()
{
	
	//Ask for the name
	string resName = validatename();
	firstName = resName;

	//Ask for the name
	string resLastname = validteLastname();
	lastName = resLastname;

	//Ask for the name
	string resUsername = validteUsername();
	username = resUsername;

	//Ask for the name
	string resEmail = validateEmail();
	email = resEmail;

	//Ask for the name
	string resPass = validatePassword("");
	password = resPass;

	//Ask for the name
	string resPhone = validtePhone();
	phone = resPhone;

	//Ask for the name
	string resAddress = validteAddress();
	address = resAddress;

	created_at = time(0);
	
	//call model
	//Read last record to get the Id
	//int lastId = model:getlastId();
	//idUs = lastId + 1;
	//created_at
	//model::addUser(idUs, firstName, lastName, username, email, password, phone, address, created_at)
	 UserModel user;
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
