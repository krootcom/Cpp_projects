#include <iostream>
#include <string>
using namespace std;

class President {
private:
	President() {};          //Закрытые конструктор по умолчанию
	President(const President&);        //Копирующий конструктор
	const President& operator=(const President&); //Присваивание

	string name;

public:
	static President& GetInstance() {
		//статические обьекты копируются только раз
		static President onlyInstance;
		return onlyInstance;
	}

	string GetName()
	{ return name; }

	void SetName(string InputName)
	{ name = InputName; }
};

int main() {
	President& onlyPresident = President::GetInstance();
	onlyPresident.SetName("Vladimir Putin");

	//Раскоментируете если хотите проверить
	// President second;
	// President* third= new President();
	// President fourth = onlyPresident;
	// onlyPresident = President::GetInstance();

	cout << " President name is ";
	cout << President::GetInstance().GetName() << endl;

	return 0;
}