# axSurface
Forked from https://github.com/weissms/owb-mirror .


## to-do-list
* building ;
* 3rd-parth dependencies ;
* cross platform validate ;
* sync up with latest webkit codebase ; 



## How to build (ubuntu)
* install dependencies ;

```shell
	sudo apt install cmake cmake-curses-gui python perl pkg-config bison flex gperf
	sudo apt install libxml2-dev libcairo2-dev libsdl1.2-dev libcurl4-openssl-dev
```


* pkg-config-path ;
	-	libpng12 (`pkg_check_modules`)
	-	JPEG (`find_package`)

* compile flags ;
`-w`
`-std=c++11`
`-std=c99`

* how to build ;

```shell
	mkdir ../build-axSurf
	cd ../build-axSurf
	cmake ../axSurface/trunk
	make
```


