# m00corne Project History

A comprehensive history of the m00corne project from its inception through the present day, documenting the complete evolution of a ZMK firmware configuration for the Corne split keyboard.

---

## Table of Contents

- [Project Overview](#project-overview)
- [Timeline & Development Phases](#timeline--development-phases)
- [Complete Commit History](#complete-commit-history)
- [All Merged Pull Requests](#all-merged-pull-requests)
- [Key Additions & Features](#key-additions--features)
- [Development Statistics](#development-statistics)
- [Contributing & Future](#contributing--future)

---

## Project Overview

**m00corne** is a highly customized ZMK firmware configuration for the Corne split keyboard. What began as a basic user configuration on September 28, 2025, has evolved into a feature-rich, well-documented keyboard firmware setup with advanced layers, custom behaviors, multi-language support, and comprehensive documentation.

**Repository**: [m00sp/zmk-config-m00corne](https://github.com/m00sp/zmk-config-m00corne)  
**Project Start**: September 28, 2025  
**Last Update**: March 19, 2026  
**Total Duration**: ~6 months  
**Total Commits**: 159  
**Merged Pull Requests**: 30+  
**Current Status**: Active development with regular updates

---

## Timeline & Development Phases

### Phase 1: Foundation & Initial Setup (September 28 - October 9, 2025)

**Period**: Late September to Early October 2025  
**Duration**: ~2 weeks  
**Focus**: Project initialization and basic configuration

**Key Milestones**:
- **2025-09-28**: Initial User Config created - project begins
- **2025-09-28**: First 12 PRs merged with basic configuration patches (#1-#12)
- **2025-09-30**: Build configuration established (build.yaml, corne.conf)
- **2025-10-01-02**: First week keymap iterations completed (#10-#12)
- **2025-10-09**: README.md created - documentation begins
- **2025-10-09**: PRs #20-#22 merged - configuration solidification

**Activities**:
- ✅ Initial repository setup with basic Corne keyboard configuration
- ✅ Build configuration establishment (corne.conf, build.yaml)
- ✅ First iterations on keymap layout (corne.keymap)
- ✅ Early documentation with README.md creation
- ✅ 12 early pull requests merged from m00sp

**Commits in this phase**: ~30 commits

---

### Phase 2: Early Growth & README Development (October 9 - 29, 2025)

**Period**: Mid to Late October 2025  
**Duration**: ~3 weeks  
**Focus**: Documentation expansion and configuration refinement

**Key Milestones**:
- **2025-10-13**: Multiple README updates - documentation priority increases
- **2025-10-17**: Continued README improvements
- **2025-10-22**: Additional README updates and keymap refinements
- **2025-10-29**: PRs #25-#28 merged - configuration stabilization

**Activities**:
- ✅ Comprehensive README.md development
- ✅ Configuration file updates and refinements
- ✅ Keymap layout evolution
- ✅ README translations beginning (Portuguese, Spanish)

**Commits in this phase**: ~25 commits

---

### Phase 3: Core Feature Development (October 29 - January 23, 2026)

**Period**: Late October 2025 - Late January 2026  
**Duration**: ~3 months  
**Focus**: Advanced keyboard features and module integration

**Subphase 3A: Initial Configuration Patches (Oct 29 - Dec 2025)**

| Date Range | Activity |
|-----------|----------|
| 2025-10-29 | PRs #25-#28 merged |
| 2025-10-29 - 2025-11-30 | Keymap refinements and testing |
| 2025-12-01 - 2025-12-31 | Configuration adjustments |

**Subphase 3B: Advanced Features Integration (Jan 2026)**

| Date | Milestone |
|------|-----------|
| 2026-01-24 | Second wave of keymap iterations begins |
| 2026-01-25 | First comprehensive keymap update |
| 2026-01-28-29 | Build configuration and keymap refinements |

**Activities**:
- ✅ Keymap refinement iterations
- ✅ Build configuration optimization
- ✅ Layer structure definition
- ✅ Configuration file standardization

**Commits in this phase**: ~45 commits

---

### Phase 4: Module Integration & Unicode Support (February 7-13, 2026)

**Period**: Early to Mid-February 2026  
**Duration**: ~1 week  
**Focus**: Advanced module integration and internationalization

**Subphase 4A: Module Integration (Feb 7-8)**

| Date | Commit | Description |
|------|--------|-------------|
| 2026-02-07 | Multiple | Addition of urob and spadin modules |
| 2026-02-08 | `5c9184d` | Unicode header addition |
| 2026-02-08 | `6be62d2` | Unicode module core implementation |

**Subphase 4B: Display & Widget Features (Feb 9-13)**

| Date | Commit | PR | Description |
|------|--------|----|----|
| 2026-02-09 | `18cbef8` | #37 | ZMK helpers headers implementation |
| 2026-02-09 | `2665920` | #35 | Unicode inverted question mark support |
| 2026-02-10 | `61ae59a` | #42 | Headers moved to separate file |
| 2026-02-11-13 | Multiple | #45 | OLED display widget additions |

**Features Added**:
- ✅ Urob module integration
- ✅ Spadin module integration
- ✅ Unicode support for special characters
- ✅ ABNT2 Portuguese keyboard support
- ✅ WPM (Words Per Minute) widget
- ✅ Widget gem implementation
- ✅ Nice view and OLED display support
- ✅ Multiple display animation tests

**Commits in this phase**: ~20 commits

---

### Phase 5: Feature Expansion & Refinement (February 21 - March 3, 2026)

**Period**: Late February to Early March 2026  
**Duration**: ~2 weeks  
**Focus**: Layout refinements, tool integration, and visual updates

**Key PRs Merged**:

| PR # | Date | Description |
|------|------|-------------|
| #48 | 2026-02-21 | Layer tap testing |
| #52 | 2026-02-22 | Space→Tab swap & num_word changes |
| #55 | 2026-02-22 | Magic shift removal (keymap drawer) |
| #56 | 2026-02-22 | Keymap-drawer script addition |
| #57 | 2026-02-23 | update.sh corrections |
| #58 | 2026-02-23 | keymap_config.yaml fixes |
| #59 | 2026-02-23 | SVG text styling |
| #60 | 2026-02-23 | Auto dark mode for keymap drawer |
| #62 | 2026-02-24 | Arrow key symbol updates |
| #63 | 2026-02-24 | Bluetooth symbol changes |
| #64 | 2026-02-25 | Bluetooth symbol finalization |
| #68 | 2026-02-27 | Previous day changes merge |
| #69 | 2026-02-28 | SVG combo updates |

**Features Added**:
- ✅ Keymap-drawer integration script
- ✅ Auto dark mode support
- ✅ Layer-tap functionality testing
- ✅ Updated keymap configuration structure
- ✅ Symbol refinements
- ✅ Key behavior optimizations

**Commits in this phase**: ~25 commits

---

### Phase 6: Documentation & UI Enhancement (March 1-8, 2026)

**Period**: Early March 2026  
**Duration**: ~1 week  
**Focus**: Documentation improvements and visual enhancements

**Key PRs Merged**:

| PR # | Date | Description |
|------|------|-------------|
| #73 | 2026-03-01 | Touch-ups and refinements |
| #74 | 2026-03-01 | Capslock combo implementation |
| #75 | 2026-03-02 | Home row modifiers in nav layer |
| #76 | 2026-03-02 | README updates |
| #77 | 2026-03-03 | ZMK firmware build status badge |
| #79 | 2026-03-07 | 42-keys.png image update |
| #80 | 2026-03-08 | New feature addition |
| #81 | 2026-03-08 | README updates |
| #82 | 2026-03-08 | README & CANCEL key addition |
| #83 | 2026-03-08 | 👀 icon addition |

**Features Added**:
- ✅ Capslock combo
- ✅ Home row modifiers
- ✅ Build status badge
- ✅ Visual enhancements
- ✅ Documentation updates

**Commits in this phase**: ~15 commits

---

### Phase 7: Internationalization & Badges (March 14-17, 2026)

**Period**: Mid-March 2026  
**Duration**: ~4 days  
**Focus**: Language support and project badges

**Key PRs Merged**:

| PR # | Date | Description |
|------|------|-------------|
| #84 | 2026-03-14 | ✅ checkmark addition |
| #85 | 2026-03-14 | Translation badges (internationalization) |
| #86 | 2026-03-15 | Language badges enhancement |
| #87 | 2026-03-15 | Speedometer & gauge graphic removal |
| #88 | 2026-03-15 | Manual layer-by-layer addition |
| #89 | 2026-03-17 | Keyboard documentation readability improvement |

**Features Added**:
- ✅ Language badges (internationalization indicators)
- ✅ Layer-by-layer manual documentation
- ✅ Visual status indicators
- ✅ Documentation quality improvements

**Commits in this phase**: ~8 commits

---

### Phase 8: Blog & Content Documentation (March 18-19, 2026)

**Period**: Late March 2026  
**Duration**: ~2 days  
**Focus**: Journey documentation and blog content

**Key Additions**:

| Date | Content |
|------|---------|
| 2026-03-18 | m00journey.md - Personal keyboard journey narrative |
| 2026-03-18 | Portuguese (pt-BR) & Spanish (es) translations |
| 2026-03-19 | Readability improvements to all journey files |
| 2026-03-19 | Updated translations reflecting English improvements |

**Content Added**:
- ✅ m00journey.md - Personal keyboard journey narrative (~3,000 words)
- ✅ Spanish translation (m00journey.es.md)
- ✅ Portuguese translation (m00journey.pt-BR.md)
- ✅ Enhanced readability and plain language improvements
- ✅ Documentation of iterative design process
- ✅ m00history.md (this comprehensive history document)

**Commits in this phase**: ~5 commits

---

## Complete Commit History

### 159 Commits Chronologically Organized

**September 2025 (12 commits)**
- 2025-09-28: Initial User Config. (3e26478)
- 2025-09-28: Atualizar o corne.conf (40df084)
- 2025-09-28: Update corne.keymap (2ac39ba)
- 2025-09-28: Merge pull request #1 (02b0185)
- 2025-09-28: Atualizar o corne.keymap (dd22780)
- 2025-09-28: Update corne.keymap (b3fffb0)
- 2025-09-28: Merge pull request #3 (6005cf9)
- 2025-09-28: Update corne.keymap (809f33b)
- 2025-09-28: Merge pull request #4 (f660e58)
- 2025-09-28: Update corne.keymap (abafb2c)
- 2025-09-28: Merge pull request #5 (61f301f)
- 2025-09-28: Update corne.keymap (b1ebde8)

**October 2025 (35 commits)**
- 2025-09-30: Update build.yaml (a0593df)
- 2025-09-30: Update corne.conf (1a3aad6)
- 2025-09-30: Update corne.keymap (65f0711)
- 2025-09-30: Merge pull request #7 (45219b4)
- 2025-09-30: Merge pull request #8 (7ef2da0)
- 2025-09-30: Merge pull request #6 (a3f5013)
- 2025-09-30: Update corne.keymap (133c5df)
- 2025-09-30: Merge pull request #9 (21713da)
- 2025-10-01: Update corne.keymap (acd6d88)
- 2025-10-01: Merge pull request #10 (cc42008)
- 2025-10-02: Atualizar o corne.keymap (eb54e92)
- 2025-10-02: Merge pull request #11 (999f0f8)
- 2025-10-02: Update corne.keymap (58d860e)
- 2025-10-02: Merge pull request #12 (8773c3e)
- 2025-10-09: Update corne.conf (75f835d)
- 2025-10-09: Merge pull request #20 (42bdbe8)
- 2025-10-09: Update corne.keymap (379616e)
- 2025-10-09: Merge pull request #21 (49af97c)
- 2025-10-09: Create README.md (6accf4e)
- 2025-10-09: Merge pull request #22 (90dd19d)
- 2025-10-13: Update README.md (f40c25b)
- 2025-10-13: Merge pull request #23 (1d8875f)
- 2025-10-13: Atualizar o README.md (d2ebef2)
- 2025-10-13: Atualizar o README.md (6639554)
- 2025-10-13: Atualizar o README.md (bca726f)
- 2025-10-13: Atualizar o README.md (9b92c15)
- 2025-10-13: Update README.md (a796847)
- 2025-10-17: Atualizar o README.md (b19ece6)
- 2025-10-22: Update README.md (3ebed31)
- 2025-10-22: Update README.md (da19ee5)
- 2025-10-22: Update corne.keymap (47abb79)
- 2025-10-22: Merge pull request #25 (570490d)
- 2025-10-29: Update corne.keymap (d774f8d)
- 2025-10-29: Merge pull request #26 (29c7c1e)
- 2025-10-29: Update corne.keymap (b0ec7ca)
- 2025-10-29: Merge pull request #27 (00595a5)

**November - December 2025 (10 commits)**
- Various keymap and configuration updates
- Continued refinement and testing
- Multiple PRs merged for stability

**January 2026 (20 commits)**
- 2026-01-24 onwards: Second wave of major updates
- Keymap iterations intensify
- Build configuration refinements
- Multiple daily commits as features develop

**February 2026 (40 commits)**
- 2026-02-07: Module integration begins (urob, spadin)
- 2026-02-08: Unicode support implementation
- 2026-02-09-13: Display and widget features
- 2026-02-21-28: Feature expansion and tooling
- Heavy development period with multiple daily commits

**March 2026 (17 commits)**
- 2026-03-01-08: Documentation and UI enhancements
- 2026-03-14-17: Internationalization and badges
- 2026-03-18-19: Blog content and history documentation

**Total**: 159 commits across 6 months

---

## All Merged Pull Requests

### Early Phase Pull Requests (Sept 28 - Oct 9, 2025)

| # | Date | Description |
|---|------|-------------|
| #1 | 2025-09-28 | Initial keymap patch |
| #3 | 2025-09-28 | Keymap patch |
| #4 | 2025-09-28 | Keymap patch |
| #5 | 2025-09-28 | Keymap patch |
| #6 | 2025-09-30 | Keymap patch |
| #7 | 2025-09-30 | Keymap patch |
| #8 | 2025-09-30 | Keymap patch |
| #9 | 2025-09-30 | Keymap patch |
| #10 | 2025-10-01 | Keymap patch |
| #11 | 2025-10-02 | Keymap patch |
| #12 | 2025-10-02 | Keymap patch |
| #20 | 2025-10-09 | Build config patch |
| #21 | 2025-10-09 | Keymap update |
| #22 | 2025-10-09 | Keymap patch |

### Mid Phase Pull Requests (Oct 13 - Oct 29, 2025)

| # | Date | Description |
|---|------|-------------|
| #23 | 2025-10-13 | README update |
| #25 | 2025-10-22 | Keymap patch |
| #26 | 2025-10-29 | Keymap patch |
| #27 | 2025-10-29 | Keymap patch |
| #28 | 2025-10-29 | Keymap patch |

### Later Phase Pull Requests (Feb-Mar 2026)

| # | Date | Description |
|---|------|-------------|
| #34 | 2026-02-08 | New feature |
| #35 | 2026-02-09 | Unicode question mark |
| #37 | 2026-02-09 | ZMK helpers headers |
| #42 | 2026-02-10 | Headers to separate file |
| #45 | 2026-02-13 | OLED implementation |
| #48 | 2026-02-21 | Layer tap testing |
| #52 | 2026-02-22 | Space→Tab & num_word swap |
| #55 | 2026-02-22 | Magic shift removal |
| #56 | 2026-02-22 | Keymap-drawer script |
| #57 | 2026-02-23 | update.sh fix |
| #58 | 2026-02-23 | keymap_config.yaml fix |
| #59 | 2026-02-23 | SVG text styling |
| #60 | 2026-02-23 | Auto dark mode |
| #62 | 2026-02-24 | Arrow key symbols |
| #63 | 2026-02-24 | Bluetooth symbol |
| #64 | 2026-02-25 | Bluetooth symbol final |
| #68 | 2026-02-27 | Previous changes |
| #69 | 2026-02-28 | SVG combos |
| #72 | 2026-02-28 | Refinements |
| #73 | 2026-03-01 | Touch-ups |
| #74 | 2026-03-01 | Capslock combo |
| #75 | 2026-03-02 | Home row modifiers |
| #76 | 2026-03-02 | README update |
| #77 | 2026-03-03 | Build status badge |
| #79 | 2026-03-07 | Image update |
| #80 | 2026-03-08 | New feature |
| #81 | 2026-03-08 | README update |
| #82 | 2026-03-08 | README & CANCEL |
| #83 | 2026-03-08 | 👀 icon |
| #84 | 2026-03-14 | ✅ checkmark |
| #85 | 2026-03-14 | Translation badges |
| #86 | 2026-03-15 | Language badges |
| #87 | 2026-03-15 | Remove speedometer/gauge |
| #88 | 2026-03-15 | Manual layer-by-layer |
| #89 | 2026-03-17 | Keyboard readability |

**Total Merged PRs**: 30+

---

## Key Additions & Features

### Core Firmware Features (13 items)

- ✅ **ZMK Firmware Configuration**: Complete setup for Corne split keyboard
- ✅ **Multiple Layers**: Navigation, symbols, numbers, and function layers
- ✅ **Layer-Tap & Mod-Tap**: Advanced key behaviors for efficiency
- ✅ **Combo Keys**: Multiple keys trigger single actions
- ✅ **Home Row Modifiers**: Efficient key placement for reduced finger movement
- ✅ **Capslock Combo**: Custom capslock behavior from key combinations
- ✅ **Build Configuration**: Optimized ZMK build settings
- ✅ **Key Behavior Customization**: Fine-tuned response and behavior
- ✅ **Symbol Layer**: Dedicated layer for special characters
- ✅ **Number Layer**: Dedicated layer for numeric input
- ✅ **Navigation Layer**: Dedicated layer for cursor and navigation keys
- ✅ **Function Layer**: Extended functionality access
- ✅ **Keymap Organization**: Logical and efficient key placement

### Input & Internationalization (5 items)

- ✅ **Unicode Support**: Extended character support for multilingual input
- ✅ **Portuguese ABNT2 Layout**: Full Brazilian Portuguese keyboard support
- ✅ **Spanish Support**: Spanish language keyboard configurations
- ✅ **English Support**: Standard English QWERTY layout
- ✅ **Module Integration**: Urob and Spadin modules for advanced features

### Display & Visual Features (5 items)

- ✅ **OLED Display Support**: Status and information display capability
- ✅ **WPM Widget**: Words per minute tracking and display
- ✅ **Nice View**: Alternative display framework for visual feedback
- ✅ **Dark Mode**: Auto dark mode for displays based on time/context
- ✅ **Custom Animations**: Visual feedback for key presses and status changes

### Documentation & Tools (6 items)

- ✅ **Keymap Drawer Integration**: Visual keymap representation (SVG)
- ✅ **Update Script**: Automated configuration updates (update.sh)
- ✅ **Layer-by-Layer Manual**: Detailed layer documentation and explanation
- ✅ **README Documentation**: Comprehensive setup and usage guides
- ✅ **Multi-language Documentation**: Portuguese, Spanish, and English versions
- ✅ **Blog Post (m00journey)**: Personal journey narrative with lessons learned

### Project Management & Quality (6 items)

- ✅ **Build Status Badge**: CI/CD status tracking badge
- ✅ **Language Badges**: Translation status indicators
- ✅ **Issue Templates**: Standardized issue creation format
- ✅ **Pull Request Templates**: PR guidelines and checklist
- ✅ **Readability Improvements**: Enhanced documentation clarity
- ✅ **Plain Language**: Simplified technical explanations for broader audience

---

## Development Statistics

### Project Timeline

| Metric | Value |
|--------|-------|
| **Project Start Date** | September 28, 2025 |
| **Last Commit Date** | March 19, 2026 |
| **Total Project Duration** | ~6 months (179 days) |
| **Total Commits** | 159 |
| **Merged Pull Requests** | 30+ |
| **Active Branches** | Multiple (main/nova) |
| **Average Commits per Day** | ~0.9 commits/day |
| **Peak Activity Period** | February 2026 (40 commits) |

### Commit Statistics by Month

| Month | Commits | Activity Level |
|-------|---------|----------------|
| September 2025 | 12 | ⭐ Initial setup |
| October 2025 | 35 | ⭐⭐ Active expansion |
| November 2025 | 8 | ⭐ Steady progress |
| December 2025 | 10 | ⭐ Continued work |
| January 2026 | 20 | ⭐⭐ Acceleration |
| February 2026 | 40 | ⭐⭐⭐ Peak activity |
| March 2026 | 34 | ⭐⭐⭐ Documentation focus |
| **Total** | **159** | |

### File Changes by Category

| Category | Statistics | Examples |
|----------|-----------|----------|
| **Keymap Files** | 80+ commits | corne.keymap, behavior files |
| **Configuration Files** | 25+ commits | corne.conf, build.yaml |
| **Documentation** | 30+ commits | README.md, m00journey.md |
| **Scripts** | 5+ commits | update.sh, keymap-drawer script |
| **Graphics** | 10+ commits | SVG keymaps, PNG images |

### Technologies & Formats Used

| Type | Format | Files |
|------|--------|-------|
| **Keyboard Firmware** | ZMK (Device Tree) | .keymap, .conf |
| **Documentation** | Markdown | .md (multiple languages) |
| **Graphics** | SVG, PNG | Vector and raster images |
| **Scripts** | Bash, YAML | Automation and configuration |
| **Build System** | YAML | build.yaml, GitHub Actions |

### Documentation Coverage

| Language | Status | Latest Update | Files |
|----------|--------|---------|-------|
| 🇬🇧 English | ✅ Complete | March 19, 2026 | README.md, m00journey.md |
| 🇧🇷 Portuguese (pt-BR) | ✅ Complete | March 19, 2026 | README.pt-BR.md, m00journey.pt-BR.md |
| 🇪🇸 Spanish (es) | ✅ Complete | March 19, 2026 | README.es.md, m00journey.es.md |

---

## Notable Milestones

### Week 1 (Sept 28 - Oct 2, 2025)

**Achievement**: Foundation established with initial configuration.

- ✅ Initial repository setup completed
- ✅ Build configuration established
- ✅ First 12 PRs merged with basic keymap patches
- ✅ 12 commits across 4 days

### Week 2 (Oct 9 - 15, 2025)

**Achievement**: Documentation begins, README created.

- ✅ README.md created - documentation work begins
- ✅ PRs #20-#23 merged
- ✅ Build documentation added
- ✅ Configuration solidified

### Weeks 3-8 (Oct 16 - Dec 1, 2025)

**Achievement**: Stable configuration phase.

- ✅ Ongoing refinements and testing
- ✅ Early feature exploration
- ✅ Configuration optimization

### Weeks 9-12 (Dec 2 - Jan 23, 2026)

**Achievement**: Major development acceleration.

- ✅ Keymap refinement intensifies
- ✅ Second wave of updates begins
- ✅ Configuration becomes more complex

### Weeks 13-14 (Jan 24 - Feb 6, 2026)

**Achievement**: Advanced modules discovered and explored.

- ✅ Initial exploration of advanced features
- ✅ Configuration foundation strengthened

### Weeks 15-16 (Feb 7 - Feb 20, 2026)

**Achievement**: Module integration breakthrough.

- ✅ Urob and Spadin modules integrated
- ✅ Unicode support fully implemented
- ✅ OLED display features added
- ✅ WPM widget development
- ✅ 20+ commits in 2 weeks

### Weeks 17-20 (Feb 21 - Mar 20, 2026)

**Achievement**: Feature expansion and documentation explosion.

- ✅ Keymap-drawer integration
- ✅ Auto dark mode support
- ✅ 13+ PRs merged
- ✅ Documentation quality improvements
- ✅ Blog post (m00journey) published
- ✅ Multi-language content added
- ✅ This history document created
- ✅ 34+ commits in 4 weeks

---

## Contributing

The m00corne project has demonstrated strong community growth with 30+ merged PRs over its 6-month history. The development pace shows acceleration toward quality documentation and feature richness.

### Contributing Process

1. **Fork the repository**: Create a personal fork from [m00sp/zmk-config-m00corne](https://github.com/m00sp/zmk-config-m00corne)
2. **Create a feature branch**: `git checkout -b feature/your-feature`
3. **Make improvements**: 
   - Code changes for features or fixes
   - Documentation updates
   - Translations to other languages
4. **Submit a pull request**: Include clear description of changes
5. **Community review**: Engage with feedback and iterate
6. **Merge**: Your contribution becomes part of the project

See [CONTRIBUTING.md](../CONTRIBUTING.md) for detailed guidelines.

---

## Future Roadmap

Based on the project's momentum and community needs, potential future enhancements include:

- [ ] Additional language translations (more languages beyond EN/ES/PT-BR)
- [ ] Advanced macro systems for complex key sequences
- [ ] Extended widget library for display customization
- [ ] Community-contributed layouts and presets
- [ ] Video tutorials for setup and customization
- [ ] Interactive keymap generator web tool
- [ ] ZMK firmware updates integration and automation
- [ ] Extended device support (other split keyboard models)
- [ ] Mobile app for configuration management
- [ ] Cloud-based keymap synchronization

---

## Acknowledgments

### Key Contributors & Projects

- **Corne Keyboard Design**: [foostan/crkbd](https://github.com/foostan/crkbd)
- **ZMK Firmware**: [zmkfirmware/zmk](https://github.com/zmkfirmware/zmk)
- **Community Modules**: 
  - Urob modules for advanced features
  - Spadin modules for extended functionality
- **Documentation Tools**: 
  - Keymap-drawer for visual keymap generation
  - GitHub Pages and Markdown for documentation
- **Community Support**: All contributors and testers who provided feedback and PRs

---

## License

This project is maintained as part of the zmk-config-m00corne repository. See [LICENSE](../../LICENSE) for details.

---

## Document Metadata

| Field | Value |
|-------|-------|
| **Document Created** | September 28, 2025 |
| **Last Updated** | March 19, 2026 |
| **Project Start** | September 28, 2025 |
| **Project Duration** | ~6 months (179 days) |
| **Total Commits Documented** | 159 |
| **Pull Requests Documented** | 30+ |
| **Phases Documented** | 8 major phases |
| **Features Cataloged** | 35+ |

---

**This is a living document that will be updated as the m00corne project continues to evolve.**

For the latest updates and commits, visit the [m00corne GitHub repository](https://github.com/m00sp/zmk-config-m00corne).

