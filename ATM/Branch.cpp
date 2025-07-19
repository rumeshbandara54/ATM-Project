#include "Branch.h"
#include <iostream>

void Branch::manageBranch() { 
    int choice;

    while (true) {
        std::cout << "\n====== Branch Details ======\n";
        std::cout << "1. Add Branch\n";
        std::cout << "2. View All Branches\n";
        std::cout << "3. Return to Main Menu\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            Branch newBranch;
            newBranch.inputBranchDetails();
            branches.push_back(newBranch);
        }
        else if (choice == 2) {
            if (branches.empty()) {
                std::cout << "No branches available.\n";
            }
            else {
                for (const auto& branch : branches) {
                    branch.displayBranchDetails();
                    std::cout << "-------------------------\n";
                }
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

//auto create branch accung 50
void Branch::preloadDefaultBranches() {
    for (int i = 1; i <= 50; ++i) {
        Branch defaultBranch;
        defaultBranch.branchCode = "JP" + std::to_string(i);
        defaultBranch.bankCity = "kyoto";
        defaultBranch.bankBranch = "Japan Bank Branch " + std::to_string(i);
        defaultBranch.branchPhone = std::string("03-1234-56") + (i < 10 ? "0" : "") + std::to_string(i);

        branches.push_back(defaultBranch);
    }
    std::cout << "Japanese banks with branches in Kyoto.\n";
}



void Branch::inputBranchDetails() {
    std::cout << "Enter Branch Code: ";
    std::cin >> branchCode;

    std::cout << "Enter Bank City: ";
    std::cin.ignore();
    std::getline(std::cin, bankCity);

    std::cout << "Enter Bank Branch: ";
    std::getline(std::cin, bankBranch);

    std::cout << "Enter Branch Phone Number: ";
    std::cin >> branchPhone;

    std::cout << "Branch details successfully added.\n";
}

//branch shw
void Branch::displayBranchDetails() const {
    std::cout << "\nBranch Code: " << branchCode
        << "\nBank City: " << bankCity
        << "\nBank Branch: " << bankBranch
        << "\nBranch Phone Number: " << branchPhone << "\n";
}
