//
//  Accounts.hpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 07/10/2023.
//

#ifndef Accounts_hpp
#define Accounts_hpp

#include <stdio.h>
#include <string>
class Accounts{
private:
    std::string m_userName;
    std::string m_accPass;
    std::string m_fName;
    std::string m_lName;
    std::string m_Email;
    bool  m_isAccCustomer;
    bool m_isAccAdmin;

public:
    void setuserName(std::string m_userName);
    void setaccPass(std::string m_accPass);
    void setfName(std::string m_fName);
    void setlName(std::string m_lName);
    void setEmail(std::string m_email);
    std::string m_getUserName();
    std::string m_getaccPass();
    std::string m_getfName();
    std::string m_getlName();
    std::string m_getEmail();
    virtual void ViewAccDetails() = 0;
    virtual void ResetAccPassword() = 0;

    
};


#endif /* Accounts_hpp */
