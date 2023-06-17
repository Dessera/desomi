#include "enode/node_type.hpp"

using domi::core::Enode;
using EnodePtr = domi::core::Enode::EnodePtr;
using EnodeRawPtr = domi::core::Enode::EnodeRawPtr;
using EnodeComponentCtor = domi::core::Enode::EnodeComponentCtor;

EnodePtr Enode::clone() const {
  EnodePtr clone = std::make_unique<Enode>();
  for (const auto& child : children_) {
    clone->insert(child->clone());
  }
  return clone;
}

Enode::Enode(const Enode& other) {
  children_.clear();
  for (const auto& child : other.children_) {
    insert(child->clone());
  }
}

Enode& Enode::operator=(const Enode& other) {
  if (this == &other) {
    return *this;
  }
  children_.clear();
  for (const auto& child : other.children_) {
    insert(child->clone());
  }
  return *this;
}

Enode& Enode::operator=(Enode&& other) noexcept {
  if (this == &other) {
    return *this;
  }
  children_ = std::move(other.children_);
  parent_ = other.parent_;
  return *this;
}
