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
