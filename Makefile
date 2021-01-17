CC = gcc

5_13_inner: 5_13_inner.c vec.c
	$(CC) 5_13_inner.c vec.c  -o  5_13_inner

5_13perfLAB: 5_13perfLAB.c clock.c fcyc.c
	$(CC) 5_13perfLAB.c clock.c fcyc.c -o 5_13perfLAB

5_13perf: 5_13perf.c clock.c fcyc.c
	$(CC) 5_13perf.c clock.c fcyc.c -o 5_13perf

5_13_inline: 5_13_inline.c clock.c fcyc.c
	$(CC) 5_13_inline.c clock.c fcyc.c -o 5_13_inline

5_13_SetAffinity: 5_13_SetAffinity.c clock.c fcyc.c
	$(CC) 5_13_SetAffinity.c clock.c fcyc.c -o 5_13_SetAffinity

plot:
	gnuplot plot.gp

# .PHONY: clean
clean:
	@rm -f *.o
	@rm -f 5_13_inner
	@rm -f *.txt
	@rm -f result.png
	@rm -f 5_13perf
	@rm -f 5_13perfLAB
	@rm -f 5_13_inner
	@rm -f 5_13_inline
	@rm -f 5_13_SetAffinity
