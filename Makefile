NAME := game

all: linux

linux: build/$(NAME)-linux.zip
windows: build/$(NAME)-windows.zip

build/$(NAME)-linux.zip: build/app
	rm build/$(NAME)-linux.zip
	mkdir $(NAME)
	cp -rf build/app resources $(NAME)
	zip -r build/$(NAME)-linux.zip $(NAME)
	rm -rf $(NAME)

build/$(NAME)-windows.zip: build/app.exe
	rm build/$(NAME)-windows.zip
	mkdir $(NAME)
	cp -rf build/app.exe resources windows/* $(NAME)
	zip -r build/$(NAME)-windows.zip $(NAME)
	rm -rf $(NAME)

build/app: src/* include/coco/*
	gcc -I include -o build/app src/main.c include/glad.c -lglfw -lGL -lm -lopenal -lalut

build/app.exe: src/* include/coco/*
	x86_64-w64-mingw32-gcc -I include -o build/app.exe src/main.c include/glad.c -L windows -lglfw3 -lopengl32 -lm
