#ifndef __INSUFFICIENT_FUND_EXCEPTION_H__
#define __INSUFFICIENT_FUND_EXCEPTION_H__

using namespace std;

class InsufficientFundsException: public std::exception {
    public: 
        InsufficientFundsException() noexcept = default;
        ~InsufficientFundsException() = default;
        virtual const char *what() const noexcept{
            return "insufficient funds exception";
        }
}
#endif
/*__INSUFFICIENT_FUND_EXCEPTION_H__*/