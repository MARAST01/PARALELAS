all:
	g++ -o exe ejemploThread.cpp -lpthread
	./exe
	g++ -o exe ejemploTbb.cpp -ltbb
	./exe
	g++ -o exe ejemploOpenmp.cpp -fopenmp
	./exe
	rm exe

clean:
	rm exe