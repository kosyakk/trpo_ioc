#ifndef PROCESSOR_H
#define PROCESSOR_H

enum ProcessorType
{ x86,
   x64
};

class Computer
{
   public:
        IntelProcessor* GetProcessor(double speed, ProcessorType type, string version)
    {
       return new IntelProcessor(speed, type, version);
    }
};

class IntelProcessor
{
     string Version;
     ProcessorType Type;
     double Speed;
   public:
     IntelProcessor;

//get,set????

  string GetProcessorInfo()
  {
   return "Processor for" + Version + Speed + Type;
  }

 };

#endif // PROCESSOR_H
