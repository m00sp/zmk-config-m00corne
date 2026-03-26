# Quick Start: Display Static Image on OLED

Simple instructions for displaying a static LVGL image on your Corne OLED display.

---

## Overview

Use the pre-built static image (`black.c`) as your OLED display graphic. This avoids the complexity of animation and is much simpler to integrate.

**File**: `boards/shields/corne_oled_animation/assets/black.c`
**Image**: 32×128 pixels, 1-bit color (black & white)



---

## Step 1: Set Up Directory Structure

```bash
cd /home/mimomu/zmk-config-m00corne
mkdir -p boards/shields/corne_oled_image/widgets
```

---

## Step 2: Copy the Static Image File

The `black.c` file already exists. If you need a different static image, use it as a template:

```bash
# Copy as a reference (optional)
cp boards/shields/corne_oled_animation/assets/black.c \
   boards/shields/corne_oled_image/widgets/
```

**Image specs**: 32×128 pixels, 1-bit LVGL format, all white pixels.

---

## Step 3: Create Widget Header

**File: `boards/shields/corne_oled_image/widgets/image.h`**

```c
/*
 * Copyright (c) 2024 ZMK Contributors
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>

// Static image
extern const lv_img_dsc_t black;

// Initialize image widget
void image_widget_init(lv_obj_t *parent, lv_coord_t x, lv_coord_t y);
```

---

## Step 4: Create Widget Implementation

**File: `boards/shields/corne_oled_image/widgets/image.c`**

```c
/*
 * Copyright (c) 2024 ZMK Contributors
 * SPDX-License-Identifier: MIT
 */

#include "image.h"

static lv_obj_t *image_obj = NULL;

void image_widget_init(lv_obj_t *parent, lv_coord_t x, lv_coord_t y) {
    image_obj = lv_img_create(parent);
    lv_obj_set_pos(image_obj, x, y);
    lv_img_set_src(image_obj, &black);
}
```

---

## Step 5: Create Build Configuration

**File: `boards/shields/corne_oled_image/CMakeLists.txt`**

```cmake
zephyr_library()

zephyr_library_sources(
    widgets/image.c
    widgets/black.c
)

zephyr_library_include_directories(widgets)
```

---

## Step 6: Create Kconfig Files

**File: `boards/shields/corne_oled_image/Kconfig.shield`**

```kconfig
config SHIELD_CORNE_OLED_IMAGE
    def_bool $(shields_list_contains,corne_oled_image)
    select LVGL
    select ZMK_DISPLAY
```

**File: `boards/shields/corne_oled_image/Kconfig.defconfig`**

```kconfig
if SHIELD_CORNE_OLED_IMAGE

config LVGL
    default y

config ZMK_DISPLAY
    default y

endif
```

---

## Step 7: Create Configuration Files

**File: `boards/shields/corne_oled_image/corne_oled_image.conf`**

```conf
CONFIG_ZMK_DISPLAY=y
```

**File: `boards/shields/corne_oled_image/corne_oled_image.overlay`**

```dts
/ {
    chosen {
        zephyr,display = &oled;
    };
};

&i2c0 {
    status = "okay";

    oled: ssd1306@3c {
        compatible = "solomon,ssd1306fb";
        reg = <0x3c>;
        width = <128>;
        height = <64>;
        segment-offset = <0>;
        page-offset = <0>;
        display-offset = <0>;
        multiplex-ratio = <63>;
        segment-remap;
        com-invdir;
        com-sequential;
        prechargep = <0x22>;
        reset-gpios = <&gpio0 4 GPIO_ACTIVE_LOW>;
    };
};
```

---

## Step 8: Create ZMK Metadata

**File: `boards/shields/corne_oled_image/corne_oled_image.zmk.yml`**

```yaml
file_format: "1"
id: corne_oled_image
name: Corne OLED Image
type: shield
requires: [corne_left, corne_right]
features:
  - display
```

---

## Step 9: Update Build Configuration

Edit `build.yaml`:

```yaml
---
include:
  - board: nice_nano_v2
    shield: corne_left corne_oled_image
  - board: nice_nano_v2 
    shield: corne_right corne_oled_image
  - board: nice_nano_v2
    shield: settings_reset
```

---

## Step 10: Build and Flash

```bash
cd /home/mimomu/zmk-config-m00corne

# Clean previous builds
rm -rf build/

# Build firmware
west build -b nice_nano_v2 -- -DSHIELD="corne_left corne_oled_image"
west build -b nice_nano_v2 -- -DSHIELD="corne_right corne_oled_image"

# Flash (if building locally)
west flash --board nice_nano_v2 --sideload
```

---

## Troubleshooting

| Problem | Solution |
|---------|----------|
| Image doesn't display | Check overlay device tree configuration and I2C address |
| Build fails | Verify all files are in correct directories and CMakeLists.txt references them |
| Wrong image displayed | Confirm `black.c` is the image you want; replace if needed |

---

**Done!** Your OLED display now shows a static image.

For future customization, replace `black.c` with a different image using an LVGL converter.
