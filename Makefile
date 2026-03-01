all:
	g++ -Wall hexbinarydec.cpp -o hbd

run: 
	./hbd

try: all run
