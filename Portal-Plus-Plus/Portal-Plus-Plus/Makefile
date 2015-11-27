all: compile link

compile: ./*.cpp ./*.h
	g++ -c ./*.cpp ./*.h -std=c++11

link: ./*.o
	g++ ./*.o -o portal++ -lsfml-graphics -lsfml-window -lsfml-system
	
clean:
	rm -f ./*.o
	rm -f ./*.gch
	rm -f ./portal++
	rm -f ./cout.txt