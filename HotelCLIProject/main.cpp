// hotelAssignment.cpp : Defines the entry point for the console application.

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include "Registration.hpp"
#include "ValidationManager.hpp"
#include "LogIn.hpp"
#include "MainMenue.hpp"


int dog = 100;

std::vector<std::string>::const_iterator conIter;
std::vector<std::string>::iterator iter;
std::ofstream hotelFiles;
std::ifstream hotelFilesRead;
std::vector<std::string> hotelRooms(100, "EMPTY");
int userInput;
LogIn loginOb;
Registration Register;
MainMenue mainMenueObj;
void ViewAllRooms();
void AddCustomersToRooms(std::string customerName, int roomNumber);
void DisplayEmptyRooms();
void DeleteCustomerFromRoom();
void FindRoomFromCustomerName();
void StoreProgramDataToFile();
void LoadProgamDataFromFile();
void SortRoomByAlphabet();
void ER();
int EXIT = 0;
int counter = 0;
char filename[50];
bool loggedIn  = false;

int main()
{
    mainMenueObj.Display();
    return 0;
}



void ViewAllRooms() {
    
     counter = 1;
     std::cout << "Customer name    room number" << std::endl;
    for (conIter = hotelRooms.begin(); conIter <= hotelRooms.end() - 1;  conIter++,counter++)
    {
        std::cout << *conIter<<"                 "<<counter<< std::endl;

    }
}
void AddCustomersToRooms(std::string customerName, int roomNumber) {

    std::cout << "Type in the name of the customer you want to add to the hotel admin" << std::endl;
    hotelRooms[roomNumber] = customerName;
    

}
void DisplayEmptyRooms()
{
    
    iter = hotelRooms.begin();
    counter = 1;
    for (iter = hotelRooms.begin(); iter <= hotelRooms.end() - 1; iter++ ,counter++)
    {
        if (*iter == "EMPTY")
        {
            std::cout << *iter <<"  "<<counter<< std::endl;
        }

    }
    
    
    
}
void DeleteCustomerFromRoom()
{
    std::string customerName;
    std::cin >> customerName;

    //this algorithm finds the customer by namee and sets the iter to refer to the customers room

    iter = find(hotelRooms.begin(), hotelRooms.end(), customerName);
    counter = std::distance(hotelRooms.begin(), iter);

    /*this code checks to see if the customer we searched for exist if they
    do it runs the if statment whi Tch deletes our customer and if the customer
    name  can't be found it returns a error message */

    if (iter != hotelRooms.end())
    {
        std::cout <<*iter<< " Has been removed from the room it is now empty " << "\nhis room number was " << counter + 1 << std::endl;
        hotelRooms.erase(iter);
       
    }
    else
    {
        std::cout << "The customer is not staying in the hotel" << std::endl;
    }
    
    
    
}
void FindRoomFromCustomerName()
{
    std::string customerName;
    std::cin >> customerName;
    iter = find(hotelRooms.begin(), hotelRooms.end(), customerName);
    counter = std::distance(hotelRooms.begin(), iter);

    if (iter != hotelRooms.end())
    {
        std::cout << "The customer is staying in the hotel\nHis name is"<<*iter<<"\nhis room number is "<<counter+1<<std::endl;
    }
    else
    {
        std::cout << "The customer is not staying in the hotel" << std::endl;
    }
    
  
    
}
void StoreProgramDataToFile()
{
    std::string userInput;

    std::cout << "Enter file name and press enter to save"<<std::endl;
    std::cin >> userInput;
    hotelFiles.open(userInput);
    for (iter = hotelRooms.begin(); iter <= hotelRooms.end() - 1; iter++)
    {

        hotelFiles << *iter<<std::endl;
    }
    hotelFiles.close();
    
}
void LoadProgamDataFromFile()
{
    std::cin.ignore();
    std::cin.getline(filename, 50);
    hotelFilesRead.open(filename);
    if (!hotelFilesRead.is_open())
    {
        //exit(EXIT_FAILURE);
        std::cout << "FILE NOT FOUND"<< std::endl;
    }
    else
    {
        std::cout << "FILE  FOUND" << std::endl;
    }

    char word[50];
    hotelFilesRead >> word;
    int i = 0;
    while (hotelFilesRead.good())
    {
        std::cout << word << " \n";
        hotelFilesRead >> word;
        iter = hotelRooms.begin();
        hotelRooms[i] = word;
        ++i;
    }
    hotelFilesRead.close();
    
}
void SortRoomByAlphabet()
{
    std::sort(hotelRooms.begin(),hotelRooms.end());
    

}


struct HotelCustomers{
    std::string CustomerName;
    int roomNumber;
    void storeVals(std::string customerName, int rmNumber) {
        std::cout << "please type in customer name followed by room number" << std::endl;
        std::cin >> customerName;
        std::cin >> roomNumber;
    }
    
};

