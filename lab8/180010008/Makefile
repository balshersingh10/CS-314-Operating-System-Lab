random:
	@echo "Building Random"
	@rm -f random random.dat 
	@gcc -w random.c -o random
	@./random > random.dat
	@gnuplot random.p

optimal:
	@echo "Building Optimal"
	@rm -f optimal optimal.dat 
	@gcc -w optimal.c -o optimal
	@./optimal > optimal.dat
	@gnuplot optimal.p

lru:
	@echo "Building Lru"
	@rm -f lru lru.dat 
	@gcc -w lru.c -o lru
	@./lru > lru.dat
	@gnuplot lru.p

clock:
	@echo "Building Clock"
	@rm -f clock clock.dat 
	@gcc -w clock.c -o clock
	@./clock > clock.dat
	@gnuplot clock.p

all: random lru clock optimal