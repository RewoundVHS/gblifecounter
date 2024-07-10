//AUTOGENERATED FILE FROM png2asset
#ifndef METASPRITE_sprite_H
#define METASPRITE_sprite_H

#include <stdint.h>
#include <gbdk/platform.h>
#include <gbdk/metasprites.h>

#define sprite_TILE_ORIGIN 0
#define sprite_TILE_W 8
#define sprite_TILE_H 16
#define sprite_WIDTH 8
#define sprite_HEIGHT 16
#define sprite_TILE_COUNT 2
#define sprite_PALETTE_COUNT 1
#define sprite_COLORS_PER_PALETTE 4
#define sprite_TOTAL_COLORS 4
#define sprite_PIVOT_X 4
#define sprite_PIVOT_Y 8
#define sprite_PIVOT_W 8
#define sprite_PIVOT_H 16
extern const metasprite_t* const sprite_metasprites[1];

BANKREF_EXTERN(sprite)

extern const palette_color_t sprite_palettes[4];
extern const uint8_t sprite_tiles[32];

#endif