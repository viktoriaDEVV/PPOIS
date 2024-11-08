#include <gtest/gtest.h>
#include "Delivery.h"
#include<sstream>

TEST(DeliveryTests, GettersReturnCorrectValues) {
    Date deliveryDate = {10, 11, 2023};
    Provider provider("Book Supplier", "123-456-7890", "123 Main St, Cityville");
    Delivery delivery("Batch001", deliveryDate, 100, provider);

    EXPECT_EQ(delivery.getBatchNumber(), "Batch001");
    EXPECT_EQ(delivery.getDeliveryDate().day, 10);
    EXPECT_EQ(delivery.getDeliveryDate().month, 11);
    EXPECT_EQ(delivery.getDeliveryDate().year, 2023);
    EXPECT_EQ(delivery.getAmountBook(), 100);
    EXPECT_EQ(delivery.getProvider().getName(), "Book Supplier");
}

TEST(DeliveryTests, SettersUpdateValuesCorrectly) {
    Date deliveryDate = {10, 11, 2023};
    Provider provider("Book Supplier", "123-456-7890", "123 Main St, Cityville");
    Delivery delivery("Batch001", deliveryDate, 100, provider);

    // Обновление значений
    delivery.setBatchNumber("Batch002");
    Date newDate = {15, 12, 2023};
    delivery.setDeliveryDate(newDate);
    delivery.setAmountBook(150);
    Provider newProvider("New Supplier", "098-765-4321", "456 Another St, Townsville");
    delivery.setProvider(newProvider);

    // Проверяем обновленные значения
    EXPECT_EQ(delivery.getBatchNumber(), "Batch002");
    EXPECT_EQ(delivery.getDeliveryDate().day, 15);
    EXPECT_EQ(delivery.getDeliveryDate().month, 12);
    EXPECT_EQ(delivery.getDeliveryDate().year, 2023);
    EXPECT_EQ(delivery.getAmountBook(), 150);
    EXPECT_EQ(delivery.getProvider().getName(),"New Supplier");
    EXPECT_EQ(delivery.getProvider().getPhoneNumber(), "098-765-4321");
    EXPECT_EQ(delivery.getProvider().getAddress(), "456 Another St, Townsville");
}

TEST(DeliveryTests, UpdateAmountChangesAmount) {
    Date deliveryDate = {10, 11, 2023};
    Provider provider = {"Book Supplier", "123-456-7890", "123 Main St, Cityville"};
    Delivery delivery("Batch001", deliveryDate, 100, provider);

    delivery.updateAmount(150);
    
    // Проверяем вывод после обновления
    std::ostringstream buffer;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    delivery.updateAmount(150);
    std::cout.rdbuf(originalCoutBuffer); // Возвращаем оригинальный буфер

    EXPECT_EQ(buffer.str(), "Amount of books updated to 150.\n");
}

TEST(DeliveryTests, UpdateDeliveryDateChangesDate) {
    Date deliveryDate = {10, 11, 2023};
    Provider provider = {"Book Supplier", "123-456-7890", "123 Main St, Cityville"};
    Delivery delivery("Batch001", deliveryDate, 100, provider);

    Date newDate = {15, 12, 2023};
    delivery.updateDeliveryDate(newDate);
    
    // Проверяем вывод после обновления
    std::ostringstream buffer;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    delivery.updateDeliveryDate(newDate);
    std::cout.rdbuf(originalCoutBuffer); // Возвращаем оригинальный буфер

    EXPECT_EQ(buffer.str(), "Delivery date updated to 15-12-2023.\n");
}

TEST(DeliveryTests, ConfirmDeliveryOutputsCorrectMessage) {
    Date deliveryDate = {10, 11, 2023};
    Provider provider = {"Book Supplier", "123-456-7890", "123 Main St, Cityville"};
    Delivery delivery("Batch001", deliveryDate, 100, provider);

    std::ostringstream buffer;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    delivery.confirmDelivery();

    std::cout.rdbuf(originalCoutBuffer); // Возвращаем оригинальный буфер

    EXPECT_EQ(buffer.str(), "Delivery confirmed for batch number Batch001.\n");
}

TEST(DeliveryTests, IsDeliveryOnTimeReturnsCorrectValue) {
    Date deliveryDate = {10, 11, 2023};
    Provider provider = {"Book Supplier", "123-456-7890", "123 Main St, Cityville"};
    Delivery delivery("Batch001", deliveryDate, 100, provider);

    Date currentDate1 = {9, 11, 2023}; // До
    Date currentDate2 = {10, 11, 2023}; // В день
    Date currentDate3 = {11, 11, 2023}; // После

    EXPECT_TRUE(delivery.isDeliveryOnTime(currentDate1)); // Доставка вовремя
    EXPECT_TRUE(delivery.isDeliveryOnTime(currentDate2)); // Доставка вовремя
    EXPECT_FALSE(delivery.isDeliveryOnTime(currentDate3)); // Доставка не вовремя
}

TEST(DeliveryTests, PrintDeliveryDetailsOutputsBatchNumberAndDate) {
    // Создание необходимых объектов
    Date deliveryDate = {10, 11, 2023};
    Provider provider("Book Supplier", "123-456-7890", "123 Main St, Cityville");
    Delivery delivery("Batch001", deliveryDate, 100, provider);

    // Перенаправляем cout в строковый поток
    std::ostringstream buffer;
    std::streambuf* originalCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    // Вызов метода
    delivery.printDeliveryDetails();

    // Возвращаем оригинальный буфер
    std::cout.rdbuf(originalCoutBuffer);

    // Проверка только основных деталей
    EXPECT_NE(buffer.str().find("Batch Number: Batch001"), std::string::npos);
    EXPECT_NE(buffer.str().find("Delivery Date: 10-11-2023"), std::string::npos);
}
