.syntax unified
.text
.global s_zeros
.thumb_func

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
