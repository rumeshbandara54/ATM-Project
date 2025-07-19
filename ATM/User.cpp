#include "User.h"

User::User(std::string u, std::string p, std::string e, std::string tp, std::string branch, std::string addr, double b)
    : username(u), password(p), email(e), TP(tp), branchCode(branch), address(addr), balance(b) {}
