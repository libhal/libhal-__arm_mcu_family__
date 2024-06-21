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

#include <libhal-__arm_mcu_family__/clock.hpp>
#include <libhal-__arm_mcu_family__/constants.hpp>

using namespace hal::literals;

namespace hal::__arm_mcu_family__ {
void maximize_all_clocks(hertz p_external_crystal_frequency)
{
  // TODO: Use p_external_crystal_frequency to generate a clock tree that will
  // maximize the system clocks for everything (or almost everything).
  clock_tree maximum_clock_tree{};
  static_cast<void>(p_external_crystal_frequency);  // delete this after impl
  configure_clocks(maximum_clock_tree);
}

hertz frequency(peripheral p_peripheral)
{
  static_cast<void>(p_peripheral);  // delete this after impl
  return 1'000'000.0_MHz;
}

bool using_external_oscillator()
{
  // TODO: Read a register and determine if the external oscillator is enabled,
  // active, and in use.
  return false;
}

void configure_clocks(clock_tree const& p_clock_tree)
{
  // TODO: Configure the system's clock tree.
  static_cast<void>(p_clock_tree);  // delete this after impl
}
}  // namespace hal::__arm_mcu_family__
