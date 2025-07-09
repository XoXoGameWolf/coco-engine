all: linux windows

linux: build/game-linux.zip
windows: build/game-windows.zip

build/game-linux.zip: build/app
	rm build/game-linux.zip
	mkdir game
	cp -rf build/app resources game
	zip -r build/game-linux.zip game
	rm -rf game

build/game-windows.zip: build/app.exe
	rm build/game-windows.zip
	mkdir game
	cp -rf build/app.exe resources windows/* game
	zip -r build/game-windows.zip game
	rm -rf game

build/app: src/* include/coco/*
	gcc -I include -o build/app src/main.c include/glad.c -lglfw -lGL -lm

build/app.exe: src/* include/coco/*
	x86_64-w64-mingw32-gcc -I include -o build/app.exe src/main.c include/glad.c -L windows -lglfw3 -lopengl32 -lm