all: compile link
test: testgen runner

compile: ./*.cpp ./*.h
	g++ -c ./*.cpp ./*.h -std=c++11

link: ./*.o
	g++ ./*.o -o portal++ -lsfml-graphics -lsfml-window -lsfml-system

testgen: PortalTestSuite.h
	cxxtestgen --error-printer -o runner.cpp PortalTestSuite.h

runner: runner.cpp
	g++ runner.cpp -o runner -std=c++11

clean:
	rm -f ./*.o
	rm -f ./*.gch
	rm -f ./portal++
	rm -f ./cout.txt
	rm -f ./runner
	rm -f ./runner.cpp