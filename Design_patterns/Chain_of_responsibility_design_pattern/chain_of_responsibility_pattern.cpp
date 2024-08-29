
/*
    use cases: Design Vending machine/ ATM / loggers
*/


#include "bits/stdc++.h"
using namespace std;

int INFO=1;
int DEBUG=2;
int ERROR=3;

class LogProcessor{
    public:
    
    LogProcessor *nextLoggerProcessor;

    LogProcessor(LogProcessor* loggerProcessor): nextLoggerProcessor(loggerProcessor){}
    virtual void log(int logLevel, string message){
        if(nextLoggerProcessor != NULL){
            nextLoggerProcessor->log(logLevel, message);
        }
    }
    virtual ~LogProcessor()=default;
};

class InfoLogProcessor: public LogProcessor{
    public:
    InfoLogProcessor(LogProcessor *nextLoggerProcessor):LogProcessor(nextLoggerProcessor){}
    // InfoLogProcessor(LogProcessor *nextLoggerProcessor){
    //     LogProcessor::LogProcessor(nextLoggerProcessor);
    // }
    void log(int logLevel, string message) override{
        if(logLevel == INFO){
            cout << "INFO: " + message << endl;
        }else{
            LogProcessor::log(logLevel, message);
        }
    }
};

class ErrorLogProcessor: public LogProcessor{
    public:
    ErrorLogProcessor(LogProcessor *nextLoggerProcessor):LogProcessor(nextLoggerProcessor){}
    // ErrorLogProcessor(LogProcessor *nextLoggerProcessor){
    //     LogProcessor::LogProcessor(nextLoggerProcessor);
    // }
    void log(int logLevel, string message) override{
        if(logLevel == ERROR){
            cout << "ERROR: " + message << endl;
        }else{
            LogProcessor::log(logLevel, message);
        }
    }
};

class DebugLogProcessor: public LogProcessor{
    public:
    DebugLogProcessor(LogProcessor *nextLoggerProcessor):LogProcessor(nextLoggerProcessor){}
    // DebugLogProcessor(LogProcessor *nextLoggerProcessor){
    //     LogProcessor::LogProcessor(nextLoggerProcessor);
    // }
    void log(int logLevel, string message) override{
        if(logLevel == DEBUG){
            cout << "DEBUG: " + message << endl;
        }else{
            LogProcessor::log(logLevel, message);
        }
    }
};

//client code
int main(){
    // ErrorLogProcessor *error = new ErrorLogProcessor(nullptr);
    // DebugLogProcessor *debug = new DebugLogProcessor(error);
    // InfoLogProcessor *info = new InfoLogProcessor(debug);
    // LogProcessor *logObject = info;
    LogProcessor *logObject = new InfoLogProcessor(new DebugLogProcessor(new ErrorLogProcessor(nullptr)));
    logObject->log(ERROR, "Exception happens ");
    logObject->log(DEBUG, "Need for debuggging ");
    logObject->log(INFO, "Just for info ");
    return 0;
}