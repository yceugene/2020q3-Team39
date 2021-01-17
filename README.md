# 2020q3-Team39
A study of CS:APP Homework 5.13.

## Run the program
* To simple implement the inner product function for vector in length 4.
    ``` bash
    $ make 5_13_inner
    $ ./5_13_inner
    ```
* Implement the inner product, and calculate the CPE by performance lab.
    ``` bash
    $ make 5_13perfLAB
    $ ./5_13perfLAB
    ```
* Implement the inner product, and calculate the CPE by perf.
    ``` bash
    $ make 5_13perf
    $ ./5_13perf
    ```
* Implement the inner product by using inline assembly (integer).
    ``` bash
    $ make 5_13_inline: 5_13_inline.c clock.c fcyc.c
    $ ./5_13_inline
    ```
* Plot the relationship graph between the CPE and number of vector elements.
    ``` bash
    $ make plot
	```
    or
    ```
    $ gnuplot plot.gp
    ```
* Tried to make the program runs on single CPU-core (CPU:1) only.
    ``` bash
    $ make 5_13_SetAffinity
    $ ./5_13_SetAffinity
	```

## Reference:
* [Assign 5.13](https://hackmd.io/@dange/H1bmDn5am) / [Github](https://github.com/allenchen8210/team15)
* [DreamAndDead/CSAPP-3e-Solutions](https://github.com/DreamAndDead/CSAPP-3e-Solutions)
