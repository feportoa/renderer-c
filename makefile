run : 
	make clean
	g++ main.cpp -o main.out
	./main.out $(WIDTH) $(HEIGHT) > result.ppm

show : result.ppm
	convert result.ppm result.jpg
	display result.jpg

clean : 
	rm -f main.out result.ppm
