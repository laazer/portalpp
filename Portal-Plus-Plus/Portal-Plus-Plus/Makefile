all: compile link
test: testgen compile runner

compile: ./*.cpp ./*.h
	g++ -c ./*.cpp ./*.h -std=c++11

link: ./*.o
	g++ ./*.o -o portal++ -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

testgen: PortalTestSuite.h
	cxxtestgen --error-printer -o runner.cpp PortalTestSuite.h

runner: ./*.o
	rm -f main.o
	g++ ./*.o -o runner -I$CXXTEST -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

clean:
	rm -f ./*.o
	rm -f ./*.gch
	rm -f ./portal++
	rm -f ./cout.txt
	rm -f ./runner
	rm -f ./runner.cpp