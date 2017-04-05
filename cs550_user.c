#include "types.h"
#include "user.h"
#include "date.h"

//Declarations
int mydate(struct rtcdate *);

//For linear search
int aaICO(void);
int xMznMiMbd2ASBAopjUBD(void);

//For hash table
int Ayr5H(void);
int y7NBZ(void);


int main() {
        int start_time, stop_time,itr, result, val=-1, rv;

	//Date with exusting implementation
	struct rtcdate r;
        if (mydate(&r)) {
                printf(2, "date failed\n");
        }
	
        printf(1,"%s\n","Printing results for date" );
        printf(1, "%d-%d-%d %d:%d:%d\n",r.year, r.month, r.day, r.hour, r.minute, r.second);

	printf(1,"\n**Testing for date bad address\n");
	struct rtcdate *r1=(struct  rtcdate *)-2;
        if (mydate(r1)) {
		asm volatile("movl %%eax, %0" : "=rm" (rv) : );
               	printf(1,"Value return: %d\t",rv);
		printf(2, "date failed\n");
        }

	printf(1,"\n");

	//Performance for pid
	printf(1,"\nPerformance for pid: ");
	start_time=uptime();
	for(itr=0;itr<1000000;itr++) {
		val=getpid();
	}
	stop_time=uptime();
	result=(stop_time-start_time)*10;
	printf(1, "%d%s",result," nanoseconds");

	printf(1,"\n");

	//First element in the linear search array
	val=aaICO();
	printf(1,"\nASCII for aaICO %d",val);
	printf(1,"\nPerformance by linear search for aaICO (First entry): ");
        start_time=uptime();
        for(itr=0;itr<1000000;itr++) {
                val=aaICO();
        }
        stop_time=uptime();
        result=(stop_time-start_time)*10;
        printf(1, "%d%s",result," nanoseconds");
	if (val <0 ) {
                printf(2, "ascii failed\n");
        }

	printf(1,"\n");

	//Last element in the linear search array
	val=xMznMiMbd2ASBAopjUBD();
        printf(1,"\nASCII for xMznMiMbd2ASBAopjUBD %d",val);
        printf(1,"\nPerformance by linear search for xMznMiMbd2ASBAopjUBD (last entry): ");
        start_time=uptime();
        for(itr=0;itr<1000000;itr++) {
                val=xMznMiMbd2ASBAopjUBD();
        }
        stop_time=uptime();
        result=(stop_time-start_time)*10;
        printf(1, "%d%s",result," nanoseconds");
        if (val <0 ) {
                printf(2, "ascii failed\n");
        }

	printf(1,"\n");

	//First entry in the hash table
        printf(1,"\nASCII for Ayr5H %d",val);
        printf(1,"\nPerformance using hash table for Ayr5H (First entry): ");
        start_time=uptime();
        for(itr=0;itr<1000000;itr++) {
                val=Ayr5H();
        }
        stop_time=uptime();
        result=(stop_time-start_time)*10;
        printf(1, "%d%s",result," nanoseconds");
        if (val <0 ) {
                printf(2, "ascii failed\n");
        }

	printf(1,"\n");

	//Last entry with most collision in the hash table
	val=y7NBZ();
        printf(1,"\nASCII for y7NBZ  %d",val);
        printf(1,"\nPerformance using hash table for y7NBZ (Last entry with most collision): ");
        start_time=uptime();
        for(itr=0;itr<1000000;itr++) {
                val=y7NBZ();
        }
        stop_time=uptime();
        result=(stop_time-start_time)*10;
        printf(1, "%d%s",result," nanoseconds");
        if (val <0 ) {
                printf(2, "ascii failed\n");
        }

	printf(1,"\n\n");

	printf(1,"***Testing code for unknown system call name or a bad string address***\n\n");

	printf(1,"Calling ajJ2rUS36Ds7gCvYhWvRMQ4cM (Entry in hash table) with int 65: \n");
	char *p = "ajJ2rUS36Ds7gCvYhWvRMQ4cM";
	asm volatile("movl %0, %%eax" : : "rm" (p));
	asm volatile("int $65" : :);
	asm volatile("movl %%eax, %0" : "=rm" (rv) : );
	printf(1,"Value returned: %d\n",rv);

	printf(1,"\n");
 
	printf(1,"Calling aaICO (Entry for linear search) with int 66: \n");
        p = "aaICO";
        asm volatile("movl %0, %%eax" : : "rm" (p));
        asm volatile("int $66" : :);
        asm volatile("movl %%eax, %0" : "=rm" (rv) : );
        printf(1,"Value returned: %d\n",rv);

	exit();
        return 0;
}
