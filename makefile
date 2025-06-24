main: main.o
	@echo "Gerando arquivos executável"
	gcc *.o -o main

main.o: main.c
	@echo "Compilando e gerando objetos"
	gcc -c *.c

clean: 
	@echo "Apagando objetos e executáveis antigos..."
	rm -f *.o main
#	del /f *.o

run: 
	./main

# LINUX 
# MAKE (CRIA E PREPARA ARQUIVOS .O)
# MAKE RUN (EXECUTA)
# MAKE CLEAN (LIMPA ARQUIVOS .O)
# ls (VERIFICAR ARQUIVOS)


# WINDOWS
# mingw32-make (CRIA E PREPARA ARQUIVOS .O)
# mingw32-make run (EXECUTA)
# mingw32-make clean (LIMPA ARQUIVOS .O)
# ls (VERIFICAR ARQUIVOS)