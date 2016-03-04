COMPILER="g++"
LDFLAGS=`pkg-config --libs opencv`
CFLAGS=`pkg-config --cflags opencv`

pset: pset.cpp
	$(COMPILER) $(LDFLAGS) $(CFLAGS) pset.cpp -o psetviz	
