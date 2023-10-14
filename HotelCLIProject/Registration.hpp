//
//  Registration.hpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 07/10/2023.
//

#ifndef Registration_hpp
#define Registration_hpp

#include <stdio.h>
#include "Accounts.hpp"
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include<ctype.h>
#include "ValidationManager.hpp"

class Registration : ValidationManager
{
     
private:
    std::vector<Accounts> accContainer;
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
