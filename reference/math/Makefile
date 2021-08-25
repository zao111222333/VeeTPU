
all: sim
	./sim

sim: FPDemo.v FPDemoSim.v 
	iverilog -o $@ $^

waves:
	gtkwave waves.gtkw &

clean:
	rm -fr sim waves.vcd
