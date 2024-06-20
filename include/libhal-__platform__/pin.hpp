// Copyright 2024 Khalil Estell
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <cstdint>

namespace hal::__platform__ {

/**
 * @brief Struct representing a specific and unique pin on the device
 *
 */
struct pin_select_t
{
  // TODO: Update this to what makes sense for your platform
  std::uint8_t port;
  std::uint8_t pin;
};

/**
 * @brief A configuration for a pin
 *
 */
struct pin_config_t
{
  // TODO: erase what is here and fill out with the ways that a pin on this
  // platform can be modified. If this struct scheme does not work for your
  // application, you may change this file to whatever whats best for the
  // platform.
  bool input_analog;
};

/**
 * @brief Construct pin manipulation object
 *
 * @param p_pin_select - the pin to configure
 * @param p_config - Configuration to set the pin to
 */
void configure_pin(pin_select_t p_pin_select, pin_config_t p_config);
}  // namespace hal::__platform__
