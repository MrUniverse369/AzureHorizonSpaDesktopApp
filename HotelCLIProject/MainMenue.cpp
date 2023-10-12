//
//  MainMenue.cpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 12/10/2023.
//

#include "MainMenue.hpp"
#include "AdminMenue.hpp"

AdminMenue adminMenueObj;

int MainMenue::Display(){
    
    std::cout<<"Welcome to Azure HorizonInn \n";
    std::cout <<"1:Login \n2:Register \n3:Exit \n\n";
    std::cin>>m_userInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    switch (m_userInput) {
        case 1:
            if (logInObj.authenticate() == true) {
                adminMenueObj.Display();
                
            }
            else{
                MainMenue::Display();
            }
            break;
        case 2:
            registerObj.CreateUser();
            break;
        case 3:
            return 0;
            break;
        default:
            MainMenue::Display();
            break;
    };
    return 0;
};
