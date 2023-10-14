//
//  ValidationManager.cpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 09/10/2023.
//

#include "ValidationManager.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <regex>

std::string ValidationManager::CleanInputRW(){
    
    do { getline(std::cin,m_userInput);
        std::cout<<"UserInpiut is:"<<m_userInput<<std::endl;
        for (int i = 0; i < m_userInput.size(); i++) {
            if (std::isspace(m_userInput[i])) {
                std::cout<<"Incorrect Input please make sure your input mathches the convetions required \n";
                m_isInputInvalid = true;
                break;
            }
            else if(m_userInput.size() - 1){
                m_isInputInvalid = false;
            }
            
    }
   
    }while (m_isInputInvalid);
    
    return m_userInput;
    
};
std::string ValidationManager::CleanInputAlpha(){
    do {getline(std::cin,m_userInput);
        for (int i = 0 ; i < m_userInput.size(); i++) {
            if (!isalpha(m_userInput[i])) {
                std::cout<<"Incorrect Input please make sure your input mathches the convetions required \n";
                m_isInputInvalid = true;
                break;
            }
            else if(m_userInput.size() - 1){
                m_isInputInvalid = false;
            }
            
        }
    } while (m_isInputInvalid);
    return m_userInput;
};

std::string ValidationManager::CleanInputEmail(){
    std::regex regexVal("^[a-zA-Z0-9+_.-]+@[a-zA-Z0-9.-]+$");
    
    do {getline(std::cin,m_userInput);
        if(std::regex_match(m_userInput,regexVal)){
            std::cout<<"Email is Valid \n";
            m_isInputInvalid = false;
        }
        else{
            std::cout<<"Email is not Valid \n";
            m_isInputInvalid = true;
        }
    } while (m_isInputInvalid);
    
    return  m_userInput;
};

void ValidationManager::ClearBuffer(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.clear();
};

