//
//  LogIn.cpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 10/10/2023.
//

#include "LogIn.hpp"
#include <string>
#include "ValidationManager.hpp"

bool LogIn::authenticate(){
    std::cout<<"Type in your UserName \n";
    std::cin >> m_username;
    std::cout <<"Type in your Password \n";
    std::cin >> m_password;
    std::ifstream read(m_username + ".txt");
    getline(read,m_user);
    getline(read,m_pass);
    read.close();
    if (m_username == m_user && m_password == m_pass) {
        std::cout<<"Log in successful\n";
        return true;
    }
    else
    {
        std::cout<<"Login Failed Try again\n";
        return false;
    }
};
