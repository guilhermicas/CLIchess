output: ../src/main.o ../src/board/board.o ../src/board/piece/piece.o
	gcc ../src/main.o ../src/board/board.o ../src/board/piece/piece.o -o ../bin/output

piece.o: ../src/board/piece/piece.c ../src/board/piece/piece.h
	gcc -c ../src/board/piece/piece.c

board.o: ../src/board/board.c ../src/board/board.h
	gcc -c ../src/board/board.c

main.o: ../src/main.c
	gcc -c ../src/main.c

clean:
	rm -r ../src/**/*.o
