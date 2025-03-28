<<<<<<<< HEAD:tests/tap_hold_configurations/chordal_hold/hold_on_other_key_press/config.h
/* Copyright 2022 Vladislav Kucheriavykh
 * Copyright 2024 Google LLC
========
/* Copyright 2022 QMK
>>>>>>>> origin/master:keyboards/deemen17/de80/halconf.h
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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

<<<<<<<< HEAD:tests/tap_hold_configurations/chordal_hold/hold_on_other_key_press/config.h
#include "test_common.h"
#define CHORDAL_HOLD
#define HOLD_ON_OTHER_KEY_PRESS
========
#define HAL_USE_SPI TRUE

#include_next <halconf.h>

>>>>>>>> origin/master:keyboards/deemen17/de80/halconf.h
