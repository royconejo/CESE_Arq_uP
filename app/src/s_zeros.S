.syntax unified
.text
.global s_zeros
.thumb_func

// r0 = vector, r1 = elementos
s_zeros:
        cbz r0, end         // vuelve si el puntero es cero
        cbz r1, end         // vuelve si elementos es cero

        mov r2, $0          // r2 = cero
        and r3, r1, 0x7     // r3 = r1 & 0x7 (r3 = r1 MOD 8)
        sub r1, r1, r3      // r1 -= r3
        cbz r1, loop1       // menor o igual a 8 elementos
    loop8:
        str r2, [r0, 0]
        str r2, [r0, 4]
        str r2, [r0, 8]
        str r2, [r0, 12]
        str r2, [r0, 16]
        str r2, [r0, 20]
        str r2, [r0, 24]
        str r2, [r0, 28]
        add r0, $32
        subs r1, $8
        bne loop8
    loop1:
        subs r3, $1
        str r2, [r0, r3, LSL 2]
        bne loop1
    end:
        bx lr

///////////////////////////////////////////////////////////
// Codigo original debajo

.if 0
    // r0 = vector, r1 = elementos
    s_zeros:
            cbz r0, end     // vuelve si el puntero es cero
            cbz r1, end     // vuelve si elementos es cero

            mov r2, #0      // r2 = cero
            mov r3, r1      // r3 = r1 = elementos
        loop:
            subs r3, #1
            str r2, [r0, r3, LSL 2]
            bne loop
        end:
            bx lr
.endif

