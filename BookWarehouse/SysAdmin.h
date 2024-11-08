#pragma once
#include <iostream>

using namespace std;

class SysAdmin
{
private:
    string firstName;
    string secondName;
    string login;
    string password;
public:
    SysAdmin(const string& fName, const string& sName, const string& userLogin, const string& userPassword);
    string getFullName() const;
    void setPassword(const string& newPassword);
    bool checkPassword(const string& inputPassword) const;
    void printAdminDetails() const;
    void grantAccess(const string& user);
    void revokeAccess(const string& user);
    void logAction(const string& action);
    void addUser(const string& username);
    void removeUser(const string& username);
    void resetPassword(const string& username);
    void updateSystemSettings(const string& setting, const string& value);
    void generateSystemReport();
};