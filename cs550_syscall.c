#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"
#include "syscall.h"
#include "types.h"
#include "defs.h"

//Marks the total number of system calls for int 65
#define SIZE_65_CALLS 50

//Marks the total row number of system calls 2D arr for int 66
#define SIZE_ROW_66_CALLS 26
//Marks the total col number of system calls 2D arr for int 66
#define SIZE_COL_66_CALLS 4

#define getASCII(name) \
int sys_##name(void) {\
    int result=0, i=0;\
    while(#name[i]!='\0') {\
            result += #name[i];\
            i++;\
    }\
    return result;\
}

//for int 65
getASCII(aaICO)//1
getASCII(RwwzQ)//2
getASCII(vPlkH)//3
getASCII(nAAkW)//4
getASCII(V4XHy)//5
getASCII(DIJ1J)//6
getASCII(uby8E)//7
getASCII(HrYmw)//8
getASCII(It9GD)//9
getASCII(kBqyL)//10
getASCII(uFvqh)//11
getASCII(kCOzo)//12
getASCII(BdglP)//13
getASCII(vsu9T)//14
getASCII(GhENr)//15
getASCII(cNlc2)//16
getASCII(AUX47)//17
getASCII(OJjUF)//18
getASCII(rwbCB)//19
getASCII(U63O6)//20
getASCII(buYn9)//21
getASCII(pvRfc)//22
getASCII(IbIsf)//23
getASCII(RH7FR)//24
getASCII(u5Ncu)//25
getASCII(vA3kF)//26
getASCII(ZyJFv)//27
getASCII(a_kuY)//28
getASCII(DF2ak)//29
getASCII(bifXB)//30
getASCII(OpuAe)//31
getASCII(DNUxN)//32
getASCII(ancIB)//33
getASCII(fiuCL)//34
getASCII(f85c4)//35
getASCII(pKQyj)//36
getASCII(sPh9f)//37
getASCII(aSdV9)//38
getASCII(hEwee)//39
getASCII(m7xSo)//40
getASCII(lpg5S)//41
getASCII(J7GF1)//42
getASCII(GYEGy)//43
getASCII(UHuoA)//44
getASCII(lfawm)//45
getASCII(SkxVQ)//46
getASCII(m7dk_)//47
getASCII(C2FTH)//48
getASCII(ZFvwG)//49
getASCII(xMznMiMbd2ASBAopjUBD)//50



//for int 66
getASCII(ajJ2rUS36Ds7gCvYhWvRMQ4cM)//1
getASCII(lcQQ6)//2
getASCII(tG0cd)//3
getASCII(BQaye)//4
getASCII(vRL61)//5
getASCII(BfPAS)//6
getASCII(rNV_x)//7
getASCII(m9TVP)//8
getASCII(dN3rB)//9
getASCII(NEorw)//10
getASCII(iE45d)//11
getASCII(VFGu_)//12
getASCII(zqf7e)//13
getASCII(Ayr5H)//14
getASCII(y7dVW)//15
getASCII(RhaR2)//16
getASCII(GUT_3)//17
getASCII(mtwGL)//18
getASCII(Rz1qA)//19
getASCII(BDslj)//20
getASCII(DYcHF)//21
getASCII(XVI4N)//22
getASCII(RknTi)//23
getASCII(eraAb)//24
getASCII(K7plu)//25
getASCII(UPjQy)//26
getASCII(uFjK1)//27
getASCII(E8Jj9)//28
getASCII(viJpE)//29
getASCII(y8hmu)//30
getASCII(GhPNY)//31
getASCII(mEymb)//32
getASCII(UAi7z)//33
getASCII(g3fke)//34
getASCII(spiXC)//35
getASCII(sCY6P)//36
getASCII(lQ5p2)//37
getASCII(yFLZV)//38
getASCII(y7NBZ)//39
getASCII(JS_81)//40
getASCII(pHGgA)//41
getASCII(D3BT2)//42
getASCII(LYSUb)//43
getASCII(UHDeS)//44
getASCII(zQQm5)//45
getASCII(T4IiC)//46
getASCII(ZnCtG)//47
getASCII(TBDYx)//48
getASCII(k_jNM)//49




//Helper function for string comparison
int strcmp(char *str1, char *str2) {
    while(*str1==*str2) {
     if(*str1=='\0'||*str2=='\0')
     	break;
     	str1++;
	str2++;
    }
    if(*str1=='\0' && *str2=='\0') {
    	return 0;
    } else {
	return -1;
    }
}


//Implementation for date function
struct rtcdate;
int argptr(int, char**, int);
void cmostime(struct rtcdate *);

int sys_mydate(void) {
    struct rtcdate *r;
    if(argptr(0, (void*)&r, sizeof(&r)) < 0)
    	return -1;
	    
    cmostime(r);
    return 0;
}

//for virtual function
typedef int (*Function)(void); 

//Structure for linear search array and hash table entry
typedef struct sys_calls_arr {
	char *name;
	Function func;	
}SYS_CALL_ARR;



//Array for linear search
static SYS_CALL_ARR syscalls65[SIZE_65_CALLS] = {
{(char*)"aaICO",sys_aaICO},//1
{(char*)"RwwzQ",sys_RwwzQ},//2
{(char*)"vPlkH",sys_vPlkH},//3
{(char*)"nAAkW",sys_nAAkW},//4
{(char*)"V4XHy",sys_V4XHy},//5
{(char*)"DIJ1J",sys_DIJ1J},//6
{(char*)"uby8E",sys_uby8E},//7
{(char*)"HrYmw",sys_HrYmw},//8
{(char*)"It9GD",sys_It9GD},//9
{(char*)"kBqyL",sys_kBqyL},//10
{(char*)"uFvqh",sys_uFvqh},//11
{(char*)"kCOzo",sys_kCOzo},//12
{(char*)"BdglP",sys_BdglP},//13
{(char*)"vsu9T",sys_vsu9T},//14
{(char*)"GhENr",sys_GhENr},//15
{(char*)"cNlc2",sys_cNlc2},//16
{(char*)"AUX47",sys_AUX47},//17
{(char*)"OJjUF",sys_OJjUF},//18
{(char*)"rwbCB",sys_rwbCB},//19
{(char*)"U63O6",sys_U63O6},//20
{(char*)"buYn9",sys_buYn9},//21
{(char*)"pvRfc",sys_pvRfc},//22
{(char*)"IbIsf",sys_IbIsf},//23
{(char*)"RH7FR",sys_RH7FR},//24
{(char*)"u5Ncu",sys_u5Ncu},//25
{(char*)"vA3kF",sys_vA3kF},//26
{(char*)"ZyJFv",sys_ZyJFv},//27
{(char*)"a_kuY",sys_a_kuY},//28
{(char*)"DF2ak",sys_DF2ak},//29
{(char*)"bifXB",sys_bifXB},//30
{(char*)"OpuAe",sys_OpuAe},//31
{(char*)"DNUxN",sys_DNUxN},//32
{(char*)"ancIB",sys_ancIB},//33
{(char*)"fiuCL",sys_fiuCL},//34
{(char*)"f85c4",sys_f85c4},//35
{(char*)"pKQyj",sys_pKQyj},//36
{(char*)"sPh9f",sys_sPh9f},//37
{(char*)"aSdV9",sys_aSdV9},//38
{(char*)"hEwee",sys_hEwee},//39
{(char*)"m7xSo",sys_m7xSo},//40
{(char*)"lpg5S",sys_lpg5S},//41
{(char*)"J7GF1",sys_J7GF1},//42
{(char*)"GYEGy",sys_GYEGy},//43
{(char*)"UHuoA",sys_UHuoA},//44
{(char*)"lfawm",sys_lfawm},//45
{(char*)"SkxVQ",sys_SkxVQ},//46
{(char*)"m7dk_",sys_m7dk_},//47
{(char*)"C2FTH",sys_C2FTH},//48
{(char*)"ZFvwG",sys_ZFvwG},//49
{(char*)"xMznMiMbd2ASBAopjUBD",sys_xMznMiMbd2ASBAopjUBD},//50
};



//system call for int 65 using linear search
void syscall65(void)
{
	char * str_name = (char *)proc->tf->eax;
	int i;
	for(i=0;i<SIZE_65_CALLS;i++) {
		if(strcmp(syscalls65[i].name, str_name)==0) {
			proc->tf->eax =  syscalls65[i].func();
			return;
		} 
	}
	proc->tf->eax = -1;
}


//2D array for system calls based on the initials
static SYS_CALL_ARR syscalls66[SIZE_ROW_66_CALLS][SIZE_COL_66_CALLS] = {
{{},{},{},{}},//a
{{},{},{},{}},//b
{{},{},{},{}},//c
{{},{},{},{}},//d
{{},{},{},{}},//e
{{},{},{},{}},//f
{{},{},{},{}},//g
{{},{},{},{}},//h
{{},{},{},{}},//i
{{},{},{},{}},//j
{{},{},{},{}},//k
{{},{},{},{}},//l
{{},{},{},{}},//m
{{},{},{},{}},//n
{{},{},{},{}},//o
{{},{},{},{}},//p
{{},{},{},{}},//q
{{},{},{},{}},//r
{{},{},{},{}},//s
{{},{},{},{}},//t
{{},{},{},{}},//u
{{},{},{},{}},//v
{{},{},{},{}},//w
{{},{},{},{}},//x
{{},{},{},{}},//y
{{},{},{},{}},//z
};

int chaining_search(int entry, char * call_name) {
	int j=0, flag=1;
	while( j<SIZE_COL_66_CALLS) {
		if (strcmp(syscalls66[entry][j].name,call_name) ==0) {
			flag=0;
			break;
		}
		j++;
	}
	if(flag==0) {
		return j;
	} else {
		return -1;	
	}
}

void syscall66(void) {
    char * str_name = (char *)proc->tf->eax;
	
	int hash_entry;
	char c = str_name[0];
	char A = 'A';
	char Z = 'Z';
	char a = 'a';
	char z = 'z';
	if(c>=A && c<=Z) {
		hash_entry = c-A;
		
	} else if(c>=a && c<=z) {
		hash_entry = c-a;
	} else {
		proc->tf->eax=-1;
		return;		
	}

	int col=chaining_search(hash_entry, str_name);
	if(col>=0) {
		proc->tf->eax=syscalls66[hash_entry][col].func();	
	} else {
		proc->tf->eax=-1;	
	}
}

int calculatehash(char * str_name) {
	int hash_entry=-1;
	char c = str_name[0];
	char A = 'A';
	char Z = 'Z';
	char a = 'a';
	char z = 'z';
	if(c>=A && c<=Z) {
		hash_entry = c-A;
		
	} else if(c>=a && c<=z) {
		hash_entry = c-a;
	} else {
		hash_entry=-1;
	}
	return hash_entry;
}


void handleCollision(int entry, char* name, int (* func)(void)) {
	int j=0, flag=0;
	while(syscalls66[entry][j].name && j<SIZE_COL_66_CALLS) {
		j++;
		flag=1;
	}
	if(flag==1) {
		syscalls66[entry][j].name=name;
		syscalls66[entry][j].func=func;
	}
}

void insertHashEntry(char * name, int (* func)(void)) {
	int hash_entry = calculatehash(name);

	if(hash_entry<0 || hash_entry>=SIZE_ROW_66_CALLS) {
		return;
	}

	if(syscalls66[hash_entry][0].name) {
		handleCollision(hash_entry ,name, func);
	} else {
		syscalls66[hash_entry][0].name=name;
		syscalls66[hash_entry][0].func=func;
	}
}

/*void printHash() {
	int i,j;
	for(i=0;i<26;i++) {
		for(j=0;j<4;j++) {
			cprintf("row:%d col:%d :%s\t",i,j,syscalls66[i][j].name); 
		}
		cprintf("\n");
	}	
}*/

void initialiseHashmap () {
	insertHashEntry("Ayr5H",sys_Ayr5H);//1
	insertHashEntry("lcQQ6",sys_lcQQ6);//2
	insertHashEntry("tG0cd",sys_tG0cd);//3
	insertHashEntry("BQaye",sys_BQaye);//4
	insertHashEntry("vRL61",sys_vRL61);//5
	insertHashEntry("BfPAS",sys_BfPAS);//6
	insertHashEntry("rNV_x",sys_rNV_x);//7
	insertHashEntry("m9TVP",sys_m9TVP);//8
	insertHashEntry("dN3rB",sys_dN3rB);//9
	insertHashEntry("NEorw",sys_NEorw);//10
	insertHashEntry("iE45d",sys_iE45d);//11
	insertHashEntry("VFGu_",sys_VFGu_);//12
	insertHashEntry("zqf7e",sys_zqf7e);//13
	insertHashEntry("ajJ2rUS36Ds7gCvYhWvRMQ4cM",sys_ajJ2rUS36Ds7gCvYhWvRMQ4cM);//14
	insertHashEntry("y7dVW",sys_y7dVW);//15
	insertHashEntry("RhaR2",sys_RhaR2);//16
	insertHashEntry("GUT_3",sys_GUT_3);//17
	insertHashEntry("mtwGL",sys_mtwGL);//18
	insertHashEntry("Rz1qA",sys_Rz1qA);//19
	insertHashEntry("BDslj",sys_BDslj);//20
	insertHashEntry("DYcHF",sys_DYcHF);//21
	insertHashEntry("XVI4N",sys_XVI4N);//22
	insertHashEntry("RknTi",sys_RknTi);//23
	insertHashEntry("eraAb",sys_eraAb);//24
	insertHashEntry("K7plu",sys_K7plu);//25
	insertHashEntry("UPjQy",sys_UPjQy);//26
	insertHashEntry("uFjK1",sys_uFjK1);//27
	insertHashEntry("E8Jj9",sys_E8Jj9);//28
	insertHashEntry("viJpE",sys_viJpE);//29
	insertHashEntry("y8hmu",sys_y8hmu);//30
	insertHashEntry("GhPNY",sys_GhPNY);//31
	insertHashEntry("mEymb",sys_mEymb);//32
	insertHashEntry("UAi7z",sys_UAi7z);//33
	insertHashEntry("g3fke",sys_g3fke);//34
	insertHashEntry("spiXC",sys_spiXC);//35
	insertHashEntry("sCY6P",sys_sCY6P);//36
	insertHashEntry("lQ5p2",sys_lQ5p2);//37
	insertHashEntry("yFLZV",sys_yFLZV);//38
	insertHashEntry("y7NBZ",sys_y7NBZ);//39
	insertHashEntry("JS_81",sys_JS_81);//40
	insertHashEntry("pHGgA",sys_pHGgA);//41
	insertHashEntry("D3BT2",sys_D3BT2);//42
	insertHashEntry("LYSUb",sys_LYSUb);//43
	insertHashEntry("UHDeS",sys_UHDeS);//44
	insertHashEntry("zQQm5",sys_zQQm5);//45
	insertHashEntry("T4IiC",sys_T4IiC);//46
	insertHashEntry("ZnCtG",sys_ZnCtG);//47
	insertHashEntry("TBDYx",sys_TBDYx);//48
	insertHashEntry("k_jNM",sys_k_jNM);//49
}
