//
//  AdminMenue.hpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 12/10/2023.
//

#ifndef AdminMenue_hpp
#define AdminMenue_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include "Menue.hpp"
#include "MainMenue.hpp"
#include <vector>

class AdminMenue : Menue {
private:
    int m_userInput;
    int m_roomNumber;
    std::string m_customerName;
    std::vector<std::string> m_hotelRooms(int size, std::string elemVal);
    std::vector<std::string>::const_iterator m_conIter;
    std::vector<std::string>::iterator m_iter;
    int m_counter;
    MainMenue mc;
    void  ViewAllRooms();
    void  AddCustomersToRooms(std::string m_customerName ,int m_roomNumber);
    void DisplayEmptyRooms();
    void DeleteCustomerFromRoom();
    void FindRoomFromCustomerName();
    void StoreProgramDataToFile();
    void LoadProgamDataFromFile();
    void SortRoomByAlphabet();
protected:
public:
    int Display() override;
    void InitHotelRooms();
};
#endif /* AdminMenue_hpp */
