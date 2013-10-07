#include <iostream>

using namespace std;

//전방선언
class Duck;
class RedheadDuck;
class QuackBehavior;



//인터페이스
class QuackBehavior
{
    public:
        virtual void quack()=0;
};

//QuackBehavior 구현1
class QuackLikeDogBehavior : public QuackBehavior
{
    public:
        QuackLikeDogBehavior()   {}

        virtual void quack() 
        {
            cout << "멍멍" << endl;
        }

};

//QuackBehavior 구현2
class QuackLikeCatBehavior : public QuackBehavior
{
    public:
        QuackLikeCatBehavior()   {}

        virtual void quack() 
        {
            cout << "야옹" << endl;
        }

};

//QuackBehavior 구현3
class QuackLikeDuckBehavior : public QuackBehavior
{
    public:
        QuackLikeDuckBehavior()   {}

        virtual void quack() 
        {
            cout << "꽥" << endl;
        }

};


//오리
class Duck
{
    public:
        void performQuack()
        {
            quack->quack();
        }
        void setQuackBehavior(QuackBehavior *quackBehavior)
        {
            if(quack)
                delete quack;
            quack = quackBehavior;
        }

    protected:
        QuackBehavior *quack;
};


//빨간머리 오리
class RedheadDuck : public Duck
{
    public:
        RedheadDuck()
        {
            quack = new QuackLikeDogBehavior();
        }
};


//청둥 오리
class MallardDuckDuck : public Duck
{
    public:
        MallardDuckDuck()
        {
            quack = new QuackLikeCatBehavior();
        }
};


//메인
int main()
{
    Duck *duck1 = new RedheadDuck();
    duck1->performQuack();


    Duck *duck2 = new MallardDuckDuck();
    duck2->performQuack();

    duck2->setQuackBehavior(new QuackLikeDuckBehavior());
    duck2->performQuack();

    return 0;
}

