// This commented version doesn't compile itself, and it's not a quine. but it
// has roughly the same game logic and game representation as the real version.
// Converting this version into the real version is pretty complex and
// frustrating because it involves making the program a quine, making it
// small enough to fit in 80x28, and also making it compile itself, but the
// actual game logic doesn't change.

#include <ctime>
#include <curses.h>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <unistd.h>

/* string s stores the program data (well not in this commented version, but in
 * the real version it does). It's a wstring because the state of the program is
 * also encoded in the spare bits of each character in the string.
 *
 * wstring is guaranteed to have at least 16 bit characters
 * 4 bits: unused
 * 2 bits: direction (for head this means the next direction after tick)
 * 2 bits: state (also infers colour)
 * 8 bits: character
 */
std::wstring s = L"########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################"
                 "########################################";

// map input characters to direction constants
std::map<int, int> map = {{'s', 0}, {'a', 1}, {'w', 2}, {'d', 3}};

int width = 40, height = 20, x = 2, y = 2, px = 2, py = 0, dir, extra;

// get a 2-bit direction from an x,y position in s
int get_dir(int x, int y) { return (s[(y * width) + x] >> 10) & 3; }

// clear and set a direction at x,y
int set_dir(int d) { (s[(y * width) + x] &= ~(3 << 10)) |= ((d & 3) << 10); }

// get a 2-bit colour from an x,y position in s
int get_color(int x, int y) { return (s[(y * width) + x] >> 8) & 3; }

// clear and set a colour
void set_color(int x, int y, int c) {
  (s[(y * width) + x] &= ~(3 << 8)) |= (c & 3) << 8;
}

void draw() {
  move(0, 0);
  // iterate over s and draw each character
  for (int i = 0; i < width * height; i += 2) {
    // set the colour attribute
    attron(extra = s[i] & 3 << 8);
    addch((char)s[i]);
    addch(s[i + 1]);
    attroff(extra);
    // manually insert newlines where they should be, so s doesn't
    // need to encode them
    if (i % width == width - 2) {
      addch('\n');
    }
  }
  refresh();
}

// move the food pixel to a new random position. it's really inefficient,
// optimised for small source size
int move_food() {
  int fx = (rand() % width / 2) * 2, fy = rand() % height;
  if (get_color(fx, fy) == 0) {
    set_color(fx, fy, 2);
  } else {
    move_food();
  }
}

// apply a direction dir to given x,y coords
int apply(int dir, int &x, int &y) {
  if (!dir) {
    y++;
  }
  if (dir == 1) {
    x -= 2;
  }
  if (dir == 2) {
    y--;
  }
  if (dir == 3) {
    x += 2;
  }
}

// compute the next frame of the game
int do_tick() {
  dir = get_dir(x, y);
  if ((extra = getch()) >= 0 && abs(map[extra] - dir) != 2) {
    dir = map[extra];
  }
  set_dir(dir);
  apply(dir, x, y);
  if (y == height || x < 0 || y < 0 || x > width - 2 || get_color(x, y) == 1) {
    return 0;
  }
  set_dir(dir);
  if (get_color(x, y) == 2) {
    move_food();
  } else {
    s[(py * width) + px] &= ~(3 << 8);
    apply(get_dir(px, py), px, py);
  }
  set_color(x, y, 1);
  draw();
  return 1;
}

// runloop
void run() {
  while (do_tick()) {
    usleep(150000);
  }
}

int main(int argc, char *argv[]) {
  srand(time(0));
  initscr();
  start_color();
  for (int i = 0; i < 3; i++) {
    // create color pairs (only pair 1 and 2 will be used; 0 is useless)
    init_pair(i, 0, i + 9);
    // set the initial position of the snake (length 3)
    set_color(2, i, 1);
  }
  noecho();
  timeout(0);
  curs_set(0);
  move_food();
  run();
  endwin();
}
