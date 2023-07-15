/*
 * Encode external UTF-8 text to internal 8-bit encoding.
 *
 * Unicode          UTF-8           Internal    Characters
 * -------------------------------------------------------------
 * 0000...007F      00...7f         00...7f     ASCII
 * 0400...040F      d0 80...8f      80...8f     ЀЁЂЃЄЅІЇЈЉЊЋЌЍЎЏ
 * 0410...041F      d0 90...9f      90...9f     АБВГДЕЖЗИЙКЛМНОП
 * 0420...042F      d0 a0...af      a0...af     РСТУФХЦЧШЩЪЫЬЭЮЯ
 * 0430...043F      d0 b0...bf      b0...bf     абвгдежзийклмноп
 * 0440...044F      d1 80...8f      c0...cf     рстуфхцчшщъыьэюя
 * 0450...045F      d1 90...9f      d0...df     ѐёђѓєѕіїјљњћќѝўџ
 * 0460...046F      d1 a0...af      e0...ef     ѠѡѢѣѤѥѦѧѨѩѪѫѬѭѮѯ
 * 0470...047F      d1 b0...bf      f0...ff     ѰѱѲѳѴѵѶѷѸѹѺѻѼѽѾѿ
 */
#include <stdint.h>
#include "advexter.h"

/*
 * Return true when the byte is a prefix of UTF-8 sequence.
 */
bool is_utf8(int ch)
{
    return (ch & 0x80) != 0;
}

/*
 * Combine two bytes of UTF-8 sequence and encode into internal representation.
 */
int get_utf8(int c1, int c2)
{
    switch ((uint8_t) c1) {
    case 0xd0:
        return 0x80 | (c2 & 0x3f);
    case 0xd1:
        return 0xc0 | (c2 & 0x3f);
    default:
        return '?';
    }
}

/*
 * Encode one character internal encoding into UTF-8 string.
 */
static char *encode_utf8(char *ptr, char ch)
{
    if (~ch & 0x80) {
        // ASCII character.
        *ptr++ = ch;
    } else {
        // Cyrillic character.
        if (~ch & 0x40) {
            *ptr++ = 0xd0;
        } else {
            *ptr++ = 0xd1;
        }
        *ptr++ = 0x80 | (ch & 0x3f);
    }
    return ptr;
}

/*
 * Encode the word from internal encoding into UTF-8 string.
 * Return a pointer to the static string.
 */
const char *word_utf8(const char w[4])
{
    static char buf[16];
    char *p = buf;

    p = encode_utf8(buf, w[0]);
    p = encode_utf8(p, w[1]);
    p = encode_utf8(p, w[2]);
    p = encode_utf8(p, w[3]);
    *p = 0;
    return buf;
}
