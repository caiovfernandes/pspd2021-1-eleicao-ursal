export OMP_NUM_THREADS?=8
export INPUTS_PATH= ../../input/
export INPUT_FILE?=file001-sample

init:
	@echo "Decompressing inputs examples"
	tar xf ../../input.tar.gz
	@touch input/.create


sequencial:
	@echo "Runs sequencial scripts"
	gcc sequencial.c 
	./a.out < $(INPUTS_PATH)$(INPUT_FILE)