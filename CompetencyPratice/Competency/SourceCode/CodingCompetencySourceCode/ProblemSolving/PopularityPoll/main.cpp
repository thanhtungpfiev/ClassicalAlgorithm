/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 4/14/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Person {
    int id = 0;
    string name = "";
    int point = 0;
};

bool comparePerson(const Person& a, const Person& b)
{
    if (a.point == b.point) {
        return a.id < b.id;
    }
    return a.point > b.point;
}

void bruteforce()
{
    int N = 5;
    cin >> N;
    vector<Person> persons;
    string name = "";
    for (int i = 0; i < N; ++i) {
        cin >> name;
        Person p;
        p.id = i;
        p.name = name;
        persons.push_back(p);
    }
    int M = 6;
    cin >> M;
    int point = 0;
    for (int i = 0; i < M; ++i) {
        cin >> name >> point;
        for (int j = 0; j < N; ++j) {
            if (persons[j].name == name) {
                persons[j].point += point;
            }
        }
    }
    sort(persons.begin(), persons.end(), comparePerson);
    for (int i = 0; i < 3; ++i) {
        cout << persons[i].name << " " << persons[i].point << endl;
    }
}

void greedy()
{
    int N = 5;
    cin >> N;
    vector<Person> persons;
    map<string, int> mapPerson;
    string name = "";
    for (int i = 0; i < N; ++i) {
        cin >> name;
        Person p;
        p.id = i;
        p.name = name;
        persons.push_back(p);
        mapPerson.insert({name, i});
    }
    int M = 6;
    cin >> M;
    int point = 0;
    for (int i = 0; i < M; ++i) {
        cin >> name >> point;
        if (mapPerson.find(name) != mapPerson.end()) {
            persons[mapPerson[name]].point += point;
        }
    }
    sort(persons.begin(), persons.end(), comparePerson);
    for (int i = 0; i < 3; ++i) {
        cout << persons[i].name << " " << persons[i].point << endl;
    }
}

int main()
{
//    bruteforce();
    greedy();
    return 0;
}
