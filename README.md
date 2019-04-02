# Lemin
    
### The goal of this project is to find the quickest way to get n ants across the farm.

* Obviously, there are some basic constraints. To be the first to arrive, ants will need to take the shortest path (and that isn’t necessarily the simplest). They will also need to avoid traffic jams as well as walking all over their fellow ants.

* At the beginning of the game, all the ants are in the room ##start. The goal is to bring them to the room ##end with as few turns as possible. Each room can only contain one ant at a time. (except at ##start and ##end which can contain as many ants as necessary.)

* At each turn you can move each ant only once and through a tube (the room at the receiving end must be empty).

* You must to display your results on the standard output in the following format:
```
number_of_ants
the_rooms
the_ways
the_links

Lx-y Lz-w Lr-o ...
```
x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y, w, o represents the rooms’ names.

#### Map example

	12 			- numbers of aints
	##start			- start room
	1 23 3			- number of room and coordinates
	2 16 7
	#comment		- any comment
	3 16 3
	4 16 5
	5 9 3
	6 1 5
	7 4 8
	8 9 5
	##end			- this is the end 
	1-2			- links between rooms
	2-4
	1-3
	3-4
	1-4
	1-5
	5-6
	6-7
	7-8
	8-4
	6-4
	1-8

You can choose one in `maps/` after cloning this repo.

### Usage
```
git clone https://github.com/vkozhemi/lem-in.git
cd lem-in
make
./lem-in < maps/map.txt
```
Also as a bonus to this project I decided to find all unique ways on the map and let the ants walk on all of them.

## Example 1

	3
	##start
	0 1 2
	##end
	4 9 2
	1 3 4
	2 5 0
	3 5 4
	0-1
	1-4
	0-2
	2-4
	1-3
	3-2

### shortest unique paths

	Way [0] ->(1)->(4)
	Way [1] ->(2)->(4)

### steps of each aint (L1, L2, L3) in the room (1, 2 ...)

	L1-1 L2-2 
	L2-4 L1-4 L3-1 
	L3-4 

![Image alt](https://github.com/vkozhemi/lem-in/raw/master/img/1.png)

## Example 2

	13
	##start
	0 1 2
	##end
	19 9 2
	1 3 4
	2 5 0
	3 5 4
	4 4 4
	5 5 5
	#comment
	##### another comment
	6 6 6
	7 7 7
	8 8 8
	9 9 9
	10 10 10
	11 11 11
	12 12 12
	13 13 13
	14 14 14
	15 15 15
	16 16 16
	17 17 17
	18 18 18
	0-1
	0-1
	1-19
	1-1
	1-2
	2-3
	3-19
	0-4
	4-5
	5-6
	6-7
	7-8
	8-9
	9-19
	0-10
	10-11
	11-12
	12-13
	13-14
	14-15
	15-16
	16-17
	17-18
	18-19
	3-5
	3-7
	5-12
	7-15

### shortest unique paths
	Way [0] ->(1)->(19)
	Way [1] ->(4)->(5)->(3)->(19)

### steps of each aint (L1, L2 ... L13) in the room (1, 2 ... 19)
	L1-1 L2-4 
	L2-5 L1-19 L3-1 L4-4 
	L2-3 L4-5 L3-19 L5-1 L6-4 
	L4-3 L6-5 L5-19 L7-1 L8-4 
	L6-3 L8-5 L7-19 L9-1 L10-4 
	L8-3 L10-5 L9-19 L11-1 L12-4 
	L10-3 L12-5 L11-19 L13-1 
	L12-3 L13-19 
	L12-19 

![Image alt](https://github.com/vkozhemi/lem-in/raw/master/img/2.png)

