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

#include <cstddef>
#include <cstdint>

#include <libhal/functional.hpp>

namespace hal::__arm_mcu_family__ {
// TODO: Update this to fit your system
struct dma
{
  // TODO: Update these values
  static constexpr std::size_t dma_max_transfer_size = (1 << 12) - 1;
  static constexpr std::size_t dma_channel_count = 8;
  using length_t = std::uint16_t;

  // TODO: Update this to match your system
  enum class transfer_type : std::uint8_t
  {
    memory_to_memory = 0b000,
    memory_to_peripheral = 0b001,
    peripheral_to_memory = 0b010,
    peripheral_to_peripheral = 0b011,
  };

  // TODO: Update or remove this if it is not relevant.
  enum class channel_select : std::uint8_t
  {
    channel0 = 0,
    channel1,
    channel2,
    channel3,
    channel4,
    channel5,
    channel6,
    channel7,
  };

  // TODO: Update this to fit your system
  enum class transfer_width : std::uint8_t
  {
    bit_8 = 0b000,
    bit_16 = 0b001,
    bit_32 = 0b010,
  };

  // TODO: Update this to fit your system
  enum class request : std::uint8_t
  {
    memory = 0,
    uart0_rx = 1,
    uart0_tx = 1,
    spi1_tx = 1,
    spi1_rx = 1,
  };

  // TODO: Update this list to match whats available for your mcu
  const volatile void* source;
  volatile void* destination;
  length_t length;
  transfer_type transfer_type;
  transfer_width source_transfer_width;
  request source_peripheral;
  bool source_increment;
  transfer_width destination_transfer_width;
  request destination_peripheral;
  bool destination_increment;
};

/**
 * @brief Initialize DMA controller
 *
 * On first call, enables DMA. Once enabled, additional calls to this function
 * do nothing.
 *
 */
void initialize_dma();

/**
 * @brief Setup and start a dma transfer
 *
 * This API will use an available dma channel for the transfer. This API will
 * block if all dma channels are in use.
 *
 * @param p_dma_instructions - Instructions for the dma transfer
 * @param p_interrupt_callback - Callback when the dma transfer has complete
 */
void setup_dma_transfer(const dma& p_dma_instructions,
                        hal::callback<void(void)> p_interrupt_callback);
}  // namespace hal::__arm_mcu_family__