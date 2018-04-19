@ https://sourceware.org/binutils/docs/as/ARM_002dInstruction_002dSet.html#ARM_002dInstruction_002dSet
.syntax unified
.thumb
.text
.global s_ajustarBrillo


@ r0 = *imagen, r1 = ancho, v2 = alto, v3 = brillo
.thumb_func
    s_ajustarBrillo:
            push {r4}

            cbz  r0, .end               @ vuelve si el puntero imagen es cero
            and  r4, r1, #0x03          @ vuelve si ancho o alto no son multiplos
            cbnz r4, .end               @ de cuatro
            and  r4, r2, #0x03
            cbnz r4, .end
            orr  r4, r3, r3, LSL #8     @ 0x0000R3R3
            orr  r4, r4, r3, LSL #16    @ 0x00R3R3R3
            orr  r4, r4, r3, LSL #24    @ 0xR3R3R3R3
            mul  r1, r1, r2             @ ancho * alto
        .loop:
            ldr    r2, [r0]
            uqadd8 r2, r2, r4
            str    r2, [r0], #4
            subs   r1, #4
            bne    .loop
        .end:
            pop  {r4}
            bx   lr
