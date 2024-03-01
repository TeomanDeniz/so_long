# so_long
Ecole-42 So_long project with a small physic engine and random map generator.

<P ALIGN="CENTER"><IMG SRC="https://cdn.discordapp.com/attachments/630843149778157623/1152983162289401956/mt.gif?ex=65edcbbf&is=65db56bf&hm=0e7cf6373dd7bfea140ef630acb4a44777ac44fbb09d464a80e73a3abddd6008&"></IMG></P>

# Gameplay

You have to input a map file from the `./maps/*.ber` directory.

```
./so_long ./maps/1.ber
```

But you also can generate a random map via not inputting any `.ber` as argument.

```
./so_long
```

You can use multi keys for move across your character. Like: `W` + `D`, `S` + `A` or arrow keys.

# Setup:

Works only in MacOS OpenGL framework. (miniLibX)

You can compile this project with `make`. If you want to compile bonus project, you can make `make bonus` or `make b`.

Normal game's executable file will appear as `./so_long`, bonus game's executable file will appear as `./so_long_bonus`.

## PHONYS

Here's the arguments `MAKE.bat` and `Makefile` using:

> `b`, `bonus` -> Compile bonus file `./so_long_bonus`

> `fc`, `fclean`, `fclear` -> Clear both object and created products.

> `c`, `clean`, `clear` -> Clear only object files

> `re` -> Remake everything

# Stuffs

There is actually tons of stuffs in this projects.

## Random Map Generator

**[Random map generator](https://github.com/TeomanDeniz/so_long/blob/main/main/map_generator/map_generator.c)** is using my favorite function **[ft_rand](https://github.com/TeomanDeniz/so_long/blob/main/libft/ft_rand.c)**.

It generates a random map with a random size that's has random "player, exit" positions, randomly generated walls and coins.

**[ft_rand](https://github.com/TeomanDeniz/so_long/blob/main/libft/ft_rand.c)** is creating a 8192 bytes array for nothing and gets it's address that was randomly generated in your RAM.

Converts it's address to a number `(long long)` via `union` structure keyword and using this address and a randomizer. Rest of the things like `__TIME__` for just creating even more random numbers for some cases.

There is also a **[RMG_MAX_TROUBLE](https://github.com/TeomanDeniz/so_long/blob/main/main/map_generator/map_generator.c#L59)**, it is a **randomly** generated map so it has a change to generate multiple maps taht impossible to solve.

So, I just created a limit value that's detecting if the map created 100 failed maps, then give a fail and exit from the game safely. (You can find all Random Map Generator constatnts in **[HERE](https://github.com/TeomanDeniz/so_long/blob/main/main/so_long.h#L54C11-L54C11)**.)

## Path-Finding

It is the easiest algorithm you can even seen.

It just fills the area like filling a bucked with water. You can find the prototype in **[HERE](https://github.com/TeomanDeniz/so_long/blob/main/prototypes/maze.c)**

## Bit-Finding

I think I should get a patent for this lol

In **[HERE](https://github.com/TeomanDeniz/so_long/blob/main/main/set_mlx/set_map_textures.c)**, I am deciding which wall should have which texture. As you see my wall textures are all specigic and it is really important for me.

So, I thought: Deciding a wall's location would be enough to set it in one byte.

> How:
> 
> We have one byte: `00000000`, it has 8 bits as we see: `12345678`
> 
> And let's think we choice a wall from a random map, like from this map:
```
###################
#  # ########  E  #
#     #####  #    #
#  P    ###     # #
#              C  #
###################
```
> And I want to choice this wall:
```
###################
#  # ########  E  #
#     #####  #    #
#  P    ##@<-   # #
#         ^    C  #
###################
```
> If we going to separate all bits to surrender this wall's surroundings, it will looks like that:
```
###################
#  # ########  E  #
#     ###123 #    #
#  P    #4@5    # #
#        678   C  #
###################
```
> Coincidence? I think not!
> 
> Now, we can set all these bits as `1`s and `0`s. If the position is wall, it is going to be `1`. Else, just `0`.
```
###################
#  # ########  E  #
#     ###110 #    #
#  P    #1@0    # #
#        000   C  #
###################
```
> And it is going to return: `11010000`, that's means there should be water on the left up side of the texture.
> 
> That means `208` in decimal.
>
> If also have to evaulate the facts of multi positioning:
```
110   110   111   111
1@0   1@0   1@0   1@0
000   100   000   100
```
> That "corner" textrue must work on all of these types of positions.
> 
> So, we just simply use `&` for that:
```c
if ((X & 219U) == 219U)
 // "/" SCISSOR TEXTURE
if ((X & 208U) == 208U)
 // LEFT TOP CORNER
```
> Is this that simple? Yep.

## Movement

Movement is easy. But soft movement... Well, you need math for that. And a variable type for fractional calculation. So we gonna use `double`! Yay! Cancer.

At **[movement2 example](https://github.com/TeomanDeniz/so_long/blob/main/prototypes/movement2.c)**, I used `lerp` function to make the movement more smoother.

Instead of doing:

```c
		if (vars->moving[0] == 1)
			vars->y -= PLAYER_SPEED;
		if (vars->moving[1] == 1)
			vars->x -= PLAYER_SPEED;
		if (vars->moving[2] == 1)
			vars->y += PLAYER_SPEED;
		if (vars->moving[3] == 1)
			vars->x += PLAYER_SPEED;
```

we are created `target_x` and `target_y` to make the character `x` and `y` smoothly flow at the target points:

```c
		if (vars->moving[0] == 1)
			vars->target_y -= PLAYER_SPEED;
		if (vars->moving[1] == 1)
			vars->target_x -= PLAYER_SPEED;
		if (vars->moving[2] == 1)
			vars->target_y += PLAYER_SPEED;
		if (vars->moving[3] == 1)
			vars->target_x += PLAYER_SPEED;

		vars->x = ft_lerp(vars->x, vars->target_x, 0.02);
		vars->y = ft_lerp(vars->y, vars->target_y, 0.02);
```

You can assume `0.02` as friction during the floating.

And here ve go! We have a smooth movement like The Binding Of Isaac has!

## Physics

That's easy. At **[movement3 example](https://github.com/TeomanDeniz/so_long/blob/main/prototypes/movement3.c)**, we simply have cubes to make the movement has physics.

But how?

We created a custom struct:

```c
struct s_barrier
{
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
};
```

We just simply control if the moving target coordinates are in the barrier coordinates. If it is, then don't move the target coordinates. And that's it.

## Enemy AI

There is literally nothing in enemy AI. They are moving randomly in random directions. They are literally walking meats. XD
