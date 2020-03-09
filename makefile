PROGNAMECLIENT := "client"
PROGNAMESERVER := "server"

CLIENT := $(wildcard src/client/*.cpp)
OBJECTCLIENT := $(patsubst src/client/%.cpp, obj/client/%.o, $(CLIENT))
OBJECTCLIENT := $(patsubst obj/client/main.o, , $(OBJECTCLIENT))

SERVER := $(wildcard src/server/*.cpp)
OBJECTSERVER := $(patsubst src/server/%.cpp, obj/server/%.o, $(SERVER))
OBJECTSERVER := $(patsubst obj/server/main.o, , $(OBJECTSERVER))

allProgram: ./bin bin/$(PROGNAMECLIENT) bin/$(PROGNAMESERVER)

./bin:
	@mkdir -p bin
	@echo "bin folder created"

bin/$(PROGNAMECLIENT): lib/libclient.a src/client/main.cpp src/client/*.hpp
	@g++ -std=c++17 src/client/main.cpp -lclient -Llib -L /home/student/poco/poco-1.10.1/lib/Linux/i686/ -lPocoNet -lPocoFoundation -I /home/student/poco/poco-1.10.1/Net/include/ -I /home/student/poco/poco-1.10.1/Foundation/include/ -o $@ 
	@echo "compiling client..."

bin/$(PROGNAMESERVER): lib/libserver.a src/server/main.cpp src/server/*.hpp
	@g++ -std=c++17 src/server/main.cpp -lserver -Llib -L /home/student/poco/poco-1.10.1/lib/Linux/i686/ -lPocoNet -lPocoFoundation -I /home/student/poco/poco-1.10.1/Net/include/ -I /home/student/poco/poco-1.10.1/Foundation/include/ -o $@ 
	@echo "compiling server..."

lib/libclient.a: $(OBJECTCLIENT) ./lib
	@ar rc $@ $<
	@echo "static lib client created"

lib/libserver.a: $(OBJECTSERVER) ./lib
	@ar rc $@ $<
	@echo "static lib server created"

obj/client/%.o: src/client/%.cpp ./obj/client
	@g++ -std=c++17 -c $< -o $@ -L /home/student/poco/poco-1.10.1/lib/Linux/i686/ -lPocoNet -lPocoFoundation -I /home/student/poco/poco-1.10.1/Net/include/ -I /home/student/poco/poco-1.10.1/Foundation/include/

obj/server/%.o: src/server/%.cpp ./obj/server
	@g++ -std=c++17 -c $< -o $@ -L /home/student/poco/poco-1.10.1/lib/Linux/i686/ -lPocoNet -lPocoFoundation -I /home/student/poco/poco-1.10.1/Net/include/ -I /home/student/poco/poco-1.10.1/Foundation/include/

./lib:
	@mkdir -p lib
	@echo "lib created"

./obj/client:
	@mkdir -p obj/client
	@echo "obj/client created"

./obj/server:
	@mkdir -p obj/server
	@echo "obj/server created"

.PHONY: clean
clean:
	@rm -rf bin/ lib/ obj/
	@echo "cleaning..."