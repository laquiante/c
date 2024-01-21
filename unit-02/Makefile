# Aufruf make speicherorte

.PHONY = all clean

# Auswahl des Compilers
# Demo via DELL XPS mit 22.04 und ConnectX-5

# Port 1: InfiniBand 100Gbit/s  (alternative Ethernet)
# Port 2: InfiniBand 100Gbit/s  (alternative Ethernet)
# RDMA-CORE

CC := gcc

LINKERFLAG = -lm

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

%: %.o
        @echo "Zusammenbauen"
        ${CC} ${LINKERFLAG} $< -o $@

# Das % Zeichen übernimmt den Namen aus ${BINS} 
# und somit vom *ARG[]

%.o: %.c
        @echo "Objekterstellung"
        ${CC} -c $<

clean:
        @echo "Tatortreiniger"
        rm -rvf *.o ${BINS}
