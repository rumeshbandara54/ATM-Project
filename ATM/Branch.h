#pragma once
#include <vector>
#include "User.h"
#include "Admin.h"
#include "Branch.h"

class Branch {
private:
    std::string branchCode;
    std::string bankCity;
    std::string bankBranch;
    std::string branchPhone;

    std::vector<Branch> branches;

public:
    Branch() = default;

    Branch(const std::string& code, const std::string& city, const std::string& branch, const std::string& phone)
        : branchCode(code), bankCity(city), bankBranch(branch), branchPhone(phone) {}

    void inputBranchDetails();
    void displayBranchDetails() const;

    void manageBranch(); //  Correct method name

    void preloadDefaultBranches(); // Declare the function Branches


    // Optional getters
    std::string getBranchCode() const { return branchCode; }
    std::string getBankCity() const { return bankCity; }
    std::string getBankBranch() const { return bankBranch; }
    std::string getBranchPhone() const { return branchPhone; }
};
