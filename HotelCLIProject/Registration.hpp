//
//  Registration.hpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 07/10/2023.
//

#ifndef Registration_hpp
#define Registration_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include<ctype.h>
#include "ValidationManager.hpp"

class Registration : ValidationManager
{
     
private:
    std::string m_username;
    std::string m_password;
    std::string m_fName;
    std::string m_lName;
    std::string m_email;
    bool m_isInputInvalid;
    std::ofstream writeToFile;
    std::ifstream readFile;
    int m_dateOfBirth;
  
    
public:
    Registration();
   ~Registration();
    void CreateUser();
    void doesUserExist();
};
#endif /* Registration_hpp */
