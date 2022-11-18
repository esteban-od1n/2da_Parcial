#include <stdio.h>
#include <stdlib.h>

int c[9];

void pantalla(int *c, int n){
	for(int i = 0; i < n-1; i++)
		printf("%d, ", c[i]);
	printf("%d", c[n-1]);
	printf("\n");
}

void leer_archivo(){
	FILE *archivo;
	char c, texto[20];
	int j=0, i=0;

	archivo = fopen("valores.txt","rt");
	do{
		c = fgetc(archivo);
		if (c == ',') {
			c[j] = atoi(texto);
			j++;
			for (int z = 0; z<i; z++)
				texto[z]=0;
			i=0;
			continue;
		}
		texto[i] = c;
		i++;
	}while(c!= EOF);
}

void examen(int *c, int n){
    for(int i=0; i < n; i++){
        int min = i;

        for(int j=i+1; j<n; j++){
            if(c[j] < c[min]){
                min = j;
            }
        }
        if(min != i){
            int key = c[min];
            c[min] = c[i];
            c[i] = key;
        }
    }
}

int main(){
    int n = 9;
    leer_archivo();
    printf("Ingresar: ");
    pantalla(c, n);
    examen(c, n);
    printf("Mostrar: ");
    pantalla(c, n);
    printf("\n");
}
