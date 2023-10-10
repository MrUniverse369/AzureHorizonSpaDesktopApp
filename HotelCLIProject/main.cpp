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



int dog = 100;
std::vector<std::string> hotelRooms(100, "EMPTY");
std::vector<std::string>::const_iterator conIter;
std::vector<std::string>::iterator iter;
std::ofstream hotelFiles;
std::ifstream hotelFilesRead;

int userInput;
LogIn loginOb;
Registration Register;
void LoggedIn();
void MenueSystem();
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

    std::cout<<"Welcome to Azure HorizonInn \n";
    std::cout <<"1:Login \n2:Register \n3:Exit \n\n";
    std::cin>>userInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    switch (userInput) {
        case 1:
            if (loginOb.authenticate() == true) {
                MenueSystem();
            }
            else{
                main();
            }
            break;
        case 2:
            Register.CreateUser();
            break;
        case 3:
            return 0;
            break;
        default:
            main();
            break;
    }
    return 0;
}

void MenueSystem() {
    std::string customerName, tempVer;
    int roomNumber;
    system("CLS");
    std::cout <<"1: View All Rooms\n2: AddCustomersToRooms\n3: DisplayEmptyRooms\n4: DeleteCustomerFromRoom();\n5: FindRoomFromCustomerName\n6: StoreProgramDataToFile\n7: LoadProgamDataFromFile\n8: SortRoomByAlphabet \n9: LogOut"<< std::endl;
    std::cout<<"UserINputVale1"<<userInput<<std::endl;
    std::cin >> userInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    

    switch (toupper(userInput))
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
        AddCustomersToRooms(customerName , roomNumber-1);
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
            std::cout << "LoggedOut" << std::endl;
            main();
            break;

    default:
            main();
        break;
    }
}

void ViewAllRooms() {
    
     counter = 1;
     std::cout << "Customer name    room number" << std::endl;
    for (conIter = hotelRooms.begin(); conIter <= hotelRooms.end() - 1;  conIter++,counter++)
    {
        std::cout << *conIter<<"                 "<<counter<< std::endl;

    }
    MenueSystem();
}
void AddCustomersToRooms(std::string customerName, int roomNumber) {

    std::cout << "Type in the name of the customer you want to add to the hotel admin" << std::endl;
    hotelRooms[roomNumber] = customerName;
    MenueSystem();

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
    MenueSystem();
    
    
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
    
    
    MenueSystem();
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
    
  
    MenueSystem();
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
    MenueSystem();
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
    MenueSystem();
}
void SortRoomByAlphabet()
{
    std::sort(hotelRooms.begin(),hotelRooms.end());
    MenueSystem();

}



/*class HotelCustomers {
public:
    std::string CustomerName;
    int roomNumber;
    void storeVals(std::string customerName, int rmNumber) {
        std::cout << "please type in customer name followed by room number" << std::endl;
        std::cin >> customerName;
        std::cin >> roomNumber;
    }
private:



};*/
struct HotelCustomers{
    std::string CustomerName;
    int roomNumber;
    void storeVals(std::string customerName, int rmNumber) {
        std::cout << "please type in customer name followed by room number" << std::endl;
        std::cin >> customerName;
        std::cin >> roomNumber;
    }
    
};

