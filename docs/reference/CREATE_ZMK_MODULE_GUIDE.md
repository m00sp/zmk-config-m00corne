# Creating a Simplified ZMK OLED Module with Static Images

A step-by-step guide to build a ZMK module similar to `zmk-nice-oled`, but simplified with **static image support only** (no animations). This guide covers widget framework and emphasizes how to add static images to your OLED display.

---

## Overview

This guide teaches you how to:
1. Create a reusable **ZMK module** (like a GitHub module you can include in other projects)
2. Implement **widgets** (modular UI components)
3. Add **static images** to your OLED display
4. Display a full black static image on a 32×128 peripheral display

**Reference Project**: [zmk-nice-oled](https://github.com/mctechnology17/zmk-nice-oled) (simplified, without animations)

---

## Part 1: Understanding the Architecture

### Directory Structure

```
my-zmk-module/  (This becomes a GitHub repository you can include)
├── CMakeLists.txt              # Build configuration
├── Kconfig                      # Menuconfig options
├── Kconfig.defconfig            # Default configuration
├── module.yml                   # ZMK module metadata
├── src/
│   ├── display.c                # Main display driver
│   ├── display.h
│   └── widgets/                 # Widget implementations
│       ├── battery_widget.h
│       ├── battery_widget.c
│       ├── static_image_widget.h
│       └── static_image_widget.c
├── assets/                      # Pre-generated images
│   ├── black_image.c            # LVGL image descriptor
│   ├── logo_image.c
│   └── README.md
└── include/                     # Public headers
    └── zmk/display/
        └── widgets/
            └── static_image.h
```

### Key Concepts

| Concept | Purpose |
|---------|---------|
| **Shield** | Device tree overlay + configuration for hardware |
| **Module** | Reusable code package included in another ZMK config |
| **Widget** | Modular UI component (battery, image, text, etc.) |
| **LVGL** | Graphics library used by ZMK displays |
| **Static Image** | Pre-rendered image (no animation) in `lv_img_dsc_t` format |

---

## Part 2: Creating a Module from Scratch

### Step 1: Create Module Directory Structure

Create your module as a standalone folder (this will become a GitHub repo):

```bash
mkdir -p my-zmk-module/src/widgets
mkdir -p my-zmk-module/assets
mkdir -p my-zmk-module/include/zmk/display/widgets
touch my-zmk-module/CMakeLists.txt
touch my-zmk-module/Kconfig
touch my-zmk-module/Kconfig.defconfig
touch my-zmk-module/module.yml
```

---

### Step 2: Create Module Metadata (`module.yml`)

**File**: `my-zmk-module/module.yml`

This tells ZMK about your module and its dependencies.

```yaml
manifest:
  version: "0.0.1"
  name: "my-zmk-module"
  description: "Simplified OLED module with static image widgets"
  type: "module"
  license: "MIT"
```

---

### Step 3: Create Kconfig (Configuration Options)

**File**: `my-zmk-module/Kconfig`

Define what users can enable/disable in their ZMK config.

```kconfig
# Copyright (c) 2024 Your Name
# SPDX-License-Identifier: MIT

menuconfig ZMK_MY_OLED_DISPLAY
    bool "My OLED Display Module"
    depends on ZMK_DISPLAY
    select LVGL
    help
      A simplified OLED display module with static image support.

if ZMK_MY_OLED_DISPLAY

config ZMK_MY_OLED_PERIPHERAL_DISPLAY
    bool "Enable peripheral (right side) OLED display"
    default y
    help
      Show a static image on the peripheral (right) side display.

config ZMK_MY_OLED_BATTERY_WIDGET
    bool "Enable battery widget"
    default y
    help
      Display battery percentage on the screen.

config ZMK_MY_OLED_IMAGE_WIDGET
    bool "Enable static image widget"
    default y
    help
      Display static images (no animation).

endif  # ZMK_MY_OLED_DISPLAY
```

---

### Step 4: Create Default Configuration (`Kconfig.defconfig`)

**File**: `my-zmk-module/Kconfig.defconfig`

Set smart defaults when your module is enabled.

```kconfig
# Copyright (c) 2024 Your Name
# SPDX-License-Identifier: MIT

if ZMK_MY_OLED_DISPLAY

config LVGL
    default y

config ZMK_DISPLAY
    default y

config LVGL_VDB_SIZE
    default 64  # Memory for LVGL drawing buffer

config LVGL_DPI_DEF
    default 60

endif  # ZMK_MY_OLED_DISPLAY
```

---

### Step 5: Create Build Configuration (`CMakeLists.txt`)

**File**: `my-zmk-module/CMakeLists.txt`

Tell the build system what source files to compile.

```cmake
# Copyright (c) 2024 Your Name
# SPDX-License-Identifier: MIT

if(CONFIG_ZMK_MY_OLED_DISPLAY)

# Main display driver
zephyr_library()
zephyr_library_sources(src/display.c)

# Widget sources
if(CONFIG_ZMK_MY_OLED_BATTERY_WIDGET)
  zephyr_library_sources(src/widgets/battery_widget.c)
endif()

if(CONFIG_ZMK_MY_OLED_IMAGE_WIDGET)
  zephyr_library_sources(src/widgets/static_image_widget.c)
  # IMPORTANT: Include pre-generated image files
  zephyr_library_sources(assets/black_image.c)
endif()

# Include directories for headers
zephyr_library_include_directories(
  include
  src/widgets
)

endif()  # CONFIG_ZMK_MY_OLED_DISPLAY
```

---

## Part 3: Creating Widgets

### Step 6: Create Static Image Widget Header

**File**: `my-zmk-module/include/zmk/display/widgets/static_image.h`

This is the public interface for the static image widget.

```c
/*
 * Copyright (c) 2024 Your Name
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>

/**
 * @brief Initialize a static image widget
 * 
 * @param parent    Parent LVGL object (container)
 * @param image_src Pointer to lv_img_dsc_t (image descriptor)
 * @param x         X position on screen
 * @param y         Y position on screen
 * 
 * @return Pointer to created image object, NULL on error
 */
lv_obj_t *zmk_widget_static_image_init(lv_obj_t *parent, 
                                        const lv_img_dsc_t *image_src,
                                        lv_coord_t x, 
                                        lv_coord_t y);

/**
 * @brief Change the displayed image at runtime
 * 
 * @param image_obj  Pointer to image object (returned from init)
 * @param image_src  New image to display
 */
void zmk_widget_static_image_update(lv_obj_t *image_obj, 
                                     const lv_img_dsc_t *image_src);
```

---

### Step 7: Create Static Image Widget Implementation

**File**: `my-zmk-module/src/widgets/static_image_widget.c`

This implements the actual widget functionality.

```c
/*
 * Copyright (c) 2024 Your Name
 * SPDX-License-Identifier: MIT
 */

#include <zmk/display/widgets/static_image.h>
#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

lv_obj_t *zmk_widget_static_image_init(lv_obj_t *parent, 
                                        const lv_img_dsc_t *image_src,
                                        lv_coord_t x, 
                                        lv_coord_t y) {
    if (parent == NULL || image_src == NULL) {
        LOG_ERR("Invalid parent or image source");
        return NULL;
    }

    // Create image object
    lv_obj_t *image_obj = lv_img_create(parent);
    if (image_obj == NULL) {
        LOG_ERR("Failed to create image object");
        return NULL;
    }

    // Set image source
    lv_img_set_src(image_obj, image_src);

    // Position the image
    lv_obj_set_pos(image_obj, x, y);

    LOG_INF("Static image widget initialized at (%d, %d)", x, y);
    return image_obj;
}

void zmk_widget_static_image_update(lv_obj_t *image_obj, 
                                     const lv_img_dsc_t *image_src) {
    if (image_obj == NULL || image_src == NULL) {
        LOG_WRN("Invalid image object or source for update");
        return;
    }
    
    lv_img_set_src(image_obj, image_src);
    LOG_INF("Image updated");
}
```

---

### Step 8: Create Battery Widget (Simple Example)

**File**: `my-zmk-module/include/zmk/display/widgets/battery.h`

```c
/*
 * Copyright (c) 2024 Your Name
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>

lv_obj_t *zmk_widget_battery_init(lv_obj_t *parent, lv_coord_t x, lv_coord_t y);
void zmk_widget_battery_update(lv_obj_t *battery_obj, uint8_t level);
```

**File**: `my-zmk-module/src/widgets/battery_widget.c`

```c
/*
 * Copyright (c) 2024 Your Name
 * SPDX-License-Identifier: MIT
 */

#include <zmk/display/widgets/battery.h>
#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

lv_obj_t *zmk_widget_battery_init(lv_obj_t *parent, lv_coord_t x, lv_coord_t y) {
    lv_obj_t *battery_label = lv_label_create(parent);
    lv_obj_set_pos(battery_label, x, y);
    lv_label_set_text(battery_label, "BAT: 100%");
    return battery_label;
}

void zmk_widget_battery_update(lv_obj_t *battery_obj, uint8_t level) {
    if (battery_obj == NULL) return;
    
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "BAT: %u%%", level);
    lv_label_set_text(battery_obj, buffer);
}
```

---

## Part 4: Creating Static Images (THE CRITICAL PART ⭐)

### Step 9: Understanding LVGL Image Format

LVGL images are stored as **binary arrays** with metadata. The format is:

```c
// Generated by LVGL Image Converter
lv_img_dsc_t my_image = {
    .header.always_zero = 0,      // LVGL internal flag
    .header.w = 128,              // Width in pixels
    .header.h = 32,               // Height in pixels
    .header.cf = LV_IMG_CF_TRUE_COLOR,  // Color format
    .data = (const uint8_t *)image_data_array,
    .data_size = sizeof(imagedata_array),
};
```

### Step 10: Generate a Black Static Image (Full Screen - 32×128)

LVGL has an online converter, but for a **full black image**, we can create it manually.

**File**: `my-zmk-module/assets/black_image.c`

```c
/*
 * Copyright (c) 2024 Your Name
 * SPDX-License-Identifier: MIT
 * 
 * Generated static image: Full black screen (128×32 pixels)
 * Display: Peripheral OLED (SSD1306)
 * Format: 1-bit color depth (optimized for monochrome displays)
 */

#include <lvgl.h>

// Binary data for 128×32 black image
// Each byte = 8 pixels (row-major format for monochrome)
// All bytes = 0x00 means all black pixels
static const uint8_t black_image_data[] = {
    // Row 0
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // Row 1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // ... (repeat for all 32 rows)
    // For a 128×32 black image: 32 rows × 16 bytes/row = 512 bytes
};

// LVGL Image Descriptor
// This tells LVGL how to interpret the binary data
const lv_img_dsc_t black_image = {
    .header = {
        .always_zero = 0,                    // LVGL header
        .w = 128,                            // Width: 128 pixels
        .h = 32,                             // Height: 32 pixels
        .cf = LV_IMG_CF_TRUE_COLOR,          // Color format
    },
    .data = black_image_data,                // Pointer to binary data
    .data_size = sizeof(black_image_data),   // Size in bytes
};
```

**For a full black image, all bytes are `0x00`. Here's a complete 128×32 version:**

```c
/*
 * Copyright (c) 2024 Your Name
 * SPDX-License-Identifier: MIT
 * 
 * BLACK_IMAGE.C - Full black static image (128×32 pixels)
 * 
 * Resolution: 128 pixels wide × 32 pixels tall
 * Format: 1-bit monochrome (0 = black, 1 = white)
 * Size: 128 × 32 ÷ 8 = 512 bytes
 * 
 * Usage:
 *   zmk_widget_static_image_init(parent, &black_image, 0, 0);
 */

#include <lvgl.h>

static const uint8_t black_image_data[512] = {
    // All zeros = completely black display
    // 512 bytes of 0x00 (128 pixels wide ÷ 8 + 32 pixels tall)
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

// ======================================
// LVGL IMAGE DESCRIPTOR
// ======================================
// This structure tells LVGL how to interpret the binary data above
const lv_img_dsc_t black_image = {
    .header = {
        .always_zero = 0,                    // Magic header (must be 0)
        .w = 128,                            // Width: 128 pixels
        .h = 32,                             // Height: 32 pixels
        .cf = LV_IMG_CF_TRUE_COLOR,          // Color format
    },
    .data = black_image_data,                // Pointer to binary pixel data
    .data_size = sizeof(black_image_data),   // Total size: 512 bytes
};
```

---

### Step 11: Creating a Colored/Patterned Static Image

For a **white or patterned image**, modify the binary data:

```c
/*
 * WHITE_IMAGE.C - Full white static image (128×32 pixels)
 */

#include <lvgl.h>

static const uint8_t white_image_data[512] = {
    // All 0xFF = completely white display
    // 512 bytes of 0xFF (128 pixels wide ÷ 8 + 32 pixels tall)
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    // ... (repeat 0xFF for all 512 bytes)
};

const lv_img_dsc_t white_image = {
    .header = {
        .always_zero = 0,
        .w = 128,
        .h = 32,
        .cf = LV_IMG_CF_TRUE_COLOR,
    },
    .data = white_image_data,
    .data_size = sizeof(white_image_data),
};
```

### Step 12: Converting Custom Images to LVGL Format

**Use the LVGL Online Image Converter:**

1. Go to: https://lvgl.io/tools/imageconverter
2. Upload your 128×32 PNG/JPG image
3. Set output format to: **C Binary Large**
4. Set color format: **1-bit (Black & White)**
5. Copy the generated `.c` file to `assets/` folder
6. Update `CMakeLists.txt` to include it
7. Declare the image in your header:

```c
extern const lv_img_dsc_t my_custom_image;
```

---

## Part 5: Creating the Main Display Driver

### Step 13: Create Display Header

**File**: `my-zmk-module/src/display.h`

```c
/*
 * Copyright (c) 2024 Your Name
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>

/**
 * @brief Initialize the display with widgets
 */
void zmk_display_init(void);

/**
 * @brief Update display widgets (call periodically)
 */
void zmk_display_update(void);
```

### Step 14: Create Display Implementation

**File**: `my-zmk-module/src/display.c`

```c
/*
 * Copyright (c) 2024 Your Name
 * SPDX-License-Identifier: MIT
 */

#include "display.h"
#include <zmk/display/widgets/static_image.h>
#include <zmk/display/widgets/battery.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(zmk_display);

// Declare external image (defined in assets/black_image.c)
extern const lv_img_dsc_t black_image;

static lv_obj_t *root_screen = NULL;
static lv_obj_t *image_widget = NULL;
static lv_obj_t *battery_widget = NULL;

void zmk_display_init(void) {
    // Get or create the main screen
    root_screen = lv_scr_act();
    if (root_screen == NULL) {
        LOG_ERR("Failed to get active screen");
        return;
    }

    // Set background color to black
    lv_obj_set_style_bg_color(root_screen, lv_color_black(), 0);

    // Create image widget (peripheral display)
    if (IS_ENABLED(CONFIG_ZMK_MY_OLED_IMAGE_WIDGET)) {
        image_widget = zmk_widget_static_image_init(
            root_screen,
            &black_image,  // Display full black image
            0, 0           // Position at (0, 0)
        );

        if (image_widget == NULL) {
            LOG_ERR("Failed to initialize image widget");
        } else {
            LOG_INF("Image widget initialized successfully");
        }
    }

    // Create battery widget (if enabled)
    if (IS_ENABLED(CONFIG_ZMK_MY_OLED_BATTERY_WIDGET)) {
        battery_widget = zmk_widget_battery_init(root_screen, 0, 20);
        if (battery_widget == NULL) {
            LOG_ERR("Failed to initialize battery widget");
        }
    }

    LOG_INF("Display initialized");
}

void zmk_display_update(void) {
    // Update battery level (example)
    if (battery_widget != NULL && IS_ENABLED(CONFIG_ZMK_MY_OLED_BATTERY_WIDGET)) {
        static uint8_t battery_level = 100;
        zmk_widget_battery_update(battery_widget, battery_level);
        
        // Simulate battery drain
        if (battery_level > 0) {
            battery_level--;
        }
    }
}
```

---

## Part 6: Integrating Into Your ZMK Config

### Step 15: Add Module to Your ZMK Config

In your keyboard config repository (e.g., `zmk-config-m00corne`):

**File**: `build.yaml`

```yaml
---
include:
  - board: nice_nano_v2
    shield: corne_left
  - board: nice_nano_v2
    shield: corne_right
```

**Add your module** (edit `build.yaml` or create `west-modules.yaml`):

```yaml
manifest:
  remotes:
    - name: zmkfirmware
      url-base: https://github.com/zmkfirmware
    - name: myrepo
      url-base: https://github.com/yourusername
  projects:
    - name: zmk
      remote: zmkfirmware
      revision: main
      import: app/west.yml
    - name: my-zmk-module
      remote: myrepo
      revision: main
  self:
    path: config
```

**File**: `config/west.yml`

```yaml
manifest:
  version: "1"

  remotes:
    - name: zmkfirmware
      url-base: https://github.com/zmkfirmware
    - name: myrepo
      url-base: https://github.com/yourusername

  projects:
    - name: zmk
      remote: zmkfirmware
      revision: main
      import: app/west.yml
    - name: my-zmk-module
      remote: myrepo
      revision: main

  self:
    path: config
```

### Step 16: Enable in Build Config

**File**: `config/zmk.conf`

```conf
# Enable the module
CONFIG_ZMK_MY_OLED_DISPLAY=y
CONFIG_ZMK_MY_OLED_PERIPHERAL_DISPLAY=y
CONFIG_ZMK_MY_OLED_IMAGE_WIDGET=y
CONFIG_ZMK_MY_OLED_BATTERY_WIDGET=y

# LVGL configuration
CONFIG_LVGL=y
CONFIG_ZMK_DISPLAY=y
CONFIG_DISPLAY_AUTOREFRESH=y
```

---

## Part 7: Complete Example - Peripheral Black Screen

### Full Working Example

Let's say you want to display a **full black image on the right (peripheral) side** of your split keyboard.

**Create these files:**

1. **`my-zmk-module/assets/black_image.c`** (as shown in Step 10)
2. **`my-zmk-module/src/widgets/static_image_widget.c`** (as shown in Step 7)
3. **`my-zmk-module/src/display.c`** (as shown in Step 14)
4. **`my-zmk-module/CMakeLists.txt`** (as shown in Step 5)
5. **`my-zmk-module/Kconfig`** (as shown in Step 3)
6. **`my-zmk-module/Kconfig.defconfig`** (as shown in Step 4)
7. **`my-zmk-module/module.yml`** (as shown in Step 2)

**In your ZMK config (`config/zmk.conf`):**

```conf
# Enable the OLED module with black static image
CONFIG_ZMK_MY_OLED_DISPLAY=y
CONFIG_ZMK_MY_OLED_PERIPHERAL_DISPLAY=y
CONFIG_ZMK_MY_OLED_IMAGE_WIDGET=y

# Disable animations (not supported in this simplified module)
CONFIG_ZMK_MY_OLED_BATTERY_WIDGET=n

# LVGL setup
CONFIG_LVGL=y
CONFIG_ZMK_DISPLAY=y
```

**Build and flash:**

```bash
cd zmk-config-m00corne
west build -b nice_nano_v2 -- -DSHIELD="corne_left corne_right"
west flash
```

---

## Part 8: How to Add Your Own Static Images

### Workflow for Adding a New Static Image

```
1. Create or find your 128×32 PNG/JPG image
   ↓
2. Use LVGL Image Converter: https://lvgl.io/tools/imageconverter
   - Upload image
   - Set resolution: 128×32
   - Set format: 1-bit (Black & White)
   - Download .c file
   ↓
3. Place in: my-zmk-module/assets/my_image.c
   ↓
4. Update CMakeLists.txt to include:
   zephyr_library_sources(assets/my_image.c)
   ↓
5. Declare in header (e.g., display.h):
   extern const lv_img_dsc_t my_image;
   ↓
6. Update display.c to use:
   zmk_widget_static_image_init(root_screen, &my_image, 0, 0);
   ↓
7. Rebuild and flash
```

### Crystal Example from zmk-nice-oled

The original zmk-nice-oled uses **Crystal** (a build tool) to generate images from Noto Sans font. Here's the simplified version:

**Instead of generating at build time, we:**
1. Pre-generate images once using LVGL converter
2. Check them into git as `.c` files
3. Include them in `CMakeLists.txt`

This avoids needing Crystal, Python, or font generation tools.

---

## Part 9: Troubleshooting

| Problem | Solution |
|---------|----------|
| **Module not found during build** | Check `west.yml` points to correct GitHub repo and branch |
| **CONFIG_ZMK_MY_OLED_DISPLAY not available** | Ensure `Kconfig` is in module root, `west update` the module |
| **Image not displaying** | Verify `black_image_data[]` is 512 bytes (128×32÷8), check `lv_img_dsc_t` fields |
| **Build fails: undefined reference to black_image** | Add `zephyr_library_sources(assets/black_image.c)` in CMakeLists.txt |
| **Screen stays black (no widgets)** | Check `zmk_display_init()` is called, verify LVGL is enabled in `zmk.conf` |
| **Display shows garbage pixels** | Wrong image resolution - must be exactly 128×32 pixels |

---

## Summary

You now have a **complete blueprint** for creating a ZMK module with:

✅ Modular widget system  
✅ Static image support (32×128 displays)  
✅ No animation complexity  
✅ Easy to extend with new widgets  
✅ Reusable across projects  

**Key files to remember:**
- `assets/*.c` = Pre-generated images
- `src/widgets/*.c` = Reusable UI components
- `CMakeLists.txt` = Tells build system what to compile
- `Kconfig` = User-facing configuration options
- `module.yml` = Module metadata

Happy building! 🎹💻
