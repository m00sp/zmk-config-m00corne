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
