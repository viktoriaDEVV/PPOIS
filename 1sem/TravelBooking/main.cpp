#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "BookingTest.h"
#include "ReviewTest.h"
#include "PaymentTest.h"
#include "TransportationTest.h"
#include "WishlistTest.h"
#include "BaggageTest.h"
#include "ContractTest.h"
#include "DestinationTest.h"
#include "TravelHistoryTest.h"
#include "RatingTest.h"
#include "GuideTest.h"
#include "HotelTest.h"
#include "FlightTest.h"
#include "ClientTest.h"

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}