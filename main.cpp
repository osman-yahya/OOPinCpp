#include <iostream>
using namespace std;

//% Welcome to midterm-1 review of C++ programming.
//? A new for loop similar to foreach, a new console in/out functions.
void main1(){
    int A[4] = {1,2,3,4};

    for (int i : A){
    cout << i << endl;
    }

    int value;

    cout << "Enter a value :" ;
    cin >> value;
    cout << value*value << endl;

    int k,l;

    cout << "enter 2 nums : " ;
    cin >> k >> l;
    cout << "k = " << k << "  l = " << l << "  k+l = " << k+l << endl;


    char a,b;

    cout << "enter a character : " ;
    cin >> a ;
    cout << "entered : " << a ;


} 


//? We have a new class : 'string' ! it does not require basic static memory arrangement.
void main2(){
    string str;
    cout << "enter a str : ";
    cin >> str;
    cout << "String : " << str << endl; //but it only takes until space, to get full line we need another function : 

    cin.ignore(); // just to clean cin buffer.
    cout << "enter another str : ";
    getline(cin,str);
    cout << str << endl;

}

//? We have a really nice new type : auto
void main3() {
    auto x = "a";       // x: const char* (PKc)
    auto y = 12;        // y: int (i)
    auto z = "osman";   // z: const char* (PKc)
    auto t = 2.3;       // t: double (d)

    cout << "x : " << typeid(x).name() << endl;
    cout << "y : " << typeid(y).name() << endl;
    cout << "z : " << typeid(z).name() << endl;
    cout << "t : " << typeid(t).name() << endl;
}

//% Now lets dive in a bit more. We need to know what is 'scope operator' ( '::' )

namespace Main4Functions{
    int main4_x = 70;
    void function1(){
        cout << "main4 function1 called" << endl;
    }
    void function2(){
        cout << "main4 function2 called" << endl;
    }
}

int main4_x = 40; // a global x value

void main4(){
    int main4_x = 10;
    int main4_y = 20;
    cout <<  "x : " << main4_x << endl; //local x
    cout <<  "y : " << main4_y << endl; //local y
    cout <<  "global x : " <<  ::main4_x << endl; //global x
    cout <<  "namespace x : " <<  Main4Functions::main4_x << endl; //global x

    // if we call function1 directly, we get error.

    Main4Functions::function1();

    //! or we could say :
    using namespace Main4Functions;
    function2();
}

//? we have multiple namespaces declared for easier use: lets introduce 'numbers'

#include <numbers>

void main5(){
    std::cout << "pi = " << std::numbers::pi << '\n';
    std::cout << "e = " << std::numbers::e << '\n';
    std::cout << "log2(e) = " << std::numbers::log2e << '\n';
    std::cout << "log10(e) = " << std::numbers::log10e << '\n';
    std::cout << "ln(2) = " << std::numbers::ln2 << '\n';
    std::cout << "ln(10) = " << std::numbers::ln10 << '\n';
    std::cout << "sqrt(2) = " << std::numbers::sqrt2 << '\n';
    std::cout << "sqrt(3) = " << std::numbers::sqrt3 << '\n';


}

//? and we may introduce file operations:

#include <fstream>
void main6(){

    //output filestream
    ofstream File_We_Want_To_Write("data.txt" , ios::out);
    for (int i = 0 ; i < 10 ; i++){
        File_We_Want_To_Write << i << " " << pow(i,2) << endl; //we basically write with << operator.
    }

    cout << " write successed, now reading : " << endl << endl;

    File_We_Want_To_Write.close();

    //* now lets read what we wrote : 
    int num1 ,num2;

    //input filestream
    ifstream File_We_Want_To_Read;
    File_We_Want_To_Read.open("data.txt");

    if (! File_We_Want_To_Read.is_open()){
        cout << "file can not opened" << endl;
        return;
    }


    while (! File_We_Want_To_Read.eof()){
        File_We_Want_To_Read >> num1 >> num2;
        cout << num1 << " - " << num2 << endl;
    }
    File_We_Want_To_Read.close();

    cout << "file ended" << endl ;

}

//? and also with c++, we may manipulate functions : 

#include <iomanip>

void main7() {
    double pi = 3.14159265359;
    cout << "pi number : " << pi << endl;

    // Set precision:
    cout << setprecision(3);
    cout << "pi number with precision: " << pi << endl;

    // Set width and fill:
    cout << setw(10)
         << setfill('0')
         << fixed;
    cout << "pi number with width and fixed: " << pi << endl;
}


//? in c++, we have a better 'typedef' from c, again 'using' keyword: 
void main8(){

    using ArrOf5 = char[6]; //including '\0'
 
    ArrOf5 str = "osman";

    cout << str << endl;

}

//? and in c++ we have a keyword for declaring constant values : 'const'
void main9(){

    const int value = 10;
    /*
    value = 5 //compiler error
    */
    
    //* - or with pointers:

    //% pointer is constant:
    int * const ptr = new int(10);
    *ptr = 5;
    *ptr = 6;
    //*    ptr = new int; //compiler error, pointer was a constant pointer

    //% data is constant:
    int x = 5;
    int y = 6;
    const int * ptr2 = &x;
    //*    *ptr = 6; //compiler error, pointers data was constant
    ptr2 = &y; //no error; pointer is not constant, data is 

}

//? ofcourse we do have typecasting, rather than y = (float) 5/2; in c++ we got template functions :
void main10(){
    int i = 7;
    float f;

    //% static cast basically converts one type to another:
    f = static_cast <float>(i)/2;  //converted i to float,

    //% const cast may offer us to fly over constantency:
   /* 
    const char* ptr = "hello"; //here we can not change the data because it is constant. but const cast allows us : 
    char *ptr2 = const_cast<char*>(ptr);
    ptr2[0] = 'H';
    cout << ptr << endl;
    */
}

//? for memory allocation, we say goodbye to -lloc()'s and greet : new, delete

void main11(){
    int *p;
    int size;
    cout << "Enter the size : ";
    cin >> size;
    p = new int[size];
    for (int i = 0 ; i < size; i++){
        cout << "Enter " << i << ". term : ";
        cin >> p[i];
    }
    for (int i = 0 ; i < size; i++){
        cout << p[i] << " ";
    }
    //* to free a single element, we would use :  delete p; but since it is an array, we use delete[]:

    delete[] p;
}

//? inline functions are not calling by reference, they copied and pasted by compiler:
//? - in this inline func, we gave an default value to args, if we do not specify a z value, it will be 100.
inline int sum(int x = 4,int y = 5 , int z = 100){
    return x+y+z;
}
void main12(){
    cout << sum(10,15) << endl; //this becomes : cout << x+y << endl, compiler copies function each time, faster but takes more memory
}

//? in c++, we may overload functions. compiler detects which to run by args.
void print(int num){
    cout << "num : " << num << endl;
}
void print(bool val){
    cout << "bool : " << val << endl;
}
void print(string str){
    cout << "string : " << str << endl;
}

void main13(){
    print(10);
    print(true);
    print(string("osman"));
}

//? and in c++, we do not have to deal with pointers everytime. '&' helps us : 

void square(int&num){ //when we pass any number inside, it will act on that memory, not copying the value
    num = num*num;
}

void main14(){
    int x = 5;
    cout << "x = " << x << endl;
    cout << "square(x)" << endl;
    square(x); //we directly access x in function
    cout << "x = " << x << endl;
}

//? and with c++, we get lambda functions in our lives : 

void main15(){
    const int power = 2;
    auto takepower = [power](int num) {return pow(num,power);};  // [capture variables]( variables will be passed) {function}

    cout << takepower(3) << endl;
    cout << takepower(5) << endl;
    cout << takepower(6) << endl;
}

//? lets move on and create some classes : 


class Animal{
    friend void sudoAnimal(Animal);
    int legs = 2 , x= 0,y = 0; //default 4
    bool alive = true; //default true
    public:
    string name = "undefined";
    void setLeg(int);
    void move(int , int);
    void kill();
    void print();
}; //% so we declared the class but need to define them. we will use scope operator :

void Animal::kill(){
    this->alive = false;
}

void Animal::setLeg(int leg){
    this->legs = leg;
}

void Animal::move(int x=0,int y=0){
    this->x = x;
    this->y = y;
}

void Animal::print(){
    cout << this->name << " animal with " << this->legs << " legs, at ( " << this->x << " , " << this->y << " )" << "is " << (this->alive ? "alive." : "dead.") << endl;
}
void sudoAnimal(Animal instance){
    instance.x = 99;
    instance.y = 99;
}

void main16(){
    Animal dog;
    //*we can access to public parameters : 
    dog.print();

    dog.name = "Alice";
    //* but cannot access private :
    //dog.x = 5 //gets error
    //! but we declared a friend function inside. therefore we may access private parts from friend:
    sudoAnimal(dog);
    
    dog.print();

    dog.setLeg(4);
    dog.move(15,22);
    dog.print();

    dog.kill();
    dog.print();
}


//? when we initializing such objects from classes, we may want to get additional procedures while initializing : 

class Flight{
    string serial;
    int airtime;
    //* constructors got the same name: 
    //% default constructor : 
    public: //! have to declare constructor public!
    Flight(){
        serial = "NONE";
        cout << "Running engine checks" << endl << "Ready to fly!" << endl << "No serial defined" << endl << endl;
    }
    //% constructor with parameter : (c++ selects the best suitable constructor automatically)
    Flight(string str){
        serial = str;
        cout << "For " << this->serial << " serial tag." << endl << "Running engine checks" << endl << "Ready to fly!" << endl << endl;
    }
    //! If we only wanted to change values, we might use this type of constructors : 
    Flight(string str , int time) : serial(str) , airtime(time) {/*-- -- maybe write smt in here too -- --*/};

    //* And if we want something happen when deleting these objects, we use destructors : 
    ~Flight(){
        cout << "Plane crashed" << endl ;
    }

    void printfl() const { //! const functions can only be defined in classes, means that cannot change any class data.
        cout << "Flying" ; 
        //airtime = 5 //error
    }

};

void main17(){

    Flight ist_ber; //default will be called.
    Flight* ger_man = new Flight; //default will be called.

    const Flight mer_kez ("TK1223") ; //parameterized called. and since it is const, we cannot change any data from now on.
    Flight* cal_nyc = new Flight("HM5541");  //parameterized called.

    delete ger_man; // only objects with pointer hold can be deleted.

}

//? and ofcourse we may define static properties :
class Mathematic{
    public:
    
    inline static float pi = 3.14;
    
    inline static float k= 5;
    
    // inline koymazsak sınıf dışında tanımlam   ak zorundayız, içerde hata verir : 
    static float euler;
};  
float Mathematic::euler = 2.71;

void main18(){
    cout << "pi number : "<< Mathematic::pi << endl << "e number : " << Mathematic::euler << endl;
    // we may change them too : 
    cout << "prev k : " << Mathematic::k << endl;
    Mathematic::k = 15;
    cout << "new k : " << Mathematic::k << endl;

}

//? dont forget that we can nest classes : 
class Student{
    string name;
    int id;
};
class School{
    string name;
    Student students[50];
};


//? now for a more advanced topic, lets dive into operator overloading : 

class SquareMatrix{
    //- default private:
    public:
    int data[3][3];
    int dimension;
    SquareMatrix(){ //empty matrix
        dimension = 3;
        for (int i = 0 ; i < dimension ; i++){
            for (int k = 0 ; k < dimension ; k++){
                data[i][k] = 0;
            }
        }
    }
    SquareMatrix(int * arr){ // matrix with initial values provided
        dimension = 3;
        for (int i = 0 ; i < dimension ; i++){
            for (int k = 0 ; k < dimension ; k++){
                data[i][k] = arr[3* i + k ];
            }
        }
    }

    //! Now it is time for operators :
    void operator= (const SquareMatrix &source);
    SquareMatrix operator+ (const SquareMatrix &source);
    SquareMatrix operator- (const SquareMatrix &source);
    SquareMatrix operator* (int);
    void operator() ();
    //! ---- for '<<' and '>>' operators, we have to define them out of the class
};

void SquareMatrix::operator= (const SquareMatrix &source){ // ! at declaring operator= , params have to be 'const'
    for (int i = 0 ; i < 3  ; i++){
        for (int k = 0 ; k < 3 ; k++){
            this->data[i][k] = source.data[i][k];
        }
    }
}
SquareMatrix SquareMatrix::operator- (const SquareMatrix &source){
    SquareMatrix result;
    for (int i = 0 ; i < 3 ; i++){
        for (int k = 0 ; k < 3 ; k++){
            result.data[i][k] = this->data[i][k] - source.data[i][k];
        }
    }
    return result;
}
SquareMatrix SquareMatrix::operator+ (const SquareMatrix &source){
    SquareMatrix result;
    for (int i = 0 ; i < 3 ; i++){
        for (int k = 0 ; k < 3 ; k++){
            result.data[i][k] = this->data[i][k] + source.data[i][k];
        }
    }
    return result;
}
SquareMatrix SquareMatrix::operator* (int ml) { // '*' operator
    SquareMatrix result;
    result = *this;
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            result.data[i][k] = result.data[i][k] * ml;
        }
    }
    return result;
}
void SquareMatrix::operator() (){
    cout << "._._._.";
    cout << endl;
    for (int i = 0 ; i < this->dimension ; i++){
        for (int j = 0 ; j < this->dimension ; j++){
            cout << "|" << this->data[i][j];
        }
        cout << "|" << endl;
    }
    cout << "'\u203E'\u203E'\u203E'";
}

//! for << and >> operators, we need ifstream and ostream : 

/* 

#include <ostream>
#include <istream>

void operator<< ( ostream &output , SquareMatrix &instance){ 
    output << "type matrix, to see inside use instance()";
}
void operator<< ( ostream &input , SquareMatrix &i){
    input >> i[0] >> i[1] ... >> i[8];
} 

*/

void main19(){
    int nums1[9];
    int nums2[9];
    cout << "enter 9 numbers for 1st matrix ( second is identity matrix )" ; 
    for (int i = 0; i < 9; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < 9; i++) {
        nums2[i] = i == 0 || i == 4 || i == 8 ? 1 : 0;
    }

    SquareMatrix m1 (nums1);
    SquareMatrix m2 (nums2);
    m1();
    m1 = m1 + m2;
    cout << endl << "m1 + identity : " << endl ;
    m1();

    m1 = m1 - (m2 * 2);
    cout << endl << "m1 - 2*identity : " << endl ;
    m1();
    
}

//? that was it: 
void main20(){
    char message[] = {79, 115, 109, 97, 110, 32, 98, 97, 115, 97, 114, 105, 108, 97, 114, 32, 100, 105, 108, 101, 114, 0}; 
    for (int i = 0; message[i] != 0; i++) {
        cout << message[i];
    }
}



int main(){
    void (*funcs[])() = {main1,main2,main3,main4,main5,main6,main7,main8,main9,main10,main11,main12,main13,main14,main15,main16,main17,main18,main19,main20};int sel;while(true){cout<<endl<<endl<<": \033[32mEnter the scenario you want (0 to terminate)\033[0m"<<endl<<"> ";cin >>sel;if(sel>20||sel<=0){break;}cout<<endl<<"\033[34mRunning \033[0m"<<sel<<"\033[34m. case :\033[0m"<<endl<<"\033[31m----------------|\033[0m"<<sel<<"\033[31m|\033[0m"<<endl<<endl;funcs[sel-1]();cout<<endl<<endl<<"\033[31m----------------|\033[0m"<<sel<<"\033[31m|\033[0m"<<endl;}return 0;
}