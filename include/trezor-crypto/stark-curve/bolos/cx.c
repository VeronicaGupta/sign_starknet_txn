#include <err.h>
#include <errno.h>
#include <openssl/rand.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "emulate.h"
#include "environment.h"

static bool initialized = false;

/* not secure, but this is clearly not the goal of this emulator */
unsigned long sys_cx_rng(uint8_t *buffer, unsigned int length)
{
  unsigned int i;

  if (!initialized) {
    srand(env_get_rng());
    initialized = true;
  }

  for (i = 0; i < length; i++) {
    buffer[i] = rand() & 0xff;
  }

  return 0;
}

unsigned long sys_cx_rng_u8(void)
{
  uint8_t n;

  sys_cx_rng(&n, sizeof(n));

  return n;
}

unsigned long sys_cx_rng_u32(void)
{
  uint32_t n;

  sys_cx_rng((uint8_t *)&n, sizeof(n));

  return n;
}

/* Link sys_cx_rng to OpenSSL random number generator */
static int deterministic_random_bytes(unsigned char *buf, int num)
{
  sys_cx_rng(buf, num);
  return 1;
}

static const RAND_METHOD deterministic_random_methods = {
  .bytes = deterministic_random_bytes,
};

void make_openssl_random_deterministic(void)
{
  RAND_set_rand_method(&deterministic_random_methods);
}
