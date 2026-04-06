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
