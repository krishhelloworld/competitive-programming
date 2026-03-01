#include<iostream>
#include<memory>
class formula{
    private:
    std::string m_name;
    public:
    student () :  m_name("Unknown"){
        std::cout << m_name;
    }
    student (const std::string& name): m_name(){
        
    } 
    const std::string& GetName() const{
        return m_name;
    }
};

int main(){
    student shyam ;
    student ("shyam gupta");
    std::cout<<shyam.GetName()<<std::endl;
    std::cout<<"helo"<<std::endl;
}
class Example {
private:
    const int x;
    std::string s;

public:
    Example(int val, const std::string& str) : x(val), s(str) {}  // initializer list needed for x
};