#include <QCoreApplication>

#include "processor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    IOCContainer injector;

    injector.registerInstance<IProcessor, IntelProcessor>();

    injector.getObject<IProcessor>()->setProcessor("Intel Core", ProcessorType::x64, 1.0);
    auto computer = std::make_shared<Computer>(injector.getObject<IProcessor>());
    cout << computer->getInfo() << endl;

    injector.registerInstance<IProcessor, AmdProcessor>();

    injector.getObject<IProcessor>()->setProcessor("AMD", ProcessorType::x64, 1.0);
    auto computer2 = std::make_shared<Computer>(injector.getObject<IProcessor>());
    cout << computer2->getInfo() << endl;

    //------Example #2----------------

    /*gContainer.registerInstance<IAmAThing, TheThing>();
    gContainer.registerFactory<IAmTheOtherThing, TheOtherThing, IAmAThing>();

    gContainer.getObject<IAmAThing>()->TestThis();
    gContainer.getObject<IAmTheOtherThing>()->TheOtherTest();

    //Опять запршиваем объект,после последней регистрации получим объект Privet
    helloInstance = injector.getObject<IHello>();
    helloInstance->hello();*/

    return a.exec();
}
