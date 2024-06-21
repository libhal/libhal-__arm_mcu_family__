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

#include <libhal/units.hpp>

#include "constants.hpp"

namespace hal::__arm_mcu_family__ {

/// Structure representing the platform's clock tree and the ways it can be
/// configured.
struct clock_tree
{
  // TODO: Fill this out with all of the methods to configure the systems clock
  //       tree. See "libhal-lpc40/clock.hpp" and "libhal-stm32f1/clock.hpp"
  //       for examples of what a clock tree looks like.
};

/**
 * @brief Set the MCU to the maximum clock speed for the entire system
 *
 * @param p_external_crystal_frequency - frequency of the main crystal
 */
void maximize_all_clocks(hertz p_external_crystal_frequency);

/**
 * @brief Returns the operating frequency of the peripheral
 *
 * @param p_peripheral - id of the peripheral
 * @return frequency - operating frequency of the peripheral
 */
hertz frequency(peripheral p_peripheral);

/**
 * @brief Determines if the external oscillator is currently enabled and in use
 *
 * For use by drivers and in some cases applications.
 *
 * @return true - external oscillator is in use currently
 * @return false - external oscillator is NOT in use currently
 */
bool using_external_oscillator();

/**
 * @brief Apply the clock configuration to hardware
 *
 */
void configure_clocks(clock_tree const& p_clock_tree);
}  // namespace hal::__arm_mcu_family__
