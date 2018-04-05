@ https://sourceware.org/binutils/docs/as/ARM_002dInstruction_002dSet.html#ARM_002dInstruction_002dSet
.syntax unified
.thumb
.text
.global s_productoEscalar16


@ r0 = vectorIn, r1 = vectorOut, v2 = longitudVectorIn
.thumb_func
    s_productoEscalar16:
            push {r4}

            cbz r0, end         @ vuelve si el puntero vectorIn es cero
            cbz r1, end         @ vuelve si el puntero vectorOut es cero
            cbz r2, end         @ vuelve si longitudVectorIn es cero
            sub r3, r2, 10
            cbz r3, end         @ vuelve si longitudVectorIn es menor a 10

            mov  r4, #0
            ldrh r3, [r0, 0]
            add  r4, r4, r3
            ldrh r3, [r0, 2]
            add  r4, r4, r3
            ldrh r3, [r0, 4]
            add  r4, r4, r3
            ldrh r3, [r0, 6]
            add  r4, r4, r3
            ldrh r3, [r0, 8]
            add  r4, r4, r3
            ldrh r3, [r0, 10]
            add  r4, r4, r3
            ldrh r3, [r0, 12]
            add  r4, r4, r3
            ldrh r3, [r0, 14]
            add  r4, r4, r3
            ldrh r3, [r0, 16]
            add  r4, r4, r3
            ldrh r3, [r0, 18]
            add  r4, r4, r3

            sub r2, r2, #9
        loop:
        @    mov r3, #10
        @    udiv r3, r4, r3         @ r3 = r4 / 10
            mov  r3, #6554
            mul  r3, r4, r3
            lsr  r3, r3, #16
        @
            strh r3, [r1]           @ *r1 = r3
            ldrh r3, [r0, 0]        @ r3 = r0[0]
            sub  r4, r4, r3         @ r4 -= r3
            ldrh r3, [r0, 20]       @ r3 = r0[10]
            add  r4, r4, r3         @ r4 += r3

            add  r1, r1, #2
            add  r0, r0, #2
            subs r2, #1
            bne loop
        end:
            pop {r4}
            bx lr
