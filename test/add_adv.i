# 1 "add_adv.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "add_adv.c"
# 1 "add.h" 1
int add(int a,int b);
# 2 "add_adv.c" 2
int add_adv(int a,int b,int c){
 return add(a,add(b,c));
}
