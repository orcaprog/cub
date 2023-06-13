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
	- [ ] determine the coordinates `there is thre steps`
		- [ ] `1` det coordinates that is represent a wall at the intersictions with __x__
		- [ ] `2` det coordinates that is represent a wall at the intersictions with __y__
			- in the two steps above we should write a function that that calculate the coord `(x,y)`
				and other one that check if you can  move to this coordinates
		- [ ] `3` choos the coordinates that have a ray __R__ less than other
	- [ ] make the ray stop if there are a wall in the next position
***

|Name|Task|
|:-|:-|
| **aelidrys** |  det coord that is represent a wall at the intersictions with x  |
| **abouassi** |  det coord that is represent a wall at the intersictions with y  |
<!-- <img src="w3schools.jpg" width="300" height="400"> -->
***

	```
		cos(o) = x/R           &&             sin(o) = y/R


		tan(o) = sin(o)/cos(o)      =>        tan(o) = y/x


		x = y/tan(o)           &&             y = tan(o)*x
	```

<div class="imge2">
	<img src="image2.png" width="400" height="500">
</div>

<div class="imge3">
	<img src="image3.png" width="400" height="500">
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
		top:-490px;
		}
</style>

***
#### link of github repo [gxxpython](https://github.com/gxxpython/cub)
