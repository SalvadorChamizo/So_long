# so_long

Short Description
-----------------
so_long is a compact 2D puzzle game that loads map files and runs using a lightweight OpenGL helper library (MLX42). It demonstrates map parsing, game-state management, basic rendering, and input handling for a small playable application.

Key Features
------------
- Parse and validate .ber map files and produce clear map error messages.
- Run a playable 2D map with collectible items, exits, player, and optional enemies.
- Use MLX42 for cross-platform windowing and image handling ([MLX42/README.md](MLX42/README.md)).
- Buildable with a single Makefile that compiles the game, bonus variant, and vendored libs ([Makefile](Makefile)).
- Includes a minimal libft utility library and test maps ([libft/Makefile](libft/Makefile), [maps/](maps/)).

Tech Stack
----------
- Language: C (project sources under [src/](src/), bonus in [bns/](bns/))
- Graphics / Windowing: MLX42 ([MLX42/README.md](MLX42/README.md), [`mlx_image_t`](MLX42/include/MLX42/MLX42.h))
- PNG handling: LodePNG (bundled in MLX42: [MLX42/include/lodepng/lodepng.h](MLX42/include/lodepng/lodepng.h))
- Build: Make (root [Makefile](Makefile), MLX42 [Makefile](MLX42/Makefile), libft [Makefile](libft/Makefile))
- Utilities: small custom libft in [libft/](libft/)

Architecture & Design
---------------------
- Single-process C program with a clear separation:
  - Map parsing & validation: [src/read_maps.c] and [src/maps_utils.c] (maps and validation live under [maps/]).
  - Game state & initialization: [`init_game`](src/initialize.c) and [`initialize_obj`](src/initialize.c).
  - Rendering and input delegated to MLX42 — images/textures are created and managed through MLX42 types such as [`mlx_image_t`](MLX42/include/MLX42/MLX42.h).
- Build orchestrated through a top-level Makefile that also builds MLX42 and libft if needed.

Getting Started
---------------
Prerequisites
- POSIX environment (Linux or macOS). Windows supported via MSYS/MinGW with adjustments.
- gcc or compatible C compiler
- make
- GLFW + system OpenGL development headers (MLX42 expects glfw dev libs)
  - On Debian/Ubuntu: sudo apt install build-essential libglfw3-dev libx11-dev xorg-dev
  - On macOS: install via Homebrew: brew install glfw

Installation
1. Ensure prerequisites are installed.
2. Build the project (this will build MLX42 and libft as required):

```sh
make
```
3. Optional: build bonus target:

```sh
make bonus
```
Running the project

- Run the compiled binary and provide a map file from [maps/]. Example:

```sh
./so_long maps/map1.ber

```

Usage
-----

- The program expects a single .ber map path argument (examples in maps/).
- Controls: typical implementations use arrow keys or WASD for movement (controls are provided via MLX42 input hooks; see MLX42/docs/Input.md). If control mapping differs, consult the source for input handling.
- Common entry points:
    - Game initialization and state: init_game
    - Map parsing and validation: files under [src/], map examples in maps/

What I Learned / Technical Challenges
-------------------------------------

- Integrating a third-party cross-platform library (MLX42) into a small C codebase required reconciling build systems and platform flags.
- Managing manual memory in C for parsing and resource cleanup (see [src/free_memory.c] and bonus variants in [bns/]).
- Adapting image loading and simple texture handling via LodePNG (bundled in MLX42) to support in-game textures.

Future Improvements
-------------------

- Add automated unit/integration tests for map parsing and game logic.
- CI pipeline to build on Linux/macOS and run static analysis.
- Improve CLI (map selection, debug flags) and add runtime options (headless/testing mode).
- Refactor rendering to decouple MLX42 specifics behind a small graphics adapter for easier testing/replacement.

Author & Contact
----------------

- Author: schamizo
- Contact: salvadorchamizo@gmail.com

Notes & Assumptions
-------------------

Assumed standard map CLI usage and arrow/WASD controls; consult source if behavior differs.
If platform-specific linking issues arise, refer to MLX42 docs (MLX42/README.md) for platform flags and requirements.
