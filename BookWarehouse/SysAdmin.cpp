#include "SysAdmin.h"

SysAdmin::SysAdmin(const string& fName, const string& sName, const string& userLogin, const string& userPassword)
        : firstName(fName), secondName(sName), login(userLogin), password(userPassword) {}

    string SysAdmin::getFullName() const {
        return firstName + " " + secondName;
    }

    void SysAdmin::setPassword(const string& newPassword) {
        password = newPassword;
        cout << "Password updated successfully.\n";
    }

    bool SysAdmin::checkPassword(const string& inputPassword) const {
        return password == inputPassword;
    }

    void SysAdmin::printAdminDetails() const {
        cout << "Admin Name: " << getFullName() << "\n";
        cout << "Login: " << login << "\n";
    }

    void SysAdmin::grantAccess(const string& user) {
        cout << "Access granted to " << user << ".\n";
    }

    void SysAdmin::revokeAccess(const string& user) {
        cout << "Access revoked from " << user << ".\n";
    }

    void SysAdmin::logAction(const string& action) {
        cout << "Log: " << action << " performed by " << getFullName() << ".\n";
    }

    void SysAdmin::addUser(const string& username) {
        cout << "User " << username << " added.\n";
        logAction("Added user " + username);
    }

    void SysAdmin::removeUser(const string& username) {
        cout << "User " << username << " removed.\n";
        logAction("Removed user " + username);
    }

    void SysAdmin::resetPassword(const string& username) {
        string newPassword = "defaultPassword"; // Логика генерации нового пароля
        cout << "Password for " << username << " reset to " << newPassword << ".\n";
        logAction("Reset password for " + username);
    }

    void SysAdmin::updateSystemSettings(const string& setting, const string& value) {
        cout << "System setting " << setting << " updated to " << value << ".\n";
        logAction("Updated system setting " + setting);
    }

    void SysAdmin::generateSystemReport() {
        cout << "Generating system report...\n";
        cout << "Administrator Information:\n";
        cout << "---------------------------\n";
        cout << "First Name: " << firstName << "\n";
        cout << "Second Name: " << secondName << "\n";
        cout << "Login: " << login << "\n";
        cout << "---------------------------\n";
    }
