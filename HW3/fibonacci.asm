LOOP:   LODD PasCnt:
        JZER DONE:
        SUBD c1:
        STOD PasCnt:
P1:     LODD daddr:
        PSHI
        ADDD c1:
        STOD daddr:
        CALL FIB:
        INSP 1
P2:     PUSH
        LODD faddr:
        POPI
        ADDD c1:
        STOD faddr:
        JUMP LOOP:
FIB:	LODL 1
        JZER FIBZER:
        SUBD c1:
        JZER FIBONE:
        PUSH
        CALL FIB:
        PUSH
        LODL 1
        SUBD c1:
        PUSH
        CALL FIB:
        ADDL 1
	INSP 3
        RETN
RTN:    LODD tmp:
        RETN
FIBZER: LODD c0:
        RETN
FIBONE: LODD c1:
        RETN
DONE:   HALT
.LOC    100
d0:     3
        9
        18
        23
        25
f0:     0
        0
        0
        0
        0
daddr:  d0:
faddr:  f0:
c0:     0
c1:     1
PasCnt: 5
tmp:    0
