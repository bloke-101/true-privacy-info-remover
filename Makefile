OBJMODULES = file_system_utils.o random_generator.o
CFLAGS = -Wall -std=c++11 -pedantic

%.o: src/%.cpp include/%.h
	$(CXX) $(CFLAGS) -I include -c $< -o $@

true_privacy_info_remover: src/main.cpp $(OBJMODULES)
	$(CXX) $(CFLAGS) -I include $^ -o bin/$@
	rm -f $(OBJMODULES)
	
build: true_privacy_info_remover

clean:
	rm -f bin/true_privacy_info_remover
