#include <Windows.h>
#include <stdio.h>
#include <winternl.h>



//00000000003B 41 01 C1                                      		add     r9d, eax
//seg000:000000000000003E E2 ED                                         loop    loc_2D
//seg000:0000000000000040 52                                            push    rdx             ; push "0A"
//seg000:0000000000000041 41 51                                         push    r9
//seg000:0000000000000043 48 8B 52 20                                   mov     rdx, [rdx+20h]
//seg000:0000000000000047 8B 42 3C                                      mov     eax, [rdx+3Ch]
//seg000:000000000000004A 48 01 D0                                      add     rax, rdx
//seg000:000000000000004D 66 81 78 18 0B 02                             cmp     word ptr [rax+18h], 20Bh ; rax = "PE"
//seg000:0000000000000053 0F 85 72 00 00 00                             jnz     loc_CB
//seg000:0000000000000059 8B 80 88 00 00 00                             mov     eax, [rax+88h]
//seg000:000000000000005F 48 85 C0                                      test    rax, rax
//seg000:0000000000000062 74 67                                         jz      short loc_CB
//seg000:0000000000000064 48 01 D0                                      add     rax, rdx
//seg000:0000000000000067 50                                            push    rax
//seg000:0000000000000068 8B 48 18                                      mov     ecx, [rax+18h]
//seg000:000000000000006B 44 8B 40 20                                   mov     r8d, [rax+20h]
//seg000:000000000000006F 49 01 D0                                      add     r8, rdx//


//cld
//and     rsp, 0FFFFFFFFFFFFFFF0h
//call    sub_D6

//call    sub_D6
//push    r9
//push    r8
//push    rdx
//push    rcx; push "ws2_32"
//push    rsi
//xor rdx, rdx
//mov     rdx, gs: [rdx + 60h] peb
//mov     rdx, [rdx + 18h] // [rdx+18] will result in a pointer to the object "PPEB_LDR_DATA"
//mov     rdx, [rdx + 20h]// point to InMemoryOrderModuleList object and inside the object will point to the first member will be flink.

//mov     rsi, [rdx + 50h] //dll name buffer
//movzx   rcx, word ptr[rdx + 4Ah]
//xor r9, r9

//--------------

//xor rax, rax
//lodsb   // move byte ptr  "al, [rsi]
//cjmp     al, 61h; 'a'
//jl      short loc_37 // 
//sub     al, 20h; ' \\32 a 


//short loc_37 

//ror     r9d, 0Dh //p
//add     r9d, eax //rd9 
//loop    loc_2D
//push    rdx             ; push "0A"
//push    r9
//mov     rdx, [rdx+20h]
//mov     eax, [rdx+3Ch]
//add     rax, rdx
//cmp     word ptr [rax+18h], 20Bh ; rax = "PE"
//jnz     loc_CB
//mov     eax, [rax+88h]
//test    rax, rax
//jz      short loc_CB
//add     rax, rdx
//push    rax
//mov     ecx, [rax+18h]
//mov     r8d, [rax+20h]
//add     r8, rdx
//


DWORD rightRotate(DWORD n, unsigned int d)
{
	DWORD INT_BITS = 32;
	/* In n>>d, first d bits are 0. To put last 3 bits of at
			first, do bitwise or of n>>d with n <<(INT_BITS
	   - d) */
	return (n >> d) | (n << (INT_BITS - d));
}

int main() {
	//xor rdx, rdx
    //mov     rdx, gs: [rdx + 60h]
	PEB* hamad = (PEB*)__readgsbyte(0x60);
	//mov     rdx, [rdx + 18h]
	PEB_LDR_DATA* LODR = (PEB_LDR_DATA*) hamad->Ldr;
	//mov     rdx, [rdx + 20h]
	LDR_DATA_TABLE_ENTRY* loadEntery = (LDR_DATA_TABLE_ENTRY*) LODR->InMemoryOrderModuleList.Flink;
	//rsi, [rdx + 50h]
	PWSTR buffer_n = loadEntery->FullDllName.Buffer;
	//movzx   rcx, word ptr[rdx + 4Ah]
	USHORT mexlenth = loadEntery->FullDllName.MaximumLength;

	

	
	return 0;
}