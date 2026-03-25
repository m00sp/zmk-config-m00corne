# Step-by-Step: Port Urchin Peripheral Animation to OLED

Complete instructions for porting the urchin-peripheral-animation module to work with zmk-oled-nice.

**Important**: Read each step completely before executing. Don't skip "Verify" sections.

---

## SECTION 1: Extract and Prepare Artwork

### Step 1.1: Clone the urchin-peripheral-animation repository

```bash
cd /tmp
git clone --depth 1 https://github.com/GPeye/urchin-peripheral-animation.git
cd urchin-peripheral-animation
```

**Verify**: You should see `README.md`, `boards/`, `assets/`, and `zephyr/` directories.

### Step 1.2: Examine the animation frames

```bash
ls -la assets/urchincart/
```

You should see 12 C files (corro01.c through corro12.c). These are the converted animation frames.

```bash
ls -la assets/urchinpngart/
```

You should see 12 PNG files (corro01.png through corro12.png). These are the original pixel art frames.

**Important Note**: The original Urchin artwork is 68×140 pixels (which is 140×68 when rotated for nice!view). For OLED, we need to determine the safe animation area.

### Step 1.3: Copy artwork frames to your repository

Create the animation assets directory:

```bash
cd /home/mimomu/zmk-config-m00corne
mkdir -p boards/shields/corne_oled_animation/assets/
```

Copy the PNG files (we'll convert them next):

```bash
cp /tmp/urchin-peripheral-animation/assets/urchinpngart/*.png \
   boards/shields/corne_oled_animation/assets/
```

**Verify**: Check that 12 PNG files are in the new directory:

```bash
ls -la boards/shields/corne_oled_animation/assets/ | wc -l
# Should show 12 files + 2 (., ..) = 14 lines
```

---

## SECTION 2: Convert Artwork to C Arrays

### Step 2.1: Understand the OLED display dimensions

Run this to check your current OLED configuration:

```bash
grep -r "CONFIG_NICE_OLED\|display_height\|display_width" config/ boards/
```

**Common OLED sizes**:
- 128×64 (most common 0.96" OLED)
- 128×32 (0.91" OLED)
- 64×128 (vertical orientation)

The urchin artwork is currently 68×140 pixels. You have **three options**:

**Option A (Recommended)**: Resize to 64×64 (fits most OLEDs, square animation area)
**Option B**: Resize to 96×96 (if your OLED supports it)
**Option C**: Keep original size and clip/center (requires careful positioning)

**For this guide, we'll use Option A (64×64).**

### Step 2.2: Resize the PNG images to 64×64

You need an image tool. Install ImageMagick:

```bash
# On Debian/Ubuntu
sudo apt-get install imagemagick

# On macOS
brew install imagemagick

# On Arch
sudo pacman -S imagemagick
```

Resize each image:

```bash
cd boards/shields/corne_oled_animation/assets/
for f in corro*.png; do
  convert "$f" -resize 64x64 -background white -gravity center -extent 64x64 "resized_$f"
done
ls -la resized_*.png
```

**Verify**: All resized files should be exactly 64×64 pixels:

```bash
identify resized_*.png | head -3
# Should show: resized_corro01.png PNG 64x64 ...
```

### Step 2.3: Convert PNG images to C arrays using LVGL converter

Go to https://lvgl.io/tools/imageconverter

For each `resized_corro*.png`:

1. Click "Choose file" and select the PNG
2. Set these options:
   - **Color Format**: `CF_ALPHA_1_BIT` (black and white only)
   - **Output Format**: `C array`
3. Click "Convert"
4. Copy the C code output

Create a C header file for each frame:

```bash
cd /home/mimomu/zmk-config-m00corne/boards/shields/corne_oled_animation/

# Create a frames directory
mkdir -p widgets/frames
```

For **each** `resized_corro*.png`, you'll get C code from LVGL converter. Create files like:

**File: `widgets/frames/corro01.c`** (example - repeat for corro02 through corro12)

```c
/*
 * Generated from resized_corro01.png using LVGL converter
 * Copyright (c) 2024 ZMK Contributors
 * SPDX-License-Identifier: MIT
 */

#include <lvgl.h>

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_CORRO01
#define LV_ATTRIBUTE_IMG_CORRO01
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_CORRO01 uint8_t corro01_map[] = {
#if CONFIG_NICE_OLED_WIDGET_INVERTED
    0xff, 0xff, 0xff, 0xff, /*Color of index 0*/
    0x00, 0x00, 0x00, 0xff, /*Color of index 1*/
#else
    0x00, 0x00, 0x00, 0xff, /*Color of index 0*/
    0xff, 0xff, 0xff, 0xff, /*Color of index 1*/
#endif

    // [YOUR C ARRAY DATA HERE - copy from LVGL converter]
};

const lv_img_dsc_t corro01 = {
    .header.cf = LV_IMG_CF_ALPHA_1BIT,
    .header.always_zero = 0,
    .header.reserved = 0,
    .header.w = 64,
    .header.h = 64,
    .data_size = 544, // (64 * 64) / 8 + 8 bytes header
    .data = corro01_map,
};
```

**Critical Step**: You must do this for **all 12 frames** (corro01 through corro12).

**Time-saving note**: This is tedious. If you have Python installed, here's a script to batch-convert:

```python
#!/usr/bin/env python3
# Name this: convert_frames.py
import os
import sys
from PIL import Image
import struct

def png_to_c_array(png_path, output_c_path, frame_num):
    """Convert PNG to 1-bit C array"""
    img = Image.open(png_path).convert('1')  # Convert to 1-bit
    
    # Get pixel data (1-bit: 0 = black, 1 = white)
    pixels = list(img.getdata())
    
    # Pack into bytes (8 pixels per byte)
    data = []
    for i in range(0, len(pixels), 8):
        byte = 0
        for j in range(8):
            if i + j < len(pixels):
                byte = (byte << 1) | (1 if pixels[i + j] else 0)
        data.append(byte)
    
    # Generate C code
    c_code = f"""/*
 * Auto-generated from {os.path.basename(png_path)}
 * Frame {frame_num}
 */

#include <lvgl.h>

const uint8_t corro{frame_num:02d}_map[] = {{
    // LVGL 1-bit image data
"""
    
    # Add hex data (16 bytes per line)
    for i in range(0, len(data), 16):
        hex_line = ', '.join(f'0x{b:02x}' for b in data[i:i+16])
        c_code += f"    {hex_line},\n"
    
    c_code += f"""
}};

const lv_img_dsc_t corro{frame_num:02d} = {{
    .header.cf = LV_IMG_CF_ALPHA_1BIT,
    .header.always_zero = 0,
    .header.reserved = 0,
    .header.w = 64,
    .header.h = 64,
    .data_size = {len(data) + 8},
    .data = corro{frame_num:02d}_map,
}};
"""
    
    with open(output_c_path, 'w') as f:
        f.write(c_code)
    
    print(f"Generated: {output_c_path}")

# Process all frames
for i in range(1, 13):
    png_file = f"boards/shields/corne_oled_animation/assets/resized_corro{i:02d}.png"
    c_file = f"boards/shields/corne_oled_animation/widgets/frames/corro{i:02d}.c"
    
    if os.path.exists(png_file):
        png_to_c_array(png_file, c_file, i)
```

Run it:

```bash
cd /home/mimomu/zmk-config-m00corne
python3 convert_frames.py
```

**Verify**: You should have 12 C files:

```bash
ls -la boards/shields/corne_oled_animation/widgets/frames/
# Should show corro01.c through corro12.c
```

---

## SECTION 3: Create Animation Controller

### Step 3.1: Create the animation widget header

**File: `boards/shields/corne_oled_animation/widgets/animation.h`**

```c
/*
 * Copyright (c) 2024 ZMK Contributors
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>

// Forward declarations for animation frames
extern const lv_img_dsc_t corro01, corro02, corro03, corro04,
                          corro05, corro06, corro07, corro08,
                          corro09, corro10, corro11, corro12;

#define ANIMATION_FRAME_COUNT 12
#define ANIMATION_FRAME_DELAY_MS 100  // Adjust for speed

// Get frame by index (0-11)
const lv_img_dsc_t *animation_get_frame(int index);

// Initialize animation widget
void animation_widget_init(lv_obj_t *parent, lv_coord_t x, lv_coord_t y);

// Advance to next frame
void animation_advance_frame(void);

// Get current frame index
int animation_get_current_frame(void);
```

### Step 3.2: Create the animation controller C file

**File: `boards/shields/corne_oled_animation/widgets/animation.c`**

```c
/*
 * Copyright (c) 2024 ZMK Contributors
 * SPDX-License-Identifier: MIT
 */

#include "animation.h"
#include <zephyr/kernel.h>
#include <sys/util.h>

// Frame array (ordered)
static const lv_img_dsc_t *animation_frames[ANIMATION_FRAME_COUNT] = {
    &corro01, &corro02, &corro03, &corro04,
    &corro05, &corro06, &corro07, &corro08,
    &corro09, &corro10, &corro11, &corro12,
};

static int current_frame = 0;
static lv_obj_t *animation_image = NULL;
static struct k_timer animation_timer;

// Timer callback - advance frame
static void animation_timer_callback(struct k_timer *timer) {
    animation_advance_frame();
}

const lv_img_dsc_t *animation_get_frame(int index) {
    if (index < 0 || index >= ANIMATION_FRAME_COUNT) {
        return animation_frames[0];
    }
    return animation_frames[index];
}

void animation_advance_frame(void) {
    current_frame = (current_frame + 1) % ANIMATION_FRAME_COUNT;
    
    if (animation_image) {
        lv_img_set_src(animation_image, animation_get_frame(current_frame));
    }
}

int animation_get_current_frame(void) {
    return current_frame;
}

void animation_widget_init(lv_obj_t *parent, lv_coord_t x, lv_coord_t y) {
    // Create image object
    animation_image = lv_img_create(parent);
    lv_obj_set_pos(animation_image, x, y);
    lv_img_set_src(animation_image, animation_get_frame(0));
    
    // Start timer for animation
    k_timer_init(&animation_timer, animation_timer_callback, NULL);
    k_timer_start(&animation_timer, K_MSEC(ANIMATION_FRAME_DELAY_MS),
                  K_MSEC(ANIMATION_FRAME_DELAY_MS));
}
```

---

## SECTION 4: Create Shield Configuration Files

### Step 4.1: Create CMakeLists.txt

**File: `boards/shields/corne_oled_animation/CMakeLists.txt`**

```cmake
zephyr_library()

# Include animation widget source files
zephyr_library_sources(
    widgets/animation.c
    widgets/frames/corro01.c
    widgets/frames/corro02.c
    widgets/frames/corro03.c
    widgets/frames/corro04.c
    widgets/frames/corro05.c
    widgets/frames/corro06.c
    widgets/frames/corro07.c
    widgets/frames/corro08.c
    widgets/frames/corro09.c
    widgets/frames/corro10.c
    widgets/frames/corro11.c
    widgets/frames/corro12.c
)

zephyr_library_include_directories(widgets)
```

### Step 4.2: Create Kconfig.shield

**File: `boards/shields/corne_oled_animation/Kconfig.shield`**

```kconfig
config SHIELD_CORNE_OLED_ANIMATION
    def_bool $(shields_list_contains,corne_oled_animation)
    select LVGL
    select ZMK_DISPLAY

config CORNE_OLED_ANIMATION_ENABLED
    bool "Enable Urchin peripheral animation"
    depends on SHIELD_CORNE_OLED_ANIMATION
    default y
```

### Step 4.3: Create Kconfig.defconfig

**File: `boards/shields/corne_oled_animation/Kconfig.defconfig`**

```kconfig
if SHIELD_CORNE_OLED_ANIMATION

config LVGL
    default y

config ZMK_DISPLAY
    default y

config CORNE_OLED_ANIMATION_ENABLED
    default y

endif
```

### Step 4.4: Create configuration file

**File: `boards/shields/corne_oled_animation/corne_oled_animation.conf`**

```conf
# Enable display
CONFIG_ZMK_DISPLAY=y

# Enable animation widget
CONFIG_CORNE_OLED_ANIMATION_ENABLED=y

# Optional: adjust animation speed (default 100ms per frame)
# Lower = faster, Higher = slower
# CONFIG_ANIMATION_FRAME_DELAY_MS=75
```

### Step 4.5: Create device tree overlay

**File: `boards/shields/corne_oled_animation/corne_oled_animation.overlay`**

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

**Note**: Adjust the OLED address (0x3c), GPIO pin (4), and dimensions (128×64) to match your hardware.

### Step 4.6: Create ZMK metadata file

**File: `boards/shields/corne_oled_animation/corne_oled_animation.zmk.yml`**

```yaml
file_format: "1"
id: corne_oled_animation
name: Corne OLED Animation
type: shield
requires: [corne_left, corne_right]
features:
  - display
  - animation
```

---

## SECTION 5: Integrate into Build System

### Step 5.1: Update build.yaml

Edit `build.yaml` and add the animation shield:

```yaml
---
include:
  - board: nice_nano_v2
    shield: corne_left corne_oled_animation
  - board: nice_nano_v2 
    shield: corne_right corne_oled_animation
  - board: nice_nano_v2
    shield: settings_reset
```

**Verify**: The file should have the `corne_oled_animation` shield on both left and right builds.

### Step 5.2: Update corne.conf

Edit `config/corne.conf` and ensure display is enabled:

```conf
# Display
CONFIG_ZMK_DISPLAY=y
CONFIG_ZMK_DISPLAY_STATUS_SCREEN_CUSTOM=y

# Animation
CONFIG_CORNE_OLED_ANIMATION_ENABLED=y
```

---

## SECTION 6: Build and Test

### Step 6.1: Clean previous builds

```bash
cd /home/mimomu/zmk-config-m00corne
rm -rf build/
```

### Step 6.2: Build the firmware

```bash
# Using GitHub Actions (if you have it set up)
git add .
git commit -m "Add urchin OLED animation widget"
git push

# OR build locally with ZMK SDK
# Assuming you have ZMK environment set up:
west build -b nice_nano_v2 -- -DSHIELD="corne_left corne_oled_animation"
west build -b nice_nano_v2 -- -DSHIELD="corne_right corne_oled_animation"
```

**If build fails**:
- Check CMakeLists.txt for missing frame files
- Verify all 12 corro*.c files exist in `widgets/frames/`
- Check that frame #s in animation.h match actual files

### Step 6.3: Flash to device

```bash
# Flash left side
west flash --board nice_nano_v2 --sideload

# Flash right side
west flash --board nice_nano_v2 --sideload
```

### Step 6.4: Verify animation on device

After flashing:
1. Connect the keyboard
2. You should see the animation cycling on the OLED display
3. Check for correct speed (adjust `ANIMATION_FRAME_DELAY_MS` if too fast/slow)
4. Verify animation doesn't glitch or freeze

**Troubleshooting**:
- Animation frozen: Timer not starting correctly
- Animation too fast/slow: Adjust delay in `animation.h`
- Garbage on display: Check image dimensions or C array data
- No display: Check overlay device tree configuration

---

## SECTION 7: Optimization and Fine-Tuning

### Step 7.1: Adjust animation speed

Edit `boards/shields/corne_oled_animation/widgets/animation.h`:

```c
#define ANIMATION_FRAME_DELAY_MS 100  // Change this value
```

- Reduce (e.g., 75) for faster animation
- Increase (e.g., 150) for slower animation

### Step 7.2: Reduce memory if needed

If the animation takes too much flash:

**Option A**: Reduce frame count (skip every other frame: 12 → 6)
**Option B**: Compress frames (use indexed color instead of 1-bit)
**Option C**: Reduce resolution (64×64 → 48×48)

### Step 7.3: Add custom status screen integration

To display animation **with** other info (battery, BLE status), create a custom status widget:

**File: `widgets/custom_status.c`** (optional advanced step)

```c
#include <lvgl.h>
#include "animation.h"

void custom_status_screen_init(void) {
    lv_obj_t *screen = lv_scr_act();
    
    // Animation (left side)
    animation_widget_init(screen, 0, 0);
    
    // Battery indicator (right side) - implement as needed
    lv_obj_t *battery = lv_label_create(screen);
    lv_label_set_text(battery, "Battery: 80%");
    lv_obj_set_pos(battery, 80, 0);
}
```

---

## SECTION 8: Deployment and Documentation

### Step 8.1: Commit your changes

```bash
cd /home/mimomu/zmk-config-m00corne
git add boards/shields/corne_oled_animation/
git add build.yaml
git add config/corne.conf
git commit -m "Add Urchin peripheral OLED animation widget"
git push origin nova  # or your branch
```

### Step 8.2: Document in your repository

Create `docs/OLED_ANIMATION.md` in your repo root:

```markdown
# OLED Animation Setup

## Overview
Urchin peripheral animation for OLED displays using zmk-oled-nice.

## Files
- Animation code: `boards/shields/corne_oled_animation/`
- Config: `build.yaml`, `config/corne.conf`

## Customization
Edit animation speed in `widgets/animation.h`:
```c
#define ANIMATION_FRAME_DELAY_MS 100  // milliseconds per frame
```

## Building
```bash
git pull
west build -b nice_nano_v2 -- -DSHIELD="corne_left corne_oled_animation"
west build -b nice_nano_v2 -- -DSHIELD="corne_right corne_oled_animation"
```
```

### Step 8.3: Final verification checklist

- [ ] All 12 animation frame files (corro01.c - corro12.c) exist
- [ ] CMakeLists.txt lists all 12 frame files
- [ ] animation.h declares all 12 frames
- [ ] animation.c has all 12 frames in the array
- [ ] build.yaml includes `corne_oled_animation` shield
- [ ] Device tree overlay matches your OLED pins/address
- [ ] Firmware builds without errors
- [ ] Firmware flashes without errors
- [ ] Animation displays and cycles on device
- [ ] Animation speed is satisfactory
- [ ] No glitches or memory errors

---

## APPENDIX: Troubleshooting

### Problem: Build fails with "undefined reference to corroXX"
**Solution**: Check CMakeLists.txt has all 12 frame files listed exactly as they exist.

### Problem: Animation doesn't display
**Solution**: 
1. Verify device tree overlay is correct
2. Check OLED I2C address (default 0x3c)
3. Test with a simple image first (not animation)

### Problem: Animation stutters or restarts
**Solution**:
1. Reduce frame count (remove every other frame)
2. Increase frame delay (slower animation uses less CPU)
3. Check for firmware size (may be running out of flash)

### Problem: Animation is too fast/slow
**Solution**: Adjust `ANIMATION_FRAME_DELAY_MS` in animation.h

### Problem: Garbage/corrupted pixels on OLED
**Solution**:
1. Verify PNG to C array conversion
2. Check image dimensions (should be 64×64)
3. Re-generate C arrays from original PNGs

---

## APPENDIX: Commands Cheat Sheet

```bash
# Clone reference repo
git clone --depth 1 https://github.com/GPeye/urchin-peripheral-animation.git

# Resize images
convert "input.png" -resize 64x64 -background white -gravity center -extent 64x64 "output.png"

# Check PNG dimensions
identify *.png

# Build firmware
west build -b nice_nano_v2 -- -DSHIELD="corne_left corne_oled_animation"

# Clean and rebuild
rm -rf build/ && west build -b nice_nano_v2 -- -DSHIELD="corne_left corne_oled_animation"

# Check git status before committing
git status

# View file sizes
du -sh boards/shields/corne_oled_animation/
```

---

**Done!** Your OLED animation widget is now integrated into your ZMK firmware.

For future reference, keep this document in your docs/ folder.
