#include <gtest/gtest.h>
#include "Payment.h"
#include<sstream>

TEST(PaymentTest, ConstructorInitializesMembers) {
    Payment payment(150.0, "Credit Card");

    EXPECT_EQ(payment.amount, 150.0);
    EXPECT_EQ(payment.paymentMethod, "Credit Card");
}

/*TEST(PaymentTest, CalculateTotalPayment) {
    
    Hotel hotel{"Grand Hotel", "Paris", 150.0};
    Flight flight{"AA123", "New York", "Los Angeles", 300.0};
    Guide guide{"Mike","English", 50.0};
    Transportation transport{"train", 30.0};
    int nights = 3;

    Payment payment(0.0, "Credit Card");
    double total = payment.calculateTotalPayment(hotel, flight, guide, nights, transport);
    payment.amount = total;

    double expectedTotal = (hotel.calculateTotalCost(nights) + flight.price + guide.fee + transport.price);

    EXPECT_DOUBLE_EQ(payment.amount, expectedTotal);
}*/

TEST(PaymentTest, DisplayPaymentDetails) {
    Payment payment(150.0, "Credit Card");
    testing::internal::CaptureStdout();
    payment.displayPaymentDetails();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Payment Method: Credit Card") != std::string::npos);
    EXPECT_TRUE(output.find("Total Amount: $150.00") != std::string::npos);
}