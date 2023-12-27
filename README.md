![Screenshot 2023-12-27 at 21 11 17](https://github.com/KrolPolski/so_long/assets/47835762/633b2c74-c9c0-4e39-a5c0-14eb8e2c0246)

This is a very simple game where the player moves through a map, defined by an text file, to collect all the chests and then move to the exit in the fewest number of moves.

Dependencies:
https://github.com/codam-coding-college/MLX42 - this should be automatically installed using the Makefile.

It should accept any map that follows the following rules:
1) The map must end with a .ber extension
2) The map must be rectangular (all the lines must be the same length)
3) The map defines walls with a '1', empty space with a '0', and collectibles with a 'C'
4) The starting position is defined with a 'P'
5) The ending position is defined with a 'E'
6) There must be exactly one exit, one start, and at least one collectible.
7) There must be a valid path to all collectibles and the exit
8) There must be walls all along the four edges of the map

An example of a valid map:
```111111111111111
1P000111C000011
10CC00000001111
1001100C0000EC1
10C000111001111
100010CCC000001
111111111111111```


