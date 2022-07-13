#include <iostream>

using namespace std;
//Solving the dynamic connectivity problem using quick union algorithm
class quickUnion{
private:
    int root(int i);
    int sz;
    int* id;
public:
    explicit quickUnion(int N):sz{N}{ //constructor to create an array with number of objects
        id = new int[N];
        for (int i = 0; i < N; i++) {
           id[i] = i;
        }
    }
    void Union(int p, int q);
    bool Connected(int p, int q);
    ~quickUnion();
};

int quickUnion::root(int i){//find parent pointers till its root
while (i != id[i]) i = id[i];
    return i;
}

void quickUnion::Union(int p, int q) {//connect two elements if they are not connected
   int i = root(p);                   //change root of p to point to root of q
   int j = root(q);
   id[i] = j;
}

bool quickUnion::Connected(int p,int q) {//check if two elements are connected,
    return root(p) == root(q);           //they have the same root
}

quickUnion::~quickUnion() {   //destructor
if (id != nullptr){
    delete id;
}
}
//Interface
int main() {
    int M,b,c;
    cout << "Enter any number 10 and above"<<endl;//ask the user for input
    cin >> M;
    quickUnion q(M);
    while (cin >>b >>c){//check if the stdin is not empty
        if (!q.Connected(b,c)){
            q.Union(b,c);
            cout << b <<"-" << c<<endl;
        }
    }
    return 0;
}
