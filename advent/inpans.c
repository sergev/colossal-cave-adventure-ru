/*
 * ввод 2-х слов из ответа человека
 * char wrd1[10], wrd2[10];  inpans(&wrd1, &wrd2);
 */
#include <unistd.h>
#include <string.h>
#include "advexter.h"

void inpans( char *wrd1, char *wrd2 )
{
    register int i;
    register char *ptr, *ptr0;
    char buf[80];

    for(i=10; i--; ) wrd1[i] = wrd2[i] = ' ';
    buf[80-1] = '\n';
    if( !read(0, buf, 80-1) )  strcpy( buf, "конец\n");
    to_lower( buf, 80 );
    for( ptr=buf; *ptr==' ' || *ptr=='\t'; ++ptr) ;
    if( *ptr != '\n' ) {
	ptr0 = ptr;
	while( *ptr!='\n' && *ptr!=' ' && *ptr!='\t' ) {
	    if( (i=ptr-ptr0) < 10 )  wrd1[i] = *ptr;
	    ++ptr;
	}
	for( ; *ptr==' ' || *ptr=='\t'; ++ptr) ;
	if( *ptr != '\n' ) {
	    ptr0 = ptr;
	    while( *ptr!='\n' && *ptr!=' ' && *ptr!='\t' ) {
		if( (i=ptr-ptr0) < 10 )  wrd2[i] = *ptr;
		++ptr;
	    }
	}
    }
}
