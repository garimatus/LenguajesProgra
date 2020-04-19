#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
    nodo *sig;
    int dato;
};

typedef nodo *L;

class Lista{
    public:
        Lista();
        Lista(int);
        virtual ~Lista();
        int head();
        int last();
        void tail();
        void init();
        int length();
        bool null();
        bool elem_x(int);
        void reverse_xs();
        void take_n(int);
        void drop_n(int);
        void replicate_nx(int,int);
        void map_f(char,int);
    private:
        L xs;
        int len;
};

Lista::~Lista(){}

Lista::Lista(){
    xs = NULL;
    len = 0;
}

Lista::Lista(int n){
    int i,elem;
    L aux,l;
    xs = NULL;
    len = n;
    for(i=0;i<n;i++){
        aux = new nodo;
        cout <<"elemento "<<i+1<<" : ";
        cin >> elem;
        aux->dato = elem;
        aux->sig = NULL;
        if(xs == NULL){
            aux->sig = xs;
            xs = aux;
            xs->sig = NULL;
        }
        else{
            l = xs;
            while(l->sig != NULL)
                l = l->sig;
            l->sig = aux;
        }
    }
}

int Lista::head(){
    return xs->dato;
}

int Lista::last(){
    L l;
    l = xs;
    while(l->sig != NULL)
        l = l->sig;
    return l->dato;
}

void Lista::tail(){
    int n=1;
    L l;
    l = xs;
    xs = xs->sig;
    delete l;
    len--;
    l = xs;
    while(l != NULL){
        if(n == len)
            cout << l->dato << endl;
        else
            cout << l->dato<<",";
        l = l->sig;
        n++;
    }
}

void Lista::init(){
    int n=1;
    L l,p;
    l = xs;
    while(l->sig != NULL){
        p = l;
        l = l->sig;
    }
    delete l;
    len--;
    p->sig = NULL;
    l = xs;
    while(l != NULL){
        if(n == len)
            cout << l->dato <<endl;
        else
            cout << l->dato<<",";
        l = l->sig;
        n++;
    }
}

int Lista::length(){
    return len;
}

bool Lista::null(){
    if(xs == NULL){
        cout << "True" << endl;
        return true;
    }
    else{
        cout << "False" <<endl;
        return false;
    }
}

bool Lista::elem_x(int x){
    L l;
    l = xs;
    while(l != NULL){
        if(l->dato == x){
            cout << "True" << endl;
            return true;
        }
        l = l->sig;
    }
    cout << "False" <<endl;
    return false;
}


void Lista::reverse_xs(){
    int n=1;
    L l,pre,pro;
    l = xs;
    while(l != NULL){
        pro = l->sig;
        l->sig = pre;
        pre = l;
        l = pro;
    }
    xs = pre;
    l = pre;
    while(l != NULL){
        if(n == len)
            l->sig = NULL;
        l = l->sig;
        n++;
    }
    l = xs;
    n = 1;
    while(l != NULL){
        if(n == len)
            cout << l->dato;
        else
            cout << l->dato <<",";
        l = l->sig;
        n++;
    }
}

void Lista::take_n(int n){
    int i=0;
    L l,d;
    l = xs;
    while(l != NULL){
        i++;
        if(i > n){
            delete d;
            d -> sig = NULL;
            len--;
        }
        d = l;
        l = l->sig;
    }
    l = xs;
    i = 0;
    while(l != NULL){
        i++;
        if(i == len)
            cout << l->dato;
        else
            cout << l->dato<<",";
        l = l->sig;
    }
}

void Lista::drop_n(int n){
    L l,d;
    int i = len;
    l = xs;
    d = xs;
    while(l != NULL){
        if(i > n){
            d = l->sig;
            delete l;
            l->sig = NULL;
            len--;
        }
        i--;
        l = l->sig;
    }
    i = 0;
    xs = d;
    l = xs;
    while(l != NULL){
        i++;
        if(i == len)
            cout << l->dato;
        else
            cout << l->dato<<",";
        l = l->sig;
    }
}

void Lista::replicate_nx(int n,int x){
    int i = 0, lar = len;
    L l,d,p;
    l = xs;
    while(l != NULL){
        i++;
        if(i <= n)
            l->dato = x;
        if(i > n && lar > n){
            delete d;
            d->sig = NULL;
            len--;
        }
        if(i > n && lar < n){
            p = new nodo;
            p->dato = x;
            d->sig = p;
            len++;
        }
        d = l;
        l = l->sig;
    }
    l = xs;
    i = 0;
    while(l != NULL){
        i++;
        if(i == len)
            cout << l->dato;
        else
            cout << l->dato<<",";
        l = l->sig;
    }
}

void Lista::map_f(char op,int x){
    int i,b;
    L l;
    l = xs;
    if(op == '+'){
        while(l != NULL){
            l->dato = l->dato+x;
            l = l->sig;
        }
        while(l != NULL){
            i++;
            if(i == len)
                cout << l->dato;
            else
                cout << l->dato<<",";
            l = l->sig;
        }
    }
    if(op == '-'){
        while(l != NULL){
            l->dato = l->dato-x;
            l = l->sig;
        }
        while(l != NULL){
            i++;
            if(i == len)
                cout << l->dato;
            else
                cout << l->dato<<",";
            l = l->sig;
        }
    }
    if(op == '*'){
        while(l != NULL){
            l->dato = l->dato*x;
            l = l->sig;
        }
        while(l != NULL){
            i++;
            if(i == len)
                cout << l->dato;
            else
                cout << l->dato<<",";
            l = l->sig;
        }
    }
    if(op == '^'){
        while(l != NULL){
            b = l->dato;
            for(i=0;i<x-1;i++)
                l->dato *= b;
            l = l->sig;
        }
        l = xs;
        i = 0;
        while(l != NULL){
            i++;
            if(i == len)
                cout << l->dato;
            else
                cout << l->dato<<",";
            l = l->sig;
        }
    }
    else
        cout <<"la operacion no existe." << endl;
}

int main(){
    int i,n,x;
    char c;
    cout << "numero de elementos : ";
    cin >> n;
    Lista L(n);
    cout << "primer elemento : " << L.head() <<endl;
    cout << "ultimo elemento : " << L.last() <<endl;
    cout <<"numero de elementos : "<< L.length() << endl;
    system("PAUSE");
    while(i != 0){
        system("CLS");
        cout << "1 tail xs\n2 init xs\n3 null xs\n4 elem x ys\n5 reverse xs\n6 take n xs\n7 drop n xs\n8 replicate n x\n9 map f xs\ningresar : ";
        cin >> i;
        if(i == 1){
            L.tail();
            system("PAUSE");
        }
        if(i == 2){
            L.init();
            system("PAUSE");
        }
        if(i == 3){
            L.null();
            system("PAUSE");
        }
        if(i == 4){
            cout << "x : ";
            cin >> x;
            L.elem_x(x);
            system("PAUSE");
        }
        if(i == 5){
            cout << "la lista invertida : [";
            L.reverse_xs();
            cout << "]" << endl;
            system("PAUSE");
        }
        if(i == 6){
            cout << "n : ";
            cin >> n;
            cout << "los primeros "<<n<<" elementos : [";
            L.take_n(n);
            cout << "]" <<endl;
            system("PAUSE");
        }
        if(i == 7){
            cout << "n : ";
            cin >> n;
            cout << "los ultimos "<<n<<" elementos : [";
            L.drop_n(n);
            cout << "]" <<endl;
            system("PAUSE");
        }
        if(i == 8){
            cout << "n : ";
            cin >> n;
            cout << "x : ";
            cin >> x;
            cout << "replicado de "<<n<<" veces "<<x<<" : [";
            L.replicate_nx(n,x);
            cout << "]" << endl;
            system("PAUSE");
        }
        if(i == 9){
            cout <<"operacion : ";
            cin >> c;
            cout <<"x : ";
            cin >> x;
            cout << "f x : [";
            L.map_f(c,x);
            cout << "]" << endl;
            system("PAUSE");
        }
        if(i == 0)
            cout << "HASTA LUEGO!!" << endl;
    }
    return 0;
}
