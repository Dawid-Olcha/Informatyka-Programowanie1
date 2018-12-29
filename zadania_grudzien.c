#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int IsSorted (int *t,int n);
void printBackwards(int *t, int n);
void printDots(int *t, int n);
int Sum(int *t, int n);
int getLength(char *t, int i);
void Reverse (char *t,int i);
int containsDigits(char *t);
void containsDigitsHowMany(char *t);
int AreArraysIdentical(int * a1, int s1, int * a2, int s2);
char *reverseString(char *t);

int main()
{

/*1.1. Utworzyć 5-cio elementową tablicę typu int. Pobrać od użytkownika 5 elementów i dodać je do tablicy.
Następnie wyświetlić największą liczbę z tablicy (algorytm do samodzielnej implementacji).*/
printf("ZAD 1.1\n" );
printf("Wprowadz 5 liczb do tablicy 1:\n");
int n, a, max;
int tab1[5];           // Ustalenie rozmiaru tablicy na 5 zgodnie z trescia zadania. Skonstruowalem te zadanie w ten sposob
n=5;                   //  ze zmieniajac rozmiar linijke wyzej i parametr n na tej samej wielkosci
for(a=0;a<n;a++)       //mozna testowac wyniki zadan na dowolnych wielkosciach bez tworzenia nowych tablic dla zadan ponizej  z osobna
{
printf("Wprowadz %d liczbe: ",a+1 );
scanf("%d",&tab1[a]);
}
printf("\nWprowadzone liczby do Tablicy 1 to: ");
for(a=0;a<n;a++)
printf("%d ", tab1[a]);

max=tab1[0];
for(a=1;a<n;a++)
{
  if (tab1[a]>max)
  max=tab1[a];
}
printf("\nNajwieksza liczba to: %d\n", max);

/*1.2. Wyświetlić w pętli tablice z zadania 1.1 od początku i od końca (dwie pętle)*/
printf("\nZAD 1.2\n" );
printf("Wprowadzone liczby od poczatku: " );
for(a=0;a<n;a++)
{
  printf("%d ",tab1[a]);
}


printf("\nWprowadzone liczby od konca: " );
for(a=n-1;a>=0;a--)
{
  printf("%d ",tab1[a]);
}

/*1.3 Napisać algorytm sprawdzający, czy tablica jest posortowana w kolejności niemalejącej*/
printf("\n\nZAD 1.3" );
int i;
i=0;
for(a=0;a<n-1;a++)
{

  if (tab1[a+1]>=tab1[a])         //sprawdzam czy liczby nastepujace po sobie sa wieksze / rowne
  i++;                            // licze ilosc spelnionych warunkow
  else                            // do pierwszego niespelnionego
  break;                          //to mi wystarcza do okreslenia ze nie jest posortowana niemalejaco
}                                 //jesli ilosc spelnionych warnkow rowna sie ilosci zadanch petli tzn ze posortowana niemlecjaco

if(i==n-1||n==0||n==1)            // uznałem dla uproszczenia ze pusta tablica lub jedno-elementowa jest tablica posortowana niemalejaca
printf("\nTablica jest posortowana niemalejaco");
else
printf("\nTablica nie jest posortowana niemalejaco");


/*2.1. Utworzyć osobną metodę bool IsSorted(int *, int) realizującą zadanie 1.3 (UWAGA - w języku C niedostępny jest
typ bool z wartościami true i false, zamiast niego należy użyć int i wartości 1 i 0)*/
printf("\n\nZAD 2.1" );
printf("\nDzialanie funkji IsSorted: ");
if (IsSorted (tab1, n)==1)
printf("Tablica jest posortowana niemalejaco\n");
else
printf("Tablica nie jest posortowana niemalejaco\n");


/*2.2. Utworzyć metodę void printBackwards(int *a, int s) służącą do wypisania tablicy OD KOŃCA*/
printf("\nZAD 2.2\n" );
printf("Dzialanie funckji printBackwards: " );
printBackwards(tab1, n);

/*2.3 Utworzyć metodę printDots(int *a, int s) wyświetlającą w nowych liniach tyle kropek, ile znajduje się w danym
elemencie tablicy.*/
printf("\nZAD 2.3\n" );
printf("Dzialanie funckji wypisujacej printDots: \n\n" );
printDots(tab1,n);

/*2.4. Utworzyć metodę int Sum(int *a, int s) liczącą sumę elementów tablicy.*/
printf("\nZAD 2.4\n" );
printf("Suma wszystkich elemetow Tablicy 1 to: %d \n", Sum(tab1,n) );

/*2.5. Zaimplementować algorytm sortowania bąbelkowego (w funkcji main(), nie ma potrzeby tworzenia dodatkowej
funkcji). Algorytm powinien posortować dowolnie dużą tablicę w kolejności niemalejącej.*/
printf("\nZAD 2.5\n" );
int temp;
printf("Tablica 1 przed zastosowaniem algorytmu sortowania babelkowego:\n");
for(a=0;a<n;a++)
{
  printf("%d ",tab1[a]);
}
                            //update. ver2 - nie zauwazylem ze wyslalem wczesniej plik gdzie mialem wklejona wersje poczatkowa kodu
for(i=0;i<n-1;i++)          // Wersja ta dzialala i wykonywala swoje zadanie ale byla  ułomna i nieefektywna
{                           // w stosunku do poprzedniej wesji sa 2 zmiany: 1.usunieta zbyteczna petle while
for(a=0;a<n-i-1;a++)        //2. dopisana linijka kodu zeby za kazdym razem nie sprawdzac juz uporzadkowanego konca tablicy
{
  if (tab1[a]>tab1[a+1])
   {
  temp = tab1[a];           //utworzylem zmienna temp ktora sluzy do tymczasowego przechowania 1 pozycji z tabeli (liczby wiekszej niz nastepna)
  tab1[a]=tab1[a+1];        //ta wieksza jest nadpisywana przez mniejsza
  tab1[a+1]=temp;           //nastepnie licza wieksza ze zmiennej tymczasowej nadpisuje mniejsza co konczy cykl zamiany miejscami
   }
  }
}
  
printf("\n\nTablica 1 po zastosowaniu algorytmu sortowania babelkowego:\n");
for(a=0;a<n;a++)
{
  printf("%d ",tab1[a]);
}

if (IsSorted (tab1, n)==1)
printf("\n\nTablica jest posortowana niemalejaco\n");
else
printf("\n\nTablica nie jest posortowana niemalejaco\n");


/*3.1. Napisać metodę int getLength(char *str) , w której WŁASNORECZNIE (nie wolno korzystać z metody strlen() )
przeliczony zostanie rozmiar łańcucha (bez null-terminatora). Dla przykładu dla „Hello!" wynik powinien wynosić 6.*/
printf("\nZAD 3.1\n" );
char tab2[100];
printf("Wprowadz dowolny string do tablicy 2: ");

char c=getchar();                   //czyszczenie bufora z \n pozostawionego przez scanf zeby funkcja fgets mogla sie wykonac prawidlowo
fgets(tab2,99,stdin);               //fukcja fgets przyjmuje max ilosc znakow o 1 mnijsza gdyz dodaje znak \n na koncu
tab2[getLength(tab2,i)-1]='\0';     //usuwam znak \n (nadpisujac go znakiem konca tabeli) wstawiany przez funkcje fgets aby funkcja liczyla faktycznie wprowadzone znaki przez usera

printf("Ilosc znakow w Tablicy 2 to: %d\n",getLength(tab2,i) );

/*3.2. Napisać metodę void Reverse (char *str) , która wypisze łańcuch znaków od końca (zakaz używania strlen,
można uzyć metodę z zadania 3.1.)*/
printf("\nZAD 3.2\n" );
printf("Dzialanie funkcji void Reverse. Odwrocony string z Tablicy 2: " );
Reverse (tab2,i);

/*3.3. Napisać metodę bool containsDigits(char * str), która zwróci informację, czy w danym stringu znajduje się
jakakolwiek cyfra. Dla przykładu : „asdfgzxcv" -> false, „asdf5asdf" -> true*/

printf("\n\nZAD 3.3\n" );

printf("Dzialanie funkcji containsDigits: " );

if (containsDigits(tab2)==1)
printf("Tablica zawiera cyfry.\n" );
else
printf("Brak cyfr w tablicy.\n");
printf("Dzialanie funkcji containsDigitsHowMany: " );
containsDigitsHowMany(tab2);


/*3.4. Pobrać od użytkownika łańcuch znaków (dowolna metoda). Przekazać go do każdej z metod z 3. części zadań.*/

printf("\nZAD 3.4\n" );
char tab4[200];
printf("Wprowadz dowolny string do Tablicy 4: " );

fgets(tab4,199,stdin);

printf("\nDzialanie funkcji getLength dla Tablicy 4: ");
tab4[getLength(tab4,i)-1]='\0';                     //usuwam znak \n wstawiany przez funkcje fgets aby funkcja liczyla faktycznie wprowadzone znaki przez usera


printf("Ilosc znakow w tab4 to: %d",getLength(tab4,i) );

printf("\n\nDzialanie funkcji Reverse dla Tablicy 4: " );
Reverse (tab4,i);

printf("\n\nDzialanie funkcji containsDigits dla Tablicy 4: " );
if (containsDigits(tab4)==1)
printf("Tablica zawiera cyfry.\n" );
else
printf("Brak cyfr w tablicy.\n");

printf("\nDzialanie funkcji containsDigitsHowMany: " );
containsDigitsHowMany(tab4);

/*4.1. Pobrać od użytkownika liczbę n. Zaalokować pamięć na n elementów int i pobrać je od użytkownika.
Wykonać na niej metodę printBackwards z 2.2.*/
printf("\nZAD 4.1\n" );
printf("Wprowadz liczbe elementow w Tablicy 5: " );
scanf("%d",&n );
int *tab5;
tab5 = (int *) malloc(sizeof(int) * n);

for(a=0;a<n;a++)
{
printf("Wprowadz %d liczbe: ",a+1 );
scanf("%d",&tab5[a]);
}
printf("\nDzialanie funkcji printBackwards dla Tablicy 5: " );
printBackwards(tab5, n);
free(tab5);

/*4.2. Pobrać od użytkownika liczbę n. Zaalokować pamięć na n elementów int i pobrać je od użytkownika.
Następnie zaalokować pamięć i utworzyć tablicę, w której będą tylko UJEMNE wartości z pierwszej tablicy.
Na koniec zwolnić pamięć na obie tablice.*/
printf("\nZAD 4.2\n" );
printf("Wprowadz liczbe elementow w Tablicy 6: " );
scanf("%d",&n );
int tab6[n];
int *tab7;
int licznik=0;
i=0;

for(a=0;a<n;a++)
{
printf("Wprowadz %d liczby: ",a+1 );
scanf("%d",&tab6[a]);
if (tab6[a]<0)
  i++;                                     //licze ile jest liczb ujemnych
}

tab7 = (int *) malloc(sizeof(int) * i);   // alokuje pamiec dla oblicoznej ilosci liczb ujemnych ktore trafia do tablicy
for(a=0;a<n;a++)
{
if (tab6[a]<0)
 {
  licznik++;
  tab7[licznik-1]=tab6[a];
  }
}

if (licznik>0) {
printf("\nSkopiowano liczby ujemmne z Tablicy 6 do Tablicy 7.\n" );
printf("Jej zawartosc to: " );
for(a=0;a<i;a++)
printf("%d ",tab7[a] );}
else
printf("\nBrak liczb ujemnych do skopiowania do nowej Tablicy\n");

free(tab6);
free(tab7);


/*4.3. Napisać metodę bool AreArraysldentical(int * al, int sl, int * a2, int s2) zwracającą informację, czy dwie tablice
podane jako parametr są identyczne, tj. czy mają taką samą długość i czy na każdym indeksie występuje taki sam
element.*/

printf("\n\nZAD 4.3\n" );
int s1, s2;

printf("Wprowadz ile elementow ma miec Tablica 1: ");
scanf("%d",&s1 );
printf("\n");
int *a1;
a1 = (int *) malloc(sizeof(int) * s1);
for(a=0;a<s1;a++)
{
printf("Wprowadz %d element Tablicy 1: ",a+1 );
scanf("%d",&a1[a]);
}


printf("\nWprowadz ile elementow ma miec Tablica 2: ");
scanf("%d",&s2 );
printf("\n");
int *a2;
a2 = (int *) malloc(sizeof(int) * s2);
for(a=0;a<s2;a++)
{
printf("Wprowadz %d element Tablicy 2: ",a+1 );
scanf("%d",&a2[a]);
}

if (AreArraysIdentical(a1,s1,a2,s2)==1)
printf("\nTablice sa identyczne\n" );
else
printf("\nTablice sa rozne\n" );

free(a1);
free(a2);


/*
4.4. Napisać metodę char * reverseString(char*s), która ZWRÓCI (a nie wypisze!) string, który jest odwróconym
stringiem przekazanym jako pierwszy parametr. Funkcja zaalokuje pamięć na nowy łańcuch i go zwróci. (cały
algorytm należy zaimplementować samodzielnie). Należy go następnie „przechwycić" w funkcji main, aby pamięć na
koniec wyczyścić:
int main()
{
// zaalokuj i pobierz od usera tablicę *str, dla przykładu pobrać „Ala ma kota!"
char * result = reverseString(str);
printf(„%s", result); // !atok am alA
free(str); // zwalniamy pamięć z pierwszej tablicy
free(result); // zwracamy wynik z funkcji, który „przechwycił" main().
}*/

printf("\nZAD 4.4\n" );
c=getchar();  // usuwam /n z bufora pozostwionego przez scanf dla poprawnego dzialania f. fgets
int dl,max_size;
char *tab8;
max_size=100;
printf("Wprowasz string do Tablicy 8: " );
tab8 = (char *) malloc(sizeof(char) * (max_size+1));
fgets(tab8,max_size,stdin);
tab8[strlen(tab8)-1] = '\0';   //pozbywam sie znaku /n nadpisujc go znakiem \0
printf("Dzialanie funkcji reverseString dla Tablicy 8: " );

char *result=reverseString(tab8);
printf("%s\n",result );

free(tab8);
free(result);


return 0;
}

//tworzac funkcje stosowalem zapis t[] dla wygody wlasnej. W ksiazce S. Prata pisze ze mozna te zapisy stosowac zamiennie


int IsSorted (int *t, int n)
{
  if(n==1 || n==0)
return 1;

  for(int a=0;a<n-1;a++)
  if(t[a+1]<t[a])
  return 0;

return 1;

  }


void printBackwards(int *t, int n)
{
for(int a=n-1;a>=0;a--)
  printf("%d ",t[a]);
  printf("\n");
}


void printDots(int *t, int n)
{
  int a,i;
  for(i=0;i<n;i++){
  for (a=0; a<t[i]; a++) {
  printf("*");}
  printf("\n" );
  }
  printf("\n" );
}

int Sum(int *t, int n)
{
  int a,i=0;
  for(a=0;a<n;a++){
  i=t[a]+i;}
return i;
  }

  int getLength(char *t, int i)
  {
  i=0;
  while(t[i]!='\0')
  {
       i++;
     }
  return i;
  }

  void Reverse (char *t,int i)
  {
    for(i=getLength(t,i)-1;i>=0;i--)
    printf("%c", t[i]);
  }

  int containsDigits(char *t)
  {
    int i,cyfry=0;
    for(i=0; t[i]!='\0'; ++i)
       if(t[i]>='0' && t[i]<='9')
               return 1;
       }

void containsDigitsHowMany(char *t)
       {
         int i,cyfry=0;
         for(i=0; t[i]!='\0'; ++i)
            {if(t[i]>='0' && t[i]<='9')
                    ++cyfry;}
     printf("Tablica zawiera cyfry. Sztuk: %d.\n",cyfry );

}

int AreArraysIdentical(int * a1, int s1, int * a2, int s2)
{
int i;
if(s1==0 && s2==0)
return 1;

if(s1==s2){
for (i = 0; i<s1; i++){
  if (!(a1[i]==a2[i]))
    return 0;}}

    if(s1==s2){
    for (i = 0; i<s1; i++){
      if ((a1[i]==a2[i]))
        return 1;}}

return 0;
}



char *reverseString(char *t)
{
  int a,dl;
  char *result;
  dl=strlen(t); //5

  result = (char *) malloc(sizeof(char) * (dl+1));

  for(a=0;a<dl;a++)
  {
      result[a]=t[dl-a-1];
  }
  result[dl]='\0';
  return result;}
