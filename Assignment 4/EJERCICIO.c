 #include <stdio.h>
#include <math.h>
//Polinomios de Chebishev y Legendre
double P(int, double, char);
double dP (int, double, char);
//Cálculo de coeficientes
double coefa(int, double, char);

//Método de Newton
double newton (int, double, char);
double metode (int, double, double, char);

//Funciones a integrar
double f1 (double );
double f2 (double );
double f3(double );

int main (void){
    //Trobarem els intervals on hi ha les arrels, sabent que el nombre d'arrels es n.
    char C[2]="TP";
    int n;
    printf("Introdueix el valor de n \n");
    scanf("%d", &n);
    double Integral1;
    double Integral2T;    //Chebishev
    double Integral2L;    //Legendre
    double Integral3;
    for (int i=0; i<=1; i++){
        char c=C[i];

    if(c=='T'){
        printf("\nPOLINOMIS DE CHEBISHEV\n");
    }
    else{

        printf("\nPOLINOMIS DE LEGENDRE\n");
    }


    double a=-1.,b=1.;

    for (int i=2; i<100; i++){
        double h=(b-a)/i;
        double inter[n];
        double sols[n];
        double arrels[n];
        int count=0;
        int solu=0;

        for (int j=0; j<i; j++){
            if (P(n, a+j*h, c)*P(n,a+(j+1)*h, c)<0){
                inter[count]=j;
                count+=1;
            }
            if (P(n,a+j*h, c)==0){
                sols[solu]=j;
                solu+=1;
            }
        }  //Notem que no es comproba p(b)
        if (P(n, b, c)==0){
            sols[solu]=i;
            solu+=1;
        }


        if ((count+solu)==n){
        //TROBEM LES ARRELS
            for(int k=0; k<count; k++){
                arrels[k]=metode(n, a+inter[k]*h, a+(inter[k]+1)*h, c);
            }
             for (int l=0; l<solu; l++){
                printf("Hi ha una solucio en x= %.16G\n", a+sols[l]*h);
                arrels[count+l-1]=a+sols[l]*h;
            }

            for (int r=0; r<n; r++){
                    printf("x_[%d]=%.16G         a_[%d]=%.16G\n", r, arrels[r], r,  coefa(n, arrels[r], c));
            }


            if (c=='P'){
            //INTEGRAL 1 (amb Legendre)
            double integralp=0;
            for (int j= 0; j<n; j++){
            integralp+=coefa(n, arrels[j], c)*f1(arrels[j]);
            }
            Integral1=integralp;


            //INTEGRRAL 3 (amb Legendre)
            double integralt=0;
            for (int j= 0; j<n; j++){
            integralt+=coefa(n, arrels[j], c)*f3(arrels[j]);
            }
            Integral3=integralt;
            }


            if (c=='T'){
                //INTEGRAL 2 (amb Chebishev)
            double integralsT=0;
            for (int j= 0; j<n; j++){
            integralsT+=coefa(n, arrels[j], c)*f2(arrels[j]);
            }
            Integral2T=integralsT;
            }

            break;

        }









        }

    }
///TRAPEZIS
double nodes[n];
  double a=-1.;
  double b=1.;
  double h= (b-a)/(n-1);

    double I1=(h/2)*(f1(a)+f1(b));
    double I3=(h/2)*(f3(a)+f3(b));

    for (int k=1; k<(n-1); k++){
        nodes[k]=a+k*h;
        I1+=h*f1(nodes[k]);
        I3+=h*f3(nodes[k]);
    }





    ///PRIMERA INTEGRAL
    printf("\n\n");
    printf("PRIMERA INTEGRAL\n");

    //Integral Con fórmula gaussiana

    printf("Integral 1-Legendre son I1=%.16G\n", Integral1);


    //Integral Con Trapezios
    printf("Valor de la Integral 1 con la regla de los trapezios compuesta con N=%d\n", n-1);

    printf("T_1 = %.16G\n",I1);

    ///SEGUNDA INTEGRAL
    printf("\nSEGONA INTEGRAL\n");

    printf("Integral 2 con la Formulas de Chebishev \n");
    printf("I2T=%.16G\n", Integral2T);


    ///TERCERA INTEGRAL
    printf("\nTERCERA INTEGRAL\n");

    //Integral Con fórmula gaussiana
    printf("Valor de la Integral 3 con las Formulas de Integracion Gaussiana de Legendre son \n");
    printf("I3=%.16G\n",Integral3);



    //Integral Con Trapezios
    printf("Valor de la Integral 3 con la regla de los trapezios compuesta con N=%d\n", n-1);


    printf("T_3 = %.16G\n",I3);



    printf("\n\n ATENTAMENT \n Els teus alumnes preferits\n ARNAU PERICH & ERIC JIMENEZ ;)\n");
}

double P (int n, double x, char c)
{
    if (n==0){
        return 1;
    }
    if (n==1){
        return x;
    }
    else{
        if (c=='P'){
        double p[n];
        p[0]=1;
        p[1]=x;
        for (int j=2; j<=n; j++){
            p[j]=((2*j-1.)/j)*x*p[j-1]-((j-1.)/j)*p[j-2];
        }
        return p[n];
        }
    if (c=='T'){
        double t[n];
        t[0]=1;
        t[1]=x;
        for (int j=2; j<=n; j++){
            t[j]=2*x*t[j-1]-t[j-2];
        }
        return t[n];
    }
    }

}

double dP (int n, double x, char c)  //introdueixes n, x y el polinomi
{
    double pn = P(n, x, c);
    double pn1= P(n-1, x, c);
    return (-n*x*pn+n*pn1)/(1.-x*x);
}
double metode (int n, double a, double b, char c) //a, b l'interval
{
         if ((P(n, a, c)*P(n, b, c))>0){
            printf("No hi ha solucions en aquest interval");
            return 1;
         }
         double m;
         while ((b-a)>1e-4){
            m = (b+a)/2.;
            if (P(n, m, c)==0){
                return m;
            }
            if ((P(n, m, c)*P(n, a, c))<0){
                b=m;
            }
            if ((P(n, m, c)*P(n, b, c))<0){
                a=m;
            }
         }
         return newton(n, (b+a)/2, c);
}


double newton (int n, double x, char c)
{

    double a[100];
    a[0]=x;
    a[1]= x - (P(n, x, c)/dP(n, x, c));
    int k=1;
    double error = 10e-15;
    while (fabs(a[k]-a[k-1])>=error){
        a[k+1]=a[k] - (P(n, a[k], c)/dP(n, a[k], c));
        k+=1;
    }
    return a[k];
}

double coefa(int n, double x, char c)
{
    if(c=='P'){
    return (2/((1-x*x)*(dP(n, x, c))*(dP(n, x, c))));
    }
    if(c=='T'){
        return M_PI/n;
    }
}

double f1 (double x)
{
    return (1/(1+x*x));
}



double f3 (double x)
{
    return (fabs(x));
}


double f2(double x)
{
 return (x*x*x*x*x*x*x*x - 2*x*x*x*x*x*x + 3*x*x*x*x - x*x + 5);
}



