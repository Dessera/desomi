#pragma once

#define DELETE_COPY_AND_MOVE(name)       \
  name(const name&) = delete;            \
  name& operator=(const name&) = delete; \
  name(name&&) = delete;                 \
  name& operator=(name&&) = delete

#define DEFAULT_COPY_AND_MOVE(name)       \
  name(const name&) = default;            \
  name& operator=(const name&) = default; \
  name(name&&) = default;                 \
  name& operator=(name&&) = default

#define DEFAULT_CLASS_METHOD(name) \
  name() = default;                \
  DEFAULT_COPY_AND_MOVE(name);     \
  virtual ~name() = default