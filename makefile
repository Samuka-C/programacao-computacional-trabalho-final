EXE := .exe # swap to `EXE := ` for linux
CXX := g++ # swap for your prefered c++ compiler

main$(EXE): main.c
	$(CXX) $^ -o $@
