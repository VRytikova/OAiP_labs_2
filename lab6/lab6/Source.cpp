#include <iostream>
#include<string>

using namespace std;

struct stack
{
	int course, id;
	string name;
	stack* prev;
};

struct hashh
{
	stack* table[10] = { NULL };
};

void add(stack** p_st, string x, int y, int z)
{
	stack* university = new stack;
	university->name = x;
	university->course = y;
	university->id = z;
	university->prev = (*p_st);
	(*p_st) = university;
}
//
//void del(stack** p_st)
//{
//	if ((*p_st) == NULL) return;
//	stack* f = (*p_st);
//	(*p_st) = (*p_st)->prev;
//	delete(f->s);
//	delete (f);
//}

int hash_function(int id)
{
	return id % 100;
}

void add_hash(hashh* h, string name, int course, int id)
{
	int index = hash_function(id);
	add(&(h->table[index]), name, course, id);
}

stack* find_hash(hashh* h, int id)
{
	int index = hash_function(id);
	stack* st = h->table[index];
	while (st)
	{
		if (id == st->id) return st;
		st = st->prev;
	}
	return NULL;
}

//void delete_hash(hash* h, int id)
//{
//	int index = hash_function(id);
//	stack* st = h->table[index];
//	stack* next = NULL;
//	while (st)
//	{
//		if (id == st->id)
//		{
//			if (next) next->prev = st->prev;
//			else h->table[index] = st->prev;
//			delete st->s;
//			delete st;
//			return;
//		}
//		next = st;
//		st = st->prev;
//	}
//}


int main()
{
	hashh* h = new hashh();
	int  id, course, num;
	string name;
	cout<<"Enter the number of students \n";
	cin>>num;
	for (int i = 0; i < num; i++)
	{
		cout<< "Enter name \n";
		cin >> name;
		printf("Enter course \n");
		cin >> course;
		cout<< "Enter id \n";
		cin >> id;
		add_hash(h, name, course, id);
	}
	cout<< "Enter necessary id\n";
	cin >> id;
	stack* st = find_hash(h, id);
	cout<<"The name: "<< st->name<<" The course: "<< st->course<<endl;
	return 0;
}