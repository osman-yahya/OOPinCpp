#include <iostream>
#include <string> 
#include <fstream>
#include <iomanip>

using namespace std;

//3srg In cpp, we got a new form of for as similar to foreach : 
void main1(){
    int Arr[4]={1,2,3,4};
    for (int i : Arr)
    {
        cout << i << endl;
    }

}




//3srg also we get a new 'string' class, do not forget to include <string>
void main2(){
    string str;
    cout << "enter a str";
    cin >> str;
    cout << str << " entered.";
    //* cin takes until space. to take whole line : 
    getline(cin,str);
}





//3srg instead using int, float ... we may use auto : 
void main3(){
    auto x = 0; //int
    auto y = "hello" ;//string
}






//3srg and we must remember filestream, do not forget to include <fstream>
//we will open a file as an object :
//* input opening : 
void main4(){
    ifstream girisdosya; //first declare
    girisdosya.open("veri.txt"); //then open
    if(! girisdosya.is_open()){
        cout << "file couldn't opened" << endl;
    }
    //* output opening :
    ofstream cikisdosya ("veri(Copy).txt",ios::out); //no need to declare seperately

    //then easy to read : 
    while(!girisdosya.eof()){
        int temp ;
        girisdosya >> temp;
        cout << temp << endl;
        cikisdosya << temp << endl;
    } 
}







//3srg and we may manipulate iostream with <iomanip>, dive into it if necessary.
void main5(){
    double pi = 3.14159265359;
    cout << "pi number : " << pi << endl;

    // Set precision:
    cout << setprecision(3); //from now on, it will be this precised
    cout << "pi number with precision: " << pi << endl;

    // Set width and fill:
    cout << setw(10)
         << setfill('0')
         << fixed;
    cout << "pi number with width and fixed: " << pi << endl;
}






//3srg and we may use 'using' keyword instead typedef : 
//for example, instead of creating a buffer with 100 chars : 
void main6(){
    using Buffer = char[101] ;// 1 for \0
    Buffer newbuffer = "osmananannaanan";
}







//3srg and we get a new 'const' keyword : 
void main7(){
    const float e_number = 2.71123;

    //? e_number = 12;   COMPILER ERROR

    //or with pointers:
    char character1 = 'l';
    const char * ptr1 = &character1; //means it points to a CONSTANT CHAR

    ptr1 = nullptr; //valid
    //? *ptr = 'm'      COMPILER ERROR

    char * const ptr2 = &character1; //means it CONSTANTLY points to a char
    //?  ptr1 = nullptr;  COMPILER ERROR
    *ptr2 = 'm' ; //valid     
}







//3srg and instead casting like : (float)... , we'll use templates : 
void main8(){
    int i = 9;
    float f ;
    f = static_cast<float>(i) / 2; // static_cast<float>(i) converts 9 to 9.0
}







//3srg for memory allocation, we'll use 'new, delete'
void main9(){
    int * p;
    p = new int[10]; //created an int array with size 10

    //! and to free it , since it is an array, we use : 
    delete[] p;
    //! if it would be a single object, we would use : delete p;
}







//3srg and we may introduce inline functions : 
inline int sum (int x, int y){
    return x+y;
}

// whenever we call sum(x,y) , compiler will copy paste whole code, faster but expensive.
void main10(){
    int m =  sum(4,5);
}






//3srg and we may overload functions : 
void print(int x){
    cout << x << endl;
}
void print(string x){
    cout << x << endl;
}
void print(bool x){
    cout << x << endl;
}

void main11(){
    print(5);
    print(true);
    print("osman");
    //compiler will pick correct function for the type.
}





//3srg and we may call functions by reference and instances : 
int squre(int x){
    return x*x;
}//copies x value 

void squre2(int *x){
    *x = *x * *x;
}//directly modifies x but too many '*'s used 

void squre3(int &x){
    x = x*x;
}//directly modifies x
void main12(){ 

}



//3srg and we may use lambda functions instead of declaring at the top
/*
    [caputure variables] (parameter variables) -> 'return type' {codes}
*/
void main13(){ 
    int A[5] = {1,2,3,4,5};
    int multiplier = 10;
    auto f = [multiplier](int x){return multiplier * x;}; //declare as auto, it will get type 'lambda function' , not int
    for (int i : A){
        cout << f(i) << endl;
    }
}




//3srg it is time to create some classes : 
//lets inspect it : 

class Human{
    //any class or function labeled as friend can reach to private data : 
    friend void sudoHuman(Human);
    
    //here is the public datas

    protected : 
    int legs ;
    int location_x ;
    int location_y ;

    public : 
    string name ;
    string partner_name;
    // and we must add initializers (constructor):

    //default constructor : 
    Human(){
        this->name = "John";
        this->legs = 2;
        this->location_x = 0 ; 
        this->location_y = 0 ;
        partner_name = " no partner ";
    }
    //overloading constructor
    Human(string name){
        this->name = name;
        this->legs = 2;
        this->location_x = 0 ; 
        this->location_y = 0 ;
        partner_name = " no partner ";
    }
    void marry(Human &partner){
        this->partner_name = partner.name;
        partner.partner_name = this-> name;
    }
    //or we may directly initialize them as :
    Human(string name , int x , int y) : name(name), location_x(x), location_y(y) , legs(2) , partner_name(" no partner "){}

    //and when we do have destructors, we may add commands before deleting object : 

    ~Human(){
        cout << this->name << " is dead at location ( " << this->location_x << " , " << this->location_y << " )" << endl;
    }

    void getinfo(){
        cout << "Credentails of " << this->name << endl
        << "partner : " << this-> partner_name << endl
        << "location : ( " << this->location_x << " , " << this->location_y << " )" << endl;
    }
    //and we may add operators to this type of class, this is calles operator overloading :
    void operator+ (Human &human);
};

void Human::operator+(Human &human){
    this->marry(human);
    human.marry(*this);
}
void sudoHuman (Human x){
    cout << x.legs << endl;
}

void main14(){ 
    Human ahmet ("Ahmet" , 3 , 4);
    Human selma ("Selma" , 3 , 4);
    ahmet.getinfo();
    ahmet + selma;
    ahmet.getinfo();
}







//3srg now the fun part starts, we may create more specified objects from generalized ones:
//since a student is a human too,  we may extend student class from human : 
//if we do 'class Student : Human' , we wouldnt pull any member that not public from Human class :
class Student : virtual public Human{  //! ignore virtual for now, it doesnt change anything in here.
    //since we take all from Human class, we may change some of the properties and add newers:
    protected :
    string school_name ;
    public : 
    //we may override functions as well and add constructors.
    //! constructor wise, compiler will always call base class constructor and then
    //! derived class constructor. if we need to call base classes parameterized constructor : 
    Student (string name,int loc_x , int loc_y , string schoolname) : Human(name,loc_x,loc_y), school_name(schoolname){}
    
    // and if we want to override a function, we'll give the same name to it:
    void marry(){
        cout << "students can not marry" << endl;
    }

    // so since we updated marry function, no need to update a new operator+ function, base op+ will be used.

    // but we shoul give the school name too when getinfo is called from a student : 
    void getinfo(){
        Human::getinfo(); //we may call previous getinfo and add only school info :
        cout << "goes to school : " << school_name << endl;

    }
    ~Student(){ //and for destructors, previous order from consturctors will be kept : 
        // first ~Student() will be called, then ~Human() will be called.
        cout << "It is bad for a student to die :(" << endl;
    }
};
void main15(){ 
    Student merve ("Merve",4,-2,"ITU");
    Student mehmet ("Mehmet",4,-2,"ITU");
}






//3srg and we ofcourse may derive a class from 2 classes, for instance : 
//! BUT , since student has also extended from human, we will get 2 students in 
//! derived class, to avoid this, we used 'virtual' keyword at the declaration of Student, eliminates repetition.
class Intern : virtual public Human, virtual public Student{
//bla bla bla
};











//3srg generating objects from a class with a pointer has 3 syntaxes : 

void main16(){ 
    string *strptr = new string[3];
    strptr[0] = "111";
    strptr[1] = "222";
    strptr[2] = "333";

    //! OR :
    
    string * strptr2 = new string[3] { string ("AA") , string("BB") , string("CC")};
  
    //! OR : 

    string * strptr3 = new string[3] {"xx","yy","zz"};
}





//3srg and interestingly, since A Student is a Human, a human pointer allows to point a Student.
//! BUT we may only access to Human properties of Student !

void main17(){ 
    Human * hmnptr = new Student("Osman",3,4,"ITU"); // fine!
//? hmnptr-> school_name 
//! ^^^^^^^^^^^^^^^^^^^^ CAUSE ERROR! we may hold a student with a human ptr but we could only access to human properties.
}
//2gb with this property, we may create compound linkedlists.









//3srg and lets check what does polymorphism is : 
// polymorphism means : 'many shapes'
//lets say : 

class Node{

    protected : 

    
    int data1;
    

    public:
    Node* next = NULL;
    Node(int data) : data1(data) {}
    virtual void print(){cout << data1 << endl;} // do not mind 'virtual' keyword now.

    void operator+ (Node &node){
        this->next = &node;
    }
};

class BigNode : public Node{
    int data2;

    public:

    void print(){cout << data1 << " " << data2 << endl;}
    BigNode(int ndata1 , int ndata2) : Node(ndata1) , data2(ndata2) {}

};

class LinkedList {
    Node* head = NULL;
    public : 
    void operator<< (Node *newnode){
        *newnode + *head;
        head = newnode;
    }

    void printList(){
        Node* temp = head;
        while(temp != NULL){
            temp->print();
            temp = temp->next;
        }
    }
    
};

// So lets see : 
void main18(){ 
    LinkedList L;
    L << new Node(5);
    L << new Node(6); // still fine,
    L << new BigNode(3,5); // still fine, we will be able to point to a BigNode with Node pointer, (BigNode is a Node)

    L.printList(); //here, when printing nodes, all fine. but when printing BigNode, Though ptr is Node ptr, compiler will detect that it needs to use the print function in BigNode 
}






//3srg And we also have Abstract Classes, they are classes that we cannor create objects, but with one Abstract Class pointer, we can point to all classes derived from it :

// to make a class abstract, add a "virtual .... ....() = 0;" type function : 

class Soul{
    protected:
    string religion;
    public:
    Soul(string asss) : religion(asss){}
    virtual void print() = 0; //1r makes class abstract
};

class Man : public Soul{
    protected:
    string name;
    public:
    Man(string rel, string name) : Soul(rel), name(name){}
    void print(){
        cout << "O-> " << name << endl;
    }
};

class Woman : public Soul{
    protected:
    string name;
    public:
    Woman(string rel, string name) : Soul(rel), name(name){}
    void print(){
        cout << "O+  " << name << endl;
    }
};


void main19(){ 
    Soul *humans[5] ; //okey to create a ptr but restricted to create an array of objects.
    humans[0] = new Man("Muslim","Osman");
    humans[1] = new Man("Muslim","Ali");
    humans[2] = new Woman("Cristian","Natalie");
    humans[3] = new Man("Sikhist","Punjab");
    humans[4] = new Woman("Muslim","Ayse");

    // with the help of the abstract class, we can hold different type of instances in an array.
    for(Soul* A : humans){
        A->print();
    }
}










//3srg And that was it about OOP, now lets check some more C++ features, some of them still will be related with OOP : Exception Handling
//it is simple as it is in python or any other language, but here, we may catch anything : 
//lets create an error class : 
class Error{
    public:
    string err;
    Error(string msg) : err(msg){};
    void operator() (){cout << err << endl;}
};
void main20(){ 
    cout << "Enter a number, which is :\n-Odd\n-Greater Than 0\n-And not 3\n-Less than 100\n->  ";
    int number ;
    
    try{ //! We may throw whatever we want, the thing is to catch it :
        cin >> number;
        if(number < 0) throw Error("Number is less than 0"); //* throw Error object
        if(number > 100) throw "Number is greater than 100" ;  //* throw char array ( const char* ) //not string, string is a class actually.
        if(number == 3) throw 3; //* we may even throw an integer
        cout << "Given number " << number << "satisfies." << endl;
    }
    catch(Error err){
        err();
    }
    catch(const char* msg){
        cout << msg << endl;
    }
    catch (int){
        cout << "Error : entered 3!" << endl;
    }
    catch(...){ //! ' ... ' is stands for default catch
        cout << "Error occured" << endl; //maybe for entering char for an integer variabla 'number'
    }

}










//3srg And lastly, we will see templates, 
//for example, if we want to create a 'sum' function, we need to define it for every data type seperately : int, double, float
//but instead, we will use templates : 
// there is 2 types of templates : function templates and class templates

template <typename T> //* with this line, we say to compiler that, we will use type T, it may be anything :
T absolute_value(T n){ //* we take n, a variable with type 'T'
    return (n<0) ? -n : n;  //* we return abs 'n'
}
// lets see in main : 
void main21(){ 
    int x = -12;
    float y = 2.23;
    long z = 123;
    double t = -34.4;
    // we call it like : 
    cout << absolute_value <int> (x) << " " << absolute_value <float>(y) << " " << absolute_value<long>(z) << " " << absolute_value<double>(t) << endl;
    // or simply like :
    cout << absolute_value(x) << " " << absolute_value(y) << " " << absolute_value(z) << " " << absolute_value(t) << endl;
}

// we may use 'template <class T>' instead 'template <typename T>' too.
// another example would be : 
template <typename X , typename Y>
X find_value_and_multiply_with_another(X *array /* an array of type X */ , X value /* the value we want to find */ , Y multiplier /* multiplier */, int size /* size of the array */){
    //* as seen, we may use different template types also with static types such as 'int' we used for array size, 
    //! any X must be same typed when called!
    for(int i = 0 ; i < size ; i++){
        if (value == array[i]){
            return value * multiplier;
        }
    }
    throw Error("not found.");
}

void main22(){ 
    try{
        float list[10] = {23.23,22.4,-12,23.4,-233.3,4,0,23.1,0.23,-1};
        float value = 0.23;
        float result = find_value_and_multiply_with_another(list,value,5,10); // float[],float,int,int
        cout << result << endl;
    }
    catch (Error err){ // we declared 'Error' class previously.
        err() ;
    }
}







//3srg and we may also use templates in classes : 

// and we use templates not only for types, also for values.
template <typename T = int, int MAX = 10> // ! and as seen, we can give default values to templates
class Stack{
    int size ;
    T data[MAX];
    
    public :
    Stack() : size(0){}
    void print();
    void push(T data){
        if(size < MAX){
           this -> data[size] = data;
           size++;
        }
        else throw Error("stack is full.");
    }
    T pop (){
        if (size == 0 ){
            throw Error("stack is empty!");
        }
        size--;
        return data[size];
    }
};
// when we implement member functions outside, we must add template again: 
template <typename T, int MAX>
void Stack<T,MAX>::print(){ //! and we must add <T> after class name, it means for the type T Stack, print function is : 
    for(int i = 0 ; i < this->size ; i++){
        cout << this->data[i] << endl;
    }
}

//lets see the usage: 
void main23(){
    Stack <int , 5> intStack;
    Stack <char> charStack;
    string chars = "aqjlnhkaasddf";

    for(int i = 0 ; i < 10; i++){
        try{
            charStack.push(chars[i]);
            intStack.push(i*19);
        }
        catch(Error err) {err();};
    }
    intStack.print();
    charStack.print();
    for(int i = 0 ; i < 10; i++){
        try{
            cout << intStack.pop() << "  -  " << charStack.pop() << endl;
        }
        catch(Error err) {err();};
    }
}

void main24(){ 

}

void main25(){ 

}

void main26(){ 

}

void main27(){ 

}

void main28(){ 

}

void main29(){ 

}

void main30(){ 

}

void main31(){ 

}

void main32(){ 

}

void main33(){ 

}

void main34(){ 

}

void main35(){ 

}

void main36(){ 

}

void main37(){ 

}

void main38(){ 

}

void main39(){ 

}

void main40(){ 

}

void main41(){ 

}

void main42(){ 

}

void main43(){ 

}

void main44(){ 

}

void main45(){ 

}

void main46(){ 

}

void main47(){ 

}

void main48(){ 

}

void main49(){ 

}

void main50(){ 

}

















int main(){void (*funcs[])() = {main1, main2, main3, main4, main5, main6, main7, main8, main9, main10,main11, main12, main13, main14, main15, main16, main17, main18, main19, main20,main21, main22, main23, main24, main25, main26, main27, main28, main29, main30,main31, main32, main33, main34, main35, main36, main37, main38, main39, main40,main41, main42, main43, main44, main45, main46, main47, main48, main49, main50};int sel;while(true){cout<<endl<<endl<<": \033[32mEnter the scenario you want (0 to terminate)\033[0m"<<endl<<"> ";cin >>sel;if(sel>50||sel<=0){break;}cout<<endl<<"\033[34mRunning \033[0m"<<sel<<"\033[34m. case :\033[0m"<<endl<<"\033[31m----------------|\033[0m"<<sel<<"\033[31m|\033[0m"<<endl<<endl;funcs[sel-1]();cout<<endl<<endl<<"\033[31m----------------|\033[0m"<<sel<<"\033[31m|\033[0m"<<endl;}return 0;}