start:  lodd on:
        stod 4095
        call xbsywt:
        loco str1:
nextw:  pshi
        addd c1:
        stod pstr1:
        pop
        jzer crnl:
        stod 4094
        push
        subd c255:
        jneg crnl:
        call sb:
        insp 1
        push
        call xbsywt:
        pop
        stod 4094
        call xbsywt:
        lodd pstr1:
        jump nextw:
crnl:   lodd cr:
        stod 4094
        call xbsywt:
        lodd nl:
        stod 4094
        call xbsywt:
	lodd funct:
	jzer retn:
        lodd on:                ; mic1 program to print string
        stod 4093               ; and scan in a 1-5 digit number
bgndig: call rbsywt:            ; using the CSR memory locations
        lodd 4092
        subd numoff:
        push
nxtdig: call rbsywt:
        lodd 4092
        stod nxtchr:
        subd nl:
        jzer endnum:
        mult 10
        lodd nxtchr:
        subd numoff:
        addl 0
        stol 0
        jump nxtdig:
endnum: lodd numptr:
        popi
        addd c1:
        stod numptr:
        lodd numcnt:
        jzer addnms:
        subd c1:
        stod numcnt:
        jump start:
addnms: lodd funct:
	subd funct:
	stod funct:
	loco str2:
	call nextw:
	lodd binum1:		; add the binum1 and binum2 values together  and store in sum
	addd binum2:	
	stod sum:
	jneg isOF:		; if there is an overflow go to isOF
	call prntN:		; if there is no overflow, print sum and return 0 in the AC
	loco 0
	halt
prntN:	lodd sum:
	stod nxtchr:
loop:	lodd nxtchr:		; here the remainder the remainder is pushed onto the stack and the quotient/answer is the new nxtchr
	jzer load:
	lodd count:
	addd c1:
	stod count:
	lodd c10:
	push
	lodd nxtchr:
	push
	div
	pop
	stod nxtchr:
	pop
	addd numoff:
	stod temp:
	pop
	pop
	lodd temp:
	push
	jump loop:
load:	lodd count:		; after the loop has ended/once the quotient was zero, 'count' amount of elements on the stack are stored in 4094
	jzer done:
	subd c1:
	stod count:
	lodl 0
	stod 4094
	pop
	jump load:
done:	lodd 4094
	call sb:
	lodd on:
	stod 4095
	call xbsywt:	
	retn  
isOF:	loco str3:		; if overflow, print string and return -1 in ac
	call nextw:
	lodd cn1:
	halt
xbsywt: lodd 4095
        subd mask:
        jneg xbsywt:
        retn
rbsywt: lodd 4093
        subd mask:
        jneg rbsywt:
        retn
sb:     loco 8
loop1:  jzer finish:
        subd c1:
        stod lpcnt:
        lodl 1
        jneg add1:
        addl 1
        stol 1
        lodd lpcnt:
        jump loop1:
add1:   addl 1
        addd c1:
        stol 1
        lodd lpcnt:
        jump loop1:
finish: lodl 1
retn:	retn
funct:	1
numoff: 48
nxtchr: 0
numptr: binum1:
binum1: 0
binum2: 0
lpcnt:  0
mask:   10
on:     8
nl:     10
cr:     13
c1:     1
cn1:	-1
c10:    10
c255:   255
temp:	0
count:	0
sum:    0
numcnt: 1
pstr1:  0
str1:   "Please enter a 1-5 digit number followed by enter:"
str2:	"The sum of these integers is: "
str3:	"Overflow, no sum possible."
