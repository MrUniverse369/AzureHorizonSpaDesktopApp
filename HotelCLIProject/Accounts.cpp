//
//  Accounts.cpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 07/10/2023.
//

#include "Accounts.hpp"

void Accounts::setuserName(std::string m_userName){
    this->m_userName = m_userName;
};

void Accounts::setaccPass(std::string m_accPass){
    this->m_accPass = m_accPass;
};
void Accounts::setfName(std::string m_fName){
    this->m_fName;
};

void Accounts::setlName(std::string m_lName){
    this->m_lName = m_lName;
};
void Accounts::setEmail(std::string m_email){
    this->m_Email = m_email;
};

std::string Accounts::m_getUserName(){
    return this->m_userName;
}


std::string Accounts::m_getaccPass(){
 return this->m_accPass;
};

std::string Accounts::m_getfName(){
 return this->m_fName;
};

std::string Accounts::m_getlName(){
 return m_lName;
};
std::string Accounts::m_getEmail(){
 return this->m_Email;
};
