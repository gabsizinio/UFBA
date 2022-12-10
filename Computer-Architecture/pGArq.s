main:
    addi	sp,sp,-48
	sw	    s0,44(sp)
	addi	s0,sp,48
    
    li      a0,1 
    sw      a0,-4(s0)
    li      a0,5
    sw      a0,-8(s0)
    li      a0,1
    sw      a0,-12(s0)

    li      a0,4
    sw      a0,-16(s0)
    li      a0,2
    sw      a0,-20(s0)
    li      a0,0
    sw      a0,-24(s0)

    lw      a0,-8(s0)
    lw      a1,-8(s0)
    
    blt zero,a0,L
        sub a0,zero,a0
        li a3,1
    L:

    blt zero,a1,K
        sub a1,zero,a1
        li a4,1
    K:

    mult:
        add     t0, zero, zero
        addi    a1, a1, -1
    accu:
        add     t0, t0, a0
        addi    a1, a1, -1
        bge     a1, zero, accu
        add     a0, zero, t0

    xor     a5,a3,a4

    beq     a5,zero,M
        sub a0,zero,a0
    M:


    sw      a0,-28(s0)

    lw      a0,-16(s0)
    lw      a1,-4(s0)

    blt zero,a0,L2
        sub a0,zero,a0
        li a3,1
    L2:

    blt zero,a1,K2
        sub a1,zero,a1
        li a4,1
    K2:

    mult2:
        add     t0, zero, zero
        addi    a1, a1, -1
    accu2:
        add     t0, t0, a0
        addi    a1, a1, -1
        bge     a1, zero, accu2
        add     a0, zero, t0
    
    xor     a5,a3,a4

    beq     a5,zero,M2
        sub a0,zero,a0
    M2:
    
    sw      a0,-32(s0)

    lw     a0,-12(s0)
    lw     a1,-32(s0)

    blt zero,a0,L3
        sub a0,zero,a0
        li a3,1
    L3:

    blt zero,a1,K3
        sub a1,zero,a1
        li a4,1
    K3:

    mult3:
        add     t0, zero, zero
        addi    a1, a1, -1
    accumulate3:
        add     t0, t0, a0
        addi    a1, a1, -1
        bge     a1, zero, accu3
        add     a0, zero, t0
    
    xor     a5,a3,a4

    beq     a5,zero,M3
        sub a0,zero,a0
    M3:

    sw      a0,-32(s0)

    lw      a0,-28(s0)
    lw      a1,-32(s0)

    sub     a2,a0,a1

    sw      a2,-36(s0)
    
    li      a0,0
    lw      a1,-36(s0)

    blt     a0,a1,end
    beq     a0,a1,end2
    blt     a1,a0,end3


    end:
        li      a2,2
        sw      a2,-40(s0)
        jal     foo
    end2:
        li      a2,1
        sw      a2,-40(s0)
        jal     foo
    end3:
        li      a2,0
        sw      a2,-40(s0)
        jal     foo

foo:
    



