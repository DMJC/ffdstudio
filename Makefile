build:
	g++ -o ffdstudio main.cpp ffb.cpp open_existing_profile.cpp `pkg-config --cflags --libs gtkmm-3.0 sdl2`
clean:
	rm ffdstudio