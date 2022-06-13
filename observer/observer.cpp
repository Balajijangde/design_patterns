#include <iostream>
#include <list>

using namespace std;
class IObserver
{
public:
    // pure virtual function
    virtual void update(int runs, int wickets, int balls) = 0;
};
class ISubject
{
public:
    // pure virtual functions
    virtual void registerObserver(IObserver *observer) = 0;
    virtual void unregisterObserver(IObserver *observer) = 0;
    virtual void updateObserver() = 0;
};
class CrickerScoreSubject : public ISubject
{
    int runs;
    int wickets;
    int balls;
    list<IObserver *> observerList;

public:
    CrickerScoreSubject()
    {
        this->runs = 0;
        this->wickets = 0;
        this->balls = 0;
    }
    void registerObserver(IObserver *observer)
    {
        observerList.push_back(observer);
    }
    void unregisterObserver(IObserver *observer)
    {
        observerList.remove(observer);
    }
    void updateObserver()
    {
        for (auto it = observerList.begin(); it != observerList.end(); it++)
        {
            (*it)->update(this->runs, this->wickets, this->balls);
        }
    }
    void updateScores(int runs, int wickets, int balls)
    {
        this->runs = runs;
        this->wickets = wickets;
        this->balls = balls;
    }
};

class CricketScoreObserver : public IObserver
{
public:
    int runs;
    int wickets;
    int balls;
    CricketScoreObserver()
    {
        this->runs = 0;
        this->wickets = 0;
        this->balls = 0;
    }
    void update(int runs, int wickets, int balls)
    {
        this->runs = runs;
        this->wickets = wickets;
        this->balls = balls;
        cout << "Score updated, runs : " << this->runs << ", wickets : " << this->wickets << ", Balls : " << this->balls << "\n";
    }
};

int main()
{
    CrickerScoreSubject *worldFinals = new CrickerScoreSubject();
    CricketScoreObserver *hotstar = new CricketScoreObserver();
    CricketScoreObserver *tvChannel = new CricketScoreObserver();

    worldFinals->registerObserver(hotstar);
    worldFinals->registerObserver(tvChannel);
    worldFinals->updateScores(20, 1, 12);
    worldFinals->updateObserver();

    worldFinals->unregisterObserver(tvChannel);
    worldFinals->updateScores(50, 3, 25);
    worldFinals->updateObserver();
}