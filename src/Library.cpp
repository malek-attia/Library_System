#include<iostream>
#include<algorithm>
using namespace std;


void system();
void print_menu();
void add_book();
void search_books_by_prefix();
void print_who_borrowed_book_by_name();
void print_library_by_id();
void print_library_by_name();
void add_user();
void user_borrow_book();
void user_return_book();
void print_users();


struct book{
	int id;
	string name;
	int quantity;
	int borrowed=0;

	void read(){
		cout << "Enter book ID, name & quantity: ";
		cin >> id >> name >> quantity;
	}
	void print(){
		cout <<"\nid = "	  << id
			 <<" name = " 	  << name
			 <<" quantity = " << quantity
			 <<" borrowed "   << borrowed << " times";
	}
};
struct user{
	int id;
	string name;
	int borrowed[10] = {0};

	void read(){
		cout << "Enter user name & ID: ";
		cin >> name >> id;
	}
};

book books[10];
user users[10];
int books_added = 0;
int users_added = 0;

bool byId(book &a, book &b){
	return a.id < b.id;
}
bool byName(book &a, book &b){
	return a.name < b.name;
}


int main(){
	system();
	return 0;
}

void system(){
		while (true) {
			cout << "\nEnter your choice: ";
			print_menu();
			int choice;
			cin >> choice;

			if (choice == 1)
				add_book();
			else if (choice == 2)
				search_books_by_prefix();
			else if (choice == 3)
				print_who_borrowed_book_by_name();
			else if (choice == 4)
				print_library_by_id();
			else if (choice == 5)
				print_library_by_name();
			else if (choice == 6)
				add_user();
			else if (choice == 7)
				user_borrow_book();
			else if (choice == 8)
				user_return_book();
			else if (choice == 9)
				print_users();
			else
				break;
		}
}
void print_menu(){
	cout << "\nLibrary Menu:\n";
	cout << "1) add_book\n";
	cout << "2) search_books_by_prefix\n";
	cout << "3) print_who_borrowed_book_by_name\n";
	cout << "4) print_library_by_id\n";
	cout << "5) print_library_by_name\n";
	cout << "6) add_user\n";
	cout << "7) user_borrow_book\n";
	cout << "8) user_return_book\n";
	cout << "9) print_users\n";
	cout << "10) Exit\n";
}
void add_book(){
	book b;
	b.read();
	if(books_added==10){
		cout << "Sorry, No more space to add books. :(\n";
		return;
	}
	books[books_added++]=b;
}
void search_books_by_prefix(){
	string pre;
	cout << "Enter book prefix: ";
	cin >> pre;
	bool all_search=1;
	for (int i = 0; i < books_added; i++){
	bool sr4 = 1;
		for(int j = 0; j < pre.size(); j++){
			if(books[i].name[j]!=pre[j]){
				sr4 = 0;
				break;
			}
		}
		if(sr4){
			cout << books[i].name <<"\n";
			all_search=0;
		}
	}
	if(all_search)
		cout << "No results.\n";
}
void print_who_borrowed_book_by_name(){
	cout << "Enter  book name: ";
	string bn;
	cin >> bn;
	int bi=0;
	//Getting book idx
	for(;books[bi].name!=bn;bi++){
		if(bi==books_added-1){
			cout << "There's no such a book with this name :(\n";
			return;
		}
	}
	//Checking if borrowed yet?
	if(!books[bi].borrowed){
		cout << "No one borrowed this book yet.\n";
		return;
	}
	//Printing users
	for(int i = 0; i < users_added; i++)
		if(users[i].borrowed[bi])
			cout << users[i].name <<"\n";
}
void print_library_by_id(){
	sort(books, books + books_added, byId);
	for (int i = 0; i < books_added; i++)
		books[i].print();
}
void print_library_by_name(){
	sort(books, books + books_added, byName);
	for (int i = 0; i < books_added; i++)
		books[i].print();
}
void add_user(){
	user u;
	u.read();
	if(users_added==10){
		cout << "Sorry, No more space to add users. :(\n";
		return;
	}
	users[users_added++]=u;
}
void user_borrow_book(){
	cout << "Enter user name and book name: ";
	string un, bn;
	cin >> un >> bn;
	int bi=0,ui=0;
	//Getting book idx
	for(;books[bi].name!=bn;bi++){
		if(bi==books_added-1){
			cout << "There's no such a book with this name :(\n";
			return;
		}
	}
	//Getting user idx
	for(;users[ui].name!=un;ui++){
		if(ui==users_added-1){
			cout << "There's no such a user with this name :(\n";
			return;
		}
	}
	if(!books[bi].quantity){
		cout << "There's no more copies :(\n";
		return;
	}
	books[bi].borrowed++;books[bi].quantity--;
	users[ui].borrowed[bi]++;
}
void user_return_book(){
	cout << "Enter user name and book name: ";
	string un, bn;
	cin >> un >> bn;
	int bi=0,ui=0;
	//Getting book idx
	for(;books[bi].name!=bn;bi++){
		if(bi==books_added-1){
			cout << "There's no such a book with this name :(\n";
			return;
		}
	}
	//Getting user idx
	for(;users[ui].name!=un;ui++){
		if(ui==users_added-1){
			cout << "There's no such a user with this name :(\n";
			return;
		}
	}
	if(!users[ui].borrowed[bi]){
		cout << users[ui].name <<" didn't borrow this book!\n";
		return;
	}
	books[bi].borrowed--;books[bi].quantity++;
	users[ui].borrowed[bi]--;
}
void print_users(){
	for (int i = 0; i < users_added; i++)
	{
		cout <<"\nuser " << users[i].name
			 <<" id "   << users[i].id
			 <<" borrowed books ids: ";
		for(int j = 0; j < 10; j++)
		{
			if(users[i].borrowed[j])
				cout << books[j].id << " ";
		}
	}
}

/*

1   104 math4 3
1   102 math2 5
1   101 math1 4
1   103 math3 2
1   201 prog1 5
1   202 prog2 2


4
5

6 mostafa     30301
6 ali		  50501
6 noha        70701
6 ashraf      90901

7 mostafa math1
7 mostafa math2
7 mostafa math3
7 ali math1
7 ali math2
7 noha math1
7 noha math3
7 noha prog2

4
9

2 ma
2 pro
2 machine

3 math1
3 math2
3 machine

4
9
8 mostafa math1
4
9



10



 */