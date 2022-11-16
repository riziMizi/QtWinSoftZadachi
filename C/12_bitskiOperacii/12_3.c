/* Program vezba11_01.c
   Shto raboti sledniot program?*/
#include <stdio.h>

int misterija( unsigned bitovi );

int main()
{
   unsigned x;
   printf( "Vnesi cel broj: " );
   scanf( "%u", &x );
   printf( "Rezultatot e %d\n", misterija( x ) );
   return 0;
}

/*Funkcijata misterija broj kolku pati vo 32 iteracii AND operacijata
pomegu 'bitovi' i 'maska' ke ja dadat vrednosta na 'maska'. 'Bitovi' po sekoja
iteracija se pomestuva na levo za edna pozicija. Na kraj dokolku promenlivata
'total' sodrzi paren broj funkcijata vraka 1 poradi toa sto pred uslovot stoj
znakot za negacija '!', dokolku 'total' e neparen broj funkijata ke vrati 0.
*/
int misterija( unsigned bitovi )
{
   unsigned i;
   unsigned maska = 1 << 31;
   unsigned total = 0; // Brojac za kolku pati operacijata (bitovi AND maska)
                       // ke ja dadat vrednosta na maska/

    //Posle sekoja iteracija 'bitovi' se pomestuva na levo za edna pozicija
    //sto znaci deka najleviot bit(MSB) se isfrla, a najdesniot bit(LSB) stanuva 0.
   for ( i = 1; i <= 32; i++, bitovi <<= 1 ) {
      if ( ( bitovi & maska ) == maska ) {
            printf("%u %u\n", bitovi, maska);
         total++;
      }
   }
   return !( total % 2 ) ? 1 : 0; // (4 % 2 == 0). (!(4 % 2 ==0)) == 1
}

