#include <iostream>
#include <vector>
#include <string>

struct CreditRecord {
    std::string name;
    int creditAmountLimit;
    std::string accountNumber;
};

class CreditRecordSystem {
private:
    std::vector<CreditRecord> records;

public:
    void createRecord() {
        CreditRecord record;
        std::cout << "Enter name: ";
        std::cin >> record.name;

        while (true) {
            std::cout << "Enter credit amount (0-1000): ";
            std::cin >> record.creditAmountLimit;
            if (record.creditAmountLimit >= 0 && record.creditAmountLimit <= 1000) {
                break; 
            }
            std::cout << "Invalid credit amount. Please enter a amount between 0 and 1000." << std::endl;
        }

        std::cout << "Enter account number: ";
        std::cin >> record.accountNumber;
        
        records.push_back(record);
        std::cout << "Record created successfully!" << std::endl;
    }

    void readRecords() {
        if (records.empty()) {
            std::cout << "No records found." << std::endl;
            return;
        }

        std::cout << "Credit Records:" << std::endl;
        std::cout << "-----------------------------------------------------" << std::endl;
        for (const auto& record : records) {
            std::cout << "Name: " << record.name 
                      << " | Credit Amount: " << record.creditAmountLimit
                      << " | Account Number: " << record.accountNumber << std::endl;
        }
        std::cout << "-----------------------------------------------------" << std::endl;
    }

    void updateRecord() {
        std::string accountNumber;
        std::cout << "Enter account number of record to update: ";
        std::cin >> accountNumber;

        for (auto& record : records) {
            if (record.accountNumber == accountNumber) {
                std::cout << "Enter new name: ";
                std::cin >> record.name;

                while (true) {
                    std::cout << "Enter new credit score (0-1000): ";
                    std::cin >> record.creditAmountLimit;
                    if (record.creditAmountLimit >= 0 && record.creditAmountLimit <= 1000) {
                        break;
                    }
                    std::cout << "Invalid credit amount. Please enter a value between 0 and 1000." << std::endl;
                }
                std::cout << "Record successfully updated!" << std::endl; 
                return;
            }
        }
        std::cout << "Record not found." << std::endl;
    }

    void deleteRecord() {
        std::string accountNumber;
        std::cout << "Enter account number of record to delete: ";
        std::cin >> accountNumber;

        for (auto it = records.begin(); it != records.end(); ++it) {
            if (it->accountNumber == accountNumber) {
                records.erase(it);
                std::cout << "Record deleted successfully." << std::endl;
                return;
            }
        }
        std::cout << "Record not found." << std::endl;
    }
};

int main() {
    CreditRecordSystem system;
    int choice;

    do {
        std::cout << "\nCredit Record System \n";
        std::cout << "1. Create Record\n2. Read Credit Records\n3. Update Credit Record\n4. Delete Credit Record\n5. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1: system.createRecord(); break;
            case 2: system.readRecords(); break;
            case 3: system.updateRecord(); break;
            case 4: system.deleteRecord(); break;
            case 5: std::cout << "Exiting..." << std::endl; break;
            default: std::cout << "Invalid option. Please enter a valid option." << std::endl;
        }
    } while (choice != 5);

    return 0;
