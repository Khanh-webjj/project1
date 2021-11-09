#pragma once
#include "Book.cpp"
#include<vector>

class Person{
  private:
    std::string name;
    int age;
    std::string add;
    std::vector<Book> vb;
  public:
    Person(){}
    Person(std::string name, int age, std::string add, std::vector<Book> vb){
        this->name = name;
        this->age = age;
        this->add = add;
        this->vb = vb;
    }
    std::string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    std::string getAdd(){
        return add;
    }
    std::vector<Book> getVB(){
        return vb;
    }
    virtual long moneyPay() = 0;
    virtual void display(){
		std::cout<<"Name: "<<name<<"\nAge: "<<age<<"\nAdd: "<<add<<"\nList Book Borrowed:" <<std::endl;
		int size = vb.size();
		for (int i = 0; i<size; i++){
			vb[i].display();
		}
		std::cout<<"Money Pay: "<<moneyPay() <<std::endl;
	}
	static void sortPersonAge(std::vector<Person*>& vt){
        for (int i = 0; i < vt.size() - 1; i++){
			for (int j = i + 1; j < vt.size(); j++){
				if (vt[i]->getAge() > vt[j]->getAge())
				{
					Person* temp;
                    *temp=*(vt[i]);
                    *vt[i] = *vt[j];
                    *vt[j] = *temp;
				}
			}
		}
	}
 	static std::vector<int> getListAge(std::vector<Person*> vt){
 	    bool a[90];
 	    for(int i = 0; i<90; i++){
 	        a[i] = false;
 	    }
 	    int size = vt.size();
 	    std::vector<int> re;
 	    for(int i = 0; i<size; i++){
 	        if(!a[vt[i]->age]){
 	            re.push_back(vt[i]->age);
 	            a[vt[i]->age] = true;
 	        }
 	    }
 	    return re;
 	}
 	static std::vector<Book> getMaxBookBorrowed(std::vector<Person*> vp, std::vector<Book> vB){
 	    int sizeP = vp.size(), sizeB = vB.size();
 	    std::vector<int> count(sizeB, 0);
 	    for(int i = 0; i<sizeB; i++){
 	        for(int h = 0; h<sizeP; h++){
 	            std::vector<Book> b(vp[h]->getVB());
 	            for(int g =0; g<b.size(); g++){
 	                if(vB[i].getNameBook() == b[g].getNameBook()) count[i]++;
 	            }
 	        }
 	    }
 	    int max = count[0];
 	    std::vector<Book> re;
 	    for(int i =0; i<sizeB; i++){
 	        if(max<count[i]) max = count[i];
 	    }
 	    for(int i =0; i<sizeB; i++){
 	        if(max == count[i]) re.push_back(vB[i]);
 	    }
 	    return re;
 	}
};