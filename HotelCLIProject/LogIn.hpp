//
//  LogIn.hpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 10/10/2023.
//

#ifndef LogIn_hpp
#define LogIn_hpp

#include <stdio.h>
#include <string>
#include "ValidationManager.hpp"
class LogIn : ValidationManager
{
private:
    std::string m_username;
    std::string m_password;
    std::string m_user;
    std::string m_pass;
protected:
    
public:
    bool authenticate();
    
};
#endif /* LogIn_hpp */
