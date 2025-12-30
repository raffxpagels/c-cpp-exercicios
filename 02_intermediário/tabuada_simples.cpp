#include <stdio.h>
#include <locale.h>

int n, lin;

int main (){
		setlocale(LC_ALL, "PORTUGUESE");
		
		for (n = 1; n < 11; n++){
			printf ("TABUADA DO %d\n\n", n);
				for (lin = 1; lin < 11; lin++)
					printf ("%d x %d = %d\n", n, lin, n*lin);
					printf ("___________\n\n");
		}
	return 0;			
}
