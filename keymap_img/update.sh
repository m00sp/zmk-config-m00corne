#!/usr/bin/nu

echo '\n\nRemoving old ZMK keymap...'
rm keymap.yaml
echo '\n\nParsing ZMK keymap...'
keymap -c keymap_config.yaml parse -c 12 -z ../config/corne.keymap | save keymap.yaml

# echo '\n\nAdjusting keymap yaml...'
# ./keymap_img_adjuster.py keymap.yaml

echo '\n\nRemoving old keymap.svg...'
rm keymap.svg
echo '\n\nDrawing keymap...'
keymap -c keymap_config.yaml draw --qmk-keyboard crkbd/rev1 --qmk-layout LAYOUT_split_3x6_3 keymap.yaml | save keymap.svg
