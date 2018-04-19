#include "ajustarBrillo.h"
#include "core_cm4_simd.h"


#define     IMAGEN_ANCHO        80
#define     IMAGEN_ALTO         60
#define     IMAGEN_SIZE         (IMAGEN_ANCHO * IMAGEN_ALTO)

static const uint32_t   brillo  = 16;
static uint8_t          imagen  [IMAGEN_SIZE];


/*
    Ejercicio Practico (Examen 7/4/2017)
*/

void c_ajustarBrillo (uint8_t *imagen, uint32_t ancho, uint32_t alto,
                    int8_t brillo)
{
    if (!imagen || (ancho & 0x03) || (alto & 0x03))
    {
        return;
    }

    uint32_t brillo32   = brillo | brillo << 8 | brillo << 16 | brillo << 24;
    uint32_t *imagen32  = (uint32_t *)imagen;

    for (uint32_t i = (ancho * alto) >> 2; i; --i)
    {
        *imagen32++ = __UQADD8 (*imagen32, brillo32);
    }
}


#if 0
void c_ajustarBrillo (uint8_t *imagen, uint32_t ancho, uint32_t alto,
                    int8_t brillo)
{
    if (!imagen || (ancho & 0x03) || (alto & 0x03))
    {
        return;
    }

    for (uint32_t i = ancho * alto; i; --i)
    {
        uint16_t pixel = *imagen + brillo;
        *imagen ++ = (pixel > 0xFF)? 0xFF : pixel;
    }
}
#endif


#if 0
struct QP
{
    union {
        uint32_t q;
        uint16_t A;
        uint16_t B;
        uint8_t  psA;
        uint8_t  pA;
        uint8_t  psB;
        uint8_t  pB;
    };
};


void c_ajustarBrillo (uint8_t *imagen, uint32_t ancho, uint32_t alto,
                      int8_t brillo)
{
    if (!imagen || (ancho & 0x03) || (alto & 0x03))
    {
        return;
    }

    struct QP qbrillo;
    qbrillo.q    = 0;
    qbrillo.pA   = brillo;
    qbrillo.pB   = brillo;

    for (uint32_t i = (ancho * alto) >> 1; i; --i)
    {
        struct QP qp;
        qp.q    = 0;
        qp.pA   = imagen[0];
        qp.pB   = imagen[1];

        qp.q += qbrillo.q;

        imagen[0] = (qp.A > 0xFF)? 0xFF : qp.pA;
        imagen[1] = (qp.B > 0xFF)? 0xFF : qp.pB;

        imagen = &imagen[2];
    }
}
#endif


static void test_reset ()
{
    for (uint32_t i = 0; i < IMAGEN_SIZE; ++i)
    {
        imagen[i] = i;
    }
}


void test_ajustarBrillo (struct profiling_t *pr)
{
    if (!pr)
    {
        return;
    }

    profilingStart (1, 1, pr);

    test_reset ();
    PROFILE_FUNCTION(pr, c, ajustarBrillo, imagen, IMAGEN_ANCHO, IMAGEN_ALTO, brillo)
    test_reset ();
    PROFILE_FUNCTION(pr, s, ajustarBrillo, imagen, IMAGEN_ANCHO, IMAGEN_ALTO, brillo)

    profilingDone (pr);
}

