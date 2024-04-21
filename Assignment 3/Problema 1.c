#include<stdio.h>
#include<math.h>
double f (double);

int main(void)
{
    FILE *fp;
    fp=fopen("fp.txt","w");

    ///EQUIDISTANTS
    FILE *n4e;
    n4e=fopen("n4e.txt","w");
    FILE *n8e;
    n8e=fopen("n8e.txt","w");
    FILE *n16e;
    n16e=fopen("n16e.txt","w");
    FILE *n32e;
    n32e=fopen("n32e.txt","w");


    ///SHEBISHEV
    FILE *n4s;
    n4s=fopen("n4s.txt","w");
    FILE *n8s;
    n8s=fopen("n8s.txt","w");
    FILE *n16s;
    n16s=fopen("n16s.txt","w");
    FILE *n32s;
    n32s=fopen("n32s.txt","w");



    /// NÚMERO DE NODES

    int nodes[5]={4, 8, 16, 32, 64};
    int n;
    printf(" NODOS         ERROR NODOS EQUIDISTANTES         ERROR NODOS CHEBISHEV           COCIENTES\n");
    for (int i=0; i<=4; i++){
        n= nodes[i];


    /// NODES EQUIDISTANTS
    double x[n+1];
    double mate[n+1][n+1];


    for (int j=0; j<=n; j++)
    {
        x[j]=-1.+j*2./n;
        mate[j][0]= f(x[j]);
    }


    ///  NODES DE SHEBISHEV
    double y[n+1];
    double mats[n+1][n+1];
    double pi=M_PI;

     for (int j=0; j<=n; j++)
    {
        y[j]=cos(((2*j+1)*pi)/(2*(n+1)));
        mats[j][0]= f(y[j]);
    }





    for (int k=1; k<=n; k++)   //columnas
    {
        for (int q=k; q<=n;q++){ //filas
        mate[q][k]=(mate[q][k-1]-mate[q-1][k-1])/(x[q]-x[q-k]);  /// EQUIDISTANTS


        mats[q][k]=(mats[q][k-1]-mats[q-1][k-1])/(y[q]-y[q-k]);  /// CHEBISHEV

    }
    }



    double ze;
    double zs;

    double pe=mate[0][0];
    double ps=mats[0][0];


    ///Seguiment de l'error///
    double Ee=0, Es=0,  co=0;     //Como solo queremos el máximo, si es mayor al anterior lo almacenamos, si no no.

    for (int l=0; l<=180; l++){

    double we[n+1];      ///EQUIDISTANTES
        we[0]=1;
        ze=-0.989+0.011*l;
    double ws[n+1];      ///CHEBISHEV
        ws[0]=1;
        zs=-0.989+0.011*l;

    for (int m=1; m<=n; m++){
        we[m]=we[m-1]*(ze-x[m-1]);
        ws[m]=ws[m-1]*(zs-y[m-1]);
    }
    double pe=0;
    double ps=0;
    for (int k=0; k<=n; k++){
        pe=pe+mate[k][k]*we[k];
        ps=ps+mats[k][k]*ws[k];


    }

    /// CONTROL DE L'ERROR

    if (fabs(pe-f(ze))>Ee){
        Ee=fabs(pe-f(ze));
    }
    if (fabs(ps-f(zs))>Es){
        Es=fabs(ps-f(zs));
    }


    /// IMPRESIÓN

    if (n==4){

        fprintf(fp, "%.16G  %.16G\n",ze, f(ze)); // Impresión función f

        fprintf(n4e, "%.16G  %.16G\n",ze, pe);
        fprintf(n4s, "%.16G  %.16G\n",zs, ps);
    }
    if (n==8){

        fprintf(n8e, "%.16G  %.16G\n",ze, pe);
        fprintf(n8s, "%.16G  %.16G\n",zs, ps);
    }
    if (n==16){

        fprintf(n16e, "%.16G  %.16G\n",ze, pe);
        fprintf(n16s, "%.16G  %.16G\n",zs, ps);
    }
    if (n==32){

        fprintf(n32e, "%.16G  %.16G\n",ze, pe);
        fprintf(n32s, "%.16G  %.16G\n",zs, ps);
    }

    }
    /// COMPARACIÓN DE ERRORES (COCIENTES)

    co= Ee/Es;

    printf("%d                 %.16G                 %.16G         %.16G\n", n, Ee, Es, co);

}
    return 0;
}


double f (double x)
{
    return 1./(1.+25.*x*x);
}
