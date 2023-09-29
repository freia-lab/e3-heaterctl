#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <dbDefs.h>
#include <registryFunction.h>
#include <subRecord.h>
#include <aSubRecord.h>
#include <epicsExport.h>
#include <menuFtype.h>

int fillArrDebug;

static long fillArrInit(aSubRecord *precord)
{
    if (fillArrDebug)
        printf("Record %s called fillArrInit(%p)\n",
               precord->name, (void*) precord);
    return 0;
}
/*
 * Fill in an 10 element array with the content of inputs A to J. 
 * A bit mask in K is used to select the elements of the output array
 * that should be set to value given in L instead of a corresponding
 * input A - J. If the bit corresponding to a given channel is 0 then
 * the value of L will be set.
 */

static long fillArrProcess(aSubRecord *precord)
{
#define MAXN 80
#define N 10
  double *p;
  int n,bit;

  if (fillArrDebug > 5) {
    printf("Record %s called fillArrProcess(%p)\n",
	   precord->name, (void*) precord);
    printf ("Input data A-J: %f %f %f %f %f %f %f %f %f %f\n", 
	    *((double *) precord->a), *((double *) precord->b),
	    *((double *) precord->c), *((double *) precord->d),
	    *((double *) precord->e), *((double *) precord->f),
	    *((double *) precord->g), *((double *) precord->h),
	    *((double *) precord->i), *((double *) precord->j));
    printf ("Mask: %i\n", *((int *) precord->k));
    printf ("Fill value: %f\n", *((double *) precord->l));
    printf ("Number of elements in outa (NOVA): %i\n", precord->nova);
  }
  if  (precord->ftva != menuFtypeDOUBLE) {
    printf ("Wrong VALA field - must be menuFtypeDOUBLE\n");
    return -1;
  }
  p = (double *) precord->vala;
  n = precord->nova;
  if (n-- > 0) {
    bit = 1;
    if (bit & *((int *) precord->k)) {
      *p++ = *((double *) precord->a);
    } else {
      *p++ = *((double *) precord->l);
    }
  }
  if (n-- > 0) {
    bit = bit << 1;
    if (bit & *((int *) precord->k)) {
      *p++  = *((double *) precord->b);
    } else {
      *p++ = *((double *) precord->l);
    }
  }
  if (n-- > 0) {
    bit = bit << 1;
    if (bit & *((int *) precord->k)) {
      *p++  = *((double *) precord->c);
    } else {
      *p++ = *((double *) precord->l);
    }
  }
  if (n-- > 0) {
    bit = bit << 1;
    if (bit & *((int *) precord->k)) {
      *p++  = *((double *) precord->d);
    } else {
      *p++ = *((double *) precord->l);
    }
  }
  if (n-- > 0) {
    bit = bit << 1;
    if (bit & *((int *) precord->k)) {
      *p++  = *((double *) precord->e);
    } else {
      *p++ = *((double *) precord->l);
    }
  }
  if (n-- > 0) {
    bit = bit << 1;
    if (bit & *((int *) precord->k)) {
      *p++  = *((double *) precord->f);
    } else {
      *p++ = *((double *) precord->l);
    }
  }
  if (n-- > 0) {
    bit = bit << 1;
    if (bit & *((int *) precord->k)) {
      *p++  = *((double *) precord->g);
    } else {
      *p++ = *((double *) precord->l);
    }
  }
  if (n-- > 0) {
    bit = bit << 1;
    if (bit & *((int *) precord->k)) {
      *p++  = *((double *) precord->h);
    } else {
      *p++ = *((double *) precord->l);
    }
  }
  if (n-- > 0) {
    bit = bit << 1;
    if (bit & *((int *) precord->k)) {
      *p++  = *((double *) precord->i);
    } else {
      *p++ = *((double *) precord->l);
    }
  }
  if (n-- > 0) {
    bit = bit << 1;
    if (bit & *((int *) precord->k)) {
      *p++  = *((double *) precord->j);
    } else {
      *p++ = *((double *) precord->l);
    }
  }

  return 0;
}

/* Register these symbols for use by IOC code: */
epicsExportAddress(int, fillArrDebug);
epicsRegisterFunction(fillArrInit);
epicsRegisterFunction(fillArrProcess);

