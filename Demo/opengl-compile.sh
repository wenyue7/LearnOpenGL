g++ gltest.cpp glad.c -o a.out $(pkg-config --libs --cflags gl glew glfw3 glib-2.0 glproto glu) -lGLEW  -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -lglib-2.0 -lGLU -ldl -lglut -lSOIL -lXxf86vm -lXinerama -lXcursor

g++ gltest.cpp -o a.out $(pkg-config --libs --cflags gl glew glfw3 glib-2.0 glproto glu) -lGLEW  -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi
