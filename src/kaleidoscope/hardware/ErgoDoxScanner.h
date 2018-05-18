/* -*- mode: c++ -*-
 * Kaleidoscope-Hardware-ErgoDox -- ErgoDox hardware support for Kaleidoscope
 * Copyright (C) 2018  Gergely Nagy
 *
 * Based on QMK, which is (C) Jack Humbert, Erez Zukerman, et al.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <Arduino.h>

namespace kaleidoscope {
namespace hardware {

class ErgoDoxScanner {
 public:
  ErgoDoxScanner() {}

  void begin();
  void initCols();
  void selectRow(int row);
  void unselectRows();
  uint8_t readCols(int row);

 private:
  bool i2c_initialized_ = false;
  uint8_t expander_error_ = 0x20;

  uint8_t initExpander();
};

}
}
