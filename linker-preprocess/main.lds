SECTIONS {

#ifdef FOO
#include "addme.lds"
 .foo 0x80000000 : {
    _start_foo = .;
    . += 0xfff;
    _end_foo = .;
 }
#endif
}
