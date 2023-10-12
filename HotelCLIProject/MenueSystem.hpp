//
//  MenueSystem.hpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 12/10/2023.
//

#ifndef MenueSystem_hpp
#define MenueSystem_hpp
#include <iostream>
#include <stdio.h>
#include <string>
#include "Menue.hpp"
#include "MainMenue.hpp"

class MenueSystem{
private:
    MainMenue mc;
protected:
public:
    void MainMenue();
    void AdminMenue();
    void UserMenue();
};
#endif /* MenueSystem_hpp */
