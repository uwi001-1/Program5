# Link the object file into an executable called program5.out
program5.out: program5_driver.o AirshipOrderList.o
	g++ -g -std=c++17 program5_driver.o AirshipOrderList.o -o program5.out

AirshipOrderList.o: AirshipOrderList.cpp AirshipOrderList.h
	g++ -g -std=c++17 -c AirshipOrderList.cpp

program5_driver.o: program5_driver.cpp AirshipOrderList.h
	g++ -g -std=c++17 -c program5_driver.cpp

# Run the compiled program5.out executable
run:
	./program5.out

# Run the compiled program5.out executable through valgrind
valrun:
	valgrind ./program5.out

# Delete all of the object files and executable
clean:
	rm *.o program5.out