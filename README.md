This repository contains a terminal implementation of 2048 written in C with `ncurses` during a Rush at 42 Lyon.

A Rush is a short, intensive team project completed over a weekend. It focuses on collaboration, organisation and producing a working solution within a limited time.

### How it works

The player moves the tiles with the arrow keys. Tiles containing the same value merge when they collide, and a new tile is generated after each successful move.

The board size can be selected from 4 × 4 to 6 × 6. The interface adapts to the size of the terminal, handles window resizing and uses colours or ASCII characters to display the tiles.

The game also stores the ten best scores in a local file.

### Architecture

Each screen is represented by a `t_view` structure containing an `update` function and a `render` function.

```c
typedef struct s_view
{
	t_errcode	(*update)(t_app *app);
	t_errcode	(*render)(t_app *app);
}	t_view;
```

The main loop only calls these functions through the active view. Moving between the menu, the game, the scores and the end screen only requires changing the `current_view` pointer.

This separation keeps the application loop independent from the different screens and makes new views easy to add. This scalable view system is the part of the project I am most proud of.

### Usage

Build and start the game with:

```bash
make
./2048
```

Use the left and right arrow keys in the menu to select the board size. Press `P` or `Enter` to play, `S` to display the scores and `Escape` to pause or exit.

The targets `clean`, `fclean` and `re` are also available.
