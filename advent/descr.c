/*  === descr === describe current location */

#include "advexter.h"

static void ds(int n);

void descr()  { ds(0); }

void descr2() { ds(1); }

void ds(int n) {
    register int kk;

    if( n ) goto L100;
    if( dark() ) {
	rspeak(16);
    } else {
	kk=0;
	if( abrev(loc)!=0 ) {
	    kk=stext(loc);
	} else {
L100:       kk=ltext(loc);
	}
	if( kk==0 )  kk=ltext(loc);
	mes(kk);
	if( abb!=0 ) {
	    abrev(loc)=2;
	} else {
	    abrev(loc) = (abrev(loc)+1)%4;
	}
	indobj();
    }
}
