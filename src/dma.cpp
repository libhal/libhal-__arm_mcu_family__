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

#include <libhal-__arm_mcu_family__/dma.hpp>

#include <atomic>

namespace hal::__arm_mcu_family__ {
void initialize_dma()
{
  // TODO: Implement this
  // Ensure that a check is performed to determine if dma is already
  // initialized and if so, return early.
}

std::atomic_flag dma_busy = ATOMIC_FLAG_INIT;

void setup_dma_transfer(dma const& p_dma_instructions,
                        hal::callback<void(void)> p_interrupt_callback)
{
  while (dma_busy.test_and_set(std::memory_order_acquire)) {
    continue;  // spin lock
  }

  initialize_dma();

  // TODO: Implement this
  static_cast<void>(p_dma_instructions);    // delete this after impl
  static_cast<void>(p_interrupt_callback);  // delete this after impl

  dma_busy.clear();
}
}  // namespace hal::__arm_mcu_family__