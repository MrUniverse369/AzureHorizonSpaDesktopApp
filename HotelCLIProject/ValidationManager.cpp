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

std::string ValidationManager::CleanInputRW(std::string& userInput){
    
    do { getline(std::cin,userInput);
        std::cout<<"UserInpiut is:"<<userInput<<std::endl;
        for (int i = 0; i < userInput.size(); i++) {
            if (std::isspace(userInput[i])) {
                std::cout<<"Incorrect Input please make sure your input mathches the convetions required \n";
                m_isInputInvalid = true;
                break;
            }
            else if(userInput.size() - 1){
                m_isInputInvalid = false;
            }
            
    }
   
    }while (m_isInputInvalid);
    
    return userInput;
    
};
std::string ValidationManager::CleanInputAlpha(std::string &userInput){
    do {getline(std::cin,userInput);
        for (int i = 0 ; i < userInput.size(); i++) {
            if (!isalpha(userInput[i])) {
                std::cout<<"Incorrect Input please make sure your input mathches the convetions required \n";
                m_isInputInvalid = true;
                break;
            }
            else if(userInput.size() - 1){
                m_isInputInvalid = false;
            }
            
        }
    } while (m_isInputInvalid);
    return userInput;
};

std::string ValidationManager::CleanInputEmail(std::string& userInput){
    std::regex regexVal("^[a-zA-Z0-9+_.-]+@[a-zA-Z0-9.-]+$");
    
    do {getline(std::cin,userInput);
        if(std::regex_match(userInput,regexVal)){
            std::cout<<"Email is Valid \n";
            m_isInputInvalid = false;
        }
        else{
            std::cout<<"Email is not Valid \n";
            m_isInputInvalid = true;
        }
    } while (m_isInputInvalid);
    
    return  userInput;
};

void ValidationManager::ClearBuffer(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.clear();
};

