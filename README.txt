Raycasting project
Project using only standart library functions (write, read, exit, free, malloc, perror, errno) and mlx library function for screen and picture management. Other functions are handemade.

2 version:
for MacOS: using MetalApi (don't support virtual machines)
for Linux

Requirements for Linux:
sudo apt install gcc make xorg libxext-dev libbsd-dev 
./cub3d_lin/mlx_linux/configure
make

*NOTE:
Running may requests install side apps, for example X11, Xext etc.
For Linux installation: sudo apt install xorg libxext-dev zlib1g-dev libbsd-dev 

To run:
make
./cub3D.out maps/test.cub

You can use any map instead maps/test.cub.

Example of map:

S ./textures/sprite_1.xpm
F 77,0,254

R 1000 1000
EA ./textures/east.xpm
NO ./textures/north.xpm

WE ./textures/west.xpm

C 92,206,255

SO ./textures/south.xpm

        1111111111111111111111111
        1000000000110000000000001
        1011000001110W02222220001
        1001000000000002222220001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10022000000000001100000000001
10022000000000001101010010001
11000111110101111101111000111
11110111 1110101 101111010001
11111111 1111111 111111111111

Map rules:
1. S - texture for sprite in xpm format
2. F - floor color in format: RRR,GGG,BBB
3. R - Resolution in format: width height
4. EA, NO, WE, SO - textures for walls (east, north, west, south)
5. C - ceiling color in format RRR,GGG,BBB
6. 0 - free space, 1 - wall, 2 - sprite; E, N, S, W - starting point with view direction. 
7. Map must be closed by walls.
8. Map must have .cub extension.
