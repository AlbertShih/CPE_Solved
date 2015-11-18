
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Stu
{
	char name[12];
	int grade;
}	Stu;

int cmp(const void *p, const void *q)
{
	Stu *a = (Stu*)p;
	Stu *b = (Stu*)q;
	return a->grade - b->grade;
}

int main()
{
	int N;
	while( scanf("%d", &N) != EOF )
	{
		Stu *stu = new Stu[N];
		for( int i = 0; i < N; ++i )
			scanf("%s %d", stu[i].name, &stu[i].grade);
		
		qsort(stu, N, sizeof(Stu), cmp);
		
		for( int i = 0; i < N; ++i )
			printf("%s %d\n", stu[i].name, stu[i].grade);
		
		delete[] stu;
	}
}
