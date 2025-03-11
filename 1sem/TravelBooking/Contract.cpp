#include"Contract.h"

    Contract::Contract(const string& contractId, const Client& client, const TravelAgent& agent,
             const string& startDate, const string& endDate, double totalAmount)
        : contractId(contractId), client(client), agent(agent),
          startDate(startDate), endDate(endDate), totalAmount(totalAmount), isSigned(false) {}

    void Contract::signContract() {
        isSigned = true;
        cout << "Contract signed." << endl;
    }

    void Contract::displayContractDetails() const {
        cout << "Contract ID: " << contractId << endl;
        cout << "Client Name: " << client.getName() << endl;
        cout << "Client Age: " << client.getAge() << endl;
        cout << "Client Phone: " << client.getPhoneNumber() << endl;
        cout << "Travel Agent: [Agent details]" << endl;
        cout << "Start Date: " << startDate << endl;
        cout << "End Date: " << endDate << endl;
        cout << "Total Amount: $" << totalAmount << endl;
        cout << "Is Signed: " << (isSigned ? "Yes" : "No") << endl;
    }