# m00sp's ZMK Config

[![Build ZMK firmware](https://github.com/m00sp/zmk-config-m00corne/actions/workflows/build.yml/badge.svg)](https://github.com/m00sp/zmk-config-m00corne/actions/workflows/build.yml)

![](keymap_img/corne1.jpg)
![](keymap_img/corne2.jpg)

This repository contains my personal [ZMK firmware](https://github.com/zmkfirmware/zmk/)
configuration files for	a	42-keys Corne keyboard with a [Colemak Mod-DH](https://colemakmods.github.io/mod-dh/) layout adapted for Brazilian Portuguese with full support for Spanish and English languages. Inspired by [Miryoku](https://github.com/manna-harbour/miryoku/), [urob's config](https://github.com/urob/zmk-config/) and [Kim's variation](https://github.com/infused-kim/zmk-config).

The configuration currently builds against `v0.3` of upstream ZMK, extended by various [ZMK
modules](https://zmk.dev/docs/features/modules). All build dependencies are pinned in the [`west`
manifest file](https://github.com/m00sp/zmk-config-m00corne/blob/master/config/west.yml).

> [!WARNING]
>
> Under **_active development_**. Expect breaking changes and scarce/incomplete documentation.

## Highlights

- [x] Localization for Portuguese (Brazil-ABNT2). Using [zmk-locales](https://github.com/joelspadin/zmk-locales) module.
- [x] <kbd>¿</kbd> and <kbd>¡</kbd> for Spanish support (Linux and Windows). Using [ZMK macros](https://zmk.dev/docs/keymaps/behaviors/macros) and [zmk-unicode](https://github.com/urob/zmk-unicode) module [^1].
- [x] ["Timeless" homerow mods](#timeless-homerow-mods)
- [x] Auto-toggle off numbers, navigation and mouse layers using [zmk-auto-layer](https://github.com/urob/zmk-auto-layer).
- [x] Magic shift quadrupling as Repeat/Sticky-shift/Capsword/Shift
- [x] Simpler Devicetree syntax using helper macros from [zmk-helpers](https://github.com/urob/zmk-helpers).
- [x] Vertical widgets for oled displays using [zmk-oled-nice](https://github.com/mctechnology17/zmk-nice-oled).
<<<<<<< HEAD
- [x] [Combos](https://zmk.dev/docs/config/combos) instead of ["Mod-Tap"](https://zmk.dev/docs/keymaps/behaviors/hold-tap#mod-tap) for layer navigation. This is to avoid overloading the thumbs (see overview for an explanation about why I have chosen this).
=======
- [x] [Combos](https://zmk.dev/docs/config/combos) instead of ["Mod-Tap"](https://zmk.dev/docs/keymaps/behaviors/hold-tap#mod-tap) for layer navigation.
>>>>>>> origin/master

## The keymap

Here is the keymap with the base, navigation, numbers, mouse and fundtion layers.

![](keymap_img/42-keys.png)

## Documentation

For a breakdown by layer and a detail explanation layer by layer go to link below.

- [m00corne User Manual](docs/reference/README.md)

## Overview



### Timeless homerow mods

From ZMK docs:
> The most popular form of home-row mods is known as "timeless home-row mods", configured to minimize the dependency on timing.

This is from uncle urob:
> [Homerow mods](https://precondition.github.io/home-row-mods) (aka "HRMs") can be a game changer --
> at least in theory. In practice, they require some finicky timing: In its most naive implementation,
> in order to produce a "mod", they must be held _longer_ than `tapping-term-ms`. In order to produce
> a "tap", they must be held _less_ than `tapping-term-ms`. This requires very consistent typing
> speeds that, alas, I do not possess. Hence my quest for a "timer-less" HRM setup.
>
> After months of tweaking, I eventually ended up with an HRM setup that is essentially timer-less,
> resulting in virtually no misfires.[^2] Yet it provides a fluent typing experience with mostly no
> delays.
>
> One way to make HRMs effectively timer-less is to set `tapping-term-ms` to an extremely large value,
> say 5 seconds. This removes the need for quick timing decisions, but it introduces two issues: (1)
> To trigger a mod, you'd need to hold the HRM keys for what feels like an eternity. (2) During normal
> typing, there's a noticeable delay between pressing a key and seeing it appear on the screen.[^3] To
> address these, I use positive and negative exceptions that short-circuit the tapping term in most
> scenarios.
>
> - Specifically, to address the activation delay, I use ZMK's `balanced` flavor, which produces a
  > "hold" if another key is both pressed and released within the tapping-term. Because that's exactly
  > what I normally do with HRMs, there's virtually never a need to wait past my long tapping term (see
  > below for two exceptions).
> - To address the typing delay, I use ZMK's `require-prior-idle-ms` property,
  > which immediately resolves an HRM as a "tap" when it's pressed shortly _after_
  > another key has been tapped. This all but completely eliminates the delay.
>
> This is great but there are still a few rough edges:
>
> - When rolling keys, I sometimes unintentionally end up with "nested" key
  > sequences: `key1` down, `key2` down and up, `key1` up. Because of the
  > `balanced` flavor, this would falsely register `key1` as a mod. As a remedy,
  > I use ZMK's "positional hold-tap" feature to force HRMs to always resolve as
  > "tap" when the _next_ key is on the same side of the keyboard. Problem solved.
> - ... or at least almost. By default, positional-hold-tap performs the
  > positional check when the next key is _pressed_. This is not ideal, because it
  > prevents combining multiple modifiers on the same hand. To fix this, I use the
  > `hold-trigger-on-release` setting, which delays the positional-hold-tap
  > decision until the next key's _release_. With this, mods can be combined when
  > held while positional hold-tap continues to work as expected when keys are
  > tapped.
> - So far, nothing of the configuration depends on the duration of
  > `tapping-term-ms`. In practice, there are two reasons why I don't set it to
  > infinity:
  > 1. Sometimes, in rare circumstances, I want to combine a mod with a alpha-key
     > _on the same hand_ (e.g., when using the mouse with the other hand). My
     > positional hold-tap configuration prevents this _within_ the tapping term.
     > By setting the tapping term to something large but not crazy large (I use
     > 280ms), I can still use same-hand `mod` + `alpha` shortcuts by holding the
     > mod for just a little while before tapping the alpha-key.
  > 2. Sometimes, I want to press a modifier without another key (e.g., on
     > Windows, tapping `Win` opens the search menu). Because the `balanced`
     > flavour only kicks in when another key is pressed, this also requires
     > waiting past `tapping-term-ms`.
> - Finally, it is worth noting that this setup works best in combination with a
  > dedicated shift for capitalization during normal typing (I like sticky-shift
  > on a home-thumb). This is because shifting alphas is the one scenario where
  > pressing a mod may conflict with `require-prior-idle-ms`, which may result in
  > false negatives for fast typers.
>
  > ## Smart layers and other gimmicks
>
> ##### Numword
>
> Inspired by Jonas Hietala's
> [Numword](https://www.jonashietala.se/blog/2021/06/03/the-t-34-keyboard-layout/#where-are-the-digits)
> for QMK, I implemented my own
> [Auto-layer behavior](https://github.com/urob/zmk-auto-layer) for ZMK to set up
> Numword. It is triggered via a single tap on "Smart-Num". Numword continues to
> be activated as long as I type numbers, and deactivates automatically on any
> other keypress (holding it activates a non-sticky num layer).
>
> After using Numword for more than a year now, I have been overall very happy
> with it. When typing single digits, it effectively is a sticky-layer but with
> the added advantage that I can also use it to type multiple digits.
>
> The main downside is that if a sequence of numbers is _immediately_ followed by
> any of the letters on which my numpad is located (WFPRSTXCD), then the automatic
> deactivation won't work. But this is rare -- most number sequences are
> terminated by `space`, `return` or some form of punctuation/delimination. To
> deal with the rare cases where they aren't, there is a `CANCEL` key on the
> navigation-layer that deactivates Numword, Capsword and Smart-mouse. (It also
> toggles off when pressing `Numword` again, but I find it cognitively easier to
> have a dedicated "off-switch" than keeping track of which modes are currently
> active.)
>
> ##### Smart-Mouse
>
> Similarly to Numword, I have a smart-mouse layer (activated by comboing
> <kbd>W</kbd> + <kbd>P</kbd>), which replaces the navigation cluster with scroll
> and mouse-movements, and replaces the right thumbs with mouse buttons. Pressing
> any other key automatically deactivates the layer.
>
> ##### Magic Repeat/Shift/Capsword
>
> My right thumb triggers three variations of shift as well as repeat: Tapping
> after any alpha key yields key-repeat (to reduce SFUs). Tapping after any other
> keycode yields sticky-shift (used to capitalize alphas). Holding activates a
> regular shift, and double-tapping (or equivalently shift + tap) activates ZMK's
> Caps-word behavior.
>
> One minor technical detail: While it would be possible to implement the
> double-tap functionality as a tap-dance, this would add a delay when using
> single taps. To avoid the delays, I instead implemented the double-tap
> functionality as a mod-morph.

[^1]:
    I call it "timer-less", because the large tapping-term makes the behavior
    insensitive to the precise timings. One may say that there is still the
    `require-prior-idle` timeout. However, with both a large tapping-term and
    positional-hold-taps, the behavior is _not_ actually sensitive to the
    `require-prior-idle` timing: All it does is reduce the delay in typing.

[^2]:
    The delay is determined by how quickly a key is released and is not directly
    related to the tapping-term. But regardless of its duration, most people
    still find it noticeable and disruptive.

[^3]:
    E.g, if your WPM is 70 or larger, then the default of 150ms (=10500/70)
    should work well. The rule of thumb is based on an average character length
    of 4.7 for English words. Taking into account 1 extra tap for `space`, this
    yields a minimum `require-prior-idle-ms` of (60 \* 1000) / (5.7 \* x) ≈ 10500
    / x milliseconds. The approximation errs on the safe side, as in practice
    home row taps tend to be faster than average.
