#include "Logger.h"
#include <fstream>
#include <iostream>
#include <ctime>

void Logger::log(const std::string& message) {
    std::ofstream logFile("atm_log.txt", std::ios_base::app); // type file
    if (logFile.is_open()) {
        std::time_t now = std::time(nullptr);
        char dt[26]; 
        ctime_s(dt, sizeof(dt), &now);
        dt[strcspn(dt, "\n")] = 0; 

        logFile << "[" << dt << "] " << message << "\n";
        logFile.close();
    }
    else {
        std::cout << "Unable to open log file.\n";
    }
}

