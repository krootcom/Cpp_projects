#include <iostream>
#include <string>
#include <map>
#include <typeinfo>
#include <vector>
#include <set>
#include <stack>
using namespace std;

//Массив переменных
typedef map<string, int> Variables;


//Функция выдирает символы и делает их переменными
void ReadExpressionFromStr(string expr, Variables &var){
    int i = 0;
    while(i < expr.size()) {
        if(isalpha(expr[i]) /*and expr[i] != '|','&','*','+'*/) {
            string name = "";
            name.append(expr, i, 1);
            var[name];
            name.clear();
            
        }
        i++;
    }
}


// Типы токенов
enum tokentype{
    //переменная, конст, (, ), функция, операция
    var, num, op_br, cl_br, funk, op
};
//Структуры токенов
struct  token
{
    string name;
    tokentype type;

    //Конструктор
    token(string str, tokentype typ){
        name = str;
        type = typ;
    }
    token() {}
};
//Массив токенов
typedef vector<token> tokens;
//Множество раздел
set<char> DelimSet;
//Разделители
const string delimeters = " ()+*&|!";
//Иницилизируем множество раздл
void InitDelimetrs() {
    for (int i = 0; i < delimeters.size(); i++)
        DelimSet.insert(delimeters[i]);
    return;
}

//Проверка является ли символ разделителем
bool IsDelimeter(char in) {
    return DelimSet.count(in) > 0;
}

//Разбиваем выражения на токены
void CreateTokensFromExpression(string &expr, tokens &texpr) {
    InitDelimetrs();
    string ex = expr + " ";
    string name;

    //Получаем имя токена
    int i = 0;
    while (i < ex.size() - 1) {
        name = "";
        //Если текущий символ разделитель
        if (IsDelimeter(ex[i])) {
            if (ex[i] == ' ') { //На пробел забиваем большой железный
                i++;
                continue;
            }
            name = ex[i]; //Всё остальное передаём в имя токена
            i++;
        }

        else{
            while (!IsDelimeter(ex[i])){
            //Допустим это название переменной
                name += ex[i];
                i++;
            }
        }
        //Заносим токен в список токенов
        texpr.push_back(token(name, var));
    }

    //Раздаём токенам типы
    for (int j = 0; j < texpr.size(); j++){
        if (texpr[j].name[0] == '(') {
            texpr[j].type = op_br;
            continue;
        }

        if (texpr[j].name[0] == ')') {
            texpr[j].type = cl_br;
            continue;
        }

        if (isdigit(texpr[j].name[0])) {
            texpr[j].type = num;
            continue;
        }

        if (isalpha(texpr[j].name[0])) {
            if(j < texpr.size() - 1 && texpr[j+1].name[0] == '(')
                texpr[j].type =  funk;
            continue;
        }

        texpr[j].type = op;
    }

    /*Проверяем префиксные операции !
    for (int j = 0; j < texpr.size(); j++){
        if (texpr[j].name == "!" && (j == 0 || texpr[j - 1].type == op_br))
    }*/

    return;
}

//Приоритеты операций
map <string, int> prior;
//Функция выставляет приоритеты
void CreatePrior(){
    prior["+"] = 10;
    prior["*"] = 20;
    prior["|"] = 20;
    prior["&"] = 10;
}

//Переводим выражение в постфиксную запись
void CreatePostFixFromTokens(tokens  &texpr, tokens &pexpr) {
    //Создаём приоритеты
    CreatePrior();
    stack <token> TStack;

    //Ловим токены и работаем по алгоритму
    for (int i = 0; i < texpr.size(); i++) {
        switch (texpr[i].type)
        {
            case var:
            case num:
                pexpr.push_back(texpr[i]);
                break;

            case op_br:
                TStack.push(texpr[i]);
                break;

            case cl_br:
                while (TStack.top().type != op_br)
                {
                    pexpr.push_back(TStack.top());
                    TStack.pop();
                }
                TStack.pop();
                break;
            
            case op:
                if (TStack.size()){
                    while (TStack.size() && (TStack.top().type == op && 
                    prior[texpr[i].name] <= prior[TStack.top().name]) ||
                    TStack.top().type == funk)
                    {
                        pexpr.push_back(TStack.top());
                        TStack.pop();
                    } 
                }
                TStack.push(texpr[i]);
                break;
        }   
    }

    while (TStack.size()){
        pexpr.push_back(TStack.top());
        TStack.pop();
    }

    return;
}

//Указатель на функцию(для использования в операциях)
typedef bool(*func_type)(stack<double> &);
/*      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        Это как я понимаю указатель на функцию
        типа bool с фтрибутом ввиде указателя на стэк?
*/
//Массив операций
typedef map<string, func_type> Ops;
Ops ops;

/*Реализация самих операций
А вот и функции на которые он указывает
*/
bool op_and(stack <double> &s) {
    double a,b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return a&&b;
}

bool op_or(stack <double> &s){
    double a,b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return a||b;
}

//Инициализация массива операций
void CreateOps() {
    ops["+"] = op_and;
    ops["&"] = op_and;
    ops["*"] = op_or;
    ops["|"] = op_or;

    return;
}

//Считаем результат выражения
bool ResExpr(tokens &pexpr, Variables &expvars){
    CreateOps();
    stack <double> s;

       
    for (int i = 0; i < pexpr.size(); i++) {
        switch(pexpr[i].type){
            case num: {
                /*Atoi нужно для интрпретации цыфр тк  
                c_str переводит строку в С подобную
                */
                s.push(atoi(pexpr[i].name.c_str()));
                }
                break;
           
            case var:{
                Variables::iterator Vit;
                for(Vit=expvars.begin(); Vit!=expvars.end(); Vit++){
                    if(Vit->first == pexpr[i].name) {
                        s.push(Vit->second);
                        break;
                    }
                }
            }
                
            case funk:
            case op: {
                Ops::iterator Oit;//Проверяет соответствие ключа и значения через итератор
                for(Oit = ops.begin(); Oit != ops.end(); Oit++) {
                    if(Oit->first == pexpr[i].name) {
                        s.push(Oit->second(s));
                        break;
                    }
                }
            }
            break;
        }
    }

    return s.top();
}

bool CreateAllCombine(tokens &pexpr, Variables &expvars, Variables::iterator iter) {
    for((*iter).second = 1; (*iter).second >= 0; (*iter).second--) {
        if (iter != expvars.end()) {
            CreateAllCombine(pexpr, expvars, ++iter);
        }
        else if (iter == expvars.end()) {
            for(auto i = expvars.begin(); i != expvars.end(); i++) {
               cout << (*i).first << ":" << (*i).second << " ";
            }
            cout << " Res:" << ResExpr(pexpr, expvars) << endl;
        }  
    }
}




int main(){
    tokens texpr, pexpr;
    Variables expvars;
    string expr, inpt;
    //ifstream file("test.txt"); //Возможен ввод с файла
    cout << "Put task here:" ;
    cin >> inpt;

    ReadExpressionFromStr(inpt, expvars);
    
    auto iter = expvars.begin();
    cout << endl;

    cout << "Var" ;
    for(auto it = expvars.begin(); it != expvars.end(); it++)
        cout << (*it).first << ' ';
    cout << endl;
    
    CreateTokensFromExpression(inpt, texpr);

    cout << "Token:" << endl;
    for (int i = 0; i < texpr.size(); i++)
        cout << texpr[i].name << ' ';
    cout << endl << endl;

    CreatePostFixFromTokens(texpr, pexpr);

    cout << "Prefix:" << endl;
    for (int i = 0; i < pexpr.size(); i++)
        cout << pexpr[i].name << ' ';
    cout << endl << endl;

    cout << "Result:" << endl;
    int i = 0;
    CreateAllCombine(pexpr, expvars, iter);

    return 0;
}