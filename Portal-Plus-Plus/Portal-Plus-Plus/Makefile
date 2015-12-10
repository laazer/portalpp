all: compile link
valgrind: debug-compile link
test: testgen test-compile runner

compile: ./*.cpp ./*.h
	g++ -c ./*.cpp ./*.h -std=c++11

debug-compile: ./*.cpp ./*.h
	g++ -ggdb -c ./*.cpp ./*.h -std=c++11

test-compile: ./*.cpp ./*.h PortalTestSuite.hpp
	g++ -c ./*.cpp ./*.h PortalTestSuite.hpp -std=c++11

link: ./*.o
	g++ ./*.o -o portal++ -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

testgen: PortalTestSuite.hpp
	cxxtestgen --error-printer -o runner.cpp PortalTestSuite.hpp

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