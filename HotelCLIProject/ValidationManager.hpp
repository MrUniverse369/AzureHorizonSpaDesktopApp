//
//  ValidationManager.hpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 09/10/2023.
//

#ifndef ValidationManager_hpp
#define ValidationManager_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <regex>
class ValidationManager{
private:
    bool m_isInputInvalid;
    std::string m_userInput;
protected:
    std::string CleanInputRW();//returns input with non white spaces
    std::string CleanInputAlpha();//returns input that is alpha only
    std::string CleanInputEmail();//returns input that matches correct email convetions
public:
    void ClearBuffer();//clean buffer after cin is used
};

#endif /* ValidationManager_hpp */
