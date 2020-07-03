#ifndef CONFIG_H
#define CONFIG_H

#define TILE_SIZE 16
#define TILES_PER_CHUNK 16
#define CHUNK_SIZE 256
#define	DEFAULT_TILE_COUNT 32
#define DEFAULT_TILE_DATA new TileData(DEFAULT_TILE_COUNT, DEFAULT_TILE_COUNT)
#define DEFAULT_TILE_TEXTURE new TileTexture("Content/graphics/pokemon1.png", {TILE_SIZE, TILE_SIZE})
#define CONTENT_PATH "Content/"
#define GRAPHIC_PATH "Content/graphics"

#endif // !CONFIG_H


