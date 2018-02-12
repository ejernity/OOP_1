metrosimulation: main.o Train.o Waggon.o Passenger.o Lists.o
	g++ main.o Train.o Waggon.o Passenger.o Lists.o -o metrosimulation

main.o: main.cpp
	g++ -c main.cpp

Train.o: Train.cpp Train.h
	g++ -c Train.cpp

Waggon.o: Waggon.cpp Waggon.h
	g++ -c Waggon.cpp

Passenger.o: Passenger.cpp Passenger.h
	g++ -c Passenger.cpp

Lists.o: Lists.cpp Lists.h
	g++ -c Lists.cpp

clean:
	rm *.o metrosimulation