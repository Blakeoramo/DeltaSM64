#ifndef CONFIG_H
#define CONFIG_H
// HACKERSM64 CONFIG DEFINES NEAR BOTTOM
/**
 * @file config.h
 * A catch-all file for configuring various bugfixes and other settings (maybe eventually) in SM64
 */

// Bug Fixes
// --| Post-JP Version Nintendo Bug Fixes
/// Fixes bug where it shows a star when you grab a key in bowser battle stages
//#define BUGFIX_STAR_BOWSER_KEY (0 || VERSION_US || VERSION_EU || VERSION_SH)

// Support Rumble Pak
// Currently not recommended, as it may cause random crashes.
//#define ENABLE_RUMBLE (1 || VERSION_SH)

// Screen Size Defines
#define SCREEN_WIDTH 320 //Static
#define SCREEN_HEIGHT 240 //Static

// Border Height Define for NTSC Versions
#ifdef TARGET_N64
// Size of the black border at the top and bottom of the screen. You can set it to different values for console and emulator.
// There is generally no reason to have a value other than 0 for emulator. As for console, it provides a (small) performance boost.

#endif

// -- HackerSM64 specific settings --

// TEST LEVEL
// Uncomment this define and set a test level in order to boot straight into said level.
// This allows you to quickly test the level you're working on.
// If you want the game to boot normally, just comment out the define again.
//#define TEST_LEVEL LEVEL_BOB

// COMMON HACK CHANGES
// Internal ROM name. NEEDS TO BE **EXACTLY** 20 CHARACTERS. Can't be 19 characters, can't be 21 characters. You can fill it with spaces.
// The end quote should be here:               "
#define INTERNAL_ROM_NAME "DELTASM64           "
// Disable lives and hide the lives counter
//#define DISABLE_LIVES
// Skip peach letter cutscene
#define PEACH_SKIP
// Remove course specific camera processing
//#define CAMERA_FIX
// Change the movement speed when hanging from a ceiling (the vanilla value is 4.f)
#define HANGING_SPEED 4.f
// Makes Mario face the direction of the analog stick directly while hanging from a ceiling, without doing "semicircles"
//#define TIGHTER_HANGING_CONTROLS
// Makes Mario turn around instantly when moving on the ground
//#define SUPER_RESPONSIVE_CONTROLS
// Disables fall damage
//#define NO_FALL_DAMAGE
// Number of coins to spawn the "100 coin" star. If you remove the define altogether, then there won't be a 100 coin star at all.
#define X_COIN_STAR 100
// Stars don't kick you out of the level
//#define NON_STOP_STARS
// Uncomment this if you want global star IDs (useful for creating an open world hack ala MVC)
//#define GLOBAL_STAR_IDS
// Uncomment this if you want to skip the title screen (Super Mario 64 logo)
//#define SKIP_TITLE_SCREEN
// Uncomment this if you want to keep the mario head and not skip it
#define KEEP_MARIO_HEAD
// Enables "parallel lakitu camera" or "aglab cam" which lets you move the camera smoothly with the dpad
#define PARALLEL_LAKITU_CAM
// Adds multiple languages to the game. Just a placeholder for the most part, because it only works with EU, and must be enabled with EU.
//#define MULTILANG (0 || VERSION_EU)
// Enables Puppy Camera 2, a rewritten camera that can be freely configured and modified.
//#define PUPPYCAM


// HACKER QOL
// Number of possible unique model ID's (keep it higher than 256)
#define MODEL_ID_COUNT 256
// Increase audio heap size to allow for more concurrent notes to be played and for more custom sequences/banks to be imported (not supported for SH)
#define EXPAND_AUDIO_HEAP
// Custom debug mode. Press DPAD left to show the debug UI. Press DPAD right to enter the noclip mode.
//#define CUSTOM_DEBUG
// Include Puppyprint, a display library for text and large images. Also includes a custom, enhanced performance profiler.
//#define PUPPYPRINT
//#define PUPPYPRINT_DEBUG 0
// Visual debug enables some collision visuals. Tapping Right on the dpad will cycle between visual hitboxes, visual surfaces, both, and neither.
// If puppyprint is enabled, then this can be cycled only while the screen is active.
//#define VISUAL_DEBUG
// Number of supported areas per level.
#define AREA_COUNT 8
// Lightweight directional lighting engine by Fazana. Intended for giving proximity and positional pointlights to small objects.
//#define PUPPYLIGHTS
// Open all courses and doors. Used for debugging purposes to unlock all content.
#define UNLOCK_ALL

// BUG/GAME QOL FIXES
// The last frame that will be considered a firsty when wallkicking
#define FIRSTY_LAST_FRAME 1

// RELATING TO EXIT COURSE
// Disable exit course
//#define DISABLE_EXIT_COURSE
// Decides whether you can exit course while moving (has no effect if you disable exit course)
//#define EXIT_COURSE_WHILE_MOVING

// OTHER ENHANCEMENTS
// Skybox size modifier, changing this will add support for larger skybox images. NOTE: Vanilla skyboxes may break if you change this option. Be sure to rescale them accordingly.
// Whenever you change this, make sure to run "make -C tools clean" to rebuild the skybox tool (alternatively go into skyconv.c and change the file in any way (like adding/deleting a space) to specifically rebuild that tool).
// When increasing this, you should probably also increase the GFX pool size. (the GFX_POOL_SIZE define in src/game/game_init.h)
#define SKYBOX_SIZE 1
// Use a much better implementation of reverb over vanilla's fake echo reverb. Great for caves or eerie levels, as well as just a better audio experience in general.
// Reverb parameters can be configured in audio/synthesis.c to meet desired aesthetic/performance needs. Currently US/JP only.
//#define BETTER_REVERB
// Collision data is the type that the collision system uses. All data by default is stored as an s16, but you may change it to s32.
// Naturally, that would double the size of all collision data, but would allow you to use 32 bit values instead of 16.
// Rooms are s8 in vanilla, but if you somehow have more than 255 rooms, you may raise this number.
// Currently, they *must* say as s8, because the room tables generated by literally anything are explicitly u8 and don't use a macro, making this currently infeasable.
#define COLLISION_DATA_TYPE s16
#define ROOM_DATA_TYPE s8

// If you want to change the extended boundaries mode, go to engine/extended_bounds.h and change EXTENDED_BOUNDS_MODE

#endif // CONFIG_H
