OPTIONS=-I`pwd` `-lGL -lGLEW -lglfw -lSOIL`

OBJS = canvas.o polygon.o line.o circle.o sprite.o turtle.o rectangle.o text.o turtleSim.o color.o  sim.o ellipse.o

HDRS =  spriteInterface.h pose.h composite.h common_def.h  sprite.h canvas.h polygon.h turtle.h line.h  sim.h keycodes.h circle.h ellipse.h rectangle.h text.h turtleSim.h color.h simplecpp

default: $(OBJS) $(HDRS)
	ar rcs libsprite.a $(OBJS)

config: 
	cp -v $(HDRS) ../include
	rm -f ..lib/libsprite.a
	rm -f libsprite.a
	make
	cp libsprite.a ../lib/

canvas.o: canvas.cpp canvas.h sprite.h common_def.h turtle.h
	../makes++ -g -c canvas.cpp -o canvas.o 

polygon.o: polygon.cpp polygon.h sprite.h common_def.h
	../makes++ -g -c polygon.cpp -o polygon.o

line.o: line.cpp line.h sprite.h common_def.h
	../makes++ -g -c line.cpp -o line.o 

rectangle.o: rectangle.cpp rectangle.h sprite.h common_def.h
	../makes++ -g -c rectangle.cpp -o rectangle.o 

circle.o: circle.cpp circle.h sprite.h common_def.h
	../makes++ -g -c circle.cpp -o circle.o 

ellipse.o: ellipse.cpp ellipse.h sprite.h common_def.h
	../makes++ -g -c ellipse.cpp -o ellipse.o 

text.o: text.cpp text.h sprite.h canvas.h common_def.h
	../makes++ -g -c text.cpp -o text.o 

sprite.o: sprite.h sprite.cpp common_def.h pose.h
	../makes++ -g -c sprite.cpp -o sprite.o 

turtle.o: turtle.h turtle.cpp common_def.h
	../makes++ -g -c turtle.cpp -o turtle.o 

turtleSim.o: turtleSim.h turtleSim.cpp
	../makes++ -g -c turtleSim.cpp -o turtleSim.o 

color.o: color.h color.cpp
	../makes++ -g -c color.cpp -o color.o 

sim.o: sim.h sim.cpp
	../makes++ -g -c sim.cpp -o sim.o

clean:
	rm *.o *.a

