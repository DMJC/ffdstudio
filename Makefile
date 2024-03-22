build:
	g++ -o ffdstudio main.cpp ffb.cpp `pkg-config --cflags --libs gtkmm-4.0 sdl2`
clean:
	rm ffdstudio
