@ https://sourceware.org/binutils/docs/as/ARM_002dInstruction_002dSet.html#ARM_002dInstruction_002dSet
.syntax unified
.thumb
.text
.global s_zeros


@ r0 = vector, r1 = elementos
.thumb_func
    s_zeros:
            cbz r0, .end        @ vuelve si el puntero es cero
            cbz r1, .end        @ vuelve si elementos es cero

            mov r2, #0          @ r2 = cero
            and r3, r1, #0x7    @ r3 = r1 & 0x7 (r3 = r1 MOD 8)
            sub r1, r1, r3      @ r1 -= r3
            cbz r1, .loop1      @ hay menos de 8 elementos
        .loop8:
            str r2, [r0, 0]
            str r2, [r0, 4]
            str r2, [r0, 8]
            str r2, [r0, 12]
            str r2, [r0, 16]
            str r2, [r0, 20]
            str r2, [r0, 24]
            str r2, [r0, 28]
            add r0, #32
            subs r1, #8
            bne .loop8
            cbz r3, .end
        .loop1:
            subs r3, #1
            str r2, [r0, r3, LSL 2]
            bne .loop1
        .end:
            bx lr


///////////////////////////////////////////////////////////
// Codigo original debajo

/*
    @ r0 = vector, r1 = elementos
.thumb_func
    s_zeros:
            cbz r0, end     @ vuelve si el puntero es cero
            cbz r1, end     @ vuelve si elementos es cero

            mov r2, #0      @ r2 = cero
            mov r3, r1      @ r3 = r1 = elementos
        loop:
            subs r3, #1
            str r2, [r0, r3, LSL 2]
            bne loop
        end:
            bx lr
*/

