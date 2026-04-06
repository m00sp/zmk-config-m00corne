# My m00corne journey: from zero to comfortable split keyboard bliss

## The beginning: why I wanted a split keyboard

I typed with hands together on a single wide keyboard. After years of software development and writing, I noticed strain building up. My shoulders would round forward, my wrists would angle awkwardly, and by the end of long coding sessions, my neck would be tight.

I discovered the Corne keyboard—a minimalist split keyboard design. "Minimalist" means it has just 42 keys instead of the 100+ on a standard keyboard. "Split" means it separates left and right halves, letting each hand sit at a natural angle.

The catch: it requires custom configuration. There's no plug-and-play option. You build the firmware, define your own keymap, and optimize it for your workflow. That's where my journey began.

## The challenge: learning the Corne ecosystem

I faced a steep learning curve when starting:

* **Fewer keys**: How do I access numbers, symbols, and special characters with only 42 keys?
* **Layers instead of shift keys**: Most special characters come through *layers*—different "modes" you activate, similar to holding Shift for capitals, but much more flexible.
* **Custom firmware configuration**: I needed to learn the ZMK firmware system to build and flash my configuration.
* **Finding my own optimal setup**: There's no "right" answer. Every user discovers what layers, shortcuts, and key placements work for their hands and workflow.

This wasn't just about buying a keyboard. It was about understanding a different way keyboards can work.

## The journey: building my perfect setup

My m00corne configuration evolved through an iterative process. I didn't arrive at my final setup overnight.

### Phase 1: The foundation

I started with the basics—getting the keyboard to compile and flash. The first commits established:

* **Board and firmware setup**: Configuring ZMK to recognize the hardware.
* **Basic keymap**: Creating a functional layout for daily typing.
* **Layer structure**: Defining how to access less-common keys (numbers, symbols, navigation).

At this stage, I had a working keyboard, but it felt awkward. Decades of muscle memory on standard keyboards doesn't transfer instantly. Every number, arrow key, and symbol required conscious thought.

### Phase 2: Optimization and comfort

Over several iterations, I refined:

* **Key placement**: Moving frequently-used keys to easier positions.
* **Layer organization**: Discovering which keys to group together made the most sense.
* **Speed improvements**: Adding layer-tap and mod-tap features (keys that do one thing when tapped, another when held).
* **Ergonomic adjustments**: Fine-tuning which fingers should access which layers.

Small tweaks transformed my experience. Moving the space bar to a thumb key, adjusting layer modifiers, and reorganizing number placement changed typing from "I can do this" to "this feels natural."

### Phase 3: Advanced features

As I grew comfortable, I added:

* **Macros**: Quick shortcuts for common coding patterns or commands.
* **Combo keys**: Two keys pressed together trigger a third key or command.
* **Custom behaviors**: Advanced ZMK features that made my workflow faster.
* **Refined layout**: A keymap that worked with my habits, not against them.

Each improvement made a measurable difference. What started as "this is different" became "I can't imagine using a standard keyboard anymore."

## The results: why it was worth it

After settling on my final configuration, the benefits were clear:

* **Reduced strain**: My shoulders, wrists, and neck no longer ache after long sessions. The split design lets my hands sit at a natural, relaxed angle.
* **Faster typing**: My typing speed increased once muscle memory built up. The optimized layer system keeps frequently-used keys at my fingertips.
* **Genuine comfort**: The keyboard now feels like an extension of my hands, not something I'm fighting.
* **Personal workflow**: My keymap is built specifically for how I work, not how manufacturers think people should work.

Beyond personal benefits, I discovered something bigger: a keyboard can teach you. Designing your own keymap teaches ergonomics, efficiency, and intentional design.

## Lessons learned: what I'd tell my past self

### 1. Give it time

The first week was frustrating. The second week, slightly less. By week three, things clicked. Expect a learning curve—it pays off.

### 2. Small changes matter

A single key repositioned or a layer organized differently can make a huge difference. You don't need a complete redesign. Incremental improvements compound.

### 3. Copy, then customize

I started by studying existing keymaps from the Corne community. Understanding how others solved problems gave me a foundation for my own setup. You don't need to invent everything from scratch.

### 4. Document your choices

Document *why* you chose each configuration file, layer, and macro. This helps you remember your reasoning if you troubleshoot later.

### 5. There's no "final" version

My configuration has been updated many times and will continue to evolve. As my workflows change or I discover new ZMK features, I adjust. That's not failure—it's the point.

## For you: what this means if you're curious

If you're interested in split keyboards or the Corne specifically, here's what my journey suggests:

* **It's learnable**: You don't need to be a hardware engineer or firmware expert. If you can follow documentation and experiment, you can build a working Corne setup.
* **It's worth the effort**: Reduced discomfort and workflow improvements justify the learning curve. Your hands will thank you.
* **The community helps**: The Corne community is active, friendly, and willing to share configurations. You're not alone.
* **Start small**: You don't need perfect ergonomics from day one. Start with a basic, functional setup and refine from there.

## The bottom line

My m00corne journey transformed how I work. It wasn't just about swapping keyboards. It was about taking control of a tool I use 8+ hours a day and shaping it to fit my hands, not the other way around.

If you spend hours at a keyboard and experience strain or discomfort, split keyboards offer a different path. There's a learning curve, but it was one of the best technical investments I've made.

The keyboard on my desk is the result of dozens of small improvements, experiments, and iterations. Every key is placed intentionally. Every layer serves a purpose. Every session is genuinely comfortable.

That's what makes m00corne special—not just the final configuration, but the process of thoughtfully building something that works for you.

---

## Resources to get started

If you want to explore split keyboards:

* **Corne Keyboard**: [QMK/ZMK documentation](https://github.com/foostan/crkbd).
* **ZMK Firmware**: [Official ZMK documentation](https://zmk.dev).
* **This Configuration**: Check the configuration files in this repository to see how I structured my specific setup.

Welcome to the split keyboard journey. Your hands are waiting.
