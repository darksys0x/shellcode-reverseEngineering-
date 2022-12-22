#include <Windows.h>
#include <stdio.h>
#include <winternl.h>


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
//

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


int main() {
	 
	PEB* hamad = (PEB*)__readgsqword(0x60);
	LDR_DATA_TABLE_ENTRY* tableentery = (LDR_DATA_TABLE_ENTRY*)hamad->Ldr->InMemoryOrderModuleList.Flink;
	WCHAR* name = tableentery->FullDllName.Buffer;
	int maxLength = tableentery->FullDllName.MaximumLength;
	char* p = *(char*)name;
	char c = *p;
	if (c < 'a') {
		c[]
	}
	else {
		c = c - ' ';
	}



	return 0;
}