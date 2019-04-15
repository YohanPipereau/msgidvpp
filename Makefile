all:
	gcc api.c -lvppapiclient -lvppinfra -lvapiclient -lvlibmemoryclient -lsvm -o api -g

clean:
	rm api
