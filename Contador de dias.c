//Programa que dice cuantos días de nacido tienes a partir de tu fecha de nacimiento
// NO CONSIDERA QUE NO NACIMOS EL 1 DE ENERO
#include <stdio.h>
#include <time.h>
typedef int Fecha;
typedef int Aux;
void Entrada_datos(Fecha*,Fecha*,Fecha*);
void imprimir(Fecha,Fecha,Fecha);
int main()
{
    /* Uso de Biblioteca <time.h> */
    time_t tiempoactual;
    time(&tiempoactual);
    struct tm * Tiempo = localtime(&tiempoactual);
    printf("%d/%d/%d",Tiempo->tm_mday,Tiempo->tm_mon+1,Tiempo->tm_year+1900);
    
    /* DECLARATION */
    Fecha year,month,day,day_add,days_life,years_life;
    Aux X=1,cont;

    /* INPUT */
    Entrada_datos(&year,&month,&day);
    imprimir(year,month,day);

    /* BEFORE MONTH */
    if(month<Tiempo->tm_mon+1){
        years_life=Tiempo->tm_year+1900-year;
        cont=month;
        while (cont<Tiempo->tm_mon+1)
        {
            if(cont==2){ //FEBRERO
                day_add+=28;
                if(X==1){
                    day_add-=day;
                    X=-1;
                }
            }
            else if(cont%2==0){
                day_add+=30;
                if(X==1){
                    day_add-=day;
                    X=-1;
                }
            }
            else{
                day_add+=31;
                if(X==1){
                    day_add-=day;
                    X=-1;
                }
            }
            cont++;
        }
        day_add+=Tiempo->tm_mday;
    }

    /* AFTER MONTH */
    else if(month>Tiempo->tm_mon+1){
        years_life=Tiempo->tm_year+1900-year-1;
        cont=1;
        while(cont<Tiempo->tm_mon+1){
            if(cont==2) //FEBRERO
                day_add+=28;
            else if(cont%2==0) //30
                day_add+=30;
            else //31
                day_add+=31;
            cont++;
        }
        day_add+=Tiempo->tm_mday;
    }

    /* ACTUAL MONTH */
    else if(month==Tiempo->tm_mon+1){
        /* BEFORE DAYS */
        if(day<Tiempo->tm_mday){
            years_life=Tiempo->tm_year+1900-year;
            day_add=Tiempo->tm_mday-day;
        }
        /* AFTER DAYS */
        else if(day>Tiempo->tm_mday){
            years_life=Tiempo->tm_year+1900-year-1;
            day_add= 365 - day - Tiempo->tm_mday;
        }
    }    
    days_life=(years_life*365)+day_add;

    printf("\n\nTienes %d años con %d dias. ",years_life,day_add);

    return 0;
}
void Entrada_datos(Fecha * year,Fecha * month,Fecha * day){
    printf("\n\nAno de nacimiento: ");
    scanf("%d",year);
    printf("\nMes de nacimiento: ");
    scanf("%d",month);
    printf("\nDia de nacimiento: ");
    scanf("%d",day);
}
void imprimir(Fecha year,Fecha month,Fecha day){
    printf("\nAno de nacimiento: %d",year);
    printf("\nMes de nacimiento: %d",month);
    printf("\nDia de nacimiento: %d",day);
    return;
}
