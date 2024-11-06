COMPILE = gcc
FLAGS = -Wall -Wextra

PROG = jocuri_societate forme circuits segment_display

build: $(PROG)

jocuri_societate: jocuri_societate.c
	$(COMPILE) $(FLAGS) jocuri_societate.c -o jocuri_societate 

forme: forme.c
	$(COMPILE) $(FLAGS) forme.c -o forme 

circuits: circuits.c
	$(COMPILE) $(FLAGS) circuits.c -o circuits 

segment_display: segment_display.c
	$(COMPILE) $(FLAGS) segment_display.c -o segment_display 

clean:
	rm -f $(PROG) *.o
