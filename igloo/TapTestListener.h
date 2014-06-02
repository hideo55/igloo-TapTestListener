#if !defined(IGLOO_TAP_TEST_LISTENER_H_)
#define IGLOO_TAP_TEST_LISTENER_H_

#include <string>
#include <igloo/core/testlistener.h>
#include <stack>

namespace igloo {

class TapTestListener : public igloo::TestListener {
public:
    TapTestListener() 
        : TestListener(), 
          depth_(0), 
          currentCounts_(0),
          contextHasError_(false)
    {
    
    }

    virtual void TestRunStarting() {
        testCounters_.push(0);
    }

    virtual void TestRunEnded(const TestResults&) {
        std::cout << "1.." << currentCounts_ << std::endl;
    }

    virtual void ContextRunStarting(const ContextBase& context) {
        testCounters_.push(currentCounts_ + 1);
        currentCounts_ = 0;
        ++depth_;
        contextHasError_ = false;
    }

    virtual void ContextRunEnded(const ContextBase& context) {
        outputIndent();
        std::cout << "1.." << currentCounts_ << std::endl;
        currentCounts_ = testCounters_.top();
        testCounters_.pop();
        --depth_;
        outputIndent();
        if(contextHasError_){
            std::cout << "not ";
        }
        std::cout << "ok " << currentCounts_ << " - " << context.Name() << std::endl;
    }

    virtual void SpecRunStarting(const ContextBase& context, const std::string& spec) {
        ++currentCounts_;
    }

    virtual void SpecSucceeded(const ContextBase& context, const std::string& spec) {
        outputIndent();
        std::cout << "ok " << currentCounts_ << " - " << spec << std::endl;
    }

    virtual void SpecFailed(const ContextBase& , const std::string& spec) {
        outputIndent();
        std::cout << "not ok " << currentCounts_ << " - " << spec << std::endl;
        contextHasError_ = true;
    }

private:
    unsigned int depth_;
    unsigned int currentCounts_;
    std::stack<unsigned int> testCounters_; 
    bool contextHasError_;

    void outputIndent() const {
        for (size_t i = 0; i < depth_; ++i) {
            std::cout << "    ";
        }
    }
};

}

#endif /* IGLOO_TAP_TEST_LISTENER_H_ */
