#pragma once

#include <vector>
#include <string>
#include <memory>
#include <functional>

namespace syntax {

// Base class for all commands (type-erased)
class BaseCommand {
 public:
  virtual ~BaseCommand() = default;

  virtual void invoke(const std::vector<std::string>& args) = 0;
};

// Templated command with actual return type
template<typename ReturnType>
class Command : public BaseCommand {
 public:
  explicit Command(std::function<ReturnType(const std::vector<std::string>&)> fn);

  void invoke(const std::vector<std::string>& args) override;

  ReturnType getReturn() const;

 private:
  std::function<ReturnType(const std::vector<std::string>&)> callback;
  ReturnType lastReturn;
};

} // namespace syntax

#include "command.tpp"
