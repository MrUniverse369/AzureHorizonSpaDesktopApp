//
//  Registration.cpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 07/10/2023.
//
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <regex>
#include "Registration.hpp"
#include "Customer.hpp"
Customer CustomerObj;
void Registration::CreateUser(){
    
    std::cout<<"Type in userName\n";
    CustomerObj.setuserName(ValidationManager::CleanInputRW());
    std::cout<<"Type in password\n";
    CustomerObj.setaccPass(ValidationManager::CleanInputRW());
    std::cout<<"Type in your first name \n";
    CustomerObj.setfName(ValidationManager::CleanInputAlpha());
    std::cout<<"Type in your last name \n";
   CustomerObj.setlName( ValidationManager::CleanInputAlpha());
    std::cout<<"Type in your email address \n";
   CustomerObj.setEmail(ValidationManager::CleanInputEmail());
   // std::cout<<"Type in your age \n";
  //  std::cin >> m_dateOfBirth;
    
   // accContainer.push_back(CustomerObj);
    writeToFile.open(CustomerObj.m_getUserName() + ".txt");
    writeToFile << CustomerObj.m_getUserName() <<std::endl<<CustomerObj.m_getaccPass()<<std::endl<<CustomerObj.m_getfName()<<std::endl<< CustomerObj.m_getlName()<<std::endl<<CustomerObj.m_getEmail()<<std::endl;
    writeToFile.close();
   
};
void Registration::doesUserExist(){
    
};


Registration::Registration(){};
Registration::~Registration(){};
