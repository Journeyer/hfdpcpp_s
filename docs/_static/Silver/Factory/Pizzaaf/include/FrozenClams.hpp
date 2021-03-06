//===--- FrozenClams.hpp - --------------------------------------*- C++ -*-===//
//
//                     Head First Design Patterns
//
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief
///
//===----------------------------------------------------------------------===//


#ifndef	_HFDP_CPP_FACTORY_ABSTRACT_FROZEN_CLAMS_HPP_
#define _HFDP_CPP_FACTORY_ABSTRACT_FROZEN_CLAMS_HPP_

#include "Clams.hpp"
#include <string>

namespace HFDP {
  namespace Factory {
    namespace Abstract {

      class FrozenClams : public Clams {

      public:
        std::string toString() const;
      };

    } // namespace Abstract
  } // namespace Factory
} // namespace HFDP

#endif
