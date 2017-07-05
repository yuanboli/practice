JFLAGS=-g


Parse/Main.class: Parse/*.java Parse/Yylex.java
	javac ${JFLAGS} Parse/*.java

Parse/Yylex.java: Parse/Tiger.lex
	java JLex.Main Parse/Tiger.lex; mv Parse/Tiger.lex.java Parse/Yylex.java

#	cd Parse; java JLex.Main Tiger.lex; mv Tiger.lex.java Yylex.java

ErrorMsg/ErrorMsg.class:  ErrorMsg/*.java
	javac ${JFLAGS} ErrorMsg/*.java

clean:
	rm Parse/*.class ErrorMsg/*.class Parse/Yylex.java


