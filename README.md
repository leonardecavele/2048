This repository contains a terminal implementation of 2048 written in C with `ncurses` during a Rush at 42 Lyon.

A Rush is a short, intensive team project completed over a weekend. It focuses on collaboration, organisation and delivering a working program within a strict time limit.

The game supports boards from 4 × 4 to 6 × 6, responsive terminal rendering, persistent high scores and graceful handling of terminal resizing and exit signals.

### How it works

The player moves every tile on the board in one direction. Tiles with the same value merge when they collide, and each successful move generates a new tile containing either 2 or 4. The game ends when no move remains, while reaching 2048 unlocks the option to save the score or continue playing.

The board size is selected from the main menu before starting a game. The rendering logic adapts the grid and its cells to the available terminal dimensions while preserving the proportions of terminal characters.

### View architecture

The part of this project I am most proud of is its view architecture.

Every screen follows the same small interface:

```c
typedef struct s_view
{
	t_errcode	(*update)(t_app *app);
	t_errcode	(*render)(t_app *app);
}	t_view;
```

The menu, game, score board and end screen each provide their own `update` and `render` functions. The application stores these views inside `t_app` and keeps a pointer to the active one through `current_view`.

The central loop therefore remains independent from every concrete screen:

```c
errcode |= app.current_view->update(&app);
errcode |= app.current_view->render(&app);
```

Changing screens only requires assigning another view to `current_view`. Adding a new screen does not require rewriting the application loop or mixing its input and rendering logic with existing screens. This separation gives the project good scalability despite being written in procedural C.

### Project structure

| Path | Responsibility |
| --- | --- |
| `srcs/app_loop.c` | Owns the application state and delegates each frame to the active view |
| `srcs/views/` | Implements the menu, game, scores and end screens |
| `srcs/render/` | Provides reusable `ncurses` rendering, sizing and font utilities |
| `srcs/gameplay/` | Contains board creation, movement, merging and end-condition logic |
| `srcs/score.c` | Loads, ranks and persists the ten best scores |
| `srcs/signals.c` | Handles terminal resizing and clean interruption |
| `includes/` | Defines the shared interfaces and application data structures |
| `libft/` | Provides the reusable C utility library built with the project |

### Terminal rendering

The interface reacts to `SIGWINCH` and redraws itself after the terminal is resized. It checks the available dimensions before rendering and displays a clear message when the window is too small.

Tile colours follow the traditional 2048 palette when the terminal supports custom colours, with a fallback palette for more limited terminals. On a sufficiently large 4 × 4 board, values can also be rendered with an ASCII font. Newly generated tiles are visually highlighted.

### Scores

The ten best scores are stored in `scores.dat`. After a victory, a player can enter a name of up to ten letters and save the result. Scores are loaded when the application starts and displayed in descending order from the scores view.

### Controls

| Context | Key | Action |
| --- | --- | --- |
| Menu | `Left` / `Right` | Select a board size from 4 × 4 to 6 × 6 |
| Menu | `P` or `Enter` | Start a game |
| Menu | `S` | Open the scores |
| Game | Arrow keys | Move the tiles |
| Game | `Escape` | Open the pause screen |
| End screen | `C` | Continue after pausing or winning |
| End screen | `S` | Enter a name and save a winning score |
| Name input | Letters / `Backspace` / `Enter` | Edit and confirm the player name |
| Application | `Escape` | Return, cancel or exit depending on the current view |

### Build and run

The project requires a C compiler, GNU Make and the `ncurses` development library.

```bash
git clone https://github.com/leonardecavele/2048.git
cd 2048
make
./2048
```

The bundled `libft` is built automatically by the main Makefile.

### Makefile targets

| Command | Result |
| --- | --- |
| `make` | Build the game |
| `make clean` | Remove object files and dependency files |
| `make fclean` | Remove all build artifacts and the executable |
| `make re` | Rebuild the project from scratch |
