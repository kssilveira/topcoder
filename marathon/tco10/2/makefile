PROG = cellular
CPPFLAGS = -Wall -D MAIN=1 -D JAVA=1 -O3 #-pg
LFLAGS = #-pg

all: java

# ciclos
# coef = 78 / 49

java: $(PROG)
	java -jar Visualizer.jar -exec "./$(PROG)" -seed 1 -manual -delay 1000 -size 10
	#./$(PROG) < $(PROG).in
	#java -jar Visualizer.jar -seed 2 -manual -delay 1000 -size 10
	#java -jar Visualizer.jar -exe "./cat > out.txt" -seed 1

test: $(PROG)
	./$(PROG)
	touch $(PROG)

clean:
	rm -rf *~ $(PROG) gmon.out

prof:
	gprof -c $(PROG) > profiling

