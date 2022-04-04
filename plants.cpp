#include <iostream>
#include <string>

using namespace std;

class Plants{
    private:
    string latinName;
    int bloomRate, growRate;
    
    public:
    Plants(){
        setName("planta");
    }

    void setName(string latinName){
        this->latinName = latinName;
    }

    void absorbSunlight(int x, int y, int sunlightRate){
        if (x > 10 and y > 25 and sunlightRate == 20)
            this->bloomRate = 50;
        else if (x > 20 and y > 30 and sunlightRate == 30)
            this->bloomRate = 60;
        else if (x > 30 and y > 40 and sunlightRate == 40)
            this->bloomRate = 70;
        else if (x > 40 and y > 50 and sunlightRate == 50)
            this->bloomRate = 80;
    }

    void bearFlower(string fertilizer){
        if (fertilizer == "high-potassium liquid")
            this->growRate = 80;
        else if (fertilizer == "Rose food formula")
            this->growRate = 90;
    }

    void doPhotosynthesis(int waterRate, int mineralRate){
        cout << "The plant is doing photosynthesis" << "\n";
    }

    void spellLatinName(){
        cout << this->latinName << "\n";
    }
};

class Cherry : public Plants{
    private:
    enum cherryType{Tree, Bush} cherry;

    public:
    Cherry(cherryType cherry){
        this->cherry = cherry;
        setName();
    }

    ~Cherry(){
        if(this->cherry == 0)
            cout << "cherry wood table" << "\n";
        else if (this->cherry == 1)
            cout << "high quality compost" << "\n";
    }

    void setName(){
        Plants::setName("Prunus avium");
    }
};

class Lily : public Plants{
    private:
    int numOfBulbs;

    public:
    Lily(int numOfBulbs){
        this->numOfBulbs = numOfBulbs;
        setName();
    }

    ~Lily(){
        cout << "high quality compost" << "\n";
    }

    void setName(){
        Plants::setName("Lilium candidum");
    }
};

int main(){
    Lily* northEastGarden = new Lily(12);
    northEastGarden->bearFlower(string("high-potassium liquid"));
    northEastGarden->spellLatinName();
    Cherry* westWoods = new Cherry(Bush);
    westWoods->spellLatinName();
    return 0;
}

