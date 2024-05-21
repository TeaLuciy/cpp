# for compiling: "make -f makefile.m"
# for clear: "make -f makefile.m clean"

chess+ : chessman.o chesslib.o chess+.cc
	g++ -o chess+ chess+.cc chesslib.o chessman.o

chessman.o : chessman.h chessman.cc
	g++ -c chessman.cc -o chessman.o

chesslib.o : chesslib.h chesslib.cc chessman.o
	g++ -c chesslib.cc -o chesslib.o

clean :
	rm *.o chess+ 
