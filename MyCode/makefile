#生成目标文件tool
tool:main.o io.o list.o
        gcc -o tool main.o io.o list.o
        
main.o:./src/main.c ./inc/common.h
        gcc -Iinc/ -g -c -Wall src/main.c
        
io.o:./src/io.c ./inc/common.h
        gcc -Iinc/ -g -c -Wall src/io.c
		
list.o:./src/list.c ./inc/common.h
        gcc -Iinc/ -g -c -Wall src/list.c

clean:
        rm tool *.o



	