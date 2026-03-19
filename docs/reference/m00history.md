# m00corne Project History

A comprehensive history of the m00corne project, documenting the evolution from initial configuration to the current feature-rich Corne keyboard firmware setup.

---

## Table of Contents

- [Project Overview](#project-overview)
- [Timeline & Major Phases](#timeline--major-phases)
- [Merged Pull Requests](#merged-pull-requests)
- [Key Additions & Features](#key-additions--features)
- [Development Statistics](#development-statistics)

---

## Project Overview

**m00corne** is a customized ZMK firmware configuration for the Corne split keyboard. The project began as a simple keyboard configuration and evolved into a comprehensive, well-documented setup with advanced features, multiple layers, custom behaviors, and extensive documentation support in multiple languages.

**Repository**: [m00sp/zmk-config-m00corne](https://github.com/m00sp/zmk-config-m00corne)  
**Total Commits**: 158+  
**Merged Pull Requests**: 30+  
**Current Status**: Active development with regular updates

---

## Timeline & Major Phases

### Phase 1: Initial Setup (January 2026)

**Period**: Late January 2026  
**Focus**: Foundation and basic keymap configuration

| Date | Commit | Description |
|------|--------|-------------|
| 2026-01-24 | `fa3fd73` | Initial user config setup |
| 2026-01-25 | Multiple | First keymap iterations and build.yaml configuration |
| 2026-01-28 | Multiple | Early corne.keymap and corne.conf adjustments |
| 2026-01-29 | `5f878f1` | Keymap refinements |

**Key Activities**:
- Initial repository setup with basic Corne keyboard configuration
- Build configuration establishment (corne.conf)
- First iterations on keymap layout
- Early merge pull requests (#1-#12 from m00sp)

---

### Phase 2: Module Integration & Unicode Support (February 2026)

**Period**: Early to Mid-February 2026  
**Focus**: Advanced features and internationalization

#### Subphase 2A: Module Integration (Feb 7-8)

| Date | Commit | Description |
|------|--------|-------------|
| 2026-02-07 | Multiple | Addition of urob and spadin modules |
| 2026-02-08 | Multiple | Unicode module implementation |
| 2026-02-08 | `5c9184d` | Unicode header addition |
| 2026-02-08 | `6be62d2` | Unicode module core |

**Features Added**:
- ✅ Urob module integration
- ✅ Spadin module integration
- ✅ Unicode support for special characters
- ✅ ABNT2 Portuguese keyboard support

#### Subphase 2B: Widget & Display Features (Feb 9-13)

| Date | Commit | Description |
|------|--------|-------------|
| 2026-02-09 | `18cbef8` | ZMK helpers headers implementation |
| 2026-02-09 | `2665920` | Unicode inverted question mark support |
| 2026-02-10 | `61ae59a` | Headers moved to separate file |
| 2026-02-11-13 | Multiple | OLED display widget additions |

**Features Added**:
- ✅ WPM (Words Per Minute) widget
- ✅ Widget gem implementation
- ✅ Nice view and OLED display support
- ✅ Multiple display animation tests

#### Subphase 2C: Refinements & Canvas Adjustments (Feb 12-13)

| Commits | Description |
|---------|-------------|
| Multiple | Canvas size adjustments for display optimization |
| `26f15e6` | OLED display implementation |

---

### Phase 3: Feature Expansion & Improvements (Mid-February 2026)

**Period**: February 15-23, 2026  
**Focus**: Layout refinements and visual updates

| Date | Commit | PR # | Description |
|------|--------|------|-------------|
| 2026-02-21 | `6f7f14a` | - | Layer tap testing |
| 2026-02-22 | `33c6600` | #52 | Space→Tab swap & num_word changes |
| 2026-02-22 | `fd1f953` | #55 | Magic shift removal (keymap drawer) |
| 2026-02-22 | `243a554` | #56 | Keymap-drawer script addition |
| 2026-02-23 | `0c12038` | #57 | update.sh corrections |
| 2026-02-23 | `1a542ea` | #58 | keymap_config.yaml fixes |
| 2026-02-23 | `d52fbaa` | #59 | SVG text bolding |
| 2026-02-23 | `8470fa7` | #60 | Auto dark mode for keymap drawer |

**Features Added**:
- ✅ Keymap-drawer integration script
- ✅ Auto dark mode support
- ✅ Layer-tap functionality testing
- ✅ Updated keymap configuration structure

---

### Phase 4: Symbol & Behavior Updates (Late February 2026)

**Period**: February 24 - March 1, 2026  
**Focus**: Key behavior refinements and symbol updates

| Date | PR # | Description |
|------|------|-------------|
| 2026-02-24 | #62 | Arrow key symbol updates |
| 2026-02-24 | #63 | Bluetooth symbol changes |
| 2026-02-25 | #64 | Bluetooth symbol finalization (light) |
| 2026-02-27 | #68 | Previous day changes merge |
| 2026-02-28 | #69 | SVG combo updates |
| 2026-02-28 | #72 | Touch-ups and refinements |
| 2026-03-01 | #73 | Additional refinements |
| 2026-03-01 | #74 | Capslock combo implementation |

---

### Phase 5: Documentation & UI Enhancements (Early March 2026)

**Period**: March 2-8, 2026  
**Focus**: README updates and badge additions

| Date | PR # | Description |
|------|------|-------------|
| 2026-03-02 | #75 | Home row modifiers in nav layer |
| 2026-03-02 | #76 | README updates |
| 2026-03-03 | #77 | ZMK firmware build status badge |
| 2026-03-07 | #79 | 42-keys.png image update |
| 2026-03-08 | #80 | New feature addition |
| 2026-03-08 | #81 | README updates |
| 2026-03-08 | #82 | README & CANCEL key addition |
| 2026-03-08 | #83 | 👀 icon addition |

---

### Phase 6: Badges, Checkmarks & Readability (March 14-17, 2026)

**Period**: March 14-17, 2026  
**Focus**: Language badges and documentation quality

| Date | PR # | Description |
|------|------|-------------|
| 2026-03-14 | #84 | ✅ checkmark addition |
| 2026-03-14 | #85 | Translation badges (internationalization) |
| 2026-03-15 | #86 | Language badges enhancement |
| 2026-03-15 | #87 | Speedometer & gauge graphic removal |
| 2026-03-15 | #88 | Manual layer-by-layer addition |
| 2026-03-17 | #89 | Keyboard documentation readability improvement |

---

### Phase 7: Blog & Content Documentation (March 18-19, 2026)

**Period**: March 18-19, 2026  
**Focus**: Journey documentation and blog post additions

| Date | Description |
|------|-------------|
| 2026-03-18 | Blog post: m00journey initial publication |
| 2026-03-18 | Portuguese (pt-BR) & Spanish (es) translations |
| 2026-03-19 | m00journey readability improvements (Copilot agent) |
| 2026-03-19 | Translation updates reflecting English improvements |

**Content Added**:
- ✅ m00journey.md - Personal keyboard journey narrative
- ✅ Spanish translation (m00journey.es.md)
- ✅ Portuguese translation (m00journey.pt-BR.md)
- ✅ Enhanced readability and plain language improvements
- ✅ Documentation of iterative design process

---

## Merged Pull Requests

### Early Phase PRs (#1-#12)

| PR # | Description | Date |
|------|-------------|------|
| #1 | Initial patch | ~Jan 24 |
| #3 | Keymap patch | ~Jan 25 |
| #4 | Keymap patch | ~Jan 25 |
| #5 | Keymap patch | ~Jan 28 |
| #6 | Keymap patch | ~Jan 28 |
| #7 | Keymap patch | ~Jan 28 |
| #8 | Keymap patch | ~Jan 28 |
| #9 | Keymap patch | ~Jan 29 |
| #10 | Keymap patch | ~Jan 29 |
| #11 | Keymap patch | ~Jan 30 |
| #12 | Keymap patch | ~Jan 30 |

### Mid Phase PRs (#20-#30)

| PR # | Description | Date |
|------|-------------|------|
| #20 | Build config patch | ~Feb 2 |
| #21 | Keymap update | ~Feb 2 |
| #22 | Keymap patch | ~Feb 2 |
| #23 | Keymap patch | ~Feb 2 |
| #25 | Keymap patch | ~Feb 2 |
| #26 | Keymap patch | ~Feb 2 |
| #27 | Keymap patch | ~Feb 2 |
| #28 | Keymap patch | ~Feb 2 |
| #29 | Keymap patch | ~Feb 2 |
| #30 | Keymap patch | ~Feb 2 |

### Recent Phase PRs (#34-#89)

| PR # | Description | Date |
|------|-------------|------|
| #34 | New feature | Feb 8 |
| #35 | Unicode question mark | Feb 9 |
| #37 | ZMK helpers headers | Feb 9 |
| #42 | Headers to separate file | Feb 10 |
| #45 | OLED implementation | Feb 13 |
| #48 | Layer tap testing | Feb 21 |
| #52 | Space→Tab & num_word swap | Feb 22 |
| #55 | Magic shift removal | Feb 22 |
| #56 | Keymap-drawer script | Feb 22 |
| #57 | update.sh fix | Feb 23 |
| #58 | keymap_config.yaml fix | Feb 23 |
| #59 | SVG text styling | Feb 23 |
| #60 | Auto dark mode | Feb 23 |
| #62 | Arrow key symbols | Feb 24 |
| #63 | Bluetooth symbol | Feb 24 |
| #64 | Bluetooth symbol final | Feb 25 |
| #68 | Previous changes | Feb 27 |
| #69 | SVG combos | Feb 28 |
| #72 | Refinements | Feb 28 |
| #73 | Touch-ups | Mar 1 |
| #74 | Capslock combo | Mar 1 |
| #75 | Home row modifiers | Mar 2 |
| #76 | README update | Mar 2 |
| #77 | Build status badge | Mar 3 |
| #79 | Image update | Mar 7 |
| #80 | New feature | Mar 8 |
| #81 | README update | Mar 8 |
| #82 | README & CANCEL | Mar 8 |
| #83 | 👀 icon | Mar 8 |
| #84 | ✅ checkmark | Mar 14 |
| #85 | Translation badges | Mar 14 |
| #86 | Language badges | Mar 15 |
| #87 | Remove speedometer/gauge | Mar 15 |
| #88 | Manual layer-by-layer | Mar 15 |
| #89 | Keyboard readability | Mar 17 |

---

## Key Additions & Features

### Core Firmware Features

- ✅ **ZMK Firmware Configuration**: Complete setup for Corne split keyboard
- ✅ **Multiple Layers**: Navigation, symbols, numbers, and function layers
- ✅ **Layer-Tap & Mod-Tap**: Advanced key behaviors
- ✅ **Combo Keys**: Multiple keys trigger single actions
- ✅ **Home Row Modifiers**: Efficient key placement
- ✅ **Capslock Combo**: Custom capslock behavior

### Input & Internationalization

- ✅ **Unicode Support**: Extended character support
- ✅ **Portuguese ABNT2 Layout**: Full Portuguese keyboard support
- ✅ **Spanish Support**: Spanish language configurations
- ✅ **English Support**: Standard English layout
- ✅ **Module Integration**: Urob and Spadin modules

### Display & Visual Features

- ✅ **OLED Display Support**: Status and information display
- ✅ **WPM Widget**: Words per minute tracking
- ✅ **Nice View**: Alternative display framework
- ✅ **Dark Mode**: Auto dark mode for displays
- ✅ **Custom Animations**: Visual feedback

### Documentation & Tools

- ✅ **Keymap Drawer Integration**: Visual keymap representation (SVG)
- ✅ **Update Script**: Automated configuration updates
- ✅ **Layer-by-Layer Manual**: Detailed layer documentation
- ✅ **README Documentation**: Comprehensive guides
- ✅ **Multi-language Documentation**: Portuguese, Spanish, English
- ✅ **Blog Post (m00journey)**: Personal journey narrative

### Project Management & Quality

- ✅ **Build Status Badge**: CI/CD status tracking
- ✅ **Language Badges**: Translation status indicators
- ✅ **Issue Templates**: Standardized issue creation
- ✅ **Pull Request Templates**: PR guidelines
- ✅ **Readability Improvements**: Enhanced documentation clarity
- ✅ **Plain Language**: Simplified technical explanations

---

## Development Statistics

### Commit Statistics

| Metric | Value |
|--------|-------|
| **Total Commits** | 158+ |
| **Merged Pull Requests** | 30+ |
| **Active Branches** | Multiple (main/nova) |
| **Commit Frequency** | ~2-3 per day (average) |
| **Project Duration** | ~2 months (Jan 24 - Mar 19, 2026) |

### File Changes

| Category | Statistics |
|----------|-----------|
| **Keymap Files** | 50+ commits modifying corne.keymap |
| **Configuration Files** | 20+ commits updating corne.conf |
| **Documentation** | 30+ commits (README, blog, docs) |
| **Scripts** | 5+ commits (update.sh, keymap-drawer) |
| **Graphics** | 10+ commits (SVG, images) |

### Languages & Formats

- **ZMK Configuration**: Device tree source (`.keymap`, `.conf`)
- **Documentation**: Markdown (`.md`)
- **Graphics**: SVG (`.svg`), PNG (`.png`)
- **Scripts**: Bash (`.sh`)
- **Build Configuration**: YAML (`.yaml`)

### Documentation Coverage

| Language | Status | Latest Update |
|----------|--------|---------|
| English | ✅ Complete | Mar 19, 2026 |
| Portuguese (pt-BR) | ✅ Complete | Mar 19, 2026 |
| Spanish (es) | ✅ Complete | Mar 19, 2026 |

---

## Notable Milestones

### Week 1 (Jan 24-28, 2026)

**Achievement**: Foundation established with initial keymap iterations and build configuration.

- Initial repository setup completed
- Build configuration established
- First 12 PRs merged with basic keymap patches

### Week 2-3 (Feb 1-7, 2026)

**Achievement**: Advanced module integration and internationalization.

- Urob and Spadin modules integrated
- Unicode support implemented for multiple languages
- Portuguese ABNT2 keyboard support added

### Week 4 (Feb 8-13, 2026)

**Achievement**: Display and widget features added.

- OLED display support implemented
- WPM widget development
- Multiple animation tests and refinements

### Week 5-6 (Feb 21 - Mar 3, 2026)

**Achievement**: Feature refinements and documentation enhancements.

- Keymap-drawer integration
- Auto dark mode support
- README updates and badges
- Build status tracking

### Week 7-8 (Mar 14-19, 2026)

**Achievement**: Documentation quality and blog content.

- Language badges added (internationalization)
- Manual layer-by-layer documentation
- Blog post (m00journey) published in 3 languages
- Readability improvements applied across documentation

---

## Future Roadmap & Next Steps

Based on the project trajectory, potential future enhancements include:

- [ ] Additional language translations
- [ ] Advanced macro systems
- [ ] Extended widget library
- [ ] Community-contributed layouts
- [ ] Video tutorials
- [ ] Interactive keymap generator
- [ ] ZMK firmware updates integration
- [ ] Extended device support (other keyboards)

---

## Contributing

The m00corne project has demonstrated strong community involvement with 30+ merged PRs. To contribute:

1. **Fork the repository**: Create a personal fork
2. **Create a feature branch**: `git checkout -b feature/your-feature`
3. **Make improvements**: Code changes, documentation, or translations
4. **Submit a pull request**: Include clear description of changes
5. **Community review**: Engage with feedback and iterate

See [CONTRIBUTING.md](../CONTRIBUTING.md) for detailed guidelines.

---

## Acknowledgments

- **Corne Keyboard Design**: [foostan/crkbd](https://github.com/foostan/crkbd)
- **ZMK Firmware**: [zmkfirmware/zmk](https://github.com/zmkfirmware/zmk)
- **Community Modules**: Urob, Spadin, and other contributors
- **Documentation Tools**: Keymap-drawer and related tools
- **Community Support**: All contributors and testers

---

## License

This project is maintained as part of the zmk-config-m00corne repository. See [LICENSE](../../LICENSE) for details.

---

**Last Updated**: March 19, 2026  
**Created**: January 24, 2026  
**Total Project Duration**: ~2 months

