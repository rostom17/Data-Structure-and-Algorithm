#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Student
{
public:
    string name;
    int id;
    double marks;

    Student(string name, int id, double marks)
    {
        this->name = name;
        this->id = id;
        this->marks = marks;
    }
};

class Compare
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.marks == b.marks)
        {
            if (a.id > b.id)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (a.marks < b.marks)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<Student, vector<Student>, Compare> pq;
    while(n--) {
        string name;
        int id;
        double marks;
        cin >> name >> id >> marks;
        Student student (name, id, marks);
        pq.push(student);
    }

    while(!pq.empty()) 
    {
        cout << pq.top().name << " " << pq.top().id << " " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}