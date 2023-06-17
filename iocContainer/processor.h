#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "ioccontainer.h"

enum ProcessorType
{
    x86,
    x64
};

class IProcessor
{
public:
    virtual ~IProcessor() {}
    virtual string getProcessorInfo() = 0;
    virtual void setProcessor(string, ProcessorType, double) = 0;
    virtual string getProcessor(ProcessorType) = 0;
};

class IntelProcessor : public IProcessor
{
     string m_version;
     ProcessorType m_type;
     double m_speed;
   public:
     IntelProcessor() {}

//get,set????

  string getProcessorInfo() override
  {
        return m_version + " processor for " + getProcessor(m_type) + " " + to_string(m_speed);
  }

  void setProcessor(string version, ProcessorType type, double speed) override
  {
      m_version = version;
      m_type = type;
      m_speed = speed;
  }

  string getProcessor(ProcessorType type) override
  {
      switch (type)
      {
      case ProcessorType::x64:
          return "x64";
          break;

      case ProcessorType::x86:
          return "x86";
          break;

      default:
          break;
      }

      return "No processor.";
  }
 };

class AmdProcessor : public IProcessor
{
     string m_version;
     ProcessorType m_type;
     double m_speed;
   public:
     AmdProcessor() {}

//get,set????

  string getProcessorInfo() override
  {
        return m_version + " processor for " + getProcessor(m_type) + " " + to_string(m_speed);
  }

  void setProcessor(string version, ProcessorType type, double speed) override
  {
      m_version = version;
      m_type = type;
      m_speed = speed;
  }

  string getProcessor(ProcessorType type) override
  {
      switch (type)
      {
      case ProcessorType::x64:
          return "x64";
          break;

      case ProcessorType::x86:
          return "x86";
          break;

      default:
          break;
      }
      return "No processor.";
  }
 };

class Computer
{
public:
    Computer() {}

    Computer(std::shared_ptr<IProcessor> processor)
    {
        m_processor = processor;
    }

    void setProcessor(std::shared_ptr<IProcessor> processor)
    {
        m_processor = processor;
    }

    string getInfo()
    {
        if (m_processor != nullptr)
        {
            return m_processor->getProcessorInfo();
        }
        else
        {
            return "No processor";
        }
    }

private:
    std::shared_ptr<IProcessor> m_processor;
};

#endif // PROCESSOR_H
