//
//  Customer.hpp
//  HotelCLIProject
//
//  Created by Thamsanqa Mbano on 13/10/2023.
//

#ifndef Customer_hpp
#define Customer_hpp
#include "Accounts.hpp"
#include <stdio.h>
class Customer : public Accounts{
private:
    void BookRoom();
    void ViewBooking();
    void BookingAvailability();
    void ViewBookingHistory();
protected:
public:
    
    void ViewAccDetails() override;
    void ResetAccPassword() override;
};
#endif /* Customer_hpp */
