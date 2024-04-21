#include<math.h>
#include<stdio.h>
int elevar(int);
int main(void)
{
    double x[12];
    x[0]=1.9;
    for (int i=1; i<=11; i++){
        x[i]=x[i-1]+0.1;
    }

    double J[12]={0.281818559374385,  0.223890779141236, 0.166606980331990, 0.110362266922174,
    0.055539784445602, 0.002507683297244, -0.048383776468198, -0.096804954397038,
    -0.142449370046012, -0.185036033364387, -0.224311545791968, -0.260051954901934};



    for (int n=1; n<=5; n=n+2){

    double y[n+1];
    double mat[n+1][n+1];
    int l=0;
    for (int j=0; j<=n; j++)
    {

        y[j]=J[5-(n-1)/2 + j];
        mat[j][0]= x[5-(n-1)/2 + j];
    }


    for (int k=1; k<=n; k++)   //columnas
    {
        for (int q=k; q<=n;q++){ //filas
        mat[q][k]=(mat[q][k-1]-mat[q-1][k-1])/(y[q]-y[q-k]);

    }
    }


    double p=0;
    double z=0;
    double w[n+1];
    w[0]=1;
    for (int m=1; m<=n; m++){
        w[m]=w[m-1]*(z-y[m-1]);
    }
    for (int k=0; k<=n; k++){
        p=p+mat[k][k]*w[k];

    }

    printf("p[%d]=%.16G\n",n,p);

}
    return 0;
}


int elevar(int j){
    int a=1;
    for(int i=0; i<j; i++){
        a=(-1)*a;
    }
    return a;
}
