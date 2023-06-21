<div align="center">
  <h1 style="text-align: center;">Cub3D</h1>
</div>

- ## Parcine

	- [x] parce first element
	- [x] parce map

- ## Ray_cast
	- [x] draw a simple map
	- [x] make player move
	- [x] put one ray
	- [x] make ray rotate
	- [x] determine the direction `<` `^` `>` and `v`
	***
	- [x] determine the coordinates `there is thre steps`
		- [x] `1` det coordinates that is represent a wall at the intersictions with __x__
		- [x] `2` det coordinates that is represent a wall at the intersictions with __y__
			- in the two steps above we should write a function that that calculate the coord `(x,y)`
				and other one that check if you can  move to this coordinates
		- [x] `3` choos the coordinates that have a ray __R__ less than other
	- [x] make the ray stop if there are a wall in the next position
***

|Name|Task|
|:-|:-|
| **aelidrys** |    |
| **abouassi** |    |
<!-- <img src="w3schools.jpg" width="300" height="400"> -->
***

	```
		cos(o) = x/R           &&             sin(o) = y/R


		tan(o) = sin(o)/cos(o)      =>        tan(o) = y/x


		x = y/tan(o)           &&             y = tan(o)*x
	```

<div class="imge2">
	<h5 style="text-align: center;">det coord with y</h5>
	<img src="image2.png" width="300" height="400">
</div>

<div class="imge3">
	<h5 style="text-align: center;">det coord with x</h5>
	<img src="image3.png" width="300" height="400">
</div>


<style>
	.imge2
		{
		display:flex;
		/* justify-content:center;
    	align-items: center; */
		}
	.imge3
		{
		display:flex;
		justify-content:right;
    	align-items: right;
		position:relative;
		top:-400px;
		}
</style>

***
- ## Draw Walls
	- [ ] darwing walls
	- [ ] draw walls with texturs

***
#### link of github repo [gxxpython](https://github.com/gxxpython/cub)
