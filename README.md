# ASCII_Tetris

**Comando per la compilazione del programma su windows:**

g++ -I/mingw64/include/ncurses -o ASCII_Tetris main.cpp GameOver.cpp Leaderboard.cpp Game.cpp Board.cpp GameInfo.cpp MainMenu.cpp Tetramino.cpp shapes/Line.cpp shapes/LLshape.cpp shapes/RLshape.cpp shapes/SLshape.cpp shapes/Square.cpp shapes/SRshape.cpp shapes/TShape.cpp -lncurses -L/mingw64/bin -static

**Comando per la compilazione del programma su MacOS:**

g++ -o ASCII_Tetris main.cpp GameOver.cpp Leaderboard.cpp Game.cpp Board.cpp GameInfo.cpp MainMenu.cpp Tetramino.cpp shapes/Line.cpp shapes/LLshape.cpp shapes/RLshape.cpp shapes/SLshape.cpp shapes/Square.cpp shapes/SRshape.cpp shapes/TShape.cpp -lncurses

**Comando per la compilazione del programma su Linux:**

g++  main.cpp GameOver.cpp Leaderboard.cpp Game.cpp Board.cpp GameInfo.cpp MainMenu.cpp Tetramino.cpp shapes/Line.cpp shapes/LLshape.cpp shapes/RLshape.cpp shapes/SLshape.cpp shapes/Square.cpp shapes/SRshape.cpp shapes/TShape.cpp -lncurses -o ASCII_Tetris

**Comando per l'esecuzione del programma:**

.\ASCII_Tetris

**Comandi per controllare il gioco:**

-**frecce direzionali della tastiera:** muovono nella rispettiva direzione il cursore;

-**Enter:** serve per confermare l'opzione selezionata;