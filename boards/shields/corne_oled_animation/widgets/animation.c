/*
 * Copyright (c) 2024 ZMK Contributors
 * SPDX-License-Identifier: MIT
 */

#include "animation.h"
#include <zephyr/kernel.h>
#include "util.h"

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
