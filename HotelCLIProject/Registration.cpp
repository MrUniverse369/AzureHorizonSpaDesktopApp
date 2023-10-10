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
 
void Registration::CreateUser(){
    
    std::cout<<"Type in userName\n";
    m_username = ValidationManager::CleanInputRW(m_username);
    std::cout<<"Type in password\n";
    m_password = ValidationManager::CleanInputRW(m_password);
    std::cout<<"Type in your first name \n";
    m_fName = ValidationManager::CleanInputAlpha(m_fName);
    std::cout<<"Type in your last name \n";
    m_lName = ValidationManager::CleanInputAlpha(m_lName);
    std::cout<<"Type in your email address \n";
    m_email = ValidationManager::CleanInputEmail(m_email);
   // std::cout<<"Type in your age \n";
  //  std::cin >> m_dateOfBirth;
    writeToFile.open(m_username + ".txt");
    writeToFile << m_username<<std::endl<<m_password<<std::endl<<m_fName<<std::endl<<m_lName<<std::endl<<m_email<<std::endl<<m_dateOfBirth;
    writeToFile.close();
   
};
void Registration::doesUserExist(){
    
};


Registration::Registration(){};
Registration::~Registration(){};
