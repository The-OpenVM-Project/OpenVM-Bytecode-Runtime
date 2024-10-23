#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>

class Logger {
public:
    enum class LogLevel {
        INFO,
        WARNING,
        ERROR
    };

    Logger() : level(LogLevel::INFO), enabled(true) {}

    // Set the log level
    Logger& setLogLevel(LogLevel newLevel) {
        level = newLevel;
        return *this;
    }

    // Enable or disable logging
    Logger& setEnabled(bool isEnabled) {
        enabled = isEnabled;
        return *this;
    }

    // Overloaded << operator for logging
    template <typename T>
    Logger& operator<<(const T& message) {
        if (enabled) {
            std::ostringstream oss;
            oss << message;
            log(oss.str(), level, __FILE__, __LINE__, __FUNCTION__);
        }
        return *this;
    }

    // Overloaded << for changing log level
    Logger& operator<<(LogLevel newLevel) {
        level = newLevel;
        return *this;
    }

private:
    LogLevel level;
    bool enabled;  // Flag to enable or disable logging

    void log(const std::string& message, LogLevel level, const char* file, int line, const char* function) {
        std::cout << getCurrentTime() << " [" << getLogLevelString(level) << "] "
            << "[" << file << ":" << line << "] "
            << "[" << function << "] "
            << message << std::endl;
    }

    std::string getCurrentTime() {
        auto now = std::chrono::system_clock::now();
        auto now_time = std::chrono::system_clock::to_time_t(now);
        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now_time));
        return buffer;
    }

    std::string getLogLevelString(LogLevel level) {
        switch (level) {
        case LogLevel::INFO: return "\033[32mINFO\033[0m";    // Green
        case LogLevel::WARNING: return "\033[33mWARNING\033[0m"; // Yellow
        case LogLevel::ERROR: return "\033[31mERROR\033[0m";    // Red
        default: return "UNKNOWN";
        }
    }
};

// Global logger instance
Logger LOGGER;

#endif // LOGGER_HPP
