#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "BookTest.h"
#include "DeliveryTest.h"
#include "OrderTest.h"
#include "DateTest.h"
#include "ReaderTest.h"
#include "ReportTest.h"
#include "ReviewTest.h"
#include "SectionTest.h"
#include "ShelfTest.h"
#include "SysAdminTest.h"
#include "WarehouseTest.h"
#include "WishlistTest.h"
#include "WorkerTest.h"

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}