//
//  AdminMenue.cpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 12/10/2023.
//
#include "AdminMenue.hpp"
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include "MainMenue.hpp"


int AdminMenue::Display(){
    std::string customerName, tempVer;
    int roomNumber;
    system("CLS");
    std::cout <<"1: View All Rooms\n2: AddCustomersToRooms\n3: DisplayEmptyRooms\n4: DeleteCustomerFromRoom();\n5: FindRoomFromCustomerName\n6: StoreProgramDataToFile\n7: LoadProgamDataFromFile\n8: SortRoomByAlphabet \n9: LogOut"<< std::endl;
    std::cout<<"UserINputVale1"<<m_userInput<<std::endl;
    std::cin >> m_userInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    
           
    switch (toupper(m_userInput))
    {
    case 1:
        std::cout << "this is a list of who is staying in every room" << std::endl;
        ViewAllRooms();
        break;
    case 2:
        std::cout << "You choose Add customer to room"<<std::endl;
        std::cout << "Enter the customer name" << std::endl;
        std::cin >> tempVer;
        customerName = tempVer;
        std::cout << "Enter the customers roomNumber";
        std::cin >> roomNumber;
        AddCustomersToRooms(m_customerName , m_roomNumber-1);
        break;
    case 3:
        std::cout << "display empty rooms"<<std::endl;
        DisplayEmptyRooms();
        break;
    case 4:
        std::cout << "Delete customer from room" << std::endl;
        DeleteCustomerFromRoom();
        break;
    case 5:
        std::cout << "Find room from customer name " << std::endl;
        FindRoomFromCustomerName();
        break;
    case 6:
        std::cout << "Store program DataFile" << std::endl;
        StoreProgramDataToFile();
        break;
    case 7:
        std::cout << "Load Datafile" << std::endl;
        
        
        LoadProgamDataFromFile();
        break;
    case 8:
        std::cout << "sort customer names alphabetially" << std::endl;
        SortRoomByAlphabet();
        break;
           
        case 9:
            mc.Display();
            std::cout << "LoggedOut" << std::endl;
            break;
          
    default:
        
            mc.Display();
        break;
    };
    return 0;
};
void AdminMenue::InitHotelRooms(){
    std::vector<std::string> m_hotelRooms(100, "EMPTY");
    
};

void AdminMenue::ViewAllRooms() {
    std::vector<std::string> m_hotelRooms(100, "EMPTY");
    std::vector<std::string>::const_iterator m_conIter;
    std::vector<std::string>::iterator m_iter;
std::cout << "Customer name    room number" << std::endl;
for (m_conIter = m_hotelRooms.begin(); m_conIter <= m_hotelRooms.end() - 1;  m_conIter++, m_counter++)
{
   std::cout << *m_conIter<<"                 "<<m_counter<< std::endl;

}
    mc.Display();
}

void AdminMenue::DisplayEmptyRooms(){};
void AdminMenue::DeleteCustomerFromRoom(){};
void AdminMenue::StoreProgramDataToFile(){};
void AdminMenue::LoadProgamDataFromFile(){};
void AdminMenue::AddCustomersToRooms(std::string m_customerName, int m_roomNumber){};
void AdminMenue::FindRoomFromCustomerName(){};
void AdminMenue::SortRoomByAlphabet(){};

