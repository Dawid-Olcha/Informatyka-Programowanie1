#include <stdio.h>
#include <stdlib.h>


typedef struct Student
{
int Age;
int Height;
int Semester;
}Student;

typedef struct Students
{
int Age;
int Height;
int Semester;
}Students;

typedef struct Node Node;
struct Node
{
int Value;
Node * Next;
};


Student* Create(int, int , int);
void PrintStudent(Student *);
int areEqual(Student*, Student*);
void PrintStudents(Students *, int);


Node * Create_Node (int value); // tworzy liste jednoelementowg (alokuje wezet), ktora ma wezet wskazujacy na samego siebie jako nastepnik
Node* GetTail(Node* root); // metoda musi ustali€é pozycje ostatniego elementu majac dostep do korzenia i zwrdéciéjego adres (uwaga- nie jest tu wymagany malloc!)
void Add(Node* root, int value); //dodaje wezet dolisty, ktére| KORZEN jest przekazany jako parametr, do znalezienia konicalisty nalezy uzyé metody GetTail() z powyzej
void PrintList(Node* root); // metoda powinna wypisac liste, majgc tylko jej korzenh. Nalezy uzyé GetTail() do okreslenia, kiedy zakofczyé wypisywanie
void RemoveNode(Node * root, int value); // metoda powinna usunaé wezet o WARTOSCI podangj jako parametr, majac tylko korzen listy. UWAGA- nalezy usunaé wezel, zwolnié pamieé po nim i nie naruszyé integralnoscilisty (powinna nastapié zmiana nastepnika wezia PRZED usuwanym weztem, na zasadzie: 2->4->8->16->2->(...) , usuwamy wezet 4, nowalista: 2->8->16->2->(...)
void FreeList(Node * root); // metoda czySci pamieé po li$cie, usuwajac wszystkie wezty metoda free()
int Count(Node *root); // metoda zwraca rozmiar listy

void Sort(Node * root); // sortuje niemalejaco


int main()
{


/*	Zad 1.1
	Utworzyé strukture Student taka jak powyzej. Napisaé metody:
	Student* Create(int age, int height, int semester) // alokuje pamiec i tworzy studenta o podanych parametrach.
	WAZNE- pamieé nalezy potem zwolnié w main()!
	void PrintStudent(Student *s) // wypisuje wszystkich sktadowychstruktury
	bool AreEqueal(Student* s1, Student* s2) // zwraca informacje, czy sktadowe sq takie same (Uwaga - w C int zamiast
	bool)
	*/
	Student *student1, *student2;
	int Age, Height, Semester;

	printf("Wprowadz Wiek Studenta: ");
	scanf("%d",&Age);
	printf("Wprowadz Wzrost Studenta: ");
	scanf("%d",&Height);
	printf("Wprowadz Samestr Studenta: ");
	scanf("%d",&Semester);

	student1 = Create(Age, Height, Semester);

	printf("Wprowadz Wiek Studenta: ");
	scanf("%d",&Age);
	printf("Wprowadz Wzrost Studenta: ");
	scanf("%d",&Height);
	printf("Wprowadz Samestr Studenta: ");
	scanf("%d",&Semester);

	student2 = Create(Age, Height, Semester);

	PrintStudent(student1);
	PrintStudent(student2);

	if(areEqual(student1,student2))
				printf("Dane identyczne\n");
		else
				printf("Dane rozne\n");

	free(student1);
	free(student2);

/*	Zad 1.2.
	Utworzyétablice 3 studentow. Zapeini¢c ja wartosciami, wyswietli¢, zwolni¢é pamiec. Tablica powinna byé utworzona za
	pomocg metody malloc (prosze pilnowaé odpowiedniej iloSci gwiazdek!)
*/


int i, ilosc;
printf("Wprowadz ilosc studentow: " );
scanf("%d",&ilosc );


Students **students = (Students **)malloc(ilosc * sizeof(Students *));

for (i = 0; i < ilosc; i++)
	{
		students[i] = (Students *)malloc(sizeof(Students));
	}

for (i = 0; i < ilosc; i++)
	{
		printf("Wprowadz Wiek Studenta: ");
		scanf("%d",&students[i]->Age);
		printf("Wprowadz Wzrost Studenta: ");
		scanf("%d",&students[i]->Height);
		printf("Wprowadz Samestr Studenta: ");
		scanf("%d",&students[i]->Semester);
	}

for (i = 0; i < ilosc; i++)
	{
		PrintStudents(students[i],i);
	}


for (i = 0; i < ilosc; i++)
	{
  	free(students[i]);
	}
free(students);


//Zad.2

Node * root = Create_Node(2);
PrintList(root); // 2
Add(root, 4);
Add(root, 8);
Add(root, 16);
PrintList(root); // 2 -> 4 -> 8 -> 16
Add(root, 20);
PrintList(root); // 2 -> 4 -> 8 -> 16 -> 20
printf("Ostatni wezel ma wartosc %d\n", GetTail(root)->Value); // 20
Add(root, 16);
PrintList(root); // 2 -> 4 -> 8 -> 16 -> 20 -> 16
printf("%d\n", Count(root)); // 6
RemoveNode(root, 8);
PrintList(root); // 2 -> 4 -> 16 -> 20 -> 16
RemoveNode(root, 10); // element nieistniejacy
PrintList(root); // 2 -> 4 -> 16 -> 20 -> 16
RemoveNode(root, 16); // usu wszystkie wezty o wartoSsci 16
PrintList(root); // 2 -> 4 -> 20
printf("%d\n", Count(root)); // 3
FreeList(root); // zwolnienie pamieci na wszystkie wezty.
PrintList(root); // (nic, lista niezaalokowana)

//Zad 3.

FILE *plik1;
int num;

plik1 = fopen("numbers.txt", "w");
if (plik1 != NULL)
	{
  	printf("Poprawnie utworzono plik.\n");
	}
	else
		{
  		printf("Blad zapisu.\n");
  		return -1;
		}

printf("Wprowadz liczby [0 konczy program]: ");

while (1)    //  niekonczona petla
	{
		scanf("%d", &num);
  	if (num != 0)                     // waruenk dot. 0
			{
    		fprintf(plik1, "%d ", num);     // zapis wprowadzanych liczb do pliku
  		}
  		else
				{
    			break;
  			}
	}
fclose(plik1);


plik1 = fopen("numbers.txt", "r");
printf("\nLLICZBY ZAPISANE DO PLIKU: ");

while (fscanf(plik1,"%d", &num) != EOF )      // odczyt z pliku
	{
  	printf("%d ", num);                       // wyswietlenie na ekra w celu sprawdzenia poprawnosci tego co zostalo zpasiane do pliku
	}

fclose(plik1);

plik1 = fopen("numbers.txt", "r");

int tab[100];
i = 0;
int count=0;

while (fscanf(plik1,"%d", &i) != EOF )    // odczyt z pliku
	{
		tab[count]=i;                       // zapis do tablicy
		count++;
	}

fclose (plik1);


Node * root2 = Create_Node(tab[0]);   // tworzenie jak w  zad2 listy 1. elementowej cyklicznej - nadanie wartosci z poczatku tablicy (pobrane dane z pliku)

for (i = 1; i < count; i++)
	{
		Add(root2,tab[i]);               // dodawanie kolejnych elementow listy wartosciami nastepnymi z tablicy
	}

printf("\nLISTA JEDNOKIERUNKOWA. ");
PrintList(root2);                     //wyswielenie na ekran lsity
Sort(root2);                          // funkcja sortowania
printf("\nPOSORTOWANA LISTA JEDNOKIERUNKOWA. ");
PrintList(root2);                    // wyswietlenei na ekran posortowanej listy


FILE *plik2;
plik2 = fopen("sorted.txt", "w");

if (plik2 != NULL)
	{
  	printf("Poprawnie utworzono plik.\n");
	}
	else
		{
  		printf("Blad zapisu.\n");
  		return -1;
		}

Node *pierwszy=root2,*drugi;             // przyporzadkowanie wkaznikowi pierwszy wezla "root"
drugi=pierwszy->Next;                    // przyporzadkowanie wkaznikowi drugi nastpenego wezla
do
	{
		fprintf(plik2, "%d ", pierwszy->Value);   // zapis do pliku wartosci "root"
		pierwszy=drugi;                           //nastpene 2 linijki kodu do przesuniecie sie wskaznikow o 1 "krok" do przodu listy
		drugi=drugi->Next;
	}
while(drugi!=root2->Next);    //warunek konca petli

fclose(plik2);


plik2 = fopen("sorted.txt", "r");
printf("\nLiczby zapisane do pliku: ");

while (fscanf(plik2,"%d", &num) != EOF )     // dla sprawdzenie wyswitlenie na ekran zapisanej listy z pliku
	{
  	printf("%d ", num);
	}

fclose(plik2);

return 0;
}

//funkcj opisane przed Main


Student* Create(int age, int height, int semester)
{
	Student *new_student = (Student*) malloc (sizeof(Student));
	new_student->Age = age;
	new_student->Height = height;
	new_student->Semester = semester;
	return new_student;
}


void PrintStudent(Student *s)
{
  printf("Student ma: %d lat, %d cm wzrostu oraz uczy sie na %d semestrze \n", s->Age,s->Height,s->Semester);
}


int areEqual(Student* s1, Student* s2)
{
	return ((s1->Age == s2->Age)  &&  (s1->Height == s2->Height) &&  (s1->Semester == s2->Semester));
}


void PrintStudents(Students *s, int i)
{
  printf("Student %d ma: %d lat, %d cm wzrostu oraz uczy sie na %d semestrze \n",i+1, s->Age,s->Height,s->Semester);
}


Node * Create_Node (int value)
{
  Node * root = (Node*)malloc(sizeof(Node));
  root->Value=value;            // przekazany do funkcij int zapisuje wartosc
  root->Next=root;               // wezel wskazuje sam na siebie
  return root;
}

void PrintList(Node* root)
{
  Node *temp=root;                 //roboczy wskaznik
	printf("Elementy listy to: ");
	do
		{
			printf("%d  ", temp->Value );     //funkcja wyswietla wartosic
			temp=temp->Next;                 //zmienia adres na kolejny
		}
	while(temp != root  );            //konczy sie na dojsciu do poczatku listy
	printf("\n" );
}


Node* GetTail(Node* root)
{
  Node *temp=root;
	while(temp->Next != root)
  	{
			temp=temp->Next;                //funkcja przechodiz adres po adrsie wezla az dochodzi do ostaniego i zwraca do main
		}
	return temp;
}


void Add(Node* root, int value)
{
	Node* new_node = (Node*) malloc(sizeof(Node));      //tworzenie nowego wezla i zadeklarowanie pamieci
	new_node->Value=value;                              // wartosc przekazana z main
	new_node->Next=root;                                //wezel zapetla sie i wskazuje na poczatek listy root
	GetTail(root)->Next=new_node;                       // wykorzystanie funkcji Gettail zeby ostatni element(pred root) wskazywal teraz jako na nastepny nasz nowo tworzony wezel ktory wskazuje na root (linijak wyzej)
}


int Count(Node *root)
	{
		int count=1;
		Node *temp=root;
		while(temp->Next != root)            //funkcja przechodzi po kolejncyh wezlach i je zlicza i zwraca do main finalna wartosc
  		{
				temp=temp->Next;
  			count++;
			}
		return count;
	}


void RemoveNode(Node * root, int value)
	{
  	Node *pierwszy=root,*drugi;
  	drugi=pierwszy->Next;
		do
			{
  			if(drugi->Value==value)
  				{
    				pierwszy->Next=drugi->Next;             //wypinamy z listy wezel zminijac adresy na kotre wskazywaly wskazniki
    				free(drugi);                            // zwalaninie pamieci
    				drugi=pierwszy->Next;
  				}
    		else
    			{
    				pierwszy=drugi;
    				drugi=drugi->Next;
    			}
			}
		while(drugi!=root);
	}


void FreeList(Node * root)
	{
  	Node *pierwszy=root,*drugi, *start=root;
  	drugi=pierwszy->Next;
		do
			{
    		pierwszy=drugi;
    		drugi=drugi->Next;
  			free(pierwszy);                    // funkcja idze po kolei i zwalnia z pamieci poszeczgolen wezly a nastpenie dopina do root
  			start->Next=drugi->Next;
			}
		while(drugi!=root);
		free(root);           // na koiec pozostje lista jednoelemetowana i zwalniamy pamiec z root
	}


void Sort(Node * root)   // sortowanie niemalejace
	{

  	int temp;
		int licznik;
  	Node *pierwszy,*drugi;

		while (!(licznik==0))   // petl glowna trwa do mommentu az licznik (sprawdza czy zostal dokonana jakakolwike operacja sortowanai w ramach iteracji) wskaze 0
			{
				pierwszy=root;
				licznik=0;						// zerowanie licznika	pzed rozpoczeciem kolejnej petli
    		for (drugi=pierwszy->Next; drugi!=root; pierwszy=drugi, drugi=drugi->Next)   // podstawowe zalozenie petli to przechodzenie miedzy wezlami az do samego konca (root)
					{
						if(pierwszy->Value>drugi->Value)    //spr. czy wartosci sa narastajace jesli nie
    					{
								licznik++;                     //to liczymy rozpoczecie jenej operacji sortowania
      					temp=pierwszy->Value;          // zamiana wartosci pomiedzy wezlami w tych 3ech linijakch
      					pierwszy->Value=drugi->Value;
      					drugi->Value=temp;
							}
					}
			}
	}
