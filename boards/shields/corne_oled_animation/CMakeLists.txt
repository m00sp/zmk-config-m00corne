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
