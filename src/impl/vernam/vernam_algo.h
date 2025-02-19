#pragma once

#include <core/algo/algo.h>

#include <array>
#include <climits>
#include <cstdint>
#include <string>
#include <string_view>
#include <sys/stat.h>
#include <vector>

namespace coded::impl::vernam {

class VernamAlgo : public core::Algo {
public:
  VernamAlgo();
  VernamAlgo(const std::string &key);
  VernamAlgo(std::string &&key);

  virtual ~VernamAlgo() = default;

private:
  virtual std::string Encode(std::string_view decodedString) const override;
  virtual std::string Decode(std::string_view encodedString) const override;

  std::string Process(std::string_view payload) const;

private:
  std::string key_;
};

} // namespace coded::impl::vernam
