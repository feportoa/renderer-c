run : 
	make clean
	g++ -O2 main.cpp vecalg.cpp renderer.cpp -o main.out
	./main.out > result.ppm

profile : 
	make clean
	g++ -pg main.cpp vecalg.cpp renderer.cpp -o main.out
	perf record ./main.out 16:9 600
	gprof ./main.out gmon.out > profilling.txt
	clear
	echo "gprof saved to profilling.txt and use perf report"

debug : 
	make clean 
	g++ -g main.cpp vecalg.cpp renderer.cpp -o main.out
	gdb ./main.out

show : result.ppm
	convert result.ppm result.jpg
	display result.jpg

clean : 
	rm -f main.out result.ppm result.jpg gmon.out profilling.txt perf.data
