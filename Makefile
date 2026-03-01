all:
	g++ -Wall hexbinarydec.cpp -o hbd
	g++ -Wall bitsnbytes.cpp -o bnb

run: 
	./hbd
	./bnb

try: all run
