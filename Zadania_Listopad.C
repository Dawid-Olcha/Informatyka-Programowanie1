#include <stdio.h>
#include <stdlib.h>

int main()
{
/*
/*1.1. Zadeklarować zmienne typu int, float, char.
Przypisać do nich wartość, wyświetlić je na ekran.*/

  int godz, min;
  float cena, liczba;
  char miasto_start [20]="Szczecin";  //ograniczone dlugosc nazw miast do 20 znakow
  char miasto_koniec [20]="Poznan";

  godz = 17;
  min = 37;
  cena = 45.23;

printf("Pociag na trasie %s - %s odjedza o godz %d:%d. Cena biletu wynosci %.2f PLN\n\n\n", miasto_start, miasto_koniec, godz, min, cena);

/*1.2. Wyświetlić zmienną typu int na ekran.
Należy użyć metody printf i konstrukcji %d*/

int i;
printf("Prosze podac liczbe calkowita: ");
scanf("%d", &i);
printf("Wprowadzona liczba to: %d\n\n\n",i);

//1.3. Pobrać od użytkownika liczbę x. Wyświetlić kwadrat liczby x.

printf("Prosze podac liczbe calkowita: ");
scanf("%d", &i);
printf("%d do kwadratu to: %d\n\n\n", i, i*i);

/*1.4. Zapoznać się z instrukcjami warunkowymi (if, else if, else oraz switch).
Pobrać od używkownika liczbę i wyświetlić informację, czy jestona: mniejsza, większa, czy równa 0.*/


printf("Prosze podac liczbe calkowita: ");
scanf ("%d", &i);
if (i>0)
printf("Wprowadzona liczba jest wieksza od 0\n\n\n");
  else if (i<0)
  printf("Wprowadzona liczba jest mniejsza od 0\n\n\n");
    else
    printf ("Wprowadzona liczba jest rowna 0\n\n\n");

/*1.5. Pobrać ud użytkownika 3 liczby (x1, x2, x3).
Wyświetlić informację, która z tych liczb jest największa.*/


int x1, x2, x3;
printf("Prosze podac 3 liczby calkowite (oddzielone spacjami): \n");
scanf ("%d %d %d", &x1, &x2, &x3);
if (x1>=x2 && x1>=x3)                               // >= uzyte zamiast > zeby wykluczyc blad logiczny przy wprowadzeniu 3ech takich samych liczb i braku odp
printf("Liczba %d jest najwieksza\n\n\n",x1);
  else if (x2>=x3 && x2>=x1)
  printf("Liczba %d jest najwieksza\n\n\n",x2);
    else if (x3>=x2 && x3>=x1)
    printf("Liczba %d jest najwieksza\n\n\n",x3);


/*1.6. Napisać prosty kalkulator. Należy pobrać od użytkownika 2 liczby oraz operator
(jeden z czterech: mnożenie, dzielenie, dodawanie,odejmowanie).
Wymagane jest utworzenie prostego menu użytkownika. Uwaga - należy pamiętać o ułamkach (1/3 powinno dać 0.33, a nie 0)*/



float liczba1, liczba2;
char znak;


printf ("Instrukcja Kalkulatora v1.0\n");
printf ("Dostepne sa 4 dzialania arytmetyczne:\n");
printf ("1) Dodawanie - nalezy uzyc znaku \"+\" \n");
printf ("2) Odejmowanie - nalezy uzyc znaku \"-\" \n");
printf ("3) Mnozenie - nalezy uzyc znaku \"*\" \n");
printf ("4) Dzielenie - nalezy uzyc znaku \"/\" \n\n");


printf("Wprowadz znak dzialania: ");
scanf("%s",&znak);
printf("Wprowadz dwie liczby (oddzielone spacja): ");
scanf("%f %f", &liczba1, &liczba2);

switch (znak)
  {
    case '+' :
    printf ("Wynik dzialania to : %f\n\n" , liczba1+liczba2);
    break;
    case '-' :
    printf ("Wynik dzialania to : %f\n\n" , liczba1 - liczba2);
    break;
    case '*' :
    printf ("Wynik dzialania to : %f\n\n" , liczba1 * liczba2);
    break;
    case '/' :
    if (liczba2 == 0 )
    printf ("!! Blad !! Dzielenie przez zero !! Blad !!\n\n");
    else
    printf ("Wynik dzialania to : %f\n\n" ,liczba1 / liczba2);
    break;
    default :
    printf ("!! Blad !! Wprowadzono nieprawidlowy znak arytmetyczny !! Blad !! .\n\n");
    break;
    }

/*2.1. Zapoznać się z pętlą while. Pętla ta służy do wielokrotnego wykonania fragmentu kodu przez NIEZNANĄ Z GÓRY ilość razy.
Pętlawykonuje się zawsze, jeśli warunek jest prawdziwy (ewaluowany do true). Napisać pętlę, w któej użytkownik podaje liczbę x.
Należy wyświetlić tę liczbę. Jeżeli użytkownik poda 0, należy zakończyć program.*/


while (i!=0)
{
  printf ("Wprowadz liczbe (0 konczy program): ");
  scanf ("%d",&i);
  printf("Wprowadzono liczbe: %d\n",i);
}
printf("Program zakonczony.\n\n\n");

/*2.2. Przerobić kalkulator z zadania 1.6. Teraz po każdym działaniu program powinien spytać użytkownika, czy ten chce powtórzyć
wszystko od początku. Jeśli tak - restartujemy kalkulator i zaczynamy od nowa. Jeśli nie - kończymy program.*/

char odp;


printf ("Instrukcja Kalkulatora v2.0\n");
printf ("Dostepne sa 4 dzialania arytmetyczne:\n");
printf ("1) Dodawanie - nalezy uzyc znak \"+\" \n");
printf ("2) Odejmowanie - nalezy uzyc znak \"-\" \n");
printf ("3) Mnozenie - nalezy uzyc znak \"*\" \n");
printf ("4) Dzielenie - nalezy uzyc znak \"/\" \n\n");

while(odp!='n')
{
  printf("Wprowadz znak dzialania: ");
  scanf("%s",&znak);
  printf("Wprowadz dwie liczby (oddzielone spacja): ");
  scanf("%f %f", &liczba1, &liczba2);

  switch (znak)
    {
      case '+' :
        printf ("Wynik dzialania to : %f\n\n" , liczba1+liczba2);
        printf ("Czy wykonac ponowne dzialanie? .\n");
        printf ("Wprowadz \"n\" by przerwac lub \"t\" by kontynuowac.\n\n");
        scanf("%s",&odp);
      break;
      case '-' :
        printf ("Wynik dzialania to : %f\n\n" , liczba1 - liczba2);
        printf ("Czy wykonac ponowne dzialanie? .\n");
        printf ("Wprowadz \"n\" by przerwac lub \"t\" by kontynuowac.\n\n");
        scanf("%s",&odp);
      break;
      case '*' :
        printf ("Wynik dzialania to : %f\n\n" , liczba1 * liczba2);
        printf ("Czy wykonac ponowne dzialanie? .\n");
        printf ("Wprowadz \"n\" by przerwac lub \"t\" by kontynuowac.\n\n");
        scanf("%s",&odp);
      break;
      case '/' :
      if (liczba2 == 0 )
        printf ("!! Blad !! Dzielenie przez zero !! Blad !!\n\n");
      else
        printf ("Wynik dzialania to : %f\n\n" ,liczba1 / liczba2);
        printf ("Czy wykonac ponowne dzialanie? .\n");
        printf ("Wprowadz \"n\" by przerwac lub \"t\" by kontynuowac.\n\n");
        scanf("%s",&odp);
      break;
      default :
        printf ("!!Blad!! Wprowadzona nieprawidlowy znak arytmetyczny !!Blad!! .\n\n");
        printf ("Czy wykonac ponowne dzialanie? .\n");
        printf ("Wprowadz \"n\" by przerwac lub \"t\" by kontynuowac.\n\n");
        scanf("%s",&odp);

      break;
    }
}


/*2.3. Pobrać od użytkownika liczbę x. Należy wyświetlić wszystkie kolejne potęgi liczby x.
Zakończyć program, kiedy liczba przekroczy 100000.*/

int k, licznik;

printf ("Wprowadz liczbe calkowita: ");
scanf("%d", &k);
printf ("\n");
i=1;
licznik=0;
while (i<100000)
  {
    i=k*i;
    licznik++;
    printf(" %d do potegi %d to:   %d\n",k,licznik,i);
  }
printf ("\nLiczba %d przy potedze %d przekroczyla 100 000\n",k, licznik);
printf("\n\n\n");


/*2.4. Pobrać od użytkownika liczbę x. Jeśli liczba jest niedodatnia - należy zakończyć program.
Następnie należy wyświetlać kolejno (wnowej linii) wszystkie liczby mniejsze od x, aż osiągnięte zostanie 0.*/

int x;
printf("Wprowadz liczbe: ");
scanf ("%d", &x);
printf ("\n");
if(x<=0)
{
  printf("Liczba niedodatnia. Koniec programu");
}
else
{
  printf("Liczby od %d do 0 to: ",x);
  while(x>0)
    {
        x--;
        printf ("%d ",x);
    }
}
printf("\n\n\n");

/* 2.5. Zapoznać się z instrukcjami continue; i break;. Pierwsza służy do zakończenia iteracji i przejścia do następnej,
a druga natychmiastkończy pętlę. Przerobić program z zadania 1.4, aby wyświetlał tylko parzyste liczby (użyć if oraz continue).
Jeśli liczba wynosi 40, należy wyjść z pętli i zakończyć program.*/


printf("Wprowadz liczbe: ");
scanf ("%d", &x);
if(x<=0)
{
  printf("Liczba niedodatnia. Koniec programu");
}
else
{
  printf("Liczby parzyste od %d do 0 to: ",x);
}
while (x>0)
{
  x--;
  if (x==40)
  {
  printf("\nLiczba 40 konczy program \n");
  break;
  }
  else if (x%2!=0)
  {
  continue;
}
  printf ("%d ",x);

}

printf("\n\n");


/*2.6. Zapoznać się z pętlą for. Pętla służy do wykonania danego fragmentu kodu ZNANĄ Z GÓRY określoną ilość razy. Uwaga - każdą pętlę
for można zastąpić pętlą while i wzajemnie. Zwyczajowo obowiazuje zasada, że jeśli ilość iteracji jest znana - używamy for, a jeśli nie jest
znana (zależy od użytkownika lub jakiegoś stanu zewnętrznego) - używamy pętli while. Pętla for składa się z: ZMIENNEJ ITERACYJNEJ,
czyli stanu początkowego pętli, np. int i = 0. Następnie WARUNKU ZAKOŃCZENIA PĘTLI, np. i<10. Następnie OPERACJI WYKONYWANEJ
PO KAŻDEJ ITERACJI - zazwyczaj jest to zwiększenie iteratora o 1, czyli i = i + 1, bądź w skrócie i++. Napisać pętlę for, która wyświetli cyfry
od 0 do 9.*/


printf("Cyfry od 0 do 9 \n");
for (i = 0; i < 10; i++)
printf (" %d ",i);
printf("\n\n\n");


/*2.7. Pobrać od użytkownika liczby x i y. Zakładamy, że y > x (zawsze, nie musimy tego sprawdzać). Za pomocą pętli for wypisać liczby
między x a y (do przemyślenia - co jest stanem początkowym, a co warunkiem zakończenia pętli?)*/

int y;
printf("Wprowadz dwie liczby (druga wieksza): ");
scanf ("%d %d",&x , &y);
printf("Liczby od %d do %d to: ",x,y);
for (i=1; x+i<y; x++)
{
  printf ("%d ",x+i);
}
printf("\n\n\n");


printf("Wprowadz dwie liczby: ");
scanf ("%d %d",&x , &y);
printf("Liczby od %d do %d to: ",x,y);
i=1;
while (x+i<y)
{
  x++;
  printf("%d ",x);
}
printf("\n\n\n");

//2.8. Pobrać od użytkownika liczbę x. Za pomocą pętli for wypisać wszystkie liczby mniejsze od x, ale większe niż 0.

printf("Wprowadz liczbe: ");
scanf ("%d",&x);
printf("Liczby wieksze od 0 a mniejsze od %d to: ",x);
for(i=1; i<x; i++)
{
  printf (" %d",i);
}
printf("\n\n\n");


//2.9. Pobrać od użytkownika liczbę x. Za pomocą pętli for wypisywać CO TRZECIĄ liczbę większą od x. Pętla powinna się zakończyć, jeśli
//liczba przekroczy 100. Uwaga - proszę nie używać operacji continue i break, a sterować tylko parametrami pętli.

printf("Wprowadz liczbe: ");
scanf ("%d",&x );
printf("Liczby wzrastajace o 3 z zakresu od %d do 100 to: ",x);
for (i=x+3; i<100; i+=3)
{
  printf (" %d",i);
}
printf("\n\n\n");





//3.1. Napisać metodę void NewLine(). Powinna ona wypisać na ekran pojedynczą pustą linię. Użyć tej metodę w main().
void NewLine ();
NewLine ();

/*3.2. Napisać metodę void NewLines(int count). Powinna ona wypisać tyle nowych linii, ile zostało podanych W PARAMETRZE count (należy
użyć pętli for). Użyć metodę w main()*/

void NewLines (int);
scanf("%d", &x);
NewLines (x);

/*3.3. Napisać metodę void WriteBiggerNumber(int x, int y). Metoda powinna pobrać 2 parametry i zwrócić większy z nich. Wykorzystać
funckję w metodzie main(). UWAGA - pobieranie liczb od użytkownika powinno odbyć się w funkcji main(), a NIE w WriteBiggerNumber! Do
funkcji należy jedynie przesłać pobrane wcześniej parametry.*/


int WriteBiggerNumber (int, int);
printf("Wprowadz dwie liczby\n");
scanf("%d %d", &x, &y);
if(WriteBiggerNumber(x, y)==0)
{
  printf("Liczby sa rowne\n");
}
else
{
  printf("Liczba %d jest wieksza\n", WriteBiggerNumber(x, y));
}
printf("\n\n\n");


/*3.4. Napisać metodę Multiply(int x, int y) . Metoda powinna ZWRÓCIĆ (słowo kluczowe return) iloczyn dwóch parametrów. Uwaga! Metoda
NIE POWINNA wypisywać wyniku - powinien on być wyświetlony w funkcji main!*/
int Multiply(int,int);
printf("Wprowadz dwie liczby\n");
scanf("%d %d", &x, &y);
int wynik;
wynik= Multiply(x,y);
printf("%d*%d=%d\n",x,y,wynik);


return 0;
}


void NewLine ()
{
  printf("\n");
}


void NewLines (int x)
{
int i;
for (i=0;i<x;i++)
{
  printf("\n");
}
}


int WriteBiggerNumber(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else if(y > x)
	{
		return y;
	}
else
return 0;
}


int Multiply(int x,int y)
{
  return x*y;
}
