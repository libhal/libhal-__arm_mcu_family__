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

#include <libhal-armcortex/interrupt.hpp>

namespace hal::__platform__ {
/// List of each peripheral and their power on id number for this platform
enum class peripheral : std::uint8_t
{
  // TODO: Update these to the appropriate names
  peripheral0 = 0,
  peripheral1 = 1,
  peripheral2 = 2,
  // Always-on
  // TODO: Update these to the appropriate names
  cpu,                    // The main cpu should be the first always on "device"
  always_on_peripheral0,  // All following always on devices come after cpu
  always_on_peripheral1,  // All following always on devices come after cpu
};

/// List of interrupt request numbers for this platform
enum class irq : cortex_m::irq_t
{
  // TODO: Update and add the rest here...
  watchdog = 16 + 0,
  timer0 = 16 + 1,
  timer1 = 16 + 2,

  // Always have a max at the end of the list
  max,
};
}  // namespace hal::__platform__
