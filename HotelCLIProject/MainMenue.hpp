//
//  MainMenue.hpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 12/10/2023.
//
#ifndef MainMenue_hpp
#define MainMenue_hpp




#include <stdio.h>
#include <iostream>
#include "LogIn.hpp"
#include "Menue.hpp"
#include "Registration.hpp"
class MainMenue : Menue {
private:
    int m_userInput;
    LogIn logInObj;
    Registration registerObj;
   
protected:
public:
    int Display() override;
    void Donkey();
};
#endif /* MainMenue_hpp */
