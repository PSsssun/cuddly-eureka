#include <iostream>
#include <string>

const int MinimumPasswordLength = 8;


// this function defines the variable "encrypted" too soon
std::string EncryptPassword(const std::string& password)
{
    using namespace std;        

    cout << "length: " << password.length() << endl;
    if (password.length() < MinimumPasswordLength) {
        throw logic_error("Password is too short");
    }
    string encrypted(password);  // this is perferable
    // do whatever is necessary to place
    // an encrypted version of password in encrypted

    return encrypted;

}


int main() {
    
    std::cout << "Item 25: Postpone variable definitions as long as possible. " << std::endl;
    std::cout << "Password is " << EncryptPassword("youloveme");
   return 0; 

}
