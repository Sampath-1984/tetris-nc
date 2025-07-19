# tetris-nc
A simple clone of tetris written from scratch for the linux terminal.

Screenshot:
+---------------------------+
|TETRIS                     |
|                           |
|                           |
|  ######################   |
|  # . . . . . . . . . .#   |
|  # . . . . . . . . . .#   |
|  # . . . . . . . . . .#   |
|  # . . . . . . . . . .#   |
|  # . . .[][][] . . . .#   |
|  # . . . .[] . . . . .#   |
|  # . . . . . . . . . .#   |
|  # . . . . . . . . . .#   |
|  # . . . . . . . . . .#   |
|  # . . . . . . . . . .#   |
|  # . . . . . . . . . .#   |
|  # . . . . . . . . . .#   |
|  # .[] . . . . . . .[]#   |
|  #[][] . . . . .[][][]#   |
|  #[][][] . . . .[][][]#   |
|  # .[][][][][][][] . .#   |
|  #[][] . .[][][][][][]#   |
|  # .[][][][] . .[][] .#   |
|  #[] .[][][] .[][][] .#   |
|  #[][] .[] .[] .[][][]#   |
|  ######################   |
|  Score: 168               |
|                           |
|                           |
|  <= : left  | => : right  |
|  /\ : rotate| \/ : drop   |
|   p : pause |  q : quit   |
|                           |
+---------------------------+
## Dependencies:
- g++
- make
- ncurses

Both 'g++' and 'make' should already come pre-installed with your linux distribution.

### Getting ncurses:
For Debian/Ubuntu:
```
sudo apt install libncurses5-dev libncursesw5-dev
```
For Fedora:
```
sudo dnf install ncurses-devel
```
For Arch:
```
sudo pacman -S ncurses
```

## Building the program
- Clone this repo
```
git clone https://github.com/Sampath-1984/tetris-nc.git
```
- Build with 'make'
```
cd tetris-nc/
make
```
- Execute bin/tetris-nc
```
./bin/tetris-nc
```
- Deleting the program
```
make clean
```
