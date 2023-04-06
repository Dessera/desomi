#pragma once
#include <exception>
#include <string>

class WindowException : public std::exception {
 public:
  explicit WindowException(const char* message) : message_(message) {}
  explicit WindowException(const std::string& message) : message_(message.c_str()) {}
  [[nodiscard]] const char* what() const noexcept override { return message_; }

 private:
  const char* message_;
};


